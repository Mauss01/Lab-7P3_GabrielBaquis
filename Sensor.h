#pragma once
#include <string>
using namespace std;

class Sensor {
    string tipo = " ";
    int sensibilidad = 0; 

public:
    Sensor(string );
    ~Sensor();
    string getTipo();
    int getSensibilidad();
    void mejorarSensibilidad(int mejora);
};