#ifndef PACCHETTOBANDA_H
#define PACCHETTOBANDA_H

#include "pacchetto.h"

class PacchettoBanda : public Pacchetto {
private:
    time_t timestamp;
    float valore;
public:
    PacchettoBanda();
    float randomFloat() override;
    float getValore() const override;
    time_t getTime() const override;
};

#endif