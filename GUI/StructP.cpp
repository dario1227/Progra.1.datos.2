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
//
json_object* StructP::makeJson(){
    json_object* object = json_object_new_object();
    json_object* toAdd = json_object_new_string(this->nombre.c_str());
    json_object_object_add(object,"name",toAdd);
    toAdd = json_object_new_string(to_string(this->bytes).c_str());
    json_object_object_add(object,"Bytes",toAdd);
    toAdd = json_object_new_string(to_string(this->inicio).c_str());
    json_object_object_add(object,"Start",toAdd);
    toAdd = json_object_new_string(to_string(this->final).c_str());
    json_object_object_add(object,"End",toAdd);
    return object;
}
void StructP::start(Interfaz* gui){
    StructP::structs= new ListaSimple();
    int x=0;
    int ini=0;
    int fin=0;
    int total=0;
    int finales=gui->getLines();
    bool valor=false;
    string data;
    while(x<=finales){
        QString line=gui->getLine(x);
        if(line.contains("{")&&line.contains("struct")){
           string name= line.toStdString();
            name.resize(name.length()-1);
            std::reverse(name.begin(), name.end());
            name.resize(name.length()-7);
            std::reverse(name.begin(), name.end());
            data=name;
            ini=x+1;
            valor= true;
        }
        else if(line.contains("}")){
            valor=false;
            fin=x+1;
            StructP* structP=new StructP();
            structP->inicio=ini;
            structP->final=fin;
            structP->bytes=total;
            structP->nombre=data;
            NodoS* nodo= new NodoS();
            nodo->value=structP;
            StructP::structs->addL(nodo);
            total=0;
        }
        else if(valor && line.contains("int")){
            total+=4;
        }
        else if(valor && line.contains("long")){
            total+=8;
        }
        else if(valor && line.contains("char")){
            total+=1;
        }
        else if(valor && line.contains("float")){
            total+=4;
        }
        else if(valor && line.contains("double")){
            total+=4;
        }
        else if(valor && line.contains("int")){
            total+=8;
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
