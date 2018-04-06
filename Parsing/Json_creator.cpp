//
// Created by kenneth on 29/03/18.
//
#include <json-c/json.h>
#include "Json_creator.h"
void Json_creator::add_type_value(char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"type",toAdd);

}
void Json_creator::add_value( char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"value",toAdd);

}
void Json_creator::add_value_name(char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"name",toAdd);

}
