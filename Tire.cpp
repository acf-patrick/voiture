#include "Tire.h"

Tire::Tire() {
    
}
Tire::Tire(float rayon, std::string marque, std::string materiau) :
    radius(rayon), label(marque), material(materiau)
{
    air = 100;
}

std::string Tire::getLabel() {
    return label;
}

float Tire::getRadius() {
    return radius;
}

std::string Tire::getMaterial() {
    return material;
}

bool Tire::isFlat() const {
    return air <= 50;
}