//
// Created by kenneth on 25/03/18.
//

#include "Client_Server.h"
void Client_Server::connect_Server() {
    struct sockaddr_in server_addr;

    client = socket(AF_INET, SOCK_STREAM, 0);
    client = socket(AF_INET, SOCK_STREAM, 0);

    if (client < 0)
    {
        std::cout << "\nError establishing socket..." << std::endl;
        exit(1);
    }
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portNum);
    if (connect(client,(struct sockaddr *)&server_addr, sizeof(server_addr)) == 0)
        std::cout << "=> Connection to the server port number: " << portNum << std::endl;
    std::cout << "=> Awaiting confirmation from the server..." << std::endl; //line 40
    recv(client, buffer, bufsize, 0);
    std::cout << "=> Connection confirmed, you are good to go...";
    while(true){
        recv(client, buffer, bufsize, 0);
        //HACER ALGO CON LA INTERFAZ PARA ANADIRLO :D
    }
}
void Client_Server::send_Server(json_object* objeto) {
    send(client, json_object_to_json_string(objeto), bufsize, 0);
}