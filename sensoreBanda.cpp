#include "sensoreBanda.h"
#include <iostream>

int SensoreBanda::currentid = 1;

SensoreBanda::SensoreBanda(int bufferSize) : Sensore(bufferSize) {
    this->pacchetti = std::vector<PacchettoBanda*>();
    this->id = SensoreBanda::currentid;
    SensoreBanda::currentid += 1;
}

void SensoreBanda::misura() {
    PacchettoBanda *p = new PacchettoBanda();
    this->pacchetti.push_back(p);
}

std::vector<PacchettoBanda*> SensoreBanda::getPacchetti() {
    return this->pacchetti;
}

//getId
std::string SensoreBanda::getId() {
    return "BS#" + std::to_string(this->id);
}
