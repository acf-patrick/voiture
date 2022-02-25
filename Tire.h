#ifndef TIRE_H
#define TIRE_H

#include <string>

class Tire {
    
private:
// Matériau de fabrication du pneu
    std::string material;
// Marque du pneu
    std::string label;
// rayon en metre
    float radius;
// Pourcentage d'air compréssé
    int air;

public:
    Tire();
    Tire(float rayon, std::string marque, std::string materiau);

    std::string getLabel();
    float getRadius();
    std::string getMaterial();

// Le pneu est-il crevé?
    bool isFlat() const;
};

#endif // TIRE_H