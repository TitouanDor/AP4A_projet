#include "Server.hpp"
#include <iostream>
#include <fstream>

Server::Server(): name("SERVER DEFAULT"){}

Server::Server(std::string name) : name(name){}


void Server::consoleWrite(const std::string& message){
    std::cout << message << std::endl;
}


void Server::fileWrite(const std::string& message, const std::string& filename){
    std::ofstream file(filename, std::ios::app);
    std::string format = "[" + this->name + "] : " + message;
    file << format << std::endl;
    file.close();
}

std::string Server::getName(){
    return this->name;
}