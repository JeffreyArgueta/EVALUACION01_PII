#include "../include/Fecha.h"

Fecha::Fecha(int d = 0, int m = 0, int a = 0) : dia(d), mes(m), anio(a) {}

Fecha::~Fecha() {}

void Fecha::mostrarFecha() const {
    std::cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio;
}