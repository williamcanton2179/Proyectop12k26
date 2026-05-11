#ifndef MODULOPAGOS_H_INCLUDED
#define MODULOPAGOS_H_INCLUDED
#include "validacionpagos0.h"

class ModuloPagos {
public:
    void ejecutar();

private:
    validacionpagos0 motorPagos;
};


#endif // MODULOPAGOS_H_INCLUDED
