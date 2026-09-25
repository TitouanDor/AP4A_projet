#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include "Server.hpp"

class Sensor{
    private:
        int id;
        std::string type;
        float value;
        Server* serv;
        void execute();

    public:
        Sensor();
        Sensor(const int id, const std::string type,Server *serv);
        ~Sensor();
        void update();
        float getValue();
        friend std::ostream& operator<<(std::ostream &os, const Sensor &sensor);

};

#endif