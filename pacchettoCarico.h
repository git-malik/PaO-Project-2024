#ifndef PACCHETTOCARICO_H
#define PACCHETTOCARICO_H

#include "pacchetto.h"

class PacchettoCarico : public Pacchetto {
    private:
        long int timestamp;
        float valore;
    protected:
        virtual float randomFloat();
    public:
        PacchettoCarico(long int timestamp, float valore);
        PacchettoCarico();
        float getValore();
        long int getTime();
};

#endif