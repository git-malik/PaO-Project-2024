#include <vector>
#include <algorithm>
#include "pacchetto.h"
#include <string>

#ifndef SENSORE_H
#define SENSORE_H
class Sensore
{
    private:
        static int id;
        //char* id;
        int bufferSize;
    public:
        Sensore(int bufferSize);
        virtual std::string getId() = 0;
        virtual int getBufferSize();
        std::vector<Pacchetto*> getPacchetti();
        virtual void misura() = 0;
};

#endif