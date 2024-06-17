#include "pacchetto.cpp"
#include "pacchettoBanda.cpp"
#include "pacchettoCarico.cpp"
#include "pacchettoErrori.cpp"
#include "sensore.cpp"
#include "sensoreBanda.cpp"
#include "sensoreCarico.cpp"
#include "sensoreErrori.cpp"
#include "connection.cpp"
#include "host.cpp"
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char const* argv[])
{
    srand(time(0));

    std::cout << "\tTest Sensore e misurazioni" << std::endl;

    SensoreBanda sensore1(10);
    SensoreCarico sensore2(20);
    SensoreErrori sensore3(30);
    //std::cout << sensore1.getId() << std::endl;
    // std::cout << sensore2.getId() << std::endl;
    // std::cout << sensore3.getId() << std::endl;

    for (int i = 0; i < 5; i++) {
        sensore1.misura();
        sensore2.misura();
        sensore3.misura();
    }

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

    std::cout << "\tTest Connection" << std::endl;

    Host *h1 = new Host();
    Host *h2 = new Host();

    Connection *c1 = new Connection("c1", *h1, *h2); // Pass the dereferenced pointers as arguments

    //print elements
    std::cout << (c1->getPeer1()).getName() << std::endl;
    std::cout << (c1->getPeer2()).getName() << std::endl;

    //add and print sensor
    c1->addSensore(sensore1);
    c1->addSensore(sensore2);
    c1->addSensore(sensore3);

    std::vector<Sensore*> sensori = c1->getSensori();
    
    for (int i = 0; i < sensori.size(); i++) {
        std::cout << sensori.at(i)->getId() << std::endl;
    }
/*  output
    S#
    S#
    S#
     */
    //questo non dovrebbe essere un errore perchè ho esplicitamente detto che il vettore contiene puntatori a Sensore
    std::cout << "\tTest Classes" << std::endl;
    Sensore *sensore11 = new SensoreCarico(10);
    sensore11->misura();
    sensore11->misura();
    sensore11->misura();
    sensore11->misura();


    if (SensoreCarico* sensoreCarico = dynamic_cast<SensoreCarico*>(sensore11)) {
        // Add data points from sensore.getPacchetti()
        std::cout<<"Carico"<<std::endl;
         std::vector<PacchettoCarico*> pacchetti = sensoreCarico->getPacchetti();
        for (PacchettoCarico* pacchetto : pacchetti) {
            std::cout << pacchetto->getValore() << std::endl;
        }
    } else if (SensoreBanda* sensoreBanda = dynamic_cast<SensoreBanda*>(sensore11)) {
        // Add data points from sensore.getPacchetti()
        std::cout<<"Banda"<<std::endl;
        std::vector<PacchettoBanda*> pacchetti = sensoreBanda->getPacchetti();
        for (PacchettoBanda* pacchetto : pacchetti) {
            std::cout << pacchetto->getValore() << std::endl;
        }
    } else if (SensoreErrori* sensoreErrori = dynamic_cast<SensoreErrori*>(sensore11)) {
        // Add data points from sensore.getPacchetti()
        std::vector<PacchettoErrori*> pacchetti = sensoreErrori->getPacchetti();
        for (PacchettoErrori* pacchetto : pacchetti) {
            std::cout << pacchetto->getValore() << std::endl;
        }
        std::cout<<"Errori"<<std::endl;
    }
    std::cout<<std::endl;

    std::cout << "\tTest Dates" << std::endl;
    SensoreCarico *sensore12 = new SensoreCarico(10);
    //misurazione ogni 60 millisecondi
    for (int i = 0; i < 5; i++) {

        std::this_thread::sleep_for(std::chrono::milliseconds(60));
        sensore12->misura();
    }
    for (PacchettoCarico* pacchetto : sensore12->getPacchetti()) {
        std::cout << pacchetto->getTime() << std::endl;
    }
    return 0;
}
