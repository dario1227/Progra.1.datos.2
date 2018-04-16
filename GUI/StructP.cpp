//
// Created by dario1227 on 15/04/18.
//

#include <QtGui/QTextCursor>
#include "StructP.h"
#include "Interfaz.h"
ListaSimple* StructP::structs=new ListaSimple();
void StructP::start(Interfaz* gui){
    StructP::structs= new ListaSimple();
    int x=0;
    int ini=0;
    int fin=0;
    int finales=gui->getLines();
    while(x<=finales){
        QString line=gui->getLine(x);
        if(line.contains("{")){
            ini=x+1;
        }
        else if(line.contains("}")){
            fin=x+1;
            cout<<"hhoollllaaaa";
            StructP* structP=new StructP();
            structP->inicio=ini;
            structP->final=fin;
            NodoS* nodo= new NodoS();
            nodo->value=structP;
            StructP::structs->addL(nodo);
        }
        x++;

    }
}
