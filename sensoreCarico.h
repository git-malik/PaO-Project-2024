#ifndef SENSOREERRORI_H
#define SENSOREERRORI_H

#include "sensore.h"
#include "pacchettoCarico.h"

class SensoreCarico : public Sensore{
    private:
        char* id;
        std::vector<PacchettoCarico*> pacchetti;
        int bufferSize;
    public:
        SensoreCarico(char* id, int bufferSize);
        void misura();
        ~SensoreCarico();
};

#endif