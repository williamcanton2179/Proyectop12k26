#ifndef GENERADORCONSTANCIAS_H
#define GENERADORCONSTANCIAS_H

#include <iostream>
#include <string>

using namespace std;

class GeneradorConstancias {
    public:
        GeneradorConstancias();
        virtual ~GeneradorConstancias();


        void setNombre(string n);
        void setMonto(float m);
        void setTipoPersona(int t);

        string getNombre();
        float getMonto();
        int getTipoPersona();

        void entregarConstancia();

    private:
        string nombre;
        float monto;
        int tipoPersona;

        void imprimirEncabezadoBanco();
        void constanciaAlumno();
        void constanciaDocente();
        void constanciaEmpleado();
};

#endif
