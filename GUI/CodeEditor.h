//
// Created by dario1227 on 26/03/18.
//

#ifndef PROGRA_1_DATOS_2_CODEEDITOR_H
#define PROGRA_1_DATOS_2_CODEEDITOR_H


#include <QPlainTextEdit>
#include <QObject>
#include <QtWidgets/QLineEdit>
class QPaintEvent;
class QResizeEvent;
class QSize;
class QWidget;

class LineNumberArea;
//Clase del editor de codigo, recibe el padre como parametro

class CodeEditor : public QPlainTextEdit {
    Q_OBJECT
public:
    CodeEditor(QWidget *parent = 0);
    void lineNumberAreaPaintEvent(QPaintEvent *event);
    int lineNumberAreaWidth();

protected:
    void resizeEvent(QResizeEvent *event) override;

public slots:
    void updateLineNumberAreaWidth(int newBlockCount);
    void highlightCurrentLine();
    void updateLineNumberArea(const QRect &, int);

private:
    QWidget *lineNumberArea;
};


class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor) {
        codeEditor = editor;
    }

    QSize sizeHint() const override {
        return QSize(codeEditor->lineNumberAreaWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        codeEditor->lineNumberAreaPaintEvent(event);
    }

private:
    CodeEditor *codeEditor;
};



#endif //PROGRA_1_DATOS_2_CODEEDITOR_H
