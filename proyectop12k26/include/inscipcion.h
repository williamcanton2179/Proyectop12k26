#ifndef INSCRIPCION_H      //Creado por David Alegria
#define INSCRIPCION_H

#include <string>
using namespace std;

class Inscripcion
{
private:

    // DATOS INSCRIPCION
    int codigoInscripcion;

    // CARNET
    string carnetEstudiante;

    // DATOS DEL ALUMNO
    string nombreEstudiante;
    string correoElectronico;
    string carrera;

    // DATOS DE INSCRIPCION
    string ciclo;
    string jornada;
    string fechaInscripcion;
    string estadoInscripcion;

    // VARIABLES AUXILIARES
    string codigoInscripcionStr;
    string carnetStr;

public:

    // CRUD
    void menu();
    void insertar();
    void mostrar();
    void buscar();
    void modificar();
    void eliminar();
};

#endif
