#ifndef ABONO_H
#define ABONO_H

#include "Fecha.h"
class Abono {
    private:
        Fecha *fechaAbono;
        float montoAbono;
    public:
        Abono(Fecha*, float);
        virtual ~Abono();
        Fecha *getFechaAbono() const;
        float getMontoAbono() const;
};

#endif