#include "../include/Abono.h"

Abono::Abono(Fecha *fa, float ma = 0) : fechaAbono(fa), montoAbono(ma) {}

Abono::~Abono() {}

Fecha *Abono::getFechaAbono() const {
    return this->fechaAbono;
}

float Abono::getMontoAbono() const {
    return this->montoAbono;
}