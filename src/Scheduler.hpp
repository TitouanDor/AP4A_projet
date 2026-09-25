#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "Sensor.hpp"

class Scheduler{
    private:
        int delta; //temps entre update
        int size;
        Sensor* list;

    public:
        Scheduler();
        Scheduler(int delta, int size, Sensor list[]);
        ~Scheduler();
        void simulate();


};

#endif