#ifndef PACCHETTO_H
#define PACCHETTO_H
class Pacchetto
{
private:
    long int timestamp;
    float valore;
protected:
    virtual float randomFloat();
public:
    Pacchetto(long int timestamp, float valore);
    Pacchetto();
    //copy constructor
    Pacchetto(const Pacchetto &p);
    virtual long int getTime();
    virtual float getValore();
    virtual ~Pacchetto();
};

#endif
