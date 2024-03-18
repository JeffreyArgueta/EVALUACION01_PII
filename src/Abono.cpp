#include "Abono.h"

Abono::Abono(Fecha fa = Fecha(fa), float ma = 0.00) {
    this->fechaAbono = fa;
    this->montoAbono = ma;
}

Abono::~Abono() {}

Fecha Abono::getFechaAbono() {
    return this->fechaAbono;
}

float Abono::getMontoAbono() {
    return this->getMontoAbono;
}