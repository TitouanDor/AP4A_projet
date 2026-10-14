#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

class Server {
    private:
        std::string name;
        bool ConsoleEnable;
    public:
        /**
         * Constructeur par défault
         */
        Server();

        /**
         * Constructeur par recopie
         * @param other le server à recopier
         */
        Server(const Server& other);

        /**
         * Destructeur
         */
        ~Server();

        /**
         * Constructeur
         * @param name le nom du server
         * @param consol true ou false si vous voulez que la console print
         */
        Server(std::string name, bool console);

        /**
         * Getter pour récupérer le nom, principalement pour le débug
         */
        std::string getName();

        /**
         * Méthode pour écrire le message recu sur la console
         * @param message le message à écrire
         */
        void consoleWrite(const std::string& message);

        /**
         * Méthode pour écrire le message recu dans un fichier donné
         * @param message le message à écrire
         * @param filename chemin du ficher
         */
        void fileWrite(const std::string& message, const std::string& filename);

        /**
         * Méthode pour l'affectation
         * @param serv le server à affecter
         */
        Server& operator=(const Server& serv);
};

#endif // SERVER_HPP