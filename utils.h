#pragma once
#include <vector>
template<typename T>
float calcularPromedio(const vector<T>& datos) {
    if (datos.empty()) return 0;
    T suma = 0;
    for (T d : datos) suma += d;
    return float(suma) / datos.size();
}