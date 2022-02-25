#include "Television.h"

Television::Television(std::string marque) : 
    channel(0), status(false), battery(nullptr), label(marque)
{

}

Television::~Television() {
    delete battery;
}

void Television::changeChannel(int chaine) {
    channel = chaine;
}

bool Television::isOn() {
    return status;
}

void Television::onSwitch() {
    if (status)
        status = false;
    else if (battery) {
        battery->use();
        status = true;
    }
}

void Television::connectTo(Battery* alimentation) {
    if (isOn())
        battery = alimentation;
}

void Television::disconnect() {
    battery = nullptr;
}