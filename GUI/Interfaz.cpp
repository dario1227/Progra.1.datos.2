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
#include <iostream>
using namespace std;
void Interfaz::Start() {
    QWidget* main=new QWidget();
    main->setWindowTitle("C! IDE");
    main->resize(1200,700);
    QPushButton* run= new QPushButton("RUN!");
    QLabel* runL = new QLabel();
    run->setParent(runL);
    runL->resize(900,30);
    runL->move(0,0);
    QLabel* RAM = new QLabel("########");
    QLabel* log = new QLabel("########");
    QLabel* console = new QLabel("########");
    QLabel* ramTittle = new QLabel("RAM Live View");
    QLabel* conTittle = new QLabel("Console");
    conTittle->setParent(main);
    conTittle->resize(900,30);
    conTittle->move(0,330);
    this->editor=new CodeEditor(main);
    ramTittle->setAlignment(Qt::AlignCenter);
    ramTittle->resize(300,30);
    ramTittle->move(900,0);
    QLabel* LogTittle = new QLabel("Application Log");
    LogTittle->resize(900,30);
    LogTittle->move(0,530);
    runL->setParent(main);
    LogTittle->setParent(main);
    ramTittle->setParent(main);
    RAM->setParent(main);
    log->setParent(main);
    console->setParent(main);
    console->move(0,360);
    this->editor->move(0,30);
    RAM->move(900,30);
    log->move(0,560);
    RAM->resize(300,670);
    log->resize(900,140);
    console->resize(900,170);
    this->editor->resize(900,300);
    console->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    runL->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    log->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    RAM->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    conTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    ramTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    LogTittle->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    main->show();

}
QString Interfaz::getLine(int x) {
    QTextDocument* doc= this->editor->document();
    QTextBlock text= doc->findBlockByLineNumber(x);
    QString line=text.text();
    cout<<line.toStdString();
    return line;
}
