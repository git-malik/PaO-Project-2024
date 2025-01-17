#include "sensoreCarico.h"
#include <iostream>

int SensoreCarico::currentid = 1;

SensoreCarico::SensoreCarico(const std::string& name) : Sensore(name) {
    this->pacchetti = std::vector<const PacchettoCarico*>();
    this->id = "LS#"+std::to_string(SensoreCarico::currentid);
    this->name = name;
    SensoreCarico::currentid += 1;
}

SensoreCarico::SensoreCarico() : Sensore() {
    this->pacchetti = std::vector<const PacchettoCarico*>();
    this->id = "LS#"+std::to_string(SensoreCarico::currentid);
    this->name = "Load Sensor";
    SensoreCarico::currentid += 1;
}

void SensoreCarico::misura() {
    PacchettoCarico *p = new PacchettoCarico();
    this->pacchetti.push_back(p);
}

void SensoreCarico::accept(IConstSensorVisitor* visitor) const {
    visitor->visit(this);
}

void SensoreCarico::accept(ISensorVisitor* visitor) {
    visitor->visit(this);
}

const std::vector<const PacchettoCarico*>& SensoreCarico::getPacchetti() const {
    return this->pacchetti;
}

const std::string& SensoreCarico::getId() const {
    return this->id;
}

const std::string& SensoreCarico::getName() const {
    return this->name;
}

void SensoreCarico::setName(const std::string& newName) {
    this->name = newName;
}

SensoreCarico::~SensoreCarico() {
    for (const PacchettoCarico* p: this->pacchetti) {
        delete p;
    }

    this->pacchetti.clear();
}
