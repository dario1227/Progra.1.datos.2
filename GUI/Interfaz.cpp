//
// Created by dario1227 on 26/03/18.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include "Interfaz.h"
void Interfaz::Start() {
    QWidget* main=new QWidget();
    main->setWindowTitle("C! IDE");
    main->resize(1200,700);
    QPushButton* run= new QPushButton("RUN!");
    QLabel* runL = new QLabel();
    run->setParent(runL);
    runL->resize(900,30);
    runL->move(0,0);
    QLabel* text = new QLabel("########");
    QLabel* RAM = new QLabel("########");
    QLabel* log = new QLabel("########");
    QLabel* console = new QLabel("########");
    QLabel* ramTittle = new QLabel("RAM Live View");
    ramTittle->setAlignment(Qt::AlignCenter);
    ramTittle->resize(300,30);
    ramTittle->move(900,0);
    QLabel* LogTittle = new QLabel("Application Log");
    LogTittle->resize(900,30);
    LogTittle->move(0,530);
    runL->setParent(main);
    LogTittle->setParent(main);
    ramTittle->setParent(main);
    QScrollArea* scrollT= new QScrollArea();
    QScrollArea* scrollL= new QScrollArea();
    QScrollArea* scrollR= new QScrollArea();
    QScrollArea* scrollC= new QScrollArea();
    scrollC->setWidget(console);
    scrollT->setWidget(text);
    scrollL->setWidget(log);
    scrollR->setWidget(RAM);
    scrollC->setParent(main);
    scrollL->setParent(main);
    scrollR->setParent(main);
    scrollT->setParent(main);
    scrollC->move(0,330);
    scrollT->move(0,30);
    scrollR->move(900,30);
    scrollL->move(0,560);
    scrollR->resize(300,670);
    scrollT->resize(900,300);
    scrollL->resize(900,140);
    scrollC->resize(900,200);
    text->resize(1000,1000);
    RAM->resize(280,1000);
    log->resize(1000,1000);
    console->resize(1000,1000);
    text->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    console->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    runL->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    log->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    RAM->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    ramTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    LogTittle->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    main->show();

}
