#include "pacchettoCarico.h"
#include <ctime>
#include <random>
#include <iostream>

PacchettoCarico::PacchettoCarico(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoCarico::PacchettoCarico() : Pacchetto(){};