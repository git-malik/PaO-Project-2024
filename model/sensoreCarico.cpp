#include "sensoreCarico.h"
#include <iostream>

int SensoreCarico::currentid = 1;

SensoreCarico::SensoreCarico(int bufferSize) : Sensore(bufferSize) {
    this->pacchetti = std::vector<PacchettoCarico*>();
    this->id = "LS#"+SensoreCarico::currentid;
    this->name = "Load Sensor";
    SensoreCarico::currentid += 1;
}

void SensoreCarico::misura() {
    PacchettoCarico *p = new PacchettoCarico();
    this->pacchetti.push_back(p);
}

const std::vector<PacchettoCarico*>& SensoreCarico::getPacchetti() {
    return this->pacchetti;
}

//getId
std::string SensoreCarico::getId() {
    return this->id;
}
