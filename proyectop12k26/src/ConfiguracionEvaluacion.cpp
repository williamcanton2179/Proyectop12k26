//archivo creado por Freddy Muy el dia lunes 4/05/2026



#include <iostream>
#include "ConfiguracionEvaluacion.h"  //llama a la clase
using namespace std;  //para evitar estar usando std

ConfiguracionEvaluacion::ConfiguracionEvaluacion()
    : periodo(""), codigoCurso(""), nombreCurso("") {}

void ConfiguracionEvaluacion::seleccionarCurso() {
    Cursos temp;
    vector<Cursos> catalogo = temp.catalagoCursosIngSistemas();


    //trae los cursos de otra clase ya creada para saber que curso se quiere obtener nota
    cout << "\n===== Catalogo de Cursos =====" << endl;
    for (int i = 0; i < (int)catalogo.size(); i++)
        cout << "  [" << i + 1 << "] "
             << catalogo[i].getcodigoCurso() << " - "
             << catalogo[i].getnombreCurso()  << endl;

    int opcion;
    cout << "\nSeleccione un curso: ";   //pide el curso que esta desglozado por numero
    cin >> opcion;
    cin.ignore();

    if (opcion < 1 || opcion > (int)catalogo.size()) {
        cout << "Opcion invalida. Se usara el primero por defecto." << endl;   //si la opcion no es valida tomara el primer curso de la lista
        opcion = 1;
    }

    codigoCurso = catalogo[opcion - 1].getcodigoCurso();
    nombreCurso = catalogo[opcion - 1].getnombreCurso();
    cout << "Curso seleccionado: [" << codigoCurso << "] " << nombreCurso << endl;  //nos muestra que curso ha sido seleccionado
}

void ConfiguracionEvaluacion::configurarPeriodo() {
    cout << "Periodo de evaluacion (Ej: Primer Semestre 2026): ";  //se pide el periodo de evaluacion dependiendo el semestre
    getline(cin, periodo);
}

bool ConfiguracionEvaluacion::almacenarConfiguracion() {
    if (codigoCurso == "" || periodo == "") {
        cout << "Error: faltan datos de curso o periodo." << endl;  //si no se colocan bien los datos no se pueden ingresar las notas
        return false;
    }


    //aca es donde se ingresan las notas de parciales y de actividades y si no se llega a zona minima no nos da acceso a asignar nota de parcial final
    cout << "\n===== Configuracion del Curso =====" << endl;
    cout << "Curso  : [" << codigoCurso << "] " << nombreCurso << endl;
    cout << "Periodo: " << periodo                              << endl;
    cout << "\n--- Distribucion de notas ---"                   << endl;
    cout << "  Primer Parcial  : " << MAX_PRIMER_PARCIAL        << " pts" << endl;
    cout << "  Segundo Parcial : " << MAX_SEGUNDO_PARCIAL       << " pts" << endl;
    cout << "  Zona Tareas     : " << MAX_ZONA_TAREAS           << " pts" << endl;
    cout << "  Zona max        : "
         << (MAX_PRIMER_PARCIAL + MAX_SEGUNDO_PARCIAL + MAX_ZONA_TAREAS)
         << " pts (min " << MIN_ZONA_FINAL << " para habilitar final)"    << endl;
    cout << "  Examen Final    : " << MAX_EXAMEN_FINAL          << " pts" << endl;
    cout << "  Nota aprobacion : " << NOTA_APROBACION           << " pts" << endl;
    return true;
}


//trae los metodos
string ConfiguracionEvaluacion::getCodigoCurso()       const { return codigoCurso; }
string ConfiguracionEvaluacion::getNombreCurso()       const { return nombreCurso; }
string ConfiguracionEvaluacion::getPeriodo()           const { return periodo; }
int    ConfiguracionEvaluacion::getMaxPrimerParcial()  const { return MAX_PRIMER_PARCIAL; }
int    ConfiguracionEvaluacion::getMaxSegundoParcial() const { return MAX_SEGUNDO_PARCIAL; }
int    ConfiguracionEvaluacion::getMaxZonaTareas()     const { return MAX_ZONA_TAREAS; }
int    ConfiguracionEvaluacion::getMaxExamenFinal()    const { return MAX_EXAMEN_FINAL; }
int    ConfiguracionEvaluacion::getMinZonaFinal()      const { return MIN_ZONA_FINAL; }
int    ConfiguracionEvaluacion::getNotaAprobacion()    const { return NOTA_APROBACION; }
