#ifndef PACCHETTODELAY_H
#define PACCHETTODELAY_H

#include "pacchetto.h"

class PacchettoDelay : public Pacchetto
{
private:
    time_t timestamp;
    float valore;
public:
    PacchettoDelay();
    float randomFloat() override;
    float getValore() const override;
    time_t getTime() const override;
};
#endif
