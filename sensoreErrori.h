#ifndef SENSOREERRORI_H
#define SENSOREERRORI_H

#include "sensore.h"
#include "pacchettoErrori.h"

class SensoreErrori : public Sensore{
    private:
        static int currentid;
        int id;
        std::vector<PacchettoErrori*> pacchetti;
        int bufferSize;
    public:
        SensoreErrori(int bufferSize);
        std::string getId();
        void misura();
};

#endif