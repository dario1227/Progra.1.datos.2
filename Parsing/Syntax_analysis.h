//
// Created by kenneth on 29/03/18.
//

#ifndef PROGRA_1_DATOS_2_SYNTAX_ANALYSIS_H
#define PROGRA_1_DATOS_2_SYNTAX_ANALYSIS_H


#include <QtCore/QString>
#include <json-c/json.h>
class Syntax_analysis {
public:
    int actual_line = 0;
    int scope_level=0;
    int howmanyScopes = 0;
    QString  string=QString("ABCDEFGHIJKLMNOPQRSTUVWXYZ") ;
    json_object* object = json_object_new_object();

    bool syntax_analysis(QString line, int n_line);


    bool syntax_analysis_stage1(QString line);
    bool syntax_analysis_stage2(QString line, int i);
    bool syntax_analysis_stage3(QString line, int i);
    bool syntax_analysis_stagefinal(QString line);
    bool is_pointcomma_next(QString line,int last_index);
    bool is_equal_next(QString line,int lastindex);
    bool types_syntax(QString qString);
    bool contains_invalid_symbols(QString qString);
    bool types_equal(QString *pString);
    bool contains_operational(QString value,const char* type);
    bool comprobate_char(QString value, json_object* objeto);
    bool comprobate_number(QString value, json_object* objeto);
    bool comprobate_struct(QString value, json_object* objeto);
    bool comprobate_var(QString value , json_object* objeto);
    QString search_value(QString nombre);
    void parse_print(QString qString);

    void analize_to_print(QString qString);

    QString *reconstruct_without_space(QString str);

    bool parse_get_value(QString qString, QString type);

    bool parse_bool(QString qString);

    bool parse_int(QString qString);

    bool parsechar(QString qString);

    bool parse_float(QString qString);

    bool parse_double(QString qString);

    bool parse_long(QString qString);
};


#endif //PROGRA_1_DATOS_2_SYNTAX_ANALYSIS_H
