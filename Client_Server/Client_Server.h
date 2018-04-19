//
// Created by kenneth on 25/03/18.
//

#ifndef PROGRA_1_DATOS_2_CLIENT_SERVER_H
#define PROGRA_1_DATOS_2_CLIENT_SERVER_H

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <json-c/json.h>
#include <QtCore/QString>

class Client_Server {
public:
    QString* str= nullptr;
     void connect_Server();
    int client;

    static const int bufsize = 1024;
    char buffer[bufsize];

    void send_Server(json_object* objeto);
};


#endif //PROGRA_1_DATOS_2_CLIENT_SERVER_H
