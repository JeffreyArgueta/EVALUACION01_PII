#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string.h>

using namespace std;

class Cliente {
    private:
        int idCliente;
        string nombre;
        string apellido;
    public:
        Cliente(int, string, string);
        virtual ~Cliente();
        int getIdCliente();
        string getNombre();
        string getApellido();
};

#endif