#ifndef PACCHETTOBANDA_H
#define PACCHETTOBANDA_H

#include "pacchetto.h"

class PacchettoBanda : public Pacchetto {
private:
    time_t timestamp;
    float valore;
public:
    PacchettoBanda(time_t timestamp, float valore);
    PacchettoBanda();
    float getValore();
    time_t getTime();
};

#endif