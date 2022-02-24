#include "Tire.h"
#include "Battery.h"
#include <vector>

class Car {

private:
// Quatre pneus
    std::vector<Tire> tires;
// Batterie de l'automobile
    Battery battery;
// Essence en pourcentage
    int fuel;
// Vitesse en km/h
    float velocity;
// Marque de la voiture
    std::string label;
// false: éteint, true: en marche
    bool status;

    void init(std::string marque);

// retourne le nombre de pneus crevés
    int tireStatus();

public:
    Car(std::string marque);

    Car(std::string marque, float rayonPneu, std::string marquePneu, std::string materiauPneu, int capaciteBatterie, std::string marqueBatterie);

// Retourne la vitesse courrante de la voiture
    float getVelocity() const;

// La voiture est en marche
    bool isOn() const;

// Mettre la voiture en marche
    void turnOn();

// Bouger la voiture
    void move();

// Afficher
    void showSpec();
};