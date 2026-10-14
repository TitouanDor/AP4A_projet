#include "Server.hpp"
#include <iostream>
#include <fstream>

Server::Server(): name("SERVER DEFAULT"), ConsoleEnable(true){}

Server::Server(std::string name, bool console) : name(name), ConsoleEnable(console){}

Server::Server(const Server& other) : name(other.name), ConsoleEnable(other.ConsoleEnable){}

void Server::consoleWrite(const std::string& message){
    if(this->ConsoleEnable){
        std::cout << message << std::endl;
    }
    
}

Server::~Server(){}

Server& Server::operator=(const Server& serv){
    this->name = serv.name;
    return *this;
}

void Server::fileWrite(const std::string& message, const std::string& filename){
    std::ofstream file(filename, std::ios::app);
    file << message << std::endl;
    file.close();
}

std::string Server::getName(){
    return this->name;
}