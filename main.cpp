#include <iostream>
#include "Car.h"

int main() {
    Car car = Car("Volvo", 0.13, "Michelin", "Caoutchou", 32, "Bosch");
    car.move();
    car.showSpec();
    return 0;
}