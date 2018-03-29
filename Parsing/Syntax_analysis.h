//
// Created by kenneth on 29/03/18.
//

#ifndef PROGRA_1_DATOS_2_SYNTAX_ANALYSIS_H
#define PROGRA_1_DATOS_2_SYNTAX_ANALYSIS_H


#include <QtCore/QString>
#include <json-c/json.h>
class Syntax_analysis {
public:
    json_object* object = json_object_new_object();

    bool syntax_analysis(QString line);

private:
    bool syntax_analysis_stage1(QString line);
    bool syntax_analysis_stage2(QString line, int i);
    bool syntax_analysis_stage3(QString line, int i);
    bool syntax_analysis_stagefinal(QString line);
    bool is_pointcomma_next(QString line,int last_index);
    bool is_equal_next(QString line,int lastindex);
    bool types_syntax(QString qString);

    bool types_equal(QString *pString);
};


#endif //PROGRA_1_DATOS_2_SYNTAX_ANALYSIS_H
