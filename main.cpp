#include <iostream>
#include <QApplication>
#include "GUI/Interfaz.h"
using namespace std;
Interfaz* GUI;
int main(int argc, char **argv) {
    QApplication app(argc, argv);
     GUI= new Interfaz();
     QString str="34     ";
     bool x;
     str.toInt(&x,10);
     cout<<"ENCONTRE QUE FUE"<<x;
    GUI->Start();
    cout<<GUI->getCell(0,0).toStdString();
    return app.exec();
}