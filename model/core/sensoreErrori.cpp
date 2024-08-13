#include "sensoreErrori.h"

int SensoreErrori::currentid = 1;

SensoreErrori::SensoreErrori(std::string name) : Sensore(name) {
    this->pacchetti = std::vector<PacchettoErrori*>();
    this->id = "ES#"+std::to_string(SensoreErrori::currentid);
    this->name = name;
    SensoreErrori::currentid += 1;
}

SensoreErrori::SensoreErrori() : Sensore() {
    this->pacchetti = std::vector<PacchettoErrori*>();
    this->id = "ES#"+std::to_string(SensoreErrori::currentid);
    this->name = "Error Sensor";
    SensoreErrori::currentid += 1;
}

void SensoreErrori::misura() {
    PacchettoErrori *p = new PacchettoErrori();
    this->pacchetti.push_back(p);
}

const std::vector<PacchettoErrori*>& SensoreErrori::getPacchetti() {
    return this->pacchetti;
}

//getId
std::string SensoreErrori::getId() {
    return this->id;
}

//getName
std::string SensoreErrori::getName() {
    return this->name;
}

//setName
void SensoreErrori::setName(const std::string& newName) {
    this->name = newName;
}
