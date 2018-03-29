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
    this->setItem(2,1,new QTableWidgetItem("22222"));

}
