//
// Created by kenneth on 30/03/18.
//

#include <json-c/json_object.h>
#include "Operational_parsing.h"
RAM* Operational_parsing::table_values = nullptr;
json_object* Operational_parsing::object= nullptr;
bool Operational_parsing::parse(QString operation,const char* type,json_object* objeto) {
if(type=="int"){
    return parse_int(operation,type);
}
if(type=="float"){
    return parse_floar(operation,type);
}
    if(type=="double"){
        return parse_double(operation,type);
    }
    if(type=="long"){
        return parse_long(operation,type);

    }
}
bool Operational_parsing::parse_int(QString operation, const char *tipo) {
    int toAdd = 0;

        }
bool Operational_parsing::parse_floar(QString operation, const char *tipo) {

}
bool Operational_parsing::parse_long(QString operation, const char *tipo) {

}
bool Operational_parsing::parse_double(QString operation, const char *tipo) {}

bool Operational_parsing::contains_alphabet(QString str,char* varType) {
    if (varType=="float"||varType=="double"){
    bool x;
    str.toDouble(&x);
    return x;
    }
    else{
        bool x;
        str.toLong(&x,10);
        return x;
    }

}
QString Operational_parsing::reconstruct_without_space(QString *str) {
    
}
