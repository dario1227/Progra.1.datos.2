//
// Created by kenneth on 20/04/18.
//

#ifndef PROGRA_1_DATOS_2_PARSEO_STRUCT_H
#define PROGRA_1_DATOS_2_PARSEO_STRUCT_H


#include <QtCore/QString>
#include <json-c/json_object.h>
#include "../GUI/StructP.h"

class parseo_struct {
public:
    static bool parse_var(QString qString, StructP *pP, json_object *pObject);

    static bool analisis_stage2(QString qString, int i, json_object *pObject, StructP *pP);

    static bool final_analisys(QString *pString, json_object *pObject, StructP *pP);
};


#endif //PROGRA_1_DATOS_2_PARSEO_STRUCT_H
