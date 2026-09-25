#include <iostream>
#include "Sensor.hpp"
#include "Server.hpp"
#include "Scheduler.hpp"
#define SENSOR_NUMBER 4


int main() {
    Server* serv1 = new Server("BUREAU1");
    Server* serv2 = new Server("BUREAU2");
    Sensor list[SENSOR_NUMBER] = {
        Sensor(1, "TEMP", serv1),
        Sensor(2, "LIGHT", serv1),
        Sensor(3, "TEMP", serv2),
        Sensor(4,"LIGHT", serv2),

    };
    Scheduler sch = Scheduler(1,SENSOR_NUMBER,list);

    std::cout << "Starting IOT..." << std::endl;
    sch.simulate();
    std::cout << "End" << std::endl;
    return 0;
}