#include <iostream>
#include <QApplication>
#include "GUI/Interfaz.h"
using namespace std;
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    Interfaz* GUI= new Interfaz();
    GUI->Start();
    return app.exec();
}