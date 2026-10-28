#ifndef LIGHTSENSOR_HPP
#define LIGHTSENSOR_HPP

#include "../Sensor.hpp"
#include "../Server.hpp"
#include <random>

class LightSensor : public Sensor{

    public:
        LightSensor(Server* serv, int delta) : Sensor("Light", "Lux", serv, delta){}

        LightSensor() : Sensor("Light", "Lux", new Server(), 1) {}

        LightSensor(const LightSensor& other) : Sensor(other.type, other.unit, other.serv, other.delta) {}

        ~LightSensor() {}

        LightSensor& operator=(const LightSensor& other){
            this->id = next_id++;
            this->delta = other.delta;
            this->serv = other.serv;
            this->type = other.type;
            this->unit = other.unit;
            this->value = other.value;
            return *this;
        }

        float computeValue() override {
            std::random_device rd;
            std::mt19937 gen(rd());

            // Définition de l'intervalle [min, max]
            std::uniform_real_distribution<float> dis(30.0f, 1000.0f);
            float random_float = dis(gen);
            return random_float;
        }
};

#endif