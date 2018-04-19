//
// Created by dario1227 on 26/03/18.
//

#include "RAM.h"
//la tabla de la memoria RAM
RAM::RAM(int x) {
    this->setColumnCount(5);
    this->setRowCount(x);
    QStringList header;
    header<<"Type"<<"Name"<<"Direction"<<"Position"<<"Scope";
    this->setHorizontalHeaderLabels(header);
    this->setEditTriggers(QAbstractItemView::NoEditTriggers);
    QString* sa=new QString("Prueba");
    this->add(0,0,*sa);
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
    return result;

}
