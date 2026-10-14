#ifndef SOUNDSENSOR_HPP
#define SOUNDSENSOR_HPP

#include "../Sensor.hpp"


class SoundSensor : public Sensor{
    public:
        SoundSensor(Server* Serv) : Sensor("Sound", "dB", Serv){}

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