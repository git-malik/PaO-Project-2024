#include "pacchettoBanda.h"
#include <ctime>
#include <random>
#include <iostream>

PacchettoBanda::PacchettoBanda(long int timestamp, float valore) : Pacchetto(timestamp, valore){};

PacchettoBanda::PacchettoBanda() : Pacchetto() {};