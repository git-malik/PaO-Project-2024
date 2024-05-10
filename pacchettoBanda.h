#ifndef PACCHETTOBANDA_H
#define PACCHETTOBANDA_H

#include "pacchetto.h"

class PacchettoBanda : public Pacchetto {
private:
    long int timestamp;
    float valore;
protected:
    virtual float randomFloat();
public:
    PacchettoBanda(long int timestamp, float valore);
    PacchettoBanda();
    float getValore();
    long int getTime();
};

#endif