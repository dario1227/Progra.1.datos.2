//
// Created by kenneth on 12/04/18.
//

#include "parentesis_tester.h"
#include <unistd.h>
#include "Operational_parsing.h"

bool parentesis_tester::analize() {
    int cuantity_lines = Operational_parsing::interface->getLines();
    return counter(cuantity_lines);
}
bool parentesis_tester::counter(int num_lines) {
    int current_line=0;
    bool not_error = true;
    int corchete_frontal = 0;
    int corchete_back = 0;
    while(current_line!=num_lines){
        int comilla_counter = 0;
        int parentesis_counter_foward = 0;
        int parentesis_counter_backward = 0;

        QString string = Operational_parsing::interface->getLine(current_line);
        int counter2 = 0;
        while(counter2<string.length()){
            if(string[counter2]==')'){
                parentesis_counter_backward++;
            }
            if(string[counter2]=='('){
                parentesis_counter_foward++;
            }
            if(string[counter2]=='"'){
                comilla_counter++;
            }
            if(string[counter2]=='}'){
                corchete_back++;
            }
            if(string[counter2]=='{'){
                corchete_frontal++;
            }
            if(parentesis_counter_backward>parentesis_counter_foward){
                usleep(100);
                not_error=false;
                Operational_parsing::interface->addLog("Error, se coloco un ) sin que le antesediera un( linea : "+(char)current_line);
            }
            if(corchete_back>corchete_frontal){
                usleep(100);
                not_error=false;
                Operational_parsing::interface->addLog("Error, se coloco un } sin que le antesediera un { linea : "+(char)current_line);
            }
            counter2++;
        }
        if(comilla_counter!=2&&comilla_counter!=0){
            usleep(100);
            not_error=false;
             Operational_parsing::interface->addLog("Error, se esperan  2 comillas en una sola linea : "+(char)current_line);
        }
        if(parentesis_counter_backward!=parentesis_counter_foward){
            usleep(100);
            not_error=false;

            Operational_parsing::interface->addLog("Error, deben de haber la misma cantidad de ( y ) en una linea : "+(char)current_line);
        }
        current_line++;

    }
    if(corchete_back!=corchete_frontal){
        usleep(100);
        not_error=false;
        Operational_parsing::interface->addLog("Error,se debe de tener la misma cantidad de } y { en un solo codigo");

    }
    return not_error;
}