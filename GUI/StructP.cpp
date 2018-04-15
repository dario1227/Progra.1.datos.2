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
    int final=gui->getLines();
    while(x<=final){
        string line=gui->getLine(x).toStdString();
        if(line.find("{")){
            x++;
            int y=0;
            int array[30];
            while(!line.find("}")) {
                line=gui->getLine(x).toStdString();
                array[y]=x;
                y++;
                x++;
            }
            StructP *structA = new StructP();
            int z=0;
            while(z<30){
                structA->lines[z]=array[z];
                z++;
            }
            NodoS* nodo=new NodoS();
            nodo->value=structA;
            StructP::structs->addL(nodo);
            x++;
        } else{
            x++;
        }
    }


}
