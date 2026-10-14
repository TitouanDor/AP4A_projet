#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include "Sensor.hpp"
#include <vector>

class Scheduler{
    private:
        int delta; //temps entre update
        std::vector<Sensor*> list;

    public:
        /**
         * Constructeur par défault
         */
        Scheduler();

        /**
         * Cpnstructeur par recopie
         * @param other Scheduler à recopier
         */
        Scheduler(const Scheduler& other);

        /**
         * Constructeur
         * @param delta le temps entre chaque boucle
         * @param size nombre de Sensor dans la liste
         * @param list liste de tous les sensors
         */
        Scheduler(int delta);

        /**
         * Destructeur par défault
         */
        ~Scheduler();

        /**
         * Boucle infinie pour démarrer la simulation
         */
        void simulate();

        void addSensor(Sensor* sensor);

        /**
         * Méthode pour l'affectation
         * @param sch le scheduler à affecter
         */
        Scheduler& operator=(const Scheduler& sch);


};

#endif