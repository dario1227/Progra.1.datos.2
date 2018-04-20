//
// Created by dario1227 on 15/04/18.
//

#ifndef PROGRA_1_DATOS_2_STRUCTP_H
#define PROGRA_1_DATOS_2_STRUCTP_H


#include <json-c/json_object.h>
#include "ListaSimple.h"
#include "Interfaz.h"
class ListaSimple;
class StructP {
public:
    static ListaSimple* structs;
    int bytes=0;
    int inicio=0;
    string nombre;
   json_object* makeJson();
    int final =0;
    QString lines[30];
    static void start(Interfaz* gui);

};


#endif //PROGRA_1_DATOS_2_STRUCTP_H
