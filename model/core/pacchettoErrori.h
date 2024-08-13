#ifndef PACCHETTOERRORI_H
#define PACCHETTOERRORI_H

#include "pacchetto.h"

class PacchettoErrori : public Pacchetto
{
private:
    time_t timestamp;
    float valore;
public:
    float randomFloat() override;
    PacchettoErrori(time_t timestamp, float valore);
    PacchettoErrori(float random);
    PacchettoErrori();
    float getValore() override;
    time_t getTime() override;
};
#endif
