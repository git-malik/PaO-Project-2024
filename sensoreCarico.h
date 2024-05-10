#ifndef SENSORECARICO_H
#define SENSORECARICO_H

#include "sensore.h"
#include "pacchettoCarico.h"

class SensoreCarico : public Sensore{
    private:
        
        static int currentid;
        int id;
        std::vector<PacchettoCarico*> pacchetti;
        int bufferSize;
    public:
        SensoreCarico(int bufferSize);
        std::string getId();
        void misura();
};

#endif