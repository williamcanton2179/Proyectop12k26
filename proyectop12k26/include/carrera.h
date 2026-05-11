#ifndef CARRERA_H
#define CARRERA_H        //Creado por David Alegria 9959-23-11277

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
using namespace std;

class Carrera
{
    private:
        string codigoCarrera;
        string nombreCarrera;
        bool estadoCarrera;

    public:
        Carrera();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void buscar();
        void borrar();
};

#endif // CARRERA_H
