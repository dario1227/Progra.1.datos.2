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
class Client_Server {
public:
     void connect_Server();
    int client;
    int portNum = 1500;
    bool isExit = false;
    static const int bufsize = 1024;
    char buffer[bufsize];
    char* ip = "127.0.0.1";
    void send_Server(json_object* objeto);
};


#endif //PROGRA_1_DATOS_2_CLIENT_SERVER_H
