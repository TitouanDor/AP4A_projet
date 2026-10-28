#include <iostream>
#include "HeritageSensor/LightSensor.hpp"
#include "HeritageSensor/SoundSensor.hpp"
#include "HeritageSensor/TempSensor.hpp"
#include "Server.hpp"
#include "Scheduler.hpp"


int main() {
    Server* serv1 = new Server("BUREAU1", true);

    Scheduler sch = Scheduler(1);
    sch.addSensor(new LightSensor(serv1,1));
    sch.addSensor(new SoundSensor(serv1, 3));
    sch.addSensor(new TempSensor(serv1, 9));

    std::cout << "Starting IOT..." << std::endl;
    sch.simulate();
    std::cout << "End" << std::endl;
    return 0;
}