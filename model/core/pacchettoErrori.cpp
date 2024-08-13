#include "pacchettoErrori.h"

PacchettoErrori::PacchettoErrori(time_t timestamp, float valore) : Pacchetto(timestamp, valore), timestamp(timestamp), valore(valore){};

PacchettoErrori::PacchettoErrori(): Pacchetto() {
    this->timestamp = Pacchetto::getTime();
    this->valore = randomFloat();
}

PacchettoErrori::PacchettoErrori(float random): Pacchetto(){
    this->timestamp = Pacchetto::getTime();
    this->valore = random;
}

float PacchettoErrori::randomFloat()
{
    return (float)((rand()) % 99); 
}

time_t PacchettoErrori::getTime() {
    return this->timestamp;
}

float PacchettoErrori::getValore() {
    return this->valore;
}
