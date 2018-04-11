//
// Created by dario1227 on 26/03/18.
//

#ifndef PROGRA_1_DATOS_2_INTERFAZ_H
#define PROGRA_1_DATOS_2_INTERFAZ_H


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "CodeEditor.h"
#include "RAM.h"
#include <iostream>
using namespace std;
class Interfaz: public QObject{
    Q_OBJECT
public:
    CodeEditor* editor;
    static QPlainTextEdit* logger;
    static QPlainTextEdit* shell;
    RAM* table;
    static CodeEditor* document;
    void Start();
    void findWords(string a);
    int getLines();
    QString getLine(int x);
    QString getCell(int x, int y);
    static void addLog(string x);
    static void addToShell(string x);
public slots:
void prueba();
};


#endif //PROGRA_1_DATOS_2_INTERFAZ_H
