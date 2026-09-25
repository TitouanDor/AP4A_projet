#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <iostream>
#include "Server.hpp"

class Sensor{
    private:
        int id;
        std::string type;
        float value;
        Server* serv;
        /**
         * Permet d'attribuer une valeur au hasard
         */
        /*vitual*/void execute();

    public:
        /**
         * Constructeur par défault
         */
        Sensor();

        /**
         * Constructeur
         * @param id int identitfiant du sensor
         * @param type std::string type du sensor (Lumière, température, humidité)
         * @param serv Server* pointeur vers le serveur
         */
        Sensor(const int id, const std::string type,Server *serv);

        /**
         * Destructeur
         */
        ~Sensor();

        /**
         * Méthode activé pour mettre à jour le capteur et envoyer les donner au server
         */
        void update();

        /**
         * Getter pour avoir la valeur du sensor, principalement pour du debug
         */
        float getValue();

        /**
         * Permet de print le sensor
         */
        friend std::ostream& operator<<(std::ostream &os, const Sensor &sensor);

};

#endif