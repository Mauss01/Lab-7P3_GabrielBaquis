#include "RobotMecanico.h"
RobotMecanico::RobotMecanico(string n, int b, int p, int potencia, int cant)
    : Robot(n, b, p), potenciaHerramientas(potencia) {

    string herramienta = " ";
    for (int i = 0; i < cant; i++) {
        cout << "Herramienta " << "#" << i + 1 << ": "; cin.ignore(); getline(cin, herramienta);
        herramientas.push_back(herramienta);
    }
}

RobotMecanico::~RobotMecanico() {}


void RobotMecanico::optimizar() {
    potenciaHerramientas = min(100, int(potenciaHerramientas * 1.1));
    if (herramientas.size() < 5)
        herramientas.push_back("Nueva");

    if (rand() % 10 == 0 && !herramientas.empty()) {
        herramientas.erase(herramientas.begin() + (rand() % herramientas.size()));
    }
}

void RobotMecanico::mostrarEspecificaciones()  {
    vector<int> longitudes;
    for (auto& h : herramientas) {
        longitudes.push_back(h.length());
    }

    float promedio = calcularPromedio(longitudes);

    cout << "[Mecanico] " << nombre
        << " | Capacidad: " << capacidadTotal
        << " | Potencia: " << potenciaHerramientas
        << " | Herramientas: " << herramientas.size()
        << " | Prom. Longitud herramienta: " << promedio << endl;
}

bool RobotMecanico::sobrecargado()  {
    return potenciaHerramientas > 90 && herramientas.size() > 3;
}