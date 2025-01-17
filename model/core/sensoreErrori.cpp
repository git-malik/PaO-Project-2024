#include "sensoreErrori.h"

int SensoreErrori::currentid = 1;

SensoreErrori::SensoreErrori(const std::string& name) : Sensore(name) {
    this->pacchetti = std::vector<const PacchettoErrori*>();
    this->id = "ES#"+std::to_string(SensoreErrori::currentid);
    this->name = name;
    SensoreErrori::currentid += 1;
}

SensoreErrori::SensoreErrori() : Sensore() {
    this->pacchetti = std::vector<const PacchettoErrori*>();
    this->id = "ES#"+std::to_string(SensoreErrori::currentid);
    this->name = "Error Sensor";
    SensoreErrori::currentid += 1;
}

void SensoreErrori::misura() {
    PacchettoErrori *p = new PacchettoErrori();
    this->pacchetti.push_back(p);
}

void SensoreErrori::accept(IConstSensorVisitor* visitor) const {
    visitor->visit(this);
}

void SensoreErrori::accept(ISensorVisitor* visitor) {
    visitor->visit(this);
}

const std::vector<const PacchettoErrori*>& SensoreErrori::getPacchetti() const {
    return this->pacchetti;
}

//getId
const std::string& SensoreErrori::getId() const {
    return this->id;
}

//getName
const std::string& SensoreErrori::getName() const {
    return this->name;
}

//setName
void SensoreErrori::setName(const std::string& newName) {
    this->name = newName;
}

SensoreErrori::~SensoreErrori() {
    for (const PacchettoErrori* p: this->pacchetti) {
        delete p;
    }

    this->pacchetti.clear();
}