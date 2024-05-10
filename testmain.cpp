#include <iostream>
#include "sensore.cpp"
#include "pacchetto.cpp"
#include "sensoreBanda.cpp"
#include "pacchettoBanda.cpp"
#include "sensoreCarico.cpp"
#include "pacchettoCarico.cpp"
#include "sensoreErrori.cpp"
#include "pacchettoErrori.cpp"

int main(int argc, char const *argv[])
{
    SensoreBanda sensore1(10);
    SensoreBanda sensore4(10);
    SensoreCarico sensore2(20);
    SensoreErrori sensore3(30);
    std::cout << sensore1.getId() << std::endl;
    std::cout << sensore2.getId() << std::endl;
    std::cout << sensore3.getId() << std::endl;
    std::cout << sensore4.getId() << std::endl;

    sensore1.misura();
    sensore1.misura();
    sensore1.misura();
    sensore1.misura();
    sensore2.misura();
    sensore3.misura();
    //print pacchetti siz
    std::cout << sensore1.getPacchetti().size() << std::endl;
    for (int i = 0; i < sensore1.getPacchetti().size(); i++) // Check if i is within bounds
    {
        Pacchetto *p = (Pacchetto *)sensore1.getPacchetti()[i];
        std::cout << p->getValore() << std::endl;
    }
    
    
    return 0;
}
