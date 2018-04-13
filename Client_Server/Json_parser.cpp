//
// Created by kenneth on 05/04/18.
//

#include <json-c/json.h>
#include "Json_parser.h"
#include "../Parsing/Operational_parsing.h"

void Json_parser::create_json(char * var) {
    json_object* objeto = json_tokener_parse(var);

    QString* type = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"type")));
    QString* value = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"value")));
    QString* name = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"name")));
    QString* scope = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"scope")));
    QString* pos = parse_chars((char*)json_object_to_json_string(json_object_object_get(objeto,"position")));


}
void Json_parser::add_table(QString * value,QString * type,QString * name,QString* scope,QString *pos) {
    int index = 0;
    while(Operational_parsing::interface->getCell(0,index)!= nullptr&&" "){
        index++;
    }
    Operational_parsing::interface->table->add(0,index,*value);
    Operational_parsing::interface->table->add(1,index,*type);
    Operational_parsing::interface->table->add(2,index,*name);
    Operational_parsing::interface->table->add(3,index,*name);
    Operational_parsing::interface->table->add(4,index,*name);

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