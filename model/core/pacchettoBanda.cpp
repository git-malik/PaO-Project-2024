#include "pacchettoBanda.h"

PacchettoBanda::PacchettoBanda(time_t timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoBanda::PacchettoBanda() : Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
};
time_t PacchettoBanda::getTime() {
    return this->timestamp;
}

float PacchettoBanda::getValore() {
    return this->valore;
}
