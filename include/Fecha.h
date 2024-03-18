#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

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