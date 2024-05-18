#include "pacchettoBanda.h"
#include <ctime>
#include <iostream>

PacchettoBanda::PacchettoBanda(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoBanda::PacchettoBanda() : Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
};
long int PacchettoBanda::getTime() {
    //call parent function getTime
    return Pacchetto::getTime();
}

float PacchettoBanda::getValore() {
    //call parent function getValore
    return Pacchetto::getValore();
}
