#ifndef PACCHETTOCARICO_H
#define PACCHETTOCARICO_H

#include "pacchetto.h"

class PacchettoCarico : public Pacchetto {
    private:
        long int timestamp;
        float valore;
    public:
        PacchettoCarico(long int timestamp, float valore);
        PacchettoCarico();
        float getValore();
        long int getTime();
};

#endif