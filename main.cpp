#include <iostream>
#include <QApplication>
#include <thread>
#include "GUI/Interfaz.h"
#include "Parsing/exprtk.hpp"
using namespace std;
Interfaz* GUI;
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

int main(int argc, char **argv) {
    trig_function<double >();
    QApplication app(argc, argv);
     GUI= new Interfaz();
     QString str="34+34";
     bool x;
     str.toInt(&x,10);
     cout<<"ENCONTRE QUE FUE"<<x;
    GUI->Start();
    thread words(CodeEditor::findWords);
    cout<<GUI->getCell(0,0).toStdString();
    return app.exec();
}