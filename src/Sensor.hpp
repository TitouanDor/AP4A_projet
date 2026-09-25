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
         * Permet de print le sensor
         * @param os la sortie voulue
         * @param sensor le sensor à afficher
         */
        friend std::ostream& operator<<(std::ostream &os, const Sensor &sensor);

};

#endif