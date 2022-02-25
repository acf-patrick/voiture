#include "Car.h"
#include <iostream>

Car::Car(std::string marque) {
    label = marque;
    status = false;
    battery = nullptr;
    fuel = 100;
}

void Car::setTire(float rayon, std::string marque, std::string materiau) {
    tires.clear();
    for (int i=0; i<4; ++i)
        tires.emplace_back(rayon, marque, materiau);
}

void Car::showSpec() {
    std::cout << label << " :\n";
    if (battery) {
        std::cout << " - Batterie : " << std::endl
                << "\t - Power : " << battery->getPower() << '%' << std::endl
                << "\t - Capacity : " << battery->getCapacity() << " Volts" << std::endl
                << "\t - Label : " << battery->getLabel() << std::endl;
    } else 
        std::cerr << " - Pas de batterie\n";
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

Battery* Car::getBattery() {
    return battery;
}

void Car::setBattery(int capacite, std::string marque) {
    if (battery) 
        delete battery;
    battery = new Battery(capacite, marque);
}

void Car::move() {
    if (isOn())
        fuel -= 1;
}

void Car::turnOn() {
    if (battery and !battery->isLow()) {
       battery->use();
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