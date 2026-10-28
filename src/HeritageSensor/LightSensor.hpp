#ifndef LIGHTSENSOR_HPP
#define LIGHTSENSOR_HPP

#include "../Sensor.hpp"
#include <random>

class LightSensor : public Sensor{

    public:
        LightSensor(Server* Serv, int d) : Sensor("Light", "Lux", Serv, d){}

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