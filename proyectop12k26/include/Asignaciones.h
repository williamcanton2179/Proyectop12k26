#ifndef ASIGNACION_H
#define ASIGNACION_H
#include <vector>
#include <string>
#include "Alumnos.h"
#include "Cursos.h"

class Asignacion {
public:
    std::vector<std::string> cursosAsignados;
    bool validarCarnet(std::string carnet, std::vector<Alumnos> listaAlumnos);
    void asignarCurso(std::string carnet, std::string codCurso, std::vector<Cursos> catalogo, std::vector<std::string> cursosAprobados);
    std::vector<std::string> getCursosAsignados();
};
#endif
