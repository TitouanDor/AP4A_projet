#ifndef SOUNDSENSOR_HPP
#define SOUNDSENSOR_HPP

#include "../Sensor.hpp"
#include <random>

class SoundSensor : public Sensor{
    public:
        SoundSensor(Server* Serv, int d) : Sensor("Sound", "dB", Serv, d){}

        float computeValue() override {
            std::random_device rd;
            std::mt19937 gen(rd());

            // Définition de l'intervalle [min, max]
            std::uniform_real_distribution<float> dis(0.0f, 110.0f);
            float random_float = dis(gen);
            return random_float;
        }
};

#endif