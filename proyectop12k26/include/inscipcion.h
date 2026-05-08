#ifndef INSCIPCION_H     //Creado por David Alegria
#define INSCIPCION_H

#include <string>
using namespace std;

class Inscripcion
{
private:
    int codigoInscripcion;
    int carnetEstudiante;
    string nombreEstudiante;
    string correoElectronico;
    string carrera;
    string tipoInscripcion;
    string ciclo;
    string jornada;
    string fechaInscripcion;
    string estadoInscripcion;

public:
    // CRUD
    void menu();
    void insertar();
    void mostrar();
    void buscar();
    void modificar();
    void eliminar();

    // auxiliares
    void ingresarDatos();
    void mostrarDatos();
};

#endif
