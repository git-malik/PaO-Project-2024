#ifndef PACCHETTO_H
#define PACCHETTO_H
class Pacchetto
{
private:
    long int timestamp;
    float valore;
public:
    virtual float randomFloat();
    Pacchetto(long int timestamp, float valore);
    Pacchetto();
    Pacchetto(const Pacchetto &p);
    long int getTime();
    float getValore();
};

#endif
