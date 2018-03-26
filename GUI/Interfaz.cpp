//
// Created by dario1227 on 26/03/18.
//

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
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
    text->resize(900,300);
    text->move(0,30);
    QLabel* RAM = new QLabel("########");
    RAM->resize(300,670);
    RAM->move(900,30);
    QLabel* log = new QLabel("########");
    log->resize(900,140);
    log->move(0,560);
    QLabel* console = new QLabel("########");
    console->resize(900,200);
    console->move(0,330);
    QLabel* ramTittle = new QLabel("RAM Live View");
    ramTittle->setAlignment(Qt::AlignCenter);
    ramTittle->resize(300,30);
    ramTittle->move(900,0);
    QLabel* LogTittle = new QLabel("Application Log");
    LogTittle->resize(900,30);
    LogTittle->move(0,530);
    console->setParent(main);
    runL->setParent(main);
    log->setParent(main);
    LogTittle->setParent(main);
    RAM->setParent(main);
    ramTittle->setParent(main);
    text->setParent(main);
    text->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    console->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    runL->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    log->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    RAM->setStyleSheet("QLabel { background-color : darkcyan; color : black; border: 1px solid black}");
    ramTittle->setStyleSheet("QLabel { background-color : gray; color : black;  border: 1px solid black}");
    LogTittle->setStyleSheet("QLabel { background-color : gray; color : black; border: 1px solid black}");
    main->show();

}
