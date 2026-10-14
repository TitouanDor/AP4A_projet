#include <iostream>
#include "Sensor.hpp"
#include "Server.hpp"
#include "Scheduler.hpp"
#define SENSOR_NUMBER 6


int main() {
    Server* serv1 = new Server("BUREAU1", true);
    Server* serv2 = new Server("BUREAU2", false);
    Sensor list[SENSOR_NUMBER] = {
        Sensor(1, "TEMP", serv1),
        Sensor(2, "LIGHT", serv1),
        Sensor(3, "HUMIDITY", serv1),
        Sensor(4, "TEMP", serv2),
        Sensor(5,"LIGHT", serv2),
        Sensor(6,"HUMIDITY",serv2),
    };
    Scheduler sch = Scheduler(1,SENSOR_NUMBER,list);

    std::cout << "Starting IOT..." << std::endl;
    sch.simulate();
    std::cout << "End" << std::endl;
    return 0;
}