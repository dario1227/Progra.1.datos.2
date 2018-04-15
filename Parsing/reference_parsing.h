//
// Created by kenneth on 12/04/18.
//

#ifndef PROGRA_1_DATOS_2_REFERENCE_PARSING_H
#define PROGRA_1_DATOS_2_REFERENCE_PARSING_H


#include <QtCore/QString>
#include <json-c/json_object.h>

class reference_parsing {
public:

    static bool parse_reference(QString qString, json_object *pObject);
    static QString* value_getter(QString var);
    static bool is_equals_next(QString lol , int index);
    static bool is_pointcomma_next(QString str,int index);
    static bool its_type(QString str);
    static bool parse_reference_stage2(QString qString,json_object* pObject,QString type);
    static bool already_exists(QString name);
};


#endif //PROGRA_1_DATOS_2_REFERENCE_PARSING_H
