#include "sensoreDelay.h"

int SensoreDelay::currentid = 1;

SensoreDelay::SensoreDelay(const std::string& name) : Sensore(name) {
    this->pacchetti = std::vector<const PacchettoDelay*>();
    this->id = "DS#"+std::to_string(SensoreDelay::currentid);
    this->name = name;
    SensoreDelay::currentid += 1;
}

SensoreDelay::SensoreDelay() : Sensore() {
    this->pacchetti = std::vector<const PacchettoDelay*>();
    this->id = "DS#"+std::to_string(SensoreDelay::currentid);
    this->name = "Delay Sensor";
    SensoreDelay::currentid += 1;
}

void SensoreDelay::misura() {
    PacchettoDelay *p = new PacchettoDelay();
    this->pacchetti.push_back(p);
}

void SensoreDelay::accept(IConstSensorVisitor* visitor) const {
    visitor->visit(this);
}

void SensoreDelay::accept(ISensorVisitor* visitor) {
    visitor->visit(this);
}

const std::vector<const PacchettoDelay*>& SensoreDelay::getPacchetti() const {
    return this->pacchetti;
}

const std::string& SensoreDelay::getId() const {
    return this->id;
}

const std::string& SensoreDelay::getName() const {
    return this->name;
}

void SensoreDelay::setName(const std::string& newName) {
    this->name = newName;
}

SensoreDelay::~SensoreDelay() {
    for (const PacchettoDelay* p: this->pacchetti) {
        delete p;
    }

    this->pacchetti.clear();
}
