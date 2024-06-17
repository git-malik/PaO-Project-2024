#include "pacchettoBanda.h"
#include <ctime>
#include <iostream>

PacchettoBanda::PacchettoBanda(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoBanda::PacchettoBanda() : Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
};
long int PacchettoBanda::getTime() {
    return this->timestamp;
}

float PacchettoBanda::getValore() {
    return this->valore;
}
