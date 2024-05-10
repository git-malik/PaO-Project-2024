#include "sensoreErrori.h"
//#include "pacchettoErrori.cpp"
#include <stdlib.h>
#include <ctime>
#include <vector>

int SensoreErrori::currentid = 1;

SensoreErrori::SensoreErrori(int bufferSize) : Sensore(bufferSize) {
    this->id = SensoreErrori::currentid;
    SensoreErrori::currentid += 1;
}

void SensoreErrori::misura() {
    PacchettoErrori * p = new PacchettoErrori();
    this->pacchetti.push_back(p);
}

//getId
std::string SensoreErrori::getId() {
    // Return the concatenation of the string "SensoreErrori" and the id
    return "ES#" + std::to_string(this->id);
}