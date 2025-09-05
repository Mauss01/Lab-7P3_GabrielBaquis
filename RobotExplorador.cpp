#include "RobotExplorador.h"
#include <iostream>
#include <map>
#include <cstdlib>

RobotExplorador::RobotExplorador(string n, int b, int p, int alcance, vector<Sensor*> s)
    : Robot(n, b, p), alcanceTerreno(alcance), sensores(s) {
}

RobotExplorador::~RobotExplorador() {
    for (auto s : sensores) delete s;
}

void RobotExplorador::optimizar() {
    alcanceTerreno += rand() % 31;
    for (auto s : sensores)
        s->mejorarSensibilidad(5 + rand() % 16);

    if (rand() % 10 == 0 && sensores.size() > 1) {
        int idx = rand() % sensores.size();
        delete sensores[idx];
        sensores.erase(sensores.begin() + idx);
    }
}

void RobotExplorador::mostrarEspecificaciones()  {
    vector<int> sensibilidades;
    map<string, int> contador;
    for (auto s : sensores) {
        sensibilidades.push_back(s->getSensibilidad());
        contador[s->getTipo()]++;
    }

    string masComun;
    int max = 0;
    for (auto& par : contador) {
        if (par.second > max) {
            masComun = par.first;
            max = par.second;
        }
    }

    //float promedio = calcularPromedio(sensibilidades);

    cout << "[Explorador] " << nombre
        << " | Capacidad: " << capacidadTotal
        << " | Alcance: " << alcanceTerreno << " km"
        << " | Promedio Sensibilidad: " << promedio
        << " | Sensor más común: " << masComun << endl;
}

bool RobotExplorador::necesitaMantenimiento()  {
    int criticos = 0;
    for (auto s : sensores) {
        if (s->getSensibilidad() < 30)
            criticos++;
    }
    return criticos >= 2;
}
