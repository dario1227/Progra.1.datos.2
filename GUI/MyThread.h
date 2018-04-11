//
// Created by dario1227 on 11/04/18.
//

#ifndef PROGRA_1_DATOS_2_MYTHREAD_H
#define PROGRA_1_DATOS_2_MYTHREAD_H

#include "../ListaSimple/ListaSimple.h"

class ListaSimple;
class MyThread {
public:
    MyThread();
    ListaSimple* lista= nullptr;
    void addT(void (*function)());
    void startT();

};


#endif //PROGRA_1_DATOS_2_MYTHREAD_H
