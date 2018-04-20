//
// Created by dario1227 on 26/03/18.
//

#ifndef PROGRA_1_DATOS_2_RAM_H
#define PROGRA_1_DATOS_2_RAM_H


#include <QtCore/QStringListModel>
#include <QtWidgets/QTableWidget>
#include <iostream>
using namespace std;
class RAM: public  QTableWidget{
public:
    RAM(int x);
    void add(int row, int colu, QString data);
    bool isEmpty( int colu, int row);
    int searchName(string name );
    int searchPos(string pos);

};


#endif //PROGRA_1_DATOS_2_RAM_H
