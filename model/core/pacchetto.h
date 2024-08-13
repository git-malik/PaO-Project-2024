#ifndef PACCHETTO_H
#define PACCHETTO_H

#include <random>
#include <ctime>
#include <iostream>

class Pacchetto
{
private:
    static time_t currenttime;
    time_t timestamp;
    float valore;
public:
    virtual float randomFloat();
    Pacchetto(time_t timestamp, float valore);
    Pacchetto();
    Pacchetto(const Pacchetto &p);
    //operator==
    bool operator==(const Pacchetto &p);
    virtual time_t getTime();
    virtual float getValore();
};

#endif
