#include "../include/Cuenta.h"

Cuenta::Cuenta() : cliente(Cliente(0,"","")) {}

Cuenta::Cuenta(int nc, Cliente c) : numeroCuenta(nc), cliente(c), saldo(0), contadorAbonos(0) {}

Cuenta::~Cuenta() {}

int Cuenta::getNumeroCuenta() const {
    return this->numeroCuenta;
}

void Cuenta::setNumeroCuenta(int snc) {
    this->numeroCuenta = snc;
}

Cliente Cuenta::getCliente() {
    return this->cliente;
}

void Cuenta::setCliente(Cliente sc) {
    this->cliente = sc;
}

bool Cuenta::agregarAbono(Abono *ab) {
    if (ab != nullptr) {
        this->lstAbonos[this->contadorAbonos] = ab;
        this->saldo += ab->getMontoAbono();
        this->contadorAbonos++;
        return true;
    }
    return false;
}

Abono *const *Cuenta::getLstAbonos() const {
    return this->lstAbonos;
}

float Cuenta::getSaldo() const {
    return this->saldo;
}

int Cuenta::getContadorAbonos() const {
    return this->contadorAbonos;
}