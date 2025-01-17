#ifndef PACCHETTOCARICO_H
#define PACCHETTOCARICO_H

#include "pacchetto.h"

class PacchettoCarico : public Pacchetto {
    private:
        time_t timestamp;
        float valore;
    public:
        PacchettoCarico();
        float randomFloat() override;
        float getValore() const override;
        time_t getTime() const override;
};

#endif