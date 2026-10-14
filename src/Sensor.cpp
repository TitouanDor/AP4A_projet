#include "Sensor.hpp"
#include "Server.hpp"
#include <random>

int Sensor::next_id = 0;

Sensor::Sensor() : id(next_id++), type("DEFAULT"), value(0){
    this->serv = nullptr;
}

Sensor::~Sensor(){
}

Sensor::Sensor(const std::string type,Server *serv) : id(next_id++), type(type){
    this->serv = serv;
}

Sensor::Sensor(const Sensor& other) : id(next_id++), type(other.type), value(other.value), serv(other.serv){}

void Sensor::execute(){
    float random_float = this->computeValue();
    this->value = random_float;
}

float Sensor::getValue(){
    return this->value;
}

void Sensor::update(){
    //met en vie le sensor mais il ne prend pas forcément la mesure il faut que le catpeur sachant indépendament s'il dois prendre la mesure
    this->execute();
    std::string mess = "[id:" + std::to_string(this->id) + "] : " + std::to_string(this->value) + " "+ this->type;
    std::string filename = ".log";
    if(this->serv){
        this->serv->consoleWrite(mess);
        this->serv->fileWrite(mess, filename);
    }
    
}

std::ostream& operator<<(std::ostream &os, const Sensor &sensor){
    os << "[" << sensor.type << "] : " << sensor.value;
    return os;
}

Sensor& Sensor::operator=(const Sensor& other){
    this->id = other.id;
    this->type = other.type;
    this->value = other.value;
    this->serv = other.serv;
    return *this;
}