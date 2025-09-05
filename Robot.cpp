#include "Robot.h"
Robot::Robot(string n, int b, int p)
    : nombre(n), bateria(b), procesadores(p) {
    capacidadTotal = bateria * procesadores;
}

Robot::~Robot() {}

int Robot::getCapacidad() {
    return capacidadTotal;
}

string Robot::getNombre() {
    return nombre;
}

void Robot::optimizar() {}
void Robot::mostrarEspecificaciones() {}