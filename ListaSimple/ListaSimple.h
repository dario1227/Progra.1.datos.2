//
// Created by dario1227 on 26/02/18.
//

#ifndef EXTRA_CLASE_1_LISTASIMPLE_H
#define EXTRA_CLASE_1_LISTASIMPLE_H

#include "NodoS.h"
class NodoS;
class ListaSimple {
public:
    ListaSimple();
    NodoS* head= nullptr;
    int large=0;
    void addL(NodoS* x);
    void delF();
    void delL();
    void del(int pos);
};



#endif //EXTRA_CLASE_1_LISTASIMPLE_H
