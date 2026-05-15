#ifndef GENERADORCONSTANCIAS_H
#define GENERADORCONSTANCIAS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class GeneradorConstancias {
private:
    string id, nombre, carnet;
    float monto;
    int tipoPersona;

    // Funciones auxiliares de diseño
    void imprimirEncabezadoBanco();
    void disenoConstanciaListado();
    bool idExiste(string searchId); // <-- Nueva función de validación

public:
    GeneradorConstancias();
    ~GeneradorConstancias();

    void recibirDatos(string n, string c, float m, int t);
    void menu();
    void insertar();
    void desplegar();
    void buscar();
    void borrar();
    void seleccionarEImprimir();
    void disenoConstancia();

    bool validarConstancia(int numeroBoleta);
};

#endif
