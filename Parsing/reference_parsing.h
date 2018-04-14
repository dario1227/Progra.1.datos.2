//
// Created by kenneth on 12/04/18.
//

#ifndef PROGRA_1_DATOS_2_REFERENCE_PARSING_H
#define PROGRA_1_DATOS_2_REFERENCE_PARSING_H


#include <QtCore/QString>
#include <json-c/json_object.h>

class reference_parsing {
public:

    static void parse_reference(QString qString, json_object *pObject);
    static QString* value_getter(QString var);
};


#endif //PROGRA_1_DATOS_2_REFERENCE_PARSING_H
