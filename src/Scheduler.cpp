#include "Scheduler.hpp"
#include "Sensor.hpp"
#include <iostream>
#include <chrono>
#include <thread>



Scheduler::Scheduler() : delta(1), size(0){
    this->list = nullptr;
}

Scheduler::Scheduler(int delta, int size, Sensor list[]) : delta(delta), size(size){
    this->list = new Sensor[this->size];
    for(int i = 0;i<this->size;++i){
        this->list[i] = list[i];
    }
}

Scheduler::~Scheduler(){
    if(this->list){
        delete[] this->list;
    }
}

void Scheduler::simulate(){
    while(true){
        std::this_thread::sleep_for(std::chrono::seconds(this->delta));
        for(int i = 0; i< this->size;++i){
            this->list[i].update();
        }
    }
    
}