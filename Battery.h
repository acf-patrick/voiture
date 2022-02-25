#ifndef BATTERY_H
#define BATTERY_H

#include <string>

class Battery {

private:
// En volts
    int capacity;
// Pourcentage de la batterie
    int power;
// Marque
    std::string label;

public:
    Battery();
    Battery(int capacite, std::string marque);

// La battérie est faible
    bool isLow() const;

// retourne l'état de la batterie
    int getPower();

    int getCapacity();

    std::string getLabel();

// Utiliser la batterie
    void use();

// Recharger la batterie
    void chargeUp();
};

#endif // BATTERY_H