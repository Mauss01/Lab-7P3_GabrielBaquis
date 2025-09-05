#pragma once
#include "Robot.h"
#include "Sensor.h"

class RobotExplorador : public Robot {
    int alcanceTerreno = 0;
    vector<Sensor*> sensores;

public:
    RobotExplorador(string, int, int, int , int);
    ~RobotExplorador();
    void optimizar() override;
    void mostrarEspecificaciones()override;
    bool necesitaMantenimiento();
};