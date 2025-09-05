#pragma once
#include <string>
#include <iostream>
using namespace std;

class Robot {
protected:
    string nombre = " ";
    int bateria = 0;       
    int procesadores = 0;  
    int capacidadTotal = 0;

public:
    Robot(string , int , int );
    virtual ~Robot();
    int getCapacidad() const;

    virtual void optimizar();
    virtual void mostrarEspecificaciones();
};
