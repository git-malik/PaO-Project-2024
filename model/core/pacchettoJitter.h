#ifndef PACCHETTOJITTER_H
#define PACCHETTOJITTER_H

#include "pacchetto.h"

class PacchettoJitter : public Pacchetto
{
private:
    time_t timestamp;
    float valore;
public:
    PacchettoJitter();
    float randomFloat();
    float getValore() const override;
    time_t getTime() const override;
};
#endif