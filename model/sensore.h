#include <vector>
#include <algorithm>
#include "pacchetto.h"
#include "pacchettoBanda.h"
#include <string>

#ifndef SENSORE_H
#define SENSORE_H
class Sensore
{
    private:
        static int id;
        std::string currentid;
        std::string name;
        std::vector<Pacchetto*> pacchetti;
        int bufferSize;
    public:
        Sensore(int bufferSize);
        virtual std::string getId() = 0;
        virtual std::string getName();
        virtual int getBufferSize();
        const std::vector<Pacchetto*>& getPacchetti();
        virtual void misura() = 0;
        Sensore& operator=(const Sensore& other);
        //operator==
        bool operator==(const Sensore& sensore) const;
};

#endif