#include "Sensor.h"
#include <cstdlib>

Sensor::Sensor(string t) : tipo(t) {
    sensibilidad = rand() % 101;
}

string Sensor::getTipo() const { return tipo; }
int Sensor::getSensibilidad() const { return sensibilidad; }

void Sensor::mejorarSensibilidad(int mejora) {
    sensibilidad += mejora;
    if (sensibilidad > 100)
        sensibilidad = 100;
}