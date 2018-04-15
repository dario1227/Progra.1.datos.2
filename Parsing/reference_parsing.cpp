//
// Created by kenneth on 12/04/18.
//

#include <iostream>
#include "reference_parsing.h"
#include "Operational_parsing.h"

bool reference_parsing::parse_reference(QString qString, json_object *pObject) {
    int counter = 0;
    int counter2=0;
    int counter_back=0;
    QString isReference = QString();
    QString reference_type = QString();

    while(counter<qString.length()&& counter2!=2){
        if(qString[counter]=='>'){
            counter_back++;
            counter2++;
        }
        if(qString[counter]=='<'){
            if(counter_back==1){
                Operational_parsing::interface->addLog("Error se espera el < antes del >");
                return false;
            }
            counter2++;
            if(qString[counter+1]=='>'){
                Operational_parsing::interface->addLog("Error no se definio el tipo de referencia");
                return false;
            }
            counter++;
        }
        if(counter2==0){
            if(qString[counter]!=' '){
                isReference.append(qString[counter]);
            }
            if(qString[counter]==' ' && !isReference.isEmpty()){
                Operational_parsing::interface->addLog("Error no se espera un espacio en medio del tipo :D");

                return false;
            }
        }
        if(counter2==1){
            reference_type.append(qString[counter]);
        }
        counter++;
    }
    if(isReference=="reference"&&its_type(reference_type)){
        if(is_pointcomma_next(qString,counter+1)||is_equals_next(qString,counter+1)){
            Operational_parsing::interface->addLog("Error no se definio el tipo de variable");
            return false;

        }
        else{
            return parse_reference_stage2(qString,pObject,reference_type);
        }
    }
    else{
        Operational_parsing::interface->addLog("Error tipo incorrecto o inexistente");

        return false;
    }

}
bool reference_parsing::is_equals_next(QString lol, int index) {
    while (index < lol.length()) {
        if (lol[index] == '=') {
            return true;
        }
        if (lol[index] != '=' && lol[index] != ' ') {
            return false;

        }
        index++;;
    }
    return false;
}
bool reference_parsing::is_pointcomma_next(QString str, int index) {
    while (index < str.length()) {
        if (str[index] == ';') {
            return true;
        }
        if (str[index] != ';' && str[index] != ' ') {
            return false;
        }
        index++;
    }
    return false;
}
bool reference_parsing::its_type(QString qString) {
    if ((qString.contains("int")&&!qString.contains("p")) || qString.contains("bool") || qString.contains("char") ||
        qString.contains("double") || qString.contains("long") || qString.contains("float") ||
        qString.contains("struct")) {
        return true;
    } else {
        return false;
    }
}
bool reference_parsing::parse_reference_stage2(QString qString, json_object *pObject, QString type) {
    int index = 0;
    while(index<qString.length()){
        if(qString[index]=='>'){
            index++;
            break;
        }
        index++;
    }
    if(index==qString.length()){
        Operational_parsing::interface->addLog("Error ,no se encontro definicion de variable");

        return false;
    }
    QString type = 
    while
}
bool reference_parsing::already_exists(QString name) {
    int index = 0;
    while(index<200){
        if( Operational_parsing::interface->getCell(1, index).contains(name)){
            Operational_parsing::interface->addLog("Ya existe una variable con el mismo nombre :D");
            return false;
        }
        index++;
    }
    if (index==200){
        return "ERROR";
    }
}