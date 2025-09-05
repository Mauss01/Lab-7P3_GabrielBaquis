#pragma once
#include "Robot.h"
#include "Sensor.h"
#include <vector>

class RobotExplorador : public Robot {
    int alcanceTerreno = 0;
    vector<Sensor*> sensores;

public:
    RobotExplorador(string, int, int, int alcance, vector<Sensor*> sensores);
    ~RobotExplorador();
    void optimizar() override;
    void mostrarEspecificaciones()override;
    bool necesitaMantenimiento();
};