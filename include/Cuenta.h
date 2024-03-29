#ifndef CUENTA_H
#define CUENTA_H

#include "Cliente.h"
#include "Abono.h"
#define DA 5

class Cuenta {
    private:
        int numeroCuenta;
        Cliente cliente;
        Abono *lstAbonos[DA];
        float saldo;
        int contadorAbonos;
    public:
        Cuenta();
        Cuenta(int, Cliente);
        virtual ~Cuenta();
        int getNumeroCuenta() const;
        void setNumeroCuenta(int);
        Cliente getCliente();
        void setCliente(Cliente);
        bool agregarAbono(Abono*);
        Abono *const *getLstAbonos() const;
        float getSaldo() const;
        int getContadorAbonos() const;
};

#endif