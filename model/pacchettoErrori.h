#ifndef PACCHETTOERRORI_H
#define PACCHETTOERRORI_H

#include "pacchetto.h"

class PacchettoErrori : public Pacchetto
{
private:
    long int timestamp;
    float valore;
public:
    float randomFloat() override;
    PacchettoErrori(long int timestamp, float valore);
    PacchettoErrori(float random);
    PacchettoErrori();
    float getValore();
    long int getTime();
};
#endif