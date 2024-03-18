#include "../include/Abono.h"

Abono::Abono(Fecha fa = Fecha(0,0,0), float ma = 0.00) : fechaAbono(fa) {
    this->fechaAbono = fa;
    this->montoAbono = ma;
}

Abono::~Abono() {}

Fecha Abono::getFechaAbono() {
    return this->fechaAbono;
}

float Abono::getMontoAbono() {
    return this->montoAbono;
}