//
// Created by kenneth on 29/03/18.
//
#include <iostream>
#include "Syntax_analysis.h"
#include "Json_creator.h"

bool Syntax_analysis::syntax_analysis(QString line) {
    if(line.contains(';')&& types_syntax(line)){
        return syntax_analysis_stage1(line);
    }
    else{
        return false;
    }
}
bool Syntax_analysis::syntax_analysis_stage1(QString line) {
    QString* parsed= new QString;
    int x = 0;
    int counter = 0;

    while(x<line.length()&&counter!=2){
        if(line.operator[](x)!=' '){
            counter++;
        }
        if(types_syntax(*parsed) && line[x+1]!=' '){
            std::cout<<"ERROR no se definio el tipo"<<std::endl;
            return false;
        }
        if(counter==1&&line[x]==' '){
            if(is_pointcomma_next(line,x)||is_equal_next(line,x)){
                std::cout<<"Error, no se ha definido nombre Variable"<<std::endl;
                return false;
            }
            else {
                if (types_syntax(*parsed)) {
                    Json_creator::add_type_value(parsed->toLatin1().data(), object);
                    return syntax_analysis_stage2(line, x);
                }
                else{
                    std::cout<<"Error, tipo inexistente"<<std::endl;
                    return false;
                }
            }

        }
        if(counter==1){
            parsed->append(line[x]);
        }
        x++;
    }
    return false;
}
/**
 * Hay que comprobar si existe o no existe la variable ya :v
 * @param line
 * @param i
 * @return
 */
bool Syntax_analysis::syntax_analysis_stage2(QString line, int i) {
    QString *parsed = new QString;
    int counter = 0;
    while (i < line.length()) {
        if (line[i] != ' ') {
            counter++;
        }
        if (counter == 1) {
            parsed->append(line[i]);

            if (is_equal_next(line, i + 1)) {
                if (types_equal(parsed)) {
                    std::cout << "ERROR,no se puede usar nombres de clases como variables" << std::endl;
                    return false;
                }
                Json_creator::add_value_name(parsed->toLatin1().data(), object);
                return syntax_analysis_stage3(line, i);

            }
            if (is_pointcomma_next(line, i + 1)) {
                if (types_equal(parsed)) {
                    std::cout << "ERROR,no se puede usar nombres de clases como variables" << std::endl;
                    return false;
                }
                Json_creator::add_value_name(parsed->toLatin1().data(), object);
                return true;
            }

        }
    }
    return false;
}

    bool Syntax_analysis::types_syntax(QString qString) {
        if (qString.contains("int") || qString.contains("bool") || qString.contains("char") ||
            qString.contains("double") || qString.contains("long") || qString.contains("float") ||
            qString.contains("struct")) {
            return true;
        } else {
            return false;
        }
    }
    bool Syntax_analysis::is_pointcomma_next(QString line, int last_index) {
        while (last_index < line.length()) {
            if (line[last_index] == ';') {
                return true;
            }
            if (line[last_index] != ';' && line[last_index] != ' ') {
                return false;
            }
            last_index++;
        }
        return false;
    }
    bool Syntax_analysis::is_equal_next(QString line, int lastindex) {
        while (lastindex < line.length()) {
            if (line[lastindex] == '=') {
                return true;
            }
            if (line[lastindex] != '=' && line[lastindex] != ' ') {
                return false;

            }
            lastindex++;;
        }
        return false;
    }

    bool Syntax_analysis::types_equal(QString *pString) {
        if (*pString == "int" || *pString == "char" || *pString == "bool" || *pString == "double" ||
            *pString == "long" || *pString == "float"
            || *pString == "struct" || *pString == "reference") {
            return true;
        } else {
            return false;
        }
    }

bool Syntax_analysis::syntax_analysis_stage3(QString line, int i) {
    while(i<line.length()&&line[i]!='='){
        i++;
    }
    if(i==line.length()){
        return false;
    }
    i++;
    while(i<line.length()){

    }
    return false;
}
