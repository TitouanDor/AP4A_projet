#include "Sensor.hpp"
#include "Server.hpp"
#include <time.h>

int Sensor::next_id = 0;

Sensor::Sensor() : id(next_id++), type("DEFAULT"), unit("NONE"), value(0), delta(1){
    this->serv = nullptr;
}

Sensor::~Sensor(){
}

Sensor::Sensor(const std::string type,std::string unit, Server *serv, int delta) : id(next_id++), type(type), unit(unit), delta(delta) {
    this->serv = serv;
}

Sensor::Sensor(const Sensor& other) : id(next_id++), type(other.type), unit(other.unit), value(other.value), serv(other.serv), delta(other.delta){}

void Sensor::execute(int t){

    if((t%this->delta) == 0){
        float random_float = this->computeValue();
        this->value = random_float;
    }
}

float Sensor::getValue(){
    return this->value;
}

void Sensor::update(){
    //met en vie le sensor mais il ne prend pas forcément la mesure il faut que le catpeur sachant indépendament s'il dois prendre la mesure
    time_t t = time(NULL);
    this->execute(t);
    std::string char_time = std::to_string(t);
    std::string char_value = std::to_string(this->value);
    std::string mess = "[id:" + std::to_string(this->id) + "] : " + char_value + " "+ this->unit;
    std::string filename = this->serv->getName() + "_" + this->type + ".log";
    std::string log = char_time + ";" +  char_value;


    if(this->serv){
        this->serv->consoleWrite(mess);
        this->serv->fileWrite(log, filename);
    }
    
}

std::ostream& operator<<(std::ostream &os, const Sensor &sensor){
    os << "[" << sensor.type << "] : " << sensor.value << sensor.unit;
    return os;
}

Sensor& Sensor::operator=(const Sensor& other){
    this->id = other.id;
    this->type = other.type;
    this->unit = other.unit;
    this->value = other.value;
    this->serv = other.serv;
    this->delta = other.delta;
    return *this;
}