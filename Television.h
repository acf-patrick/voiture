#ifndef TELEVISION_H
#define TELEVISION_H

#include "Battery.h"

class Television {
    
private:
// Chaîne courrante
    int channel;
// false: éteint, true: en marche
    bool status;
// Référence vers une batterie
    Battery* battery;
// Marque de la télévision
    std::string label;

public:
    Television(std::string marque);
    ~Television();

// Changer de chaîne
    void changeChannel(int chaine);

// Eteindre / Démarrer la télé
    void onSwitch();

// La télévision est en marche
    bool isOn();

// Déconnecter l'appareil
    void disconnect();

// Alimenter la télévision
    void connectTo(Battery* alimentation);
};

#endif // TELEVISION_H