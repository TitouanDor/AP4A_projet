#ifndef TEMPSENSOR_HPP
#define TEMPSENSOR_HPP

#include "../Sensor.hpp"
#include <random>

class TempSensor : public Sensor{
    public:
        TempSensor(Server* Serv, int d) : Sensor("Temp", "°C", Serv, d) {}

        TempSensor() : Sensor("Temp", "°C", new Server(), 1) {}

        TempSensor(const TempSensor& other) : Sensor(other.type, other.unit, other.serv, other.delta) {}

        ~TempSensor() {}

        TempSensor& operator=(const TempSensor& other){
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
            std::uniform_real_distribution<float> dis(-5.0f, 40.0f);
            float random_float = dis(gen);
            return random_float;
        }
};

#endif