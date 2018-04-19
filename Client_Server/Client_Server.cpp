//
// Created by kenneth on 25/03/18.
//

#include "Client_Server.h"
#include "Json_parser.h"
/**
 * Inicializa la coneccion al server
 */
void Client_Server::connect_Server() {
    int portNum = 1500; // NOTE that the port number is same for both client and server
    bool isExit = false;
    char* ip = "127.0.0.1";

    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);
    if (client < 0)
    {
        std::cout << "\nError establishing socket..." << std::endl;
        exit(1);
    }
    std::cout << "\n=> Socket client has been created..." <<std:: endl;

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        std::cout << "=> Connection to the server port number: " << portNum << std::endl;
    std::cout << "=> Awaiting confirmation from the server..." << std::endl; //line 40
    recv(client, buffer, bufsize, 0);
    std::cout << "=> Connection confirmed, you are good to go...";
    while(client){
        std::cout<<"ESTOY AQUI PERROS"<<std::endl;
        recv(client, buffer, bufsize, 0);
        QString str = QString(buffer);
        if(!str.contains("type")){
            return;
        }
        std::cout<< sizeof(buffer)<<std::endl;
        //HACER ALGO CON LA INTERFAZ PARA ANADIRLO :D
        //Json_parser::create_json(buffer);
    }
}
void Client_Server::send_Server(json_object* objeto) {
    send(client, json_object_to_json_string(objeto), bufsize, 0);
}