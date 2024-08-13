#include "./pacchetto.h"

time_t Pacchetto::currenttime = time(0);

Pacchetto::Pacchetto(){
    //generate timestamp between current time and current time - 1 minute
    this->timestamp = Pacchetto::currenttime; // initialize timestamp
    Pacchetto::currenttime = Pacchetto::currenttime + 60; // decrement timestamp by 60 seconds
    this->valore = Pacchetto::randomFloat();
}

float Pacchetto::randomFloat()
{
    return 1 + (float)(rand()) / ((float)(RAND_MAX / (100 - 1)));
}

Pacchetto::Pacchetto(time_t timestamp, float valore){
    this->timestamp = timestamp;
    this->valore = valore;
}

Pacchetto::Pacchetto(const Pacchetto &p){
    this->timestamp = p.timestamp;
    this->valore = p.valore;
}

//operator==
bool Pacchetto::operator==(const Pacchetto &p){
    return this->timestamp == p.timestamp && this->valore == p.valore;
}

time_t Pacchetto::getTime() {
    return this->timestamp;
}

float Pacchetto::getValore() {
    return this->valore;
}
