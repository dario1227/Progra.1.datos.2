//
// Created by dario1227 on 11/04/18.
//
#include <pthread.h>
#include "MyThread.h"
#include <thread>
MyThread::MyThread() {
    this->lista=new ListaSimple();
}
void MyThread::addT(void (*Function)()) {
    NodoS* t=new NodoS();
    t->Function=Function;
    this->lista->addL(t);


}
void MyThread::startT() {
    NodoS* temp= this->lista->head;
    while(temp!= nullptr){
        std::thread t(temp->Function);
        t.detach();
        temp=temp->next;
    }


}