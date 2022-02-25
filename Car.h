#ifndef CAR_H
#define CAR_H

#include "Tire.h"
#include "Battery.h"
#include <vector>

class Car {

private:

// Quatre pneus
    std::vector<Tire> tires;
// Batterie de l'automobile
    Battery* battery;
// Essence en pourcentage
    int fuel;
// Vitesse en km/h
    float velocity;
// Marque de la voiture
    std::string label;
// false: éteint, true: en marche
    bool status;
// Numéro matricule de la voiture
    std::string matricule;

// retourne le nombre de pneus crevés
    int tireStatus();

public:
    Car(std::string marque);

// Setter battery
    void setBattery(int capacite, std::string marque);

// Modifier les pneus
    void setTire(float rayon, std::string marque, std::string materiau = "Caoutchou");

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

// Retourne une référence vers la batterie de la voiture
    Battery* getBattery();
};

#endif // CAR_H