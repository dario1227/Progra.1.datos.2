//
// Created by kenneth on 05/04/18.
//

#ifndef PROGRA_1_DATOS_2_JSON_PARSER_H
#define PROGRA_1_DATOS_2_JSON_PARSER_H


#include <QtCore/QString>

class Json_parser {
public:
    static void create_json(char*);
    static QString* parse_chars(char*);
    static void add_table(QString *value,QString * type,QString * name,QString * ,QString * );
};


#endif //PROGRA_1_DATOS_2_JSON_PARSER_H
