//Creado el día 4 de mayo por los alumnos
//9959-25-4900: Jhonny Flores
//9959-25-4992: Josue Muy
//9959-25-6194: Juan Jolon
//9959-25-7728: Jose Barrios

#ifndef REGISTRAR_NOTAS_H
#define REGISTRAR_NOTAS_H

#include <string>
#include <vector>
#include "ConfiguracionEvaluacion.h"
#include "Alumnos.h"
#include "bitacora.h"
#include "reportes.h"
using namespace std;

// Constante que define el máximo de alumnos que se pueden registrar por curso
const int MAX_ALUMNOS = 10;

// Estructura que almacena toda la información de notas de un alumno
struct Nota {
    string carnet;
    string nombreAlumno;
    float  primerParcial;
    float  segundoParcial;
    float  zonaTareas;
    float  zona;
    float  examenFinal;
    float  notaFinal;
    bool   habilitadoFinal;
    bool   aprobado;
};

class RegistrarNotas {
private:
    Nota notas[MAX_ALUMNOS];    // Arreglo que guarda las notas de los alumnos seleccionados
    int  nAlumnos;              // Cantidad actual de alumnos registrados

    // Métodos privados (utilitarios)
    bool  validarRango(float valor, float maximo);
    float calcularZona(float p1, float p2, float tareas);
    float calcularNotaFinal(float zona, float examenFinal);
    float pedirNota(const string& etiqueta, int maximo);

public:
    RegistrarNotas();   // Constructor

    // Métodos públicos principales
    void seleccionarAlumnos(vector<Alumnos>& listaAlumnos);
    void ingresarNotas(const ConfiguracionEvaluacion& config);
    void almacenarNotas(const string& usuarioActivo);
    void mostrarResumen();
};

#endif
