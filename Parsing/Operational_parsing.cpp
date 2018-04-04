//
// Created by kenneth on 30/03/18.
//

#include <json-c/json_object.h>
#include "Operational_parsing.h"
#include "exprtk.hpp"
#include "../GUI/Interfaz.h"
#include <iostream>

Interfaz* Operational_parsing::interface = nullptr;
json_object* Operational_parsing::object= nullptr;
bool Operational_parsing::parse(QString operation,const char* type,json_object* objeto) {
    if(type=="int"){
        return parse_int(operation,type);
    }
    if(type=="float"){
        return parse_floar(operation,type);
    }
    if(type=="double"){
        return parse_double(operation,type);
    }
    if(type=="long"){
        return parse_long(operation,type);

    }
}
bool Operational_parsing::parse_int(QString operation, const char *tipo) {
    QString string_to_parse ;
    operation=reconstruct_without_space(&operation);
    int index = 0;
    while(index<operation.length()){
        QString str;
        while((operation[index]!= '+'||'/'||'*'||'-'||'%')&&index<operation.length()){
            str.append(operation[index]);
            index++;
        }
        if(!contains_alphabet(str,tipo)){
            QString string_saica = get_var_value<int>(str, tipo);
            if(string_saica=="Error"){
                return false;
            }
            string_to_parse.append(string_saica);
        }
        else{
            string_to_parse.append(str);
        }
        string_to_parse.append(operation[index]);
        index++;
    }
    int result;
    trig_function_int<double >(&result,string_to_parse.toLatin1().data());

}
bool Operational_parsing::parse_floar(QString operation, const char *tipo) {

}
bool Operational_parsing::parse_long(QString operation, const char *tipo) {

}
bool Operational_parsing::parse_double(QString operation, const char *tipo) {}

bool Operational_parsing::contains_alphabet(QString str,const char* varType) {
    if (varType=="float"||varType=="double"){
        bool x;
        str.toDouble(&x);
        return x;
    }
    else{
        bool x;
        str.toLong(&x,10);
        return x;
    }

}
QString Operational_parsing::reconstruct_without_space(QString* str) {
    QString str2;
    int index=0;
    while(index<str->length()){
        if(str->operator[](index)!=' '){
            str2.append(str[index]);}
        index++;
    }
    return str2;

}
template <typename T>
QString Operational_parsing::get_var_value(QString variable, const char *string) {
    int index = 0;
    while(index<200){
        if((string) == interface->getCell(1, index)){
            break;
        }
        index++;
    }
    if (index==200){
        return "ERROR";
    }
    if(interface->getCell(0,index)=="int"||"double"||"long"||"float"){
        return interface->getCell(2,index);
    }
    else{

        return "ERROR";
    }


}
template <typename  T>
void Operational_parsing::trig_function_int(int *direction,char* strin) {
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;
    std::string expression_string = strin ;
    T x;
    symbol_table_t symbol_table;
    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);
    T y = expression.value();
    *direction=y;
}