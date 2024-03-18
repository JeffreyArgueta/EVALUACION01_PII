#include "Cliente.h"

Cliente::Cliente(int id = 0, string n = "", string a = "") {
    this->idCliente = id;
    this->nombre = n;
    this->apellido = a;
}

Cliente::~Cliente() {}

int Cliente::getIdCliente() {
    return this->idCliente;
}

string Cliente::getNombre() {
    return this->nombre;
}

string Cliente::getApellido() {
    return this->apellido;
}