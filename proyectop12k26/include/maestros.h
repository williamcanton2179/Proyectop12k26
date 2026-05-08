#ifndef MAESTROS_H
#define MAESTROS_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "carrera.h"
#include "Cursos.h"

using namespace std;

class Maestros {
private:
    string id;
    string nombre;
    string apellido;
    string dpi;
    int codigo;
    string sede;
    int diasSemana;
    int horasClase;
    vector<Cursos> cursosAsignados;
    carrera carreraAsignada;

public:
    Maestros();

    void menu();
    void insertar();
    void desplegar();
    void modificar();
    void buscar();
    void borrar();

    void ingresarDatosPersonales();
    void generarCodigo();
    void asignarCurso();
    void asignarHorario();
    double calcularSalario();
    bool verificarCodigo(int codigoIngresado);
    void mostrarResultados();
    void mostrarCarreras();
    void mostrarCursosPorCarrera(string codigoCarrera);
    void mostrarCursosAsignados();
    void ingresarNotas();

    int getCodigo();
    string getNombreCurso();
    string getNombre();
    string getApellido();
    string getId();
    string getDpi();
    carrera getCarreraAsignada();
    vector<Cursos> getCursosAsignados();

    void setId(string id);
    void setDpi(string dpi);
};

#endif
