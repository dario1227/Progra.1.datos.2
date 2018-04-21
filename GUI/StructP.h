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
    static bool parseemeesta(QString line, Interfaz *gui);
    static ListaSimple* structs;
    static json_object* searchVariable(string struc,string variable );
    int bytes=0;
    int inicio=0;
    string nombre;
   json_object* makeJson();
    int final =0;
    json_object* lines[30];
    static json_object* getVariable(string name, StructP* estuctura);
    static void start(Interfaz* gui);
    static StructP* searchStruct(string name);

};


#endif //PROGRA_1_DATOS_2_STRUCTP_H
