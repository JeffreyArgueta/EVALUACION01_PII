#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

class Cliente {
    private:
        int idCliente;
        std::string nombre;
        std::string apellido;
    public:
        Cliente(int, std::string, std::string);
        virtual ~Cliente();
        int getIdCliente() const;
        std::string getNombre() const;
        std::string getApellido() const;
};

#endif