#ifndef ABONO_H_INCLUDED
#define ABONO_H_INCLUDED

#include "Fecha.h"
class Abono {
    private:
        Fecha fechaAbono;
        float montoAbono;
    public:
        Abono(Fecha, float);
        virtual ~Abono();
        Fecha getFechaAbono();
        float getMontoAbono();
};

#endif