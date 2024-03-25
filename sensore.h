#include <vector>
#include "pacchetto.h"

#ifndef SENSORE_H
#define SENSORE_H
class Sensore
{
private:
    char* id;
    std::vector<Pacchetto> pacchetti;
    int bufferSize;
public:
    Sensore(char* id, int bufferSize);
    char* getId();
    virtual int getBufferSize();
    virtual std::vector<Pacchetto> getPacchetti();
    virtual void misura() = 0;
    ~Sensore();
};

#endif