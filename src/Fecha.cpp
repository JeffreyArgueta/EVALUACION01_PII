#include "Fecha.h"

Fecha::Fecha(int d = 0, int m = 0, int a = 0){
    this->dia = d;
    this->mes = m;
    this->anio = a;
}

Fecha::~Fecha() {}

void Fecha::mostrarFecha() {
    cout<<this->dia<<"/"<<this->mes<<"/"<<this->anio;
}