#include "sensoreBanda.h"
#include <iostream>

int SensoreBanda::currentid = 1;

SensoreBanda::SensoreBanda(std::string name) : Sensore(name) {
    this->pacchetti = std::vector<PacchettoBanda*>();
    this->id = "BS#"+std::to_string(SensoreBanda::currentid);
    this->name = name;
    SensoreBanda::currentid += 1;
}

SensoreBanda::SensoreBanda() : Sensore() {
    this->pacchetti = std::vector<PacchettoBanda*>();
    this->id = "BS#"+std::to_string(SensoreBanda::currentid);
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

//getName
std::string SensoreBanda::getName() {
    return this->name;
}

//setName
void SensoreBanda::setName(const std::string& newName) {
    this->name = newName;
}
