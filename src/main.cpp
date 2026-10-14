#include <iostream>
#include "Sensor.hpp"
#include "Server.hpp"
#include "Scheduler.hpp"
#define SENSOR_NUMBER 6


int main() {
    Server* serv1 = new Server("BUREAU1", true);
    Server* serv2 = new Server("BUREAU2", false);
    Sensor list[SENSOR_NUMBER] = {
        Sensor("TEMP", serv1),
        Sensor("LIGHT", serv1),
        Sensor("HUMIDITY", serv1),
        Sensor("TEMP", serv2),
        Sensor("LIGHT", serv2),
        Sensor("HUMIDITY",serv2),
    };
    Scheduler sch = Scheduler(1);
    for(int i = 0;i<SENSOR_NUMBER;++i){
        sch.addSensor(&list[i]);
    }

    std::cout << "Starting IOT..." << std::endl;
    sch.simulate();
    std::cout << "End" << std::endl;
    return 0;
}