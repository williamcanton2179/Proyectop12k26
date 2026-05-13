#ifndef MAESTROS_H
#define MAESTROS_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include "Carrera.h"
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
    Carrera carreraAsignada;

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
    void guardarSalarioEnArchivo();
    void mostrarTodosLosSalarios();
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
    Carrera getCarreraAsignada();
    vector<Cursos> getCursosAsignados();

    void setId(string id);
    void setDpi(string dpi);

};

#endif
