//
// Created by kenneth on 29/03/18.
//

#ifndef PROGRA_1_DATOS_2_JSON_CREATOR_H
#define PROGRA_1_DATOS_2_JSON_CREATOR_H


class Json_creator {
public:
    static void add_type_value(char* value,json_object* objeto);
    static void add_value( char* value,json_object* objeto);
    static void add_value_name(char* value,json_object* objeto);
    static void add_scope_level(char* value,json_object* objeto);
};


#endif //PROGRA_1_DATOS_2_JSON_CREATOR_H
