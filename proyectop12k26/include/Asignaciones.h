#ifndef ASIGNACION_H
#define ASIGNACION_H
#include <vector>
#include <string>
#include "Cursos.h"

class Asignacion {
public:
    std::vector<std::string> cursosAsignados;

    // Solo usamos strings para el carnet y el catálogo de Cursos.h
    bool validarCarnetEnArchivo(std::string carnet);
    void asignarCurso(std::string carnet, std::string codCurso, std::vector<Cursos> catalogo);
    void menuAsignacion();
};
#endif
