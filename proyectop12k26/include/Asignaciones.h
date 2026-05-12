#ifndef ASIGNACION_H
#define ASIGNACION_H
#include <vector>
#include <string>
#include "Cursos.h"

struct RegistroAsignacion {
    std::string carnet;
    std::vector<std::string> codigosCursos;
};

class Asignacion {
public:
    std::vector<std::string> cursosAsignados;

    bool validarCarnetEnArchivo(std::string carnet);
    void menuAsignacion();

    // --- NUEVAS FUNCIONES CRUD ---
    void mostrarAsignaciones();     // Leer (Read)
    void editarAsignacion();        // Actualizar (Update)
    void eliminarAsignacion();      // Eliminar (Delete)
};
#endif
