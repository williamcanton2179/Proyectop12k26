// Antony Marcelo Yllescas Figueroa
// 9959-25-6813

#ifndef HORARIOS_H
#define HORARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "Cursos.h"
#include "GeneradorConstancias.h"

using namespace std;

class Horarios
{
private:

    string dia;
    string nombreCurso;
    string horaInicio;
    string horaFin;

public:

    // CONSTRUCTORES
    Horarios();

    Horarios(string dia,
              string nombreCurso,
              string horaInicio,
              string horaFin);

    // METODOS
    static vector<Horarios> generar(
        vector<Cursos> cursos,
        bool pagoValidado
    );

    static void mostrar(vector<Horarios> lista);

    static void guardarEnArchivo(vector<Horarios> lista);

    // MENU
    static void menu();
};

#endif
