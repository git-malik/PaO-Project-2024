#ifndef PACCHETTOERRORI_H
#define PACCHETTOERRORI_H

#include "pacchetto.h"

class PacchettoErrori : public Pacchetto
{
private:
    time_t timestamp;
    float valore;
public:
    PacchettoErrori();
    float randomFloat() override;
    float getValore() const override;
    time_t getTime() const override;
};
#endif
