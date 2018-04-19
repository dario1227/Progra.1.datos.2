//
// Created by dario1227 on 15/04/18.
//

#include <QtGui/QTextCursor>
#include "StructP.h"
#include "Interfaz.h"
#include "../Parsing/Syntax_analysis.h"

ListaSimple* StructP::structs=new ListaSimple();
//lista de structs en el codigo con sus lineas de inicio y final
//se encarga de agregar los structs y luego parse sus lineas de inicio a fin
void StructP::start(Interfaz* gui){
    StructP::structs= new ListaSimple();
    int x=0;
    int ini=0;
    int fin=0;
    int finales=gui->getLines();
    while(x<=finales){
        QString line=gui->getLine(x);
        if(line.contains("{")&&line.contains("struct")){
            ini=x+1;
        }
        else if(line.contains("}")){
            fin=x+1;
            StructP* structP=new StructP();
            structP->inicio=ini;
            structP->final=fin;
            NodoS* nodo= new NodoS();
            nodo->value=structP;
            StructP::structs->addL(nodo);
        }
        x++;

    }
    NodoS* temp= StructP::structs->head;
    Syntax_analysis* analysis= new Syntax_analysis();
    while (temp!=nullptr){
        int z=temp->value->inicio;
        int y=0;
        while (z<temp->value->final-1){
            bool valor =analysis->syntax_analysis(gui->getLine(z),z);
            if (valor){
                temp->value->lines[y] = gui->getLine(z);
            }
            z++;
            y++;
        }
        temp=temp->next;
    }

}
