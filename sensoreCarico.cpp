#include "sensoreCarico.h"
//

int SensoreCarico::currentid = 1;

SensoreCarico::SensoreCarico(int bufferSize) : Sensore(bufferSize) {
    this->id = SensoreCarico::currentid;
    SensoreCarico::currentid += 1;
}

void SensoreCarico::misura() {
    PacchettoCarico * p = new PacchettoCarico();
    this->pacchetti.push_back(p);
}

//getId
std::string SensoreCarico::getId() {
    // Return the concatenation of the string "SensoreCarico" and the id
    return "LS#" + std::to_string(this->id);
}

//getPacchetti
std::vector<PacchettoCarico*> SensoreCarico::getPacchetti() {
    return this->pacchetti;
}