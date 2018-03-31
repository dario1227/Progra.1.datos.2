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
using namespace std;
void Interfaz::Start() {
    QWidget* main=new QWidget();
    main->setWindowTitle("C! IDE");
    main->resize(1250,700);
    QPushButton* run= new QPushButton("RUN!");
    QLabel* runL = new QLabel();
    run->setParent(runL);
    runL->resize(900,30);
    runL->move(0,0);
    this->table = new RAM(200);
    Operational_parsing::table_values=table;
    QLabel* log = new QLabel("########");
    QLabel* console = new QLabel("########");
    QLabel* ramTittle = new QLabel("RAM Live View");
    QLabel* conTittle = new QLabel("Console");
    conTittle->setParent(main);
    connect(run,SIGNAL (clicked()),this,SLOT(prueba()));
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
    console->resize(900,170);
    this->editor->resize(900,300);
    console->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    runL->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    log->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    conTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    ramTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    LogTittle->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
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
void Interfaz::prueba() {
    Syntax_analysis* syntax = new Syntax_analysis();
    cout<<"CODIGO Fue"<<syntax->syntax_analysis(getLine(0),0)<<std::endl;
    this->table->add(1,1,getLine(2));
}
