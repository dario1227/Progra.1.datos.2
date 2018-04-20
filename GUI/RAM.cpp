//
// Created by dario1227 on 26/03/18.
//

#include "RAM.h"
//la tabla de la memoria RAM
RAM::RAM(int x) {
    this->setColumnCount(5);
    this->setRowCount(x);
    QStringList header;
    header<<"Type"<<"Name"<<"Direction"<<"Scope"<<"Value";
    this->setHorizontalHeaderLabels(header);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);

}
void RAM::add(int row, int colu, QString data) {
   QTableWidgetItem* da= new QTableWidgetItem(data);
    this->setItem(row, colu,da);
    da->setTextAlignment(Qt::AlignCenter);

}
//verifica la fila vacia
bool RAM::isEmpty(int colu, int row) {
    bool valor=this->item(row,colu)== nullptr;
   return valor;
}
int RAM::searchName(string name ){
    int index=0;
    int result=0;
    while(!isEmpty(1,index)){
        if(this->item(index,1)->text().toStdString()==name){
            result=index;
            cout<<"LO ENCONTRE PERRAS";
            break;
        }
        index++;

    }
    if(isEmpty(1,index)){
        return -1;
    }
    return result;

}
int RAM::searchPos(string pos ){
    std::cout<<pos<< "ESTA FUE LA POSICION :D"<<std::endl;
    int index=0;
    int result=0;
    while(!isEmpty(1,index)){
        if(this->item(index,2)->text().toStdString()==pos){
            result=index;
            cout<<"LO ENCONTRE PERRAS";
            break;
        }
        index++;
        std::cout<<"ESTE ES EL INDICE"<<std::endl;
    }
    if(isEmpty(1,index)){
        return -1;
    }
    return result;

}