#ifndef SENSOREERRORI_H
#define SENSOREERRORI_H

#include "sensore.h"
#include "pacchettoErrori.h"

class SensoreErrori : public Sensore{
    private:
        char* id;
        std::vector<PacchettoErrori*> pacchetti;
        int bufferSize;
    public:
        SensoreErrori(char* id, int bufferSize);
        void misura();
        ~SensoreErrori();
};

#endif