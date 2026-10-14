#include <iostream>
#include "Sensor.hpp"
#include "HeritageSensor/LightSensor.hpp"
#include "HeritageSensor/SoundSensor.hpp"
#include "HeritageSensor/TempSensor.hpp"
#include "Server.hpp"
#include "Scheduler.hpp"


int main() {
    Server* serv1 = new Server("BUREAU1", true);
    Server* serv2 = new Server("BUREAU2", false);

    Scheduler sch = Scheduler(1);
    sch.addSensor(new LightSensor(serv1));
    sch.addSensor(new SoundSensor(serv1));
    sch.addSensor(new TempSensor(serv1));
    sch.addSensor(new LightSensor(serv2));
    sch.addSensor(new SoundSensor(serv2));
    sch.addSensor(new TempSensor(serv2));

    std::cout << "Starting IOT..." << std::endl;
    sch.simulate();
    std::cout << "End" << std::endl;
    return 0;
}