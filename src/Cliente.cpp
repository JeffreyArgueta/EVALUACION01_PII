#include "../include/Cliente.h"

Cliente::Cliente(int id = 0, std::string n = "", std::string a = "") : idCliente(id), nombre(n), apellido(a) {}

Cliente::~Cliente() {}

int Cliente::getIdCliente() const {
    return this->idCliente;
}

std::string Cliente::getNombre() const {
    return this->nombre;
}

std::string Cliente::getApellido() const {
    return this->apellido;
}