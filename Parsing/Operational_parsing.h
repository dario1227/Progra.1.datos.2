//
// Created by kenneth on 30/03/18.
//

#ifndef PROGRA_1_DATOS_2_OPERATIONAL_PARSING_H
#define PROGRA_1_DATOS_2_OPERATIONAL_PARSING_H


#include <QtCore/QString>
#include "../GUI/RAM.h"

class Operational_parsing {
public:
    static RAM* table_values;
    static json_object* object;
    static bool parse(QString operation,const char* tipo,json_object*);
private:

    static bool parse_int(QString operation,const char* tipo);
    static bool parse_long(QString operation,const char* tipo);
    static bool parse_double(QString operation,const char* tipo);
    static bool parse_floar(QString operation,const char* tipo);
    static QString get_type(int line);
    static int get_var_pos(char* var);
    static QString get_value_toSume(int line);
    static int is_operational_next(int i,QString str);
    static bool contains_alphabet(QString str,char* type);
    static int convert_to_int(QString str);
    static long convert_to_long(QString str);
    static double convert_to_double(QString str);
    static float convert_to_float(QString str);
    static int get_From_table(QString* str);
    static QString reconstruct_without_space(QString* str);

};


#endif //PROGRA_1_DATOS_2_OPERATIONAL_PARSING_H
