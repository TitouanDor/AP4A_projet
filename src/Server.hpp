#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

class Server {
    private:
        std::string name;
    public:
        Server();
        Server(std::string name);
        std::string getName();

        void consoleWrite(const std::string& message);
        void fileWrite(const std::string& message, const std::string& filename);
};

#endif // SERVER_HPP