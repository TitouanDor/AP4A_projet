#ifndef SOUNDSENSOR_HPP
#define SOUNDSENSOR_HPP

#include "../Sensor.hpp"
#include <random>

class SoundSensor : public Sensor{
    public:
        SoundSensor(Server* Serv, int d) : Sensor("Sound", "dB", Serv, d){}

        SoundSensor() : Sensor("Sound", "dB", new Server(), 1) {}

        SoundSensor(const SoundSensor& other) : Sensor(other.type, other.unit, other.serv, other.delta) {}

        ~SoundSensor() {}

        SoundSensor& operator=(const SoundSensor& other){
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
            std::uniform_real_distribution<float> dis(0.0f, 110.0f);
            float random_float = dis(gen);
            return random_float;
        }
};

#endif