#include "pacchettoErrori.h"

PacchettoErrori::PacchettoErrori(): Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
}

float PacchettoErrori::randomFloat()
{
    return (float)((rand()) % 499); 
}

time_t PacchettoErrori::getTime() const {
    return this->timestamp;
}

float PacchettoErrori::getValore() const {
    return this->valore;
}

