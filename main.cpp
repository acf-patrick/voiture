#include <iostream>
#include "Car.h"
#include "Television.h"

int main() {
    Car car = Car("Volvo");
    car.setTire(0.13, "Micheclin");
    car.setBattery(32, "Bosch");
    car.move();
    car.showSpec();

    Television tv = Television("Vista");
    tv.connectTo(car.getBattery());
    tv.onSwitch();
    return 0;
}