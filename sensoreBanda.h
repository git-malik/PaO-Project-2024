#ifndef SENSOREBanda_H
#define SENSOREBanda_H

#include "sensore.h"
#include "pacchettoBanda.h"

class SensoreBanda : public Sensore{
    private:
        char* id;
        std::vector<PacchettoBanda*> pacchetti;
        int bufferSize;
    public:
        SensoreBanda(char* id, int bufferSize);
        void misura();
        ~SensoreBanda();
};

#endif