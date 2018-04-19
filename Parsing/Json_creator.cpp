//
// Created by kenneth on 29/03/18.
//
#include <json-c/json.h>
#include <QtCore/QString>
#include "Json_creator.h"
/**
 * anade el tipo a un json
 * @param value
 * @param objeto
 */
void Json_creator::add_type_value(char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"type",toAdd);

}
/**
 * anade el valor a un jsoj
 * @param value
 * @param objeto
 */
void Json_creator::add_value( char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"value",toAdd);

}
/**
 * anade el nombre a un json
 * @param value
 * @param objeto
 */
void Json_creator::add_value_name(char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"name",toAdd);

}
/**
 * anade un nivel de scope a un valor
 * @param value
 * @param objeto
 */
void Json_creator::add_scope_level(char *value, json_object *objeto) {
    json_object* toAdd = json_object_new_string(value);
    json_object_object_add(objeto,"scope",toAdd);
}