#include "sensoreJitter.h"

int SensoreJitter::currentid = 1;

SensoreJitter::SensoreJitter(const std::string& name) : Sensore(name) {
    this->pacchetti = std::vector<const PacchettoJitter*>();
    this->id = "JS#"+std::to_string(SensoreJitter::currentid);
    this->name = name;
    SensoreJitter::currentid += 1;
}

SensoreJitter::SensoreJitter() : Sensore() {
    this->pacchetti = std::vector<const PacchettoJitter*>();
    this->id = "JS#"+std::to_string(SensoreJitter::currentid);
    this->name = "Jitter Sensor";
    SensoreJitter::currentid += 1;
}

void SensoreJitter::misura() {
    PacchettoJitter *p = new PacchettoJitter();
    this->pacchetti.push_back(p);
}

void SensoreJitter::accept(IConstSensorVisitor* visitor) const {
    visitor->visit(this);
}

void SensoreJitter::accept(ISensorVisitor* visitor) {
    visitor->visit(this);
}

const std::vector<const PacchettoJitter*>& SensoreJitter::getPacchetti() const {
    return this->pacchetti;
}

const std::string& SensoreJitter::getId() const {
    return this->id;
}

const std::string& SensoreJitter::getName() const {
    return this->name;
}

void SensoreJitter::setName(const std::string& newName) {
    this->name = newName;
}

SensoreJitter::~SensoreJitter() {
    for (const PacchettoJitter* p: this->pacchetti) {
        delete p;
    }

    this->pacchetti.clear();
}