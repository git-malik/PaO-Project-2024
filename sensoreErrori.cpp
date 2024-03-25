#include "sensoreErrori.h"
#include <stdlib.h>
#include <ctime>
#include <vector>

SensoreErrori::SensoreErrori(char* id, int bufferSize) : Sensore(id, bufferSize) {}

void SensoreErrori::misura() {
    PacchettoErrori * p = new PacchettoErrori();
    this->pacchetti.push_back(p);
}
