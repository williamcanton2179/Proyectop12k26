#ifndef GENERADORCONSTANCIAS_H
#define GENERADORCONSTANCIAS_H

#include <iostream>
#include <string>

using namespace std;

class GeneradorConstancias {
private:
    string nombre;
    string carnet;
    float monto;
    int estado;
    int tipoPersona;

    void imprimirEncabezadoBanco();
    void constanciaAlumno();
    void constanciaDocente();

public:
    GeneradorConstancias();
    ~GeneradorConstancias();

    void setNombre(string n);
    void setCarnet(string c);
    void setMonto(float m);
    void setEstado(int e);
    void setTipoPersona(int t);

    string getNombre();
    string getCarnet();
    float getMonto();
    int getTipoPersona();
    string getTextoEstado();

    void entregarConstancia();
    bool validarConstancia(int numeroBoleta);
};

#endif
