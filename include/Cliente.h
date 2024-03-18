#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

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