#ifndef PACCHETTOCARICO_H
#define PACCHETTOCARICO_H

#include "pacchetto.h"

class PacchettoCarico : public Pacchetto {
    private:
        time_t timestamp;
        float valore;
    public:
        PacchettoCarico(time_t timestamp, float valore);
        PacchettoCarico();
        float getValore();
        time_t getTime();
};

#endif