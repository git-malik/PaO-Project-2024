#include "pacchetto.cpp"
#include "pacchettoBanda.cpp"
#include "pacchettoCarico.cpp"
#include "pacchettoErrori.cpp"
#include "sensore.cpp"
#include "sensoreBanda.cpp"
#include "sensoreCarico.cpp"
#include "sensoreErrori.cpp"
#include <iostream>

int main(int argc, char const* argv[])
{
    srand(time(0));

    SensoreBanda sensore1(10);
    SensoreCarico sensore2(20);
    SensoreErrori sensore3(30);
    std::cout << sensore1.getId() << std::endl;
    std::cout << sensore2.getId() << std::endl;
    std::cout << sensore3.getId() << std::endl;

    for (int i = 0; i < 5; i++) {
        sensore1.misura();
        sensore2.misura();
        sensore3.misura();
    }

    // PacchettoBanda *p = new PacchettoBanda();
    // sensore1.getPacchetti().push_back(p);
    // sensore2.misura();
    // sensore3.misura();
    // print pacchetti siz
    std::cout << "Banda" << std::endl;
    std::vector<PacchettoBanda*> pacchetti = sensore1.getPacchetti();
    //print elements
    for (int i = 0; i < pacchetti.size(); i++) {
        std::cout << pacchetti[i]->getValore() << std::endl;
    }

    std::cout << "Carico" << std::endl;
    std::vector<PacchettoCarico*> pacchetti2 = sensore2.getPacchetti();
    //print elements
    for (int i = 0; i < pacchetti2.size(); i++) {
        std::cout << pacchetti2[i]->getValore() << std::endl;
    }

    std::cout << "Errori" << std::endl;
    std::vector<PacchettoErrori*> pacchetti3 = sensore3.getPacchetti();
    //print elements
    for (int i = 0; i < pacchetti3.size(); i++) {
        std::cout << ((PacchettoErrori*)pacchetti3[i])->getValore() << std::endl;
    }
    return 0;
}
