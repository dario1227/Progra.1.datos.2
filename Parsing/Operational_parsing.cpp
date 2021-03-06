//
// Created by kenneth on 30/03/18.
//

#include <json-c/json_object.h>
#include "Operational_parsing.h"
#include "exprtk.hpp"
#include "../GUI/Interfaz.h"
#include "Json_creator.h"
#include "../Client_Server/Client_Server.h"
#include "Counter_resolving.h"
#include <iostream>

Interfaz* Operational_parsing::interface = nullptr;
json_object* Operational_parsing::object= nullptr;
Client_Server* Operational_parsing::server = nullptr;
/**
 * Inicia el parseo de una operacion con ints
 * @param operation
 * @param type
 * @param objeto
 * @return
 */
bool Operational_parsing::parse(QString operation,const char* type,json_object* objeto) {
    object=objeto;
    QString tipo = type;
    if(tipo.contains("int")){
        std::cout<<operation.toLatin1().data()<<"ELVSJFKJHKAJSBFSKLJJG";

        return parse_int(operation,type);
    }
    if(tipo.contains("float")){
        return parse_floar(operation,type);
    }
    if(tipo.contains("double")){
        return parse_double(operation,type);
    }
    if(tipo.contains("long")){
        return parse_long(operation,type);

    }
}
/**
 * Inicia la operacion del parseo de un int
 * @param operation
 * @param tipo
 * @return
 */
bool Operational_parsing::parse_int(QString operation, const char *tipo) {
    QString string_to_parse ;
    operation=*reconstruct_without_space(operation);
    int index = 0;
    int len = operation.length();
    while(index<operation.length()){
        QString *str = new QString();
        while((operation[index]!= '+'&&operation[index]!='/'&&operation[index]!='*'&&operation[index]!='-'&&operation[index]!='%')&&index<operation.length()){
            str->append(operation[index]);
            index++;
        }
        std::cout<<str->toLatin1().data()<<"ESTO FUE \n"<<std::endl;
        if(!contains_alphabet(*str,tipo)){
            QString string_saica = get_var_value<int>(*str, tipo);
            if(string_saica.contains("error",Qt::CaseInsensitive)){
                Operational_parsing::interface->addLog("Error,typos incopatibles o nivel de scope indecuado");

                return false;
            }
            string_to_parse.append(string_saica);
        }
        else{
            string_to_parse.append(*str);
        }
        string_to_parse.append(operation[index]);
        index++;

    }
    int result;
    trig_function_int<double >(&result,string_to_parse.toLatin1().data());
    std::string s=std::to_string(result);
    Json_creator::add_value((char*)s.c_str(),object);
    std::cout<<"RESULTADO FUE"<<result<<'\n'<<std::endl;

}
/**
 * Inicia el parseo de un Float
 * @param operation
 * @param tipo
 * @return
 */
bool Operational_parsing::parse_floar(QString operation, const char *tipo) {
    QString string_to_parse ;
    operation=*reconstruct_without_space(operation);
    int index = 0;
    int len = operation.length();
    while(index<operation.length()){
        QString *str = new QString();
        while((operation[index]!= '+'&&operation[index]!='/'&&operation[index]!='*'&&operation[index]!='-'&&operation[index]!='%')&&index<operation.length()){
            str->append(operation[index]);
            index++;
        }
        std::cout<<str->toLatin1().data()<<"ESTO FUE \n"<<std::endl;
        if(!contains_alphabet(*str,tipo)){
            QString string_saica = get_var_value<int>(*str, tipo);
            if(string_saica.contains("Error",Qt::CaseInsensitive)){
                Operational_parsing::interface->addLog("Error,typos incopatibles o nivel de scope indecuado");

                return false;
            }
            string_to_parse.append(string_saica);
        }
        else{
            string_to_parse.append(*str);
        }
        string_to_parse.append(operation[index]);
        index++;

    }
    float result;
    trig_function_float<double >(&result,string_to_parse.toLatin1().data());
    std::string s=std::to_string(result);
    Json_creator::add_value((char*)s.c_str(),object);
    std::cout<<"RESULTADO FUE"<<result;
}
/**
 * inicia el parseo de un long
 * @param operation
 * @param tipo
 * @return
 */
