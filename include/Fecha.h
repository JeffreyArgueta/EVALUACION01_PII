#ifndef FECHA_H
#define FECHA_H

#include <iostream>

using namespace std;

class Fecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int, int, int);
        virtual ~Fecha();
        void mostrarFecha();
};

#endif