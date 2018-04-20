//
// Created by kenneth on 29/03/18.
//
#include <iostream>
#include "Syntax_analysis.h"
#include "Json_creator.h"
#include "Operational_parsing.h"
#include "parentesis_tester.h"
#include "reference_parsing.h"
/**
 * Inicia los parametros iniciales
 * @param line
 * @param line_n
 * @return
 */
bool Syntax_analysis::syntax_analysis(QString line, int line_n) {

    if(parentesis_tester::analize()== false){
        return false;
    }
    if(line=="{"){
        object= nullptr;
        howmanyScopes++;
        scope_level++;
        return true;
    }
    this->actual_line=line_n;
    if(line=="{"){
        object= nullptr;
        scope_level++;
        return true ;
    }
    if(line=="}"){
        object= nullptr;

        scope_level--;
        return true;

    }
    if(line.contains(';')&& types_syntax(line)){
        Json_creator::add_scope_level((char*)std::to_string(scope_level).c_str(),object);
        return syntax_analysis_stage1(line);
    }
    else{
        object= nullptr;

        return false;
    }
}
/**
 * Analiza los tipos de la variable
 * @param line
 * @return
 */
bool Syntax_analysis::syntax_analysis_stage1(QString line) {
    QString* parsed= new QString;
    int x = 0;
    int counter = 0;

    while(x<line.length()&&counter!=2){
        std::cout<<parsed->toLatin1().data()<<"\n"<<"line leng="<<line.length()<<std::endl;
        if(line.operator[](x)!=' '&&counter==0){
            counter++;
        }
        if(types_syntax(*parsed) && line[x]!=' '){
            if(parsed->contains("print")){
                return syntax_analysis_stage2(line, x);

            }
            if(parsed->contains("reference")){
                return reference_parsing::parse_reference(line,this->object);
            }
            if(parsed->contains("getAddr")){
                syntax_analysis_stage2(line,x);
            }
            std::cout<<"ME SALIO ESTO"<<line[x].toLatin1()<<std::endl;
            std::cout<<"me salio esto en la linea"<<parsed->toLatin1().data()<<std::endl;
            std::cout<<"ERROR no se definio el tipo"<<std::endl;
            return false;
        }
        if(counter==1&&(line[x]==' '||(line[x]=='('&&line.contains("printf")))){


            if(is_pointcomma_next(line,x)||is_equal_next(line,x)){
                Operational_parsing::interface->addLog("ERROR se espera un nombre de variable despues del tipo :D");
                object= nullptr;

                return false;
            }
            else {
                if (types_syntax(*parsed)) {
                    Json_creator::add_type_value(parsed->toLatin1().data(), object);
                    return syntax_analysis_stage2(line, x);
                }
                else{
                    std::cout<<"Error, tipo inexistente"<<std::endl;
                    object= nullptr;

                    return false;
                }
            }

        }
        if(counter==1){
            parsed->append(line[x]);
        }
        x++;
    }
    object= nullptr;

    return false;
}
/**
 * Hay que comprobar si existe o no existe la variable ya :v
 * @param line
 * @param i
 * @return
 */
bool Syntax_analysis::syntax_analysis_stage2(QString line, int i) {
    std::cout<<"LLegue al stage 2 \n"<<std::endl;
    QString *parsed = new QString;
    int counter = 0;
    if(line.contains("printf")){
        parse_print(line);
    }
    if(line.contains("getAddr")){
        reference_parsing::parse_reference(line, object);
    }
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
                    object= nullptr;
                    return false;
                }
                Json_creator::add_value_name(parsed->toLatin1().data(), object);
                return syntax_analysis_stage3(line, i);

            }
            if (is_pointcomma_next(line, i + 1)) {
                if (types_equal(parsed)) {
                    std::cout << "ERROR,no se puede usar nombres de clases como variables" << std::endl;
                    object= nullptr;
                    return false;
                }
                if(object!= nullptr) {
                    Json_creator::add_value_name(parsed->toLatin1().data(), object);
                }
                return true;
            }

        }

        i++;
    }
    object= nullptr;

    return false;
}
/**
 * analiza si el tipo entra en estos
 * @param qString
 * @return
 */
    bool Syntax_analysis::types_syntax(QString qString) {
        if ((qString.contains("int")&&!qString.contains("print")) || qString.contains("bool") || qString.contains("char") ||
            qString.contains("double") || qString.contains("long") || qString.contains("float") ||
            qString.contains("struct")||qString.contains("printf")||qString.contains("getAddr")||qString.contains("reference")) {
            return true;
        } else {
            return false;
        }
    }
    /**
     * analiza si existe el punto y coma despues
     * @param line
     * @param last_index
     * @return
     */
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
    /**
     * Analiza si es el igual despues
     * @param line
     * @param lastindex
     * @return
     */
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
/**
 * Analiza si el tipo es igual
 * @param pString
 * @return
 */
    bool Syntax_analysis::types_equal(QString *pString) {
        if (*pString == "int" || *pString == "char" || *pString == "bool" || *pString == "double" ||
            *pString == "long" || *pString == "float"
            || *pString == "struct" || *pString == "reference") {
            return true;
        } else {
            return false;
        }
    }
