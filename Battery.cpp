#include "Battery.h"
#include <iostream>

Battery::Battery() :
    capacity(0), power(100), label("")
{

}

Battery::Battery(int capacite, std::string marque) :
    capacity(capacite), label(marque), power(100)
{

}

void Battery::chargeUp() {
    power = 100;
}

bool Battery::isLow() const {
    auto low = power <= 10;
    if (low) 
        std::cout << power << "% : Niveau de batterie faible" << std::endl;
    return low;
}

void Battery::use() {
    power -= 5;
}

int Battery::getPower() {
    return power;
}

int Battery::getCapacity() {
    return capacity;
}

std::string Battery::getLabel() {
    return label;
}