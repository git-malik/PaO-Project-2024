#include "sensoreBanda.h"

SensoreBanda::SensoreBanda(char* id, int bufferSize) : Sensore(id, bufferSize) {}

void SensoreBanda::misura() {
    PacchettoBanda * p = new PacchettoBanda();
    this->pacchetti.push_back(p);
}

SensoreBanda::~SensoreBanda() {
    delete this;
}