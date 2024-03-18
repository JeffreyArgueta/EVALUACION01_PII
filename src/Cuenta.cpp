#include "../include/Cuenta.h"
#define DA 5

Cuenta::Cuenta() : cliente(Cliente(0,"","")) {
    this->numeroCuenta = 0;
    this->saldo = 0;
    this->contadorAbonos = 0;
}

Cuenta::Cuenta(int nc, Cliente c) : cliente(c) {
    this->numeroCuenta = nc;
    this->cliente = c;
    this->contadorAbonos = 0;
}

Cuenta::~Cuenta() {}

int Cuenta::getNumeroCuenta() {
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
    if (this->contadorAbonos < DA) {
        this->lstAbonos[this->contadorAbonos] = ab;
        this->saldo += ab->getMontoAbono();
        this->contadorAbonos++;
        return true;
    }
    return false;
}

Abono **Cuenta::getLstAbonos() {
    return this->lstAbonos;
}

float Cuenta::getSaldo() {
    return this->saldo;
}

int Cuenta::getContadorAbonos() {
    return this->contadorAbonos;
}