//
// Created by kenneth on 29/03/18.
//
#include <iostream>
#include "Syntax_analysis.h"
#include "Json_creator.h"
#include "Operational_parsing.h"

bool Syntax_analysis::syntax_analysis(QString line, int line_n) {
    this->actual_line=line_n;
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
        std::cout<<parsed->toLatin1().data()<<"\n"<<"line leng="<<line.length();
        if(line.operator[](x)!=' '&&counter==0){
            counter++;
        }
        if(types_syntax(*parsed) && line[x]!=' '){
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
    std::cout<<"LLegue al stage 2 \n";
    QString *parsed = new QString;
    int counter = 0;
    while (i < line.length()) {
        if (line[i] != ' '&& counter==0) {
            counter++;
        }
        if (counter == 1) {
            parsed->append(line[i]);
            std::cout << *parsed->toLatin1().data() << "\n";
            if (is_equal_next(line, i + 1)) {


                if (types_equal(parsed)) {
                    std::cout << "ERROR,no se puede usar nombres de clases como variables" << "\n";
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

        i++;
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
    if(line[i]==';'){
        return false;
    }
    if(i==line.length()){

        return false;
    }
    i++;
    int counter=0;
    QString* parsed = new QString();
    while(i<line.length()){
        if (line[i] != ' '&& counter==0) {
            counter++;
        }
        if(counter==1){
            parsed->append(line[i]);
            if(is_pointcomma_next(line,i+1)){
                std::cout<<parsed<<"\n";
                return syntax_analysis_stagefinal(*parsed);
            }
            if(is_equal_next(line,i+1)){
                std::cout<<"ERROR no se pueden poner dos iguales"<<std::endl;
                return false;
            }

        }
    i++;
    }
    return true;
}
bool Syntax_analysis::syntax_analysis_stagefinal(QString value) {
    if(contains_invalid_symbols(value)){
        return false;
    }
    if(contains_operational(value,json_object_to_json_string(json_object_object_get(object,"type")))){
        std::cout<<value.toLatin1().data()<<"HVFHHHHHHHHHHHHHH";
//
                return Operational_parsing::parse(value,json_object_to_json_string(json_object_object_get(object,"type")),this->object);
    }
    return true;
}
bool Syntax_analysis::contains_invalid_symbols(QString qString) {
    if(qString.contains(';')||qString.contains('"')||qString.contains('!')||qString.contains('@')||qString.contains('}')||
            qString.contains('{')||qString.contains('[')||qString.contains(']')||qString.contains('*')||
            qString.contains('~')||qString.contains('?')&&(json_object_to_json_string(json_object_object_get(object,"type"))!="char")){
        return false;
    }
    else{
        return false;
    }
}
bool Syntax_analysis::contains_operational(QString value,const char*  type) {

    if(value.contains('+')||value.contains('-')||value.contains('/')||value.contains('%')){
        if(type=="char"||type=="bool"||type=="reference"||type=="struct"){
            return false;
        }
        return true;
    }
    return false;
}