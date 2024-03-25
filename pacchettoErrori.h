#ifndef PACCHETTOERRORI_H
#define PACCHETTOERRORI_H

#include "pacchetto.h"

class PacchettoErrori : public Pacchetto {
private:
    long int timestamp;
    float valore;
protected:
    virtual float randomFloat();
public:
    PacchettoErrori(long int timestamp, float valore);
    PacchettoErrori();
    float getValore();
    long int getTime();
    ~PacchettoErrori();
};

#endif