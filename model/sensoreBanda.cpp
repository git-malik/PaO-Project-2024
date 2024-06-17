#include "sensoreBanda.h"
#include <iostream>

int SensoreBanda::currentid = 1;

SensoreBanda::SensoreBanda(int bufferSize) : Sensore(bufferSize) {
    this->pacchetti = std::vector<PacchettoBanda*>();
    this->id = "BS#"+SensoreBanda::currentid;
    this->name = "Bandwidth Sensor";
    SensoreBanda::currentid += 1;
}

void SensoreBanda::misura() {
    PacchettoBanda *p = new PacchettoBanda();
    this->pacchetti.push_back(p);
}

const std::vector<PacchettoBanda*>& SensoreBanda::getPacchetti() {
    return this->pacchetti;
}

//getId
std::string SensoreBanda::getId() {
    return this->id;
}