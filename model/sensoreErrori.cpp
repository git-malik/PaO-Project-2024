#include "SensoreErrori.h"
#include <iostream>

int SensoreErrori::currentid = 1;

SensoreErrori::SensoreErrori(int bufferSize) : Sensore(bufferSize) {
    this->pacchetti = std::vector<PacchettoErrori*>();
    this->id = "ES#"+SensoreErrori::currentid;
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