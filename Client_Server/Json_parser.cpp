//
// Created by kenneth on 05/04/18.
//

#include <json-c/json.h>
#include "Json_parser.h"
#include "../Parsing/Operational_parsing.h"
/**
 * Crea un json a partir de la variable
 * @param var
 */
void Json_parser::create_json(char * var) {
    std::cout<<var<<std::endl;
    json_object* objeto = json_tokener_parse(var);
    std::cout<<json_object_to_json_string(objeto)<<std::endl;
    QString* type = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"type")));
    QString* value = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    QString* name = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"name")));
    QString* scope = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"scope")));
    QString* pos = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"Position")));
    QString* ss = new QString("OLOL");
    add_table(value,type,name,scope,pos);


}
/**
 * anade valor a la tabla segun el json
 * @param value
 * @param type
 * @param name
 * @param scope
 * @param pos
 */
void Json_parser::add_table(QString * value,QString * type,QString * name,QString* scope,QString *pos) {
    int index = 0;
    while(index<200){
        if( Operational_parsing::interface->table->isEmpty(0,index)){
            break;
        }
        index++;
    }

//    while(Operational_parsing::interface->getCell(0,index)!= nullptr&&Operational_parsing::interface->getCell(0,index)!=" "&&Operational_parsing::interface->getCell(0,index)!=NULL){
//        index++;
//    }
    Operational_parsing::interface->table->add(index,0,*type);
    Operational_parsing::interface->table->add(index,1,*name);
    Operational_parsing::interface->table->add(index,2,*pos);
    Operational_parsing::interface->table->add(index,3,*scope);
    Operational_parsing::interface->table->add(index,4,*value);

}
QString* Json_parser::parse_chars(char * character) {
    QString* str = new QString();
    QString* string_to_return = new QString();
    str->append(character);
    int x =0;
    while(x<str->length()){
        if((*str)[x]!='"'){
            (*string_to_return).append((*str)[x]);
        }
        x++;
    }
    return string_to_return;
}