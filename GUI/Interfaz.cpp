//
// Created by dario1227 on 26/03/18.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QPlainTextEdit>
#include <QtGui/QTextBlock>
#include "Interfaz.h"
#include "CodeEditor.h"
#include "RAM.h"
#include "../Parsing/Syntax_analysis.h"
#include "../Parsing/Operational_parsing.h"
#include <iostream>
#include <QThread>
#include <thread>
#include <zconf.h>

#define SPACEBAR 32;

using namespace std;
CodeEditor* Interfaz::document= nullptr;
QPlainTextEdit* Interfaz::logger= nullptr;
QPlainTextEdit* Interfaz::shell= nullptr;
void Interfaz::Start() {
    QWidget* main=new QWidget();
    Interfaz::logger=new QPlainTextEdit();
    Interfaz::shell= new QPlainTextEdit();
    this->editor=new CodeEditor(main);
    main->setWindowTitle("C! IDE");
    main->resize(1250,700);
    QPushButton* run= new QPushButton("RUN!");
    connect(run,SIGNAL(clicked()),this,SLOT(prueba()));
    QLabel* runL = new QLabel();
    run->setParent(runL);
    runL->resize(900,30);
    runL->move(0,0);
    this->table = new RAM(200);
    Operational_parsing::interface=this;
    QLabel* log = new QLabel("########");
    QLabel* console = new QLabel("########");
    QLabel* ramTittle = new QLabel("RAM Live View");
    QLabel* conTittle = new QLabel("Console");
    conTittle->setParent(main);
    conTittle->resize(900,30);
    conTittle->move(0,330);
    this->editor=new CodeEditor(main);
    ramTittle->setAlignment(Qt::AlignCenter);
    ramTittle->resize(350,30);
    ramTittle->move(900,0);
    QLabel* LogTittle = new QLabel("Application Log");
    LogTittle->resize(900,30);
    LogTittle->move(0,530);
    runL->setParent(main);
    LogTittle->setParent(main);
    ramTittle->setParent(main);
    this->table->setParent(main);
    log->setParent(main);
    console->setParent(main);
    console->move(0,360);
    this->editor->move(0,30);
    this->table->move(900,30);
    log->move(0,560);
    this->table->resize(350,670);
    log->resize(900,140);
    Interfaz::logger->setParent(log);
    Interfaz::logger->resize(900,140);
    Interfaz::shell->setParent(console);
    Interfaz::shell->resize(900,170);
    Interfaz::shell->setReadOnly(true);
    Interfaz::logger->setReadOnly(true);
    Interfaz::shell->setStyleSheet("color : blue");
    Interfaz::logger->setStyleSheet("color : red");
    console->resize(900,170);
    this->editor->resize(900,300);
    console->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    runL->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    log->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    conTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    ramTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    LogTittle->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
   Interfaz::document=this->editor;
    main->show();

}
QString Interfaz::getCell(int x, int y) {
    QString val=this->table->itemAt(x,y)->text();
    return val;
}
QString Interfaz::getLine(int x) {
    QTextDocument* doc= this->editor->document();
    QTextBlock text= doc->findBlockByLineNumber(x);
    QString line=text.text();
    QString* str = new QString();
    str->append(' ');

    cout<<line.toStdString();
    return line;
}
void Interfaz::findWords(string a) {
    qRegisterMetaType<QTextCharFormat>("QTextCharFormat");
    qRegisterMetaType<QTextCursor>("QTextCursor");
    QTextCursor *highlightCursor ;
    QTextCursor *cursor;
    QTextCharFormat *plainFormat;
    QTextCharFormat *colorFormat;
    QString * searched= new QString(a.c_str());
    highlightCursor =new QTextCursor(this->editor->document());
    cursor=new QTextCursor(this->editor->document());
    plainFormat= new QTextCharFormat(highlightCursor->charFormat());
    colorFormat = plainFormat;
    cursor->beginEditBlock();
    colorFormat->setForeground(Qt::magenta);
    while (!highlightCursor->isNull() && !highlightCursor->atEnd()) {
        *highlightCursor = this->editor->document()->find(*searched, *highlightCursor, QTextDocument::FindWholeWords);
        if (!highlightCursor->isNull()) {
            highlightCursor->movePosition(QTextCursor::WordRight,
                                          QTextCursor::KeepAnchor);
            highlightCursor->mergeCharFormat(*colorFormat);
        }
    }
    cursor->endEditBlock();
}
void Interfaz::prueba() {
    Syntax_analysis* syntax = new Syntax_analysis();
    cout<<"CODIGO Fue"<<syntax->syntax_analysis(getLine(0),0)<<std::endl;
    this->table->add(1,1,getLine(2));
    findWords("int");
    findWords("long");
    findWords("string");
    findWords("struct");
    findWords("short");
    findWords("bool");
    findWords("float");
    findWords("double");
    findWords("char");
    findWords("printf");
    addLog("ERROR");
    addToShell("KILL ME PLS :,v");

}

void Interfaz::addLog(string x) {
    Interfaz::logger->appendPlainText(x.c_str());


}
void Interfaz::addToShell(string x) {
    Interfaz::shell->appendPlainText(x.c_str());

}

