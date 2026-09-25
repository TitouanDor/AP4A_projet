#include <iostream>
#include "Sensor.hpp"
#include "Server.hpp"
#include "Scheduler.hpp"



int main() {
    Server serv = Server("DEFAULT");
    Sensor list[2] = {
        Sensor(1, "TEMP", &serv),
        Sensor(2, "LIGHT", &serv)
    };

    std::cout << serv.getName() << std::endl;
    Scheduler sch = Scheduler(1,2,list);

    std::cout << "Starting IOT..." << std::endl;
    for(int i = 0; i<10;++i){
        sch.simulate();
    }

    std::cout << "End" << std::endl;
    return 0;
}