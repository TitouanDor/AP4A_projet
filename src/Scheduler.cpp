#include "Scheduler.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <chrono>
#include <thread>
#include <vector>

Scheduler::Scheduler(const Scheduler& other) : delta(other.delta){
    this->list = other.list;
}

Scheduler::Scheduler() : delta(1){
    this->list.clear();
}

Scheduler::Scheduler(int delta) : delta(delta){
    this->list.clear();
}

Scheduler::~Scheduler(){
}

Scheduler& Scheduler::operator=(const Scheduler& sch){
    this->delta = sch.delta;
    this->list = sch.list;
    return *this;

}

void Scheduler::simulate(){
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(this->delta));
        for(int i = 0; i< this->list.size();++i){
            this->list[i]->update();
        }
    }
}

void Scheduler::addSensor(Sensor* sensor){
    this->list.push_back(sensor);
}