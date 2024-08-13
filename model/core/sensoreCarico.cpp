#include "sensoreCarico.h"
#include <iostream>

int SensoreCarico::currentid = 1;

SensoreCarico::SensoreCarico(std::string name) : Sensore(name) {
    this->pacchetti = std::vector<PacchettoCarico*>();
    this->id = "LS#"+std::to_string(SensoreCarico::currentid);
    this->name = name;
    SensoreCarico::currentid += 1;
}

SensoreCarico::SensoreCarico() : Sensore() {
    this->pacchetti = std::vector<PacchettoCarico*>();
    this->id = "LS#"+std::to_string(SensoreCarico::currentid);
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

//getName
std::string SensoreCarico::getName() {
    return this->name;
}

//setName
void SensoreCarico::setName(const std::string& newName) {
    this->name = newName;
}
