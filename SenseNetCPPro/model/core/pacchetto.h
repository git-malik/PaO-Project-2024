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
    virtual float randomFloat() = 0;
    Pacchetto();
    //operator==
    virtual bool operator==(const Pacchetto &p);
    virtual time_t getTime() const;
    virtual float getValore() const;
    virtual ~Pacchetto() = default;
};

#endif
