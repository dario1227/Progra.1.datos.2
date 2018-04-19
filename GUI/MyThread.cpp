//
// Created by dario1227 on 11/04/18.
//
#include "MyThread.h"
#include <pthread.h>
#include "ListaSimple.h"
#include "NodoS.h"
MyThread::MyThread() {
    this->lista=new ListaSimple();
}
//agrega un thread con la funcion en el parametro
void MyThread::addT(void (*Function)()) {
    NodoS* t=new NodoS();
    t->Function=Function;
    this->lista->addL(t);


}
//inicializa todos los threads
void MyThread::startT() {
    NodoS* temp= this->lista->head;
    while(temp!= nullptr){
        std::thread t(temp->Function);
        t.detach();
        temp=temp->next;
    }


}