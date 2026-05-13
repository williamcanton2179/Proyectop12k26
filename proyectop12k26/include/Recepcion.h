#ifndef RECEPCION_H
#define RECEPCION_H

#include <iostream>
#include <string>
#include "Alumnos.h"
#include "Maestros.h"

using namespace std;

class Recepcion
{
    private:
        string name, carnet, codigo, monto;

    public:

        void validarAlumno(Alumnos alumno);


        void validarMaestro(Maestros maestro);

        //crud
        void menu();
        void insertarpagosAlumnos();
        void desplegarpagosAlumnos();
        void modificarpagosAlumnos();
        void buscarpagosAlumnos();
        void borrarpagosAlumnos();
        void insertarpagosDocentes();
        void desplegarpagosDocentes();
        void modificarpagosDocentes();
        void buscarpagosDocentes();
        void borrarpagosDocentes();

};

#endif
