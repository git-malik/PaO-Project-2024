#include "sensoreBanda.h"

int SensoreBanda::currentid = 1;

SensoreBanda::SensoreBanda(const std::string& name) : Sensore(name) {
    this->pacchetti = std::vector<const PacchettoBanda*>();
    this->id = "BS#"+std::to_string(SensoreBanda::currentid);
    this->name = name;
    SensoreBanda::currentid += 1;
}

SensoreBanda::SensoreBanda() : Sensore() {
    this->pacchetti = std::vector<const PacchettoBanda*>();
    this->id = "BS#"+std::to_string(SensoreBanda::currentid);
    this->name = "Bandwidth Sensor";
    SensoreBanda::currentid += 1;
}

void SensoreBanda::misura() {
    PacchettoBanda *p = new PacchettoBanda();
    this->pacchetti.push_back(p);
}

void SensoreBanda::accept(IConstSensorVisitor* visitor) const {
    visitor->visit(this);
}

void SensoreBanda::accept(ISensorVisitor* visitor) {
    visitor->visit(this);
}

const std::vector<const PacchettoBanda*>& SensoreBanda::getPacchetti() const {
    return this->pacchetti;
}

const std::string& SensoreBanda::getId() const {
    return this->id;
}

const std::string& SensoreBanda::getName() const {
    return this->name;
}

void SensoreBanda::setName(const std::string& newName) {
    this->name = newName;
}
SensoreBanda::~SensoreBanda() {
    for (const PacchettoBanda* p: this->pacchetti) {
        delete p;
    }

    this->pacchetti.clear();
}