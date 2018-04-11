//
// Created by dario1227 on 26/02/18.
//

#ifndef EXTRA_CLASE_1_NODOS_H
#define EXTRA_CLASE_1_NODOS_H


#include "../GUI/MyThread.h"

class NodoS {
public:
    MyThread value;
    void setValue(MyThread x);
    NodoS* next= nullptr;
    NodoS(){
    next= nullptr;
    }
};


#endif //EXTRA_CLASE_1_NODOS_H
