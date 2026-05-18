
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
    string name, carnet, codigo;

    // VALIDACIONES
    bool existeAlumno(string carnetBuscar);
    bool existeDocente(string codigoBuscar);

    bool alumnoRegistrado(string nombreBuscar, string carnetBuscar);
    bool maestroRegistrado(string nombreBuscar, string codigoBuscar);

    // APOYO
    string limpiarTexto(string texto);
    string limpiarCarnet(string texto);
    bool nombreCoincide(string nombreArchivo, string nombreIngresado);

    // ===== AGREGAR ESTO =====
    double obtenerPagoAlumno(string carnetBuscar);
    double obtenerPagoMaestro(string codigoBuscar);

public:
    void validarAlumno(Alumnos alumno);
    void validarMaestro(Maestros maestro);

    void menu();

    // CRUD ALUMNOS
    void insertarpagosAlumnos();
    void desplegarpagosAlumnos();
    void modificarpagosAlumnos();
    void buscarpagosAlumnos();
    void borrarpagosAlumnos();

    // CRUD DOCENTES
    void insertarpagosDocentes();
    void desplegarpagosDocentes();
    void modificarpagosDocentes();
    void buscarpagosDocentes();
    void borrarpagosDocentes();
};

#endif