bool Operational_parsing::parse_long(QString operation, const char *tipo) {
    QString string_to_parse ;
    operation=*reconstruct_without_space(operation);
    int index = 0;
    int len = operation.length();
    while(index<operation.length()){
        QString *str = new QString();
        while((operation[index]!= '+'&&operation[index]!='/'&&operation[index]!='*'&&operation[index]!='-'&&operation[index]!='%')&&index<operation.length()){
            str->append(operation[index]);
            index++;
        }
        std::cout<<str->toLatin1().data()<<"ESTO FUE \n"<<std::endl;
        if(!contains_alphabet(*str,tipo)){
            QString string_saica = get_var_value<int>(*str, tipo);
            if(string_saica.contains("Error",Qt::CaseInsensitive)){
                Operational_parsing::interface->addLog("Error,typos incopatibles o nivel de scope indecuado");

                return false;
            }
            string_to_parse.append(string_saica);
        }
        else{
            string_to_parse.append(*str);
        }
        string_to_parse.append(operation[index]);
        index++;

    }
    long result;
    trig_function_long<double >(&result,string_to_parse.toLatin1().data());
    std::string s=std::to_string(result);
    Json_creator::add_value((char*)s.c_str(),object);
    std::cout<<"RESULTADO FUE"<<result;
}
bool Operational_parsing::parse_double(QString operation, const char *tipo) {
    QString string_to_parse ;
    operation=*reconstruct_without_space(operation);
    int index = 0;
    int len = operation.length();
    while(index<operation.length()){
        QString *str = new QString();
        while((operation[index]!= '+'&&operation[index]!='/'&&operation[index]!='*'&&operation[index]!='-'&&operation[index]!='%')&&index<operation.length()){
            str->append(operation[index]);
            index++;
        }
        if(!contains_alphabet(*str,tipo)){
            QString string_saica = get_var_value<int>(*str, tipo);
            std::cout<<string_saica.toLatin1().data()<<"ESTO FUE El Valor \n"<<std::endl;

            std::cout<<"QUE ME ESTA DANDO"<<string_saica.toLatin1().data()<<std::endl;
            if(string_saica.contains("Error",Qt::CaseInsensitive)){
                Operational_parsing::interface->addLog("Error,typos incopatibles o nivel de scope indecuado");
                return false;
            }
            string_to_parse.append(string_saica);
        }
        else{
            string_to_parse.append(*str);
        }
        string_to_parse.append(operation[index]);
        index++;

    }
    double result;
    trig_function_double<double >(&result,string_to_parse.toLatin1().data());
    std::string s=std::to_string(result);
    Json_creator::add_value((char*)s.c_str(),object);
    std::cout<<"RESULTADO FUE"<<result;
}
/**
 * Verificacion de que si es un numero ovariable
 * @param str
 * @param varType
 * @return
 */
bool Operational_parsing::contains_alphabet(QString str,const char* varType) {
    std::cout<<str.toLatin1().data()<<"ese fue el valor"<<std::endl;
    QString string = varType;
    if (string.contains("float")||string.contains("double")){
        bool x;
        str.toDouble(&x);
        std::cout<<"EL BOOL FUE"<<x;
        return x;
    }
    else{
        bool x;
        str.toLong(&x,10);
        std::cout<<"EL BOOL FUE"<<x;
        return x;
    }

}
/**
 * Reconstruye un int sin espacios
 * @param str
 * @return
 */
QString * Operational_parsing::reconstruct_without_space(QString str) {
    QString* str2 = new QString();
    int index=0;
    while(index<str.length()){
        if(str[(index)]!=' '){
            str2->append(str[index]);}
        index++;
    }
    return str2;

}
/**
 * Optiene el valor de una variable
 * @tparam T
 * @param variable
 * @param string
 * @return
 */
template <typename T>
QString Operational_parsing::get_var_value(QString variable, const char *string) {
    int index = 0;
    index =interface->table->searchName(variable.toLatin1().data());
    if(index==-1){
        return "ERROR";
    }
    if (index==200){
        return "ERROR";
    }
    if(interface->table->item(index,3)->text().toInt()>Counter_resolving::scope_level){
        return "ERROR";
    }
    if(interface->table->item(index,0)->text()=="int"||interface->table->item(index,0)->text()=="double"||interface->table->item(index,0)->text()=="long"||interface->table->item(index,0)->text()=="float"){

        return interface->table->item(index,4)->text();
    }
    else{

        return "ERROR";
    }


}
/**
 *
 * @tparam T
 * @param direction
 * @param strin
 */
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
template <typename  T>
/**
 * Operacion con una variable double
 * @tparam T
 * @param direction
 * @param str
 */
void Operational_parsing::trig_function_double(double *direction, char *str) {
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;
    std::string expression_string = str ;
    T x;
    symbol_table_t symbol_table;
    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);
    T y = expression.value();
    *direction=y;
}
template <typename  T>
/**
 * Operacion con float
 * @tparam T
 * @param direction
 * @param str
 */
void Operational_parsing::trig_function_float(float *direction, char *str) {
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;
    std::string expression_string = str ;
    T x;
    symbol_table_t symbol_table;
    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);
    T y = expression.value();
    *direction=y;
}
template <typename  T>
/**
 * Parseo operacion long
 * @tparam T
 * @param direction
 * @param str
 */
void Operational_parsing::trig_function_long(long *direction, char *str) {
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;
    std::string expression_string = str ;
    T x;
    symbol_table_t symbol_table;
    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);
    T y = expression.value();
    *direction=y;
}
/**
 * Convierte a solo chars
 * @param type
 * @return
 */
 char *Operational_parsing::convert_to_only_char(const char *type) {
    char* caracter= new char[sizeof((*reconstruct_without_space( QString(type))).toLatin1().data())-2];
    int i = 0;
    int contador = 0;
    int contador2 =0;
    while(i< sizeof(type)){
        if(type[i]=='"'){
            if(contador2==1){
                return caracter;
            }
            contador2++;
        }
        std::cout<<type[i]<<"\n";
        if(type[i]!='"'&&' '){
            caracter[contador]=type[i];
            contador++;
        }
        i++;
    }
}
