#include "sensoreCarico.h"
//

SensoreCarico::SensoreCarico(char* id, int bufferSize) : Sensore(id, bufferSize) {}

void SensoreCarico::misura() {
    PacchettoCarico * p = new PacchettoCarico();
    this->pacchetti.push_back(p);
}

SensoreCarico::~SensoreCarico() {
    delete this;
}