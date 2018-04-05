#include <iostream>
#include <QApplication>
#include <thread>
#include <zconf.h>
#include "GUI/Interfaz.h"
#include "Parsing/exprtk.hpp"
#define SPACEBAR 32;
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

void* findWords(void*) {
    qRegisterMetaType<QTextCharFormat>("QTextCharFormat");
    qRegisterMetaType<QTextCursor>("QTextCursor");
    QTextCursor *highlightCursor ;
    QTextCursor *cursor;
    QTextCharFormat *plainFormat;
    QTextCharFormat *colorFormat;
    QString * searched= new QString("hola");
    while (true) {
        usleep(10000);
        highlightCursor =new QTextCursor(GUI->editor->document());
        cursor=new QTextCursor(GUI->editor->document());
        plainFormat= new QTextCharFormat(highlightCursor->charFormat());
        colorFormat = plainFormat;
        cursor->beginEditBlock();
        colorFormat->setForeground(Qt::red);
        while (!highlightCursor->isNull() && !highlightCursor->atEnd()) {
            *highlightCursor = GUI->editor->document()->find(*searched, *highlightCursor, QTextDocument::FindWholeWords);
            if (!highlightCursor->isNull()) {
                highlightCursor->movePosition(QTextCursor::WordRight,
                                             QTextCursor::KeepAnchor);
                highlightCursor->mergeCharFormat(*colorFormat);
            }
        }
        cursor->endEditBlock();

    }
}
int main(int argc, char **argv) {
    QApplication app(argc, argv);
    qRegisterMetaType<QTextCharFormat>("QTextCharFormat");
    qRegisterMetaType<QTextCursor>("QTextCursor");
    GUI->Start();
    trig_function<double >();
     QString str="34+34";
     bool x;
     str.toInt(&x,10);
     cout<<"ENCONTRE QUE FUE"<<x;
    pthread_t t1;
    pthread_create(&t1, NULL, &findWords, NULL);
    cout<<GUI->getCell(0,0).toStdString();
    return app.exec();
}