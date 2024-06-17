#ifndef SENSOREERRORI_H
#define SENSOREERRORI_H

#include "sensore.h"
#include "pacchettoErrori.h"

class SensoreErrori : public Sensore{
    private:
        static int currentid;
        std::string id;
        std::string name;
        std::vector<PacchettoErrori*> pacchetti;
        int bufferSize;
    public:
        SensoreErrori(int bufferSize);
        std::string getId();
        const std::vector<PacchettoErrori*>& getPacchetti();
        void misura();
};

#endif