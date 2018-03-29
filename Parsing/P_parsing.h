//
// Created by kenneth on 28/03/18.
//

#ifndef PROGRA_1_DATOS_2_P_PARSING_H
#define PROGRA_1_DATOS_2_P_PARSING_H


class P_parsing {
public:
     int index = 0;
    void parseLine(QString line);
    void parseChar(QString line);
    void parseInt(QString line);
    void parseLong(QString line);
    void parseFloat(QString line);
    void parseDouble(QString line);
    void parseStruct(QString line);
    void parseReference(QString line);
    void sender_Helper(QString line);


};


#endif //PROGRA_1_DATOS_2_P_PARSING_H
