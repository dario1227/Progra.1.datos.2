//
// Created by kenneth on 20/04/18.
//

#include "parseo_struct.h"
#include "Json_creator.h"
#include "Syntax_analysis.h"
#include "Operational_parsing.h"
#include "reference_parsing.h"
bool parseo_struct::parse_var(QString line, StructP *pP, json_object *object) {
        std::cout<<"EN EL ESTAGE!1111111111111111111111111"<<std::endl;

        Syntax_analysis var = Syntax_analysis();
        Json_creator::add_peso((char*)std::to_string((*pP).bytes).c_str(),object);
        QString *parsed = new QString;
        int counter = 0;
        int i = 0;
        while(line[i]!=' '){
                i++;
        }
        while (i < line.length()) {
                if (line[i] != ' '&& counter==0) {
                        counter++;
                }
                if (counter == 1) {
                        parsed->append(line[i]);
                        std::cout << *parsed->toLatin1().data() << "\n";
                        if (var.is_equal_next(line, i + 1)) {


                                if (var.types_equal(parsed)) {

                                        Operational_parsing::interface->addLog(
                                                "ERROR,no se puede usar nombres de clases como variables");
                                        object= nullptr;
                                        return false;
                                }
                                if(Operational_parsing::interface->table->searchName(parsed->toLatin1().data())!=-1){
                                        Operational_parsing::interface->addLog("ERROR no se pueden definir nombres ya existentes");
                                        return false;
                                }
                                Json_creator::add_value_name(parsed->toLatin1().data(), object);
//________________________________________________________________________________________________________________________-;
                                return analisis_stage2(line, i,object,pP);

                        }
                        if (var.is_pointcomma_next(line, i + 1)) {
                                if (var.types_equal(parsed)) {
                                        std::cout << "ERROR,no se puede usar nombres de clases como variables" << std::endl;
                                        object= nullptr;
                                        return false;
                                }
                                if(object!= nullptr) {
                                        if(Operational_parsing::interface->table->searchName(parsed->toLatin1().data())!=-1){
                                                Operational_parsing::interface->addLog("ERROR no se pueden definir nombres ya existentes");
                                                return false;
                                        }
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

bool parseo_struct::analisis_stage2(QString line, int i, json_object *object, StructP *pP) {
        std::cout<<"EN EL ESTAGE 2222222"<<std::endl;

        Syntax_analysis var = Syntax_analysis();
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
                        if(var.is_pointcomma_next(line,i+1)){
                                std::cout<<parsed<<"\n";
                                return final_analisys(parsed, object, pP);
                        }
                        if(var.is_equal_next(line,i+1)){
                                Operational_parsing::interface->addLog("ERROR no se pueden poner dos iguales");


                                return false;
                        }

                }
                i++;
        }
        return true;
}

bool parseo_struct::final_analisys(QString *pString, json_object *pObject, StructP *pP) {
        Syntax_analysis var = Syntax_analysis();
        QString type = QString((char*)json_object_to_json_string(json_object_object_get(pObject,"value")));
        QString variable = var.search_value(*pString);
        if(variable.contains("error",Qt::CaseInsensitive)){
                Operational_parsing::interface->addLog("ERROR no se encontro la variable");
                return false;
        }
        else{
                if(type.contains(QString(pP->nombre.c_str()))){
                        return true;
                }
                else{
                        Operational_parsing::interface->addLog("Type dismatch");
                        return false;

                }
        }
}