/**
 * Etapa 3. evalue si ya existe la variable
 * @param line
 * @param i
 * @return
 */
bool Syntax_analysis::syntax_analysis_stage3(QString line, int i) {
    while(i<line.length()&&line[i]!='='){
        i++;
    }
    if(line[i]==';'){
        object= nullptr;
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
/**
 * Etapa final
 * @param value
 * @return
 */
bool Syntax_analysis::syntax_analysis_stagefinal(QString value) {
    if(contains_invalid_symbols(value)){
        return false;
    }
    if(contains_operational(value,json_object_to_json_string(json_object_object_get(object,"type")))){
        std::cout<<value.toLatin1().data()<<"HVFHHHHHHHHHHHHHH";
//
                return Operational_parsing::parse(value,json_object_to_json_string(json_object_object_get(object,"type")),this->object);
    }
    Json_creator::add_value(value.toLatin1().data(),this->object);
    return true;
}
/**
 * revisa si una variable contiene signos prohibidos
 * @param qString
 * @return
 */
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
/**
 * revisa si contiene un operacional
 * @param value
 * @param type
 * @return
 */
bool Syntax_analysis::contains_operational(QString value,const char*  type) {

    if(value.contains('+')||value.contains('-')||value.contains('/')||value.contains('%')||value.contains('*')){
        if(type=="char"||type=="bool"||type=="reference"||type=="struct"){
            return false;
        }
        return true;
    }
    return false;
}
/**
 * parseo de los print
 * @param qString
 */
void Syntax_analysis::parse_print(QString qString) {
    std::cout<<"LA LEYRAS QUE ME ENTRAN ES"<<qString.toLatin1().data()<<std::endl;

    int counter = 0;
    int index = 0;
    int comilla_counter = 0;
    QString string_to_add = QString();
    if(qString[qString.length()-1]!=';' || qString[qString.length()-2]!=')'){
         std::cout<<"ERROR SAICO";
        return;

    }
    while(index<qString.length()){
       // std::cout<<"El counter es"+counter<<std::endl;
       // std::cout<<"LA LETRA ES:"+qString[index].toLatin1()<<endl;
        if(qString[index]=='(' || qString[index]==')'||qString[index]==';'){
            std::cout<<qString[index].toLatin1()<<std::endl;
            counter++;
        }
        if((counter==1||2)&&qString[index]!='('&&qString[index]!=')'&&qString[index]!=';'&&index>5){
            string_to_add.append(qString[index]);
        }
        if(counter==3){

            analize_to_print(string_to_add);
            return;;
        }

        index++;
    }
    if(index==qString.length()){

        Operational_parsing::interface->addToShell("Error de syntaxis"+std::to_string(actual_line));
        return;
    }
    analize_to_print(string_to_add);
    return;

}
/**
 * Analiza lo que tiene un pint en el interior
 * @param qString
 */
void Syntax_analysis::analize_to_print(QString qString) {
    this->object= nullptr;

    QString str = QString();
    int counter = 0;
    int comilla_counter = 0;
    while(counter<qString.length()){
        if(qString[counter]=='"'){
            comilla_counter++;
            if(comilla_counter==2){
                counter++;
                break;
            }
        }
        if(qString[counter]!='"'){
            str.append(qString[counter]);
        }
        counter++;

    }
    if(comilla_counter==1){
        std::cout<<"ERROR no se puede usar comillas dentro de strings ";
    }
    if(comilla_counter==2){
        std::cout<<"LLEGUE HASTA AQUI"<<std::endl;
        Operational_parsing::interface->addToShell(str.toLatin1().data());
        return;
    }
    if(comilla_counter==0){
        std::cout<<"LOLOL entreaqui"<<std::endl;
        Operational_parsing::interface->addToShell(search_value(str).toLatin1().data());
        return;

    }
    else{
        Operational_parsing::interface->addLog("ERROR no se deben anadir comillas dentro de un string" + std::to_string(actual_line));
    }

}
//____________________________________________________________________________________________________________________________________________
/**
 * busca el valor de una variable
 * @param nombre
 * @return
 */
QString Syntax_analysis::search_value(QString nombre) {
    int index = Operational_parsing::interface->table->searchName(nombre.toLatin1().data());
    char* var = nombre.toLatin1().data();

    if (index==200){
        return QString ("ERROR");
    }
    if(index==-1){
        return QString("ERROR");
    }
    else{
        std::cout<<Operational_parsing::interface->getCell(1,0).toLatin1().data()<<"HASJGFGFJSGFJ"<<std::endl;
        return Operational_parsing::interface->table->item(index,4)->text();
    }

}