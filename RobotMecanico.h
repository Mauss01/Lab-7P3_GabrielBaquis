#pragma once
#include "Robot.h"
#include "utils.h"

class RobotMecanico : public Robot {
    int potenciaHerramientas = 0;
    vector<string> herramientas;

public:
    RobotMecanico(string, int, int, int, int);
    ~RobotMecanico();
    void optimizar() override;
    void mostrarEspecificaciones()override;
    bool sobrecargado();    
};