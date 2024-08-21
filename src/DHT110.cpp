#include "Dht110.h"


DHTWrapper::DHTWrapper(uint8_t pin, uint8_t type) : dht(pin, type) {}

void DHTWrapper::begin() {
    this->dht.begin();
}

float DHTWrapper::getTemperature() {
    return this->dht.readTemperature();
}

float DHTWrapper::getHumidity() {
    return this->dht.readHumidity();
}