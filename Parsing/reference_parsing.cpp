//
// Created by kenneth on 12/04/18.
//

#include <iostream>
#include "reference_parsing.h"
#include "Operational_parsing.h"
#include "Json_creator.h"
#include "Counter_resolving.h"

/**
 * Inicia el parseo de una referencia
 * @param qString
 * @param pObject
 * @return
 */
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
            Json_creator::add_type_value(isReference.toLatin1().data(),pObject);
            return parse_reference_stage2(qString,pObject,reference_type);
        }
    }
    else{
        Operational_parsing::interface->addLog("Error tipo incorrecto o inexistente");

        return false;
    }

}
/**
 * revisa si = es siguiente
 * @param lol
 * @param index
 * @return
 */
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
/**
 * Revisa si es punto y coma siguiente
 * @param str
 * @param index
 * @return
 */
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
/**
 * revisa el tipo
 * @param qString
 * @return
 */
bool reference_parsing::its_type(QString qString) {
    if ((qString.contains("int")&&!qString.contains("p")) || qString.contains("bool") || qString.contains("char") ||
        qString.contains("double") || qString.contains("long") || qString.contains("float") ||
        qString.contains("struct")) {
        return true;
    } else {
        return false;
    }
}
/**
 * parsea los tipos de referencia dentro de reference<LO>
 * @param qString
 * @param pObject
 * @param type
 * @return
 */
bool reference_parsing::parse_reference_stage2(QString qString, json_object *pObject, QString type) {
    std::cout<<"ESTOY EN PARSE REFERENCE2"<<std::endl;

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
    QString name = QString();
    int counter_No_space = 0;
    if(qString[index]!=' '){
        Operational_parsing::interface->addLog("Error ,se tiene que dejar espacio para definir la variable");

        return false;
    }
    while(index<qString.length()){
        std::cout<<"ESTOY EN PARSE REFERENCE2 while"<<std::endl;

        //inicia ese if
        if(is_equals_next(qString,index)){
            if(name.isEmpty()){
                Operational_parsing::interface->addLog("Error ,no se definio un nombre");
                return false;
            }
            else{
                if(!already_exists(name)){
                    return false;
                }
                if(contains_fault_characters(name)){
                    Operational_parsing::interface->addLog("Error ,Caracteres incorrectos en la variable");
                    return false;

                }
                else{
                    Json_creator::add_value_name(name.toLatin1().data(),pObject);
                    return parse_reference_stage3(qString,pObject,type);
                }
            }
        }
        //Termina ese if
        if(qString[index]!=' '){
            name.append(qString[index]);
        }
        index++;

    }
    Operational_parsing::interface->addLog("Error ,No se encontro definicion de la variable");
    return false;

}
/**
 * revisa si existe
 * @param name
 * @return
 */
bool reference_parsing::already_exists(QString name) {
    int index = 0;
    while(index<200){
        if(Operational_parsing::interface->table->isEmpty(1,index)){
            return true;
        }
        if( Operational_parsing::interface->getCell(1, index)==name){
            Operational_parsing::interface->addLog("Ya existe una variable con el mismo nombre :D");
            return false;
        }
        index++;
    }
    if (index==200){
        return true;
    }

}
/**
 * Revisa si contiene caracteres erroneos
 * @param qString
 * @return
 */
bool reference_parsing::contains_fault_characters(QString qString) {
    if(qString.contains("'")||qString.contains("}")||qString.contains("{")||qString.contains(")")||qString.contains("(")||qString.contains(";")||
            qString.contains('"')||qString.contains("!")||qString.contains("*")||qString.contains("?")||qString.contains("]")||
            qString.contains(':')|| qString.contains(',')|| qString.contains('.') ||qString.contains('<')){
        return true;
    }
    else{
        return false;
    }
}
/**
 * PArsea ya la referencia final
 * @param qString
 * @param pObject
 * @param type
 * @return
 */
bool reference_parsing::parse_reference_stage3(QString qString, json_object *pObject, QString type) {

    int index =0;
    while(index<qString.length()){
        if(qString[index]=='='){
            index++;
            break;
        }
        index++;
    }

    QString a_parsear = QString();
    while(index<qString.length()){
        if(qString[index]==';'){
            break;
        }
        if(qString[index]!= ' '){
            a_parsear.append(qString[index]);
        }

        index++;
    }
    int secondary_index=0,parentesis_counter=0;
    QString to_search = QString();
    QString getadd = QString();
    if(a_parsear[7]!='('){
        Operational_parsing::interface->addLog("Error,despues de getAddr tiene que ir un (");


    }
    if(a_parsear[a_parsear.length()-1]!=')'){
        Operational_parsing::interface->addLog("Error,Se debe cerrar con otros )");

    }
    while(secondary_index<a_parsear.length()){
        if(a_parsear[secondary_index]=='('||a_parsear[secondary_index]==')'){
            parentesis_counter++;
            secondary_index++;
        }
        if(parentesis_counter==2){
            break;
        }
        if(parentesis_counter==0){
            getadd.append(a_parsear[secondary_index]);
        }
        if(parentesis_counter==1){
            to_search.append(a_parsear[secondary_index]);
        }
        secondary_index++;
        }
        if(getadd!="getAddr"){
            Operational_parsing::interface->addLog("Error,para conseguir la direccion se necesita getAddr()");
            return false;
        }
        else{
            return  parse_reference_stage4(to_search,pObject,type);
    }
    }
    /**
     * Ya anade los valores de la referencia
     * @param to_search
     * @param pObject
     * @param type
     * @return
     */
bool reference_parsing::parse_reference_stage4(QString to_search, json_object *pObject, QString type) {
    int index = 0;
        index = Operational_parsing::interface->table->searchName(to_search.toLatin1().data());
    if(index==-1){
        Operational_parsing::interface->addLog("Error,variable no encontrada :D");
        return false;
    }
        if(!Operational_parsing::interface->table->item(index,0)->text().contains(type)){
        Operational_parsing::interface->addLog("Error,Los tipos no coinciden");
        return false;
    }
        if(Operational_parsing::interface->table->item(index,3)->text().toInt()>Counter_resolving::scope_level){
            Operational_parsing::interface->addLog("Niveles de scope diferentes,no se puede referenciar a la variable");

        }
    else{
        Json_creator::add_value(Operational_parsing::interface->table->item(index,2)->text().toLatin1().data(),pObject);
        return true;
    }
}