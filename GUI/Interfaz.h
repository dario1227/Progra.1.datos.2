//
// Created by dario1227 on 26/03/18.
//

#ifndef PROGRA_1_DATOS_2_INTERFAZ_H
#define PROGRA_1_DATOS_2_INTERFAZ_H


#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "CodeEditor.h"
#include "RAM.h"

class Interfaz: public QMainWindow{
    Q_OBJECT
public:
    CodeEditor* editor;
    RAM* table;
    static CodeEditor* document;
    void Start();
    QString getLine(int x);
    QString getCell(int x, int y);

public slots:
void prueba();
};


#endif //PROGRA_1_DATOS_2_INTERFAZ_H
