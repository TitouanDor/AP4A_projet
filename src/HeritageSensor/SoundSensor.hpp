#ifndef SOUNDSENSOR_HPP
#define SOUNDSENSOR_HPP

#include "../Sensor.hpp"


class SoundSensor : public Sensor{
    public:
        TempSensor(int id, Server* Serv) : Sensor(id, "dB", Serv){}

        void computeValue() override {

            std::random_device rd;
            std::mt19937 gen(rd());

            // Définition de l'intervalle [min, max]
            std::uniform_real_distribution<float> dis(0.0f, 110.0f);
            float random_float = dis(gen);
            this->setValue(random_float);
        }

};

#endif