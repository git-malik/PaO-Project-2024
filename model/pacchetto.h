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
    //operator==
    bool operator==(const Pacchetto &p);
    virtual long int getTime();
    virtual float getValore();
};

#endif
