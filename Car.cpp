#include "Car.h"
#include <iostream>

void Car::init(std::string marque) {
    label = marque;
    status = false;
    fuel = 100;
}

Car::Car(std::string marque)
{
    init(marque);
}

Car::Car(std::string marque, float rayonPneu, std::string marquePneu, std::string materiauPneu, int capaciteBatterie, std::string marqueBatterie): 
    battery(capaciteBatterie, marqueBatterie)
{
    for (int i=0; i<4; ++i)
        tires.push_back(Tire(rayonPneu, marquePneu, materiauPneu));
    init(marque);
}

void Car::showSpec() {
    std::cout << label << " :\n";
    std::cout << " - Batterie : " << std::endl
            << "\t - Power : " << battery.getPower() << '%' << std::endl
            << "\t - Capacity : " << battery.getCapacity() << " Volts" << std::endl
            << "\t - Label : " << battery.getLabel() << std::endl;
    std::cout << " - Pneus : " << std::endl
            << "\t - Label : " << tires[0].getLabel() << std::endl
            << "\t - Radius : " << tires[0].getRadius() << " meters" << std::endl
            << "\t - Material : " << tires[0].getMaterial() << std::endl;
    std::cout << " - Essence : " << fuel << "%\n";
    std::cout << " - Statut : " << (status ? "en marche" : "éteint") << std::endl;
    int count = tireStatus();
    if (count)
        std::cout << " - Vous avez " << count << " pneus crevés\n";
    else
        std::cout << " - Pneus en bon état.\n";

}

bool Car::isOn() const {
    return status;
}

float Car::getVelocity() const {
    return velocity;
}

void Car::move() {
    if (isOn())
        fuel -= 1;
}

void Car::turnOn() {
    if (!battery.isLow()) {
        battery.use();
        if (fuel <= 0) {
            std::cout << "Vous n'avez clairement plus d'essence" << std::endl;
            return;
        } else {
            status = true;
            std::cout << "Voiture demarré." << std::endl;
            int count = tireStatus();
            if (count)
                std::cout << "Vous avez " << count << " pneus crevés!" << std::endl;
        }
    }
}

int Car::tireStatus() {
    int count = 0;
    for (int i=0; i<4; ++i)
        if (tires[i].isFlat())
            count++;
    return count;
}