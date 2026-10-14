#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include <random>
#include "Server.hpp"

class Sensor{
    private:
        static int next_id;
        int id;
        std::string type;
        float value;
        Server* serv;
        /**
         * Permet d'attribuer une valeur au hasard
         */
        /*vitual*/void execute();

    protected:
        void setValue(float newValue){
            this->value = newValue;
        }

    public:
        /**
         * Constructeur par défault
         */
        Sensor();

        /**
         * Constructeur
         * @param type std::string type du sensor (Lumière, température, humidité)
         * @param serv Server* pointeur vers le serveur
         */
        Sensor(const std::string type,Server *serv);

        /**
         * Constructeur par recopie
         * @param other Sensor à recopier
         */
        Sensor(const Sensor& other);

        /**
         * Destructeur
         */
        ~Sensor();

        /**
         * Méthode d'affectation
         * @param other le sensor à affecter
         */
        Sensor& operator=(const Sensor& other);

        /**
         * Méthode activé pour mettre à jour le capteur et envoyer les donner au server
         */
        void update();

        /**
         * Getter pour avoir la valeur du sensor, principalement pour du debug
         */
        float getValue();

        /**
         * Sert à calculer la valeur capturer par un sensor
        */
        virtual float computeValue() = 0;

        /**
         * Permet de print le sensor
         * @param os la sortie voulue
         * @param sensor le sensor à afficher
         */
        friend std::ostream& operator<<(std::ostream &os, const Sensor &sensor);

};

#endif