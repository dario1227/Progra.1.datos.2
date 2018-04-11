//
// Created by dario1227 on 26/02/18.
//

#ifndef EXTRA_CLASE_1_LISTASIMPLE_H
#define EXTRA_CLASE_1_LISTASIMPLE_H
#include "NodoS.h"
class ListaSimple {
public:
    ListaSimple(){
        head= nullptr;
    }
    int large=0;
    NodoS* head= nullptr;
    void addF(MyThread x);
    void addL(MyThread x);
    void add(MyThread x , int pos);
    void delF();
    void delL();
    void del(int pos);
    void get(int pos);
    void modify(MyThread x, int pos);
};



#endif //EXTRA_CLASE_1_LISTASIMPLE_H
