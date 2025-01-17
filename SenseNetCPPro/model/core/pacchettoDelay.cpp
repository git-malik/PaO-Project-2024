#include "pacchettoDelay.h"


PacchettoDelay::PacchettoDelay(): Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
}

float PacchettoDelay::randomFloat()
{
    return (float)((rand()) % 1000); 
}

time_t PacchettoDelay::getTime() const {
    return this->timestamp;
}

float PacchettoDelay::getValore() const {
    return this->valore;
}

