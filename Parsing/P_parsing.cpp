//
// Created by kenneth on 28/03/18.
//

#include <QtCore/QString>
#include "P_parsing.h"

void P_parsing::parseLine(QString line) {
    if(line[line.size()-1]!=';'){
        return;
    }
    if(line.contains("int",Qt::CaseSensitive)){
        //parseInt()
    }
}
//void P_parsing::parseChar() {}
//void P_parsing::parseDouble() {}
