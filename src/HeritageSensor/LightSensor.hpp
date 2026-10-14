#ifndef LIGHTSENSOR_HPP
#define LIGHTSENSOR_HPP

#include "../Sensor.hpp"


class LightSensor : public Sensor{

    public:
        TempSensor(int id, Server* Serv) : Sensor(id, "dB", Serv){}

        void computeValue() override {

            std::random_device rd;
            std::mt19937 gen(rd());

            // Définition de l'intervalle [min, max]
            std::uniform_real_distribution<float> dis(30.0f, 1000.0f);
            float random_float = dis(gen);
            this->setValue(random_float);
        }
        

};

#endif