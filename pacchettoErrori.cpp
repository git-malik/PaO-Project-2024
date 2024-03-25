#include "pacchettoErrori.h"
#include <ctime>
#include <random>
#include <iostream>

float PacchettoErrori::randomFloat()
{
    return 1+ (float)(rand()) + 99; 
}

PacchettoErrori::PacchettoErrori(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoErrori::PacchettoErrori(): Pacchetto() {}