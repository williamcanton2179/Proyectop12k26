#ifndef HORARIOS_H
#define HORARIOS_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Cursos.h"
//antony marcelo yllescas figueroa
// 9959 25 6813
using namespace std;

class Horarios
{
private:
    // defimos parametros
    string nombreCurso;
    string horaInicio;
    string horaFin;

public:
    //se definio lo publico
    Horarios();
    Horarios(string nombreCurso, string horaInicio, string horaFin);

    static vector<Horarios> generar(vector<Cursos> cursos, string jornada, bool pagoRealizado);
    static void mostrar(vector<Horarios> lista);

    // archivo
    static void guardarEnArchivo(vector<Horarios> lista);
};

#endif
