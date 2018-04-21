#include <iostream>
#include <QApplication>
#include <thread>
#include "GUI/Interfaz.h"
#include "Parsing/exprtk.hpp"
#include "GUI/MyThread.h"
#include <unistd.h>
#include "GUI/ListaSimple.h"
#include "Client_Server/Client_Server.h"
#include "Parsing/Operational_parsing.h"
#include "QVector"
using namespace std;
Interfaz* GUI= new Interfaz();
template <typename T>
void trig_function()
{
    typedef exprtk::symbol_table<T> symbol_table_t;
    typedef exprtk::expression<T>     expression_t;
    typedef exprtk::parser<T>             parser_t;

    std::string expression_string = "1+2+3";

    T x;

    symbol_table_t symbol_table;
//    symbol_table.add_variable("x",x);
//    symbol_table.add_constants();

    expression_t expression;
    expression.register_symbol_table(symbol_table);

    parser_t parser;
    parser.compile(expression_string,expression);

    for (x = T(-5); x <= T(+5); x += T(0.001))
    {
        T y = expression.value();
        cout<<y<<"\n";
      //  printf("%19.15f\t%19.15f\n",x,y);
    }
}
int x=0;
void ex1(){
Client_Server server = Client_Server();
Operational_parsing::server = &server;
server.connect_Server();
}
void  ex2(){
    x+=5;
}
void ex3(){
    x+=6;
}
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    qRegisterMetaType<QTextCharFormat>("QTextCharFormat");
    qRegisterMetaType<QTextCursor>("QTextCursor");
  //  qRegisterMetaType<QVector>("QVector");
    GUI->Start();
    trig_function<double >();
  //  servidor.connect_Server();
    //Client_Server servidor = Client_Server();
    //servidor.connect_Server();
    MyThread* ejecutables=new MyThread();
   ejecutables->addT(ex1);
//    ejecutables->addT(ex2);
//    ejecutables->addT(ex3);
   ejecutables->startT();
//    usleep(2000);
    cout<<"//////////////////"<<x;
     QString str="34+34";
     bool x;
     str.toInt(&x,10);
     try {
         return app.exec();

     }catch (std::exception e){
         return 0;
     }}