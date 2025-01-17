#include "pacchettoBanda.h"

PacchettoBanda::PacchettoBanda() : Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
};

float PacchettoBanda::randomFloat()
{
    return 1 + (float)(rand()) / ((float)(RAND_MAX / (1000 - 1)));
}

time_t PacchettoBanda::getTime() const {
    return this->timestamp;
}

float PacchettoBanda::getValore() const {
    return this->valore;
}

