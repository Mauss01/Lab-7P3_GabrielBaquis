#include "Sensor.h"
#include <cstdlib>
#include <ctime>

Sensor::~Sensor(){}

Sensor::Sensor(string t) : tipo(t) {
    srand(time(0));
    sensibilidad = rand() % 100;
}

string Sensor::getTipo()  { 
    return tipo; 
}
int Sensor::getSensibilidad()  { 
    return sensibilidad; 
}

void Sensor::mejorarSensibilidad(int mejora) {
    sensibilidad += mejora;
    if (sensibilidad > 100) {
        sensibilidad = 100;
    }
}