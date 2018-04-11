//
// Created by dario1227 on 26/02/18.
//

#ifndef EXTRA_CLASE_1_NODOS_H
#define EXTRA_CLASE_1_NODOS_H


#include <thread>
#include "../GUI/MyThread.h"

class NodoS {
public:
    NodoS();
    void (*Function)();
    NodoS* next= nullptr;
};


#endif //EXTRA_CLASE_1_NODOS_H
