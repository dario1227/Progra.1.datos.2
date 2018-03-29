//
// Created by dario1227 on 26/03/18.
//

#include "RAM.h"
RAM::RAM(int x) {
    this->setColumnCount(3);
    this->setRowCount(x);
    QStringList header;
    header<<"Type"<<"Name"<<"Direction";
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
