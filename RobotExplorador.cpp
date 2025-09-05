#include "RobotExplorador.h"
#include <map>
#include "utils.h"
#include "Sensor.h"

RobotExplorador::RobotExplorador(string n, int b, int p, int alcance, int cant)
    : Robot(n, b, p), alcanceTerreno(alcance) {

    Sensor* nuevoSen;
    string tipo = " ";

    // Creando cada nuevo Sensor
    for (int i = 0; i < cant; i++) {
        cout << "Tipo sensor: "; cin >> tipo;
        nuevoSen = new Sensor(tipo);
        sensores.push_back(nuevoSen);
    }
}

RobotExplorador::~RobotExplorador() {
    for (auto s : sensores) { 
        delete s; 
    }
}

void RobotExplorador::optimizar() {
    srand(time(0));
    int tempCalc = 0;
    if ((alcanceTerreno += rand() % 30) > 100) {
        tempCalc = 100 - alcanceTerreno; // En caso se supere el limite
        alcanceTerreno += tempCalc;

    }else {
        alcanceTerreno += rand() % 30;
    }

    for (auto s : sensores) {
        s->mejorarSensibilidad(5 + rand() % 15); // Mejora de sinsibilidad
    }

    if (rand() % 10 == 0 && sensores.size() > 1) {
        int pos = rand() % sensores.size();
        delete sensores[pos];
        sensores.erase(sensores.begin() + pos);
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

    float promedio = calcularPromedio(sensibilidades);

    cout << "[Explorador] " << nombre
        << " | Capacidad: " << capacidadTotal
        << " | Alcance: " << alcanceTerreno << " km"
        << " | Promedio Sensibilidad: " << promedio
        << " | Sensor mas comun: " << masComun << endl;
}

bool RobotExplorador::necesitaMantenimiento()  {
    int criticos = 0;
    for (auto s : sensores) {
        if (s->getSensibilidad() < 30) {
            criticos++;
        }
    }
    return criticos >= 2;
}
