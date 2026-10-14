#ifndef TEMPSENSOR_HPP
#define TEMPSENSOR_HPP

#include "../Sensor.hpp"


class TempSensor : public Sensor{
    public:
        TempSensor(int id, Server* Serv) : Sensor(id, "°C", Serv) {}
        void computeValue() override {

            std::random_device rd;
            std::mt19937 gen(rd());

            // Définition de l'intervalle [min, max]
            std::uniform_real_distribution<float> dis(-5.0f, 40.0f);
            float random_float = dis(gen);
            this->setValue(random_float);
        }

};

#endif