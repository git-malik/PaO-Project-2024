#include "pacchettoJitter.h"

PacchettoJitter::PacchettoJitter(): Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
}

float PacchettoJitter::randomFloat()
{
    return (float)((rand()) % 50); 
}

time_t PacchettoJitter::getTime() const {
    return this->timestamp;
}

float PacchettoJitter::getValore() const {
    return this->valore;
}
