#pragma once
#include <string>
using namespace std;

class Sensor {
    string tipo = " ";
    int sensibilidad = 0; 

public:
    Sensor(string tipo);
    string getTipo() const;
    int getSensibilidad() const;
    void mejorarSensibilidad(int mejora);
};