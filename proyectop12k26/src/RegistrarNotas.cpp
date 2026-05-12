//Creado el día 4 de mayo por los alumnos
//9959-25-4900: Jhonny Flores
//9959-25-4992: Josue Muy
//9959-25-6194: Juan Jolon
//9959-25-7728: Jose Barrios

#include <iostream>
#include "RegistrarNotas.h"
using namespace std;

// Constructor por defecto
RegistrarNotas::RegistrarNotas() : nAlumnos(0) {}

// Valida que un valor esté dentro del rango permitido [0, maximo]
bool RegistrarNotas::validarRango(float valor, float maximo) {
    return (valor >= 0.0f && valor <= maximo);
}

// Calcula la zona (suma de parciales y tareas)
float RegistrarNotas::calcularZona(float p1, float p2, float tareas) {
    return p1 + p2 + tareas;
}

// Calcula la nota final (zona + examen final)
float RegistrarNotas::calcularNotaFinal(float zona, float examenFinal) {
    return zona + examenFinal;
}

float RegistrarNotas::pedirNota(const string& etiqueta, int maximo) {
    float valor;

    // Bucle que se repite hasta que el usuario ingrese una nota válida
    do {
        cout << "  " << etiqueta << " (0 - " << maximo << "): ";
        cin >> valor;

        // Si la nota está fuera de rango, muestra mensaje de error
        if (!validarRango(valor, maximo))
            cout << "  Error: ingrese un valor entre 0 y " << maximo << "." << endl;

    } while (!validarRango(valor, maximo));

    return valor;
}

void RegistrarNotas::seleccionarAlumnos(vector<Alumnos>& listaAlumnos) {
    // Muestra la lista completa de alumnos disponibles en el sistema
    cout << "\n===== Alumnos en el sistema =====" << endl;
    for (int i = 0; i < (int)listaAlumnos.size(); i++)
        cout << "  [" << i + 1 << "] "
             << listaAlumnos[i].getcarnetPersonal() << " - "
             << listaAlumnos[i].getnombreAlumno()   << " "
             << listaAlumnos[i].getapellidoAlumno() << endl;

    cout << "\nSeleccione alumnos del curso. Escriba 0 para terminar." << endl;

    nAlumnos = 0;
    int opcion;

    // Permite seleccionar hasta el máximo de alumnos (MAX_ALUMNOS)
    while (nAlumnos < MAX_ALUMNOS) {
        cout << "  Alumno " << (nAlumnos + 1) << " (0 para terminar): ";
        cin >> opcion;

        if (opcion == 0) break;

        // Validación de rango de opción
        if (opcion < 1 || opcion > (int)listaAlumnos.size()) {
            cout << "  Opcion invalida." << endl;
            continue;
        }

        string carnetSeleccionado = listaAlumnos[opcion - 1].getcarnetPersonal();

        // Verifica si el alumno ya fue seleccionado anteriormente (evita duplicados)
        bool duplicado = false;
        for (int j = 0; j < nAlumnos; j++) {
            if (notas[j].carnet == carnetSeleccionado) {
                cout << "  Este alumno ya fue seleccionado." << endl;
                duplicado = true;
                break;
            }
        }
        if (duplicado) continue;

        // Guarda los datos del alumno seleccionado
        notas[nAlumnos].carnet       = carnetSeleccionado;
        notas[nAlumnos].nombreAlumno = listaAlumnos[opcion - 1].getnombreAlumno()
                                     + " "
                                     + listaAlumnos[opcion - 1].getapellidoAlumno();
        nAlumnos++;
    }

    cin.ignore();
    cout << "Alumnos seleccionados: " << nAlumnos << endl;
}

void RegistrarNotas::ingresarNotas(const ConfiguracionEvaluacion& config) {
    // Recorre todos los alumnos seleccionados para ingresar sus notas
    for (int i = 0; i < nAlumnos; i++) {
        cout << "\n--- [" << notas[i].carnet << "] "
             << notas[i].nombreAlumno << " ---" << endl;

        // Solicita las notas de los parciales y tareas
        notas[i].primerParcial  = pedirNota("Primer Parcial ", config.getMaxPrimerParcial());
        notas[i].segundoParcial = pedirNota("Segundo Parcial", config.getMaxSegundoParcial());
        notas[i].zonaTareas     = pedirNota("Zona Tareas    ", config.getMaxZonaTareas());

        // Calcula la zona (suma de parciales + tareas)
        notas[i].zona           = calcularZona(notas[i].primerParcial,
                                               notas[i].segundoParcial,
                                               notas[i].zonaTareas);

        cout << "  -----------------------------" << endl;
        cout << "  Zona acumulada: " << notas[i].zona << " pts" << endl;

        // Verifica si el alumno alcanza la zona mínima para habilitar el examen final
        notas[i].habilitadoFinal = (notas[i].zona >= config.getMinZonaFinal());

        if (!notas[i].habilitadoFinal) {
            cout << "  Alumno NO habilitado para examen final." << endl;
            cout << "  (Minimo requerido: " << config.getMinZonaFinal() << " pts)" << endl;

            // Si no está habilitado, no puede presentar final
            notas[i].examenFinal = 0;
            notas[i].notaFinal   = notas[i].zona;
            notas[i].aprobado    = false;
        } else {
            cout << "  Alumno HABILITADO para examen final." << endl;

            // Solicita la nota del examen final y calcula la nota definitiva
            notas[i].examenFinal = pedirNota("Examen Final   ", config.getMaxExamenFinal());
            notas[i].notaFinal   = calcularNotaFinal(notas[i].zona, notas[i].examenFinal);

            // Determina si el alumno aprueba la materia
            notas[i].aprobado    = (notas[i].notaFinal >= config.getNotaAprobacion());
        }
    }
    cin.ignore();  // Limpia el buffer del teclado
}

void RegistrarNotas::almacenarNotas(const string& usuarioActivo) {
    // Muestra el resumen final de todas las notas antes de guardar
    mostrarResumen();

    // Guardar cada alumno en Reportes.txt
    reportes reporte;
    cout << "\n===== Guardando en archivo =====" << endl;

    // Recorre todos los alumnos y genera el reporte individual
    for (int i = 0; i < nAlumnos; i++) {
        reporte.generarDesdeNota(
            notas[i].carnet,
            notas[i].nombreAlumno,
            notas[i].primerParcial,
            notas[i].segundoParcial,
            notas[i].zonaTareas,
            notas[i].zona,
            notas[i].examenFinal,
            notas[i].notaFinal,
            notas[i].aprobado ? "APROBADO" : "REPROBADO"
        );
    }

    // Registra la acción en la bitácora de auditoría
    bitacora auditoria;
    auditoria.insertar(usuarioActivo, "RegistrarNotas", "NOTAS_ALMACENADAS");
}

void RegistrarNotas::mostrarResumen() {
    cout << "\n=================================================" << endl;
    cout << " REPORTE FINAL DE NOTAS"                            << endl;
    cout << "================================================="  << endl;

    // Inicialización de contadores y variables para estadísticas
    int   aprobados     = 0;
    int   reprobados    = 0;
    int   noHabilitados = 0;
    int   conFinal      = 0;
    float sumaNotas     = 0;
    float notaMasAlta   = -1;
    float notaMasBaja   = 101;

    // Recorre todos los alumnos y muestra su información detallada
    for (int i = 0; i < nAlumnos; i++) {
        cout << "\n  Alumno : " << notas[i].nombreAlumno         << endl;
        cout << "  Carnet : " << notas[i].carnet                 << endl;
        cout << "  P1     : " << notas[i].primerParcial          << " / 20" << endl;
        cout << "  P2     : " << notas[i].segundoParcial         << " / 25" << endl;
        cout << "  Tareas : " << notas[i].zonaTareas             << " / 20" << endl;
        cout << "  Zona   : " << notas[i].zona                   << " / 65" << endl;

        if (!notas[i].habilitadoFinal) {
            cout << "  Final  : No habilitado"                   << endl;
            cout << "  Estado : REPROBADO (sin derecho a final)" << endl;
            noHabilitados++;
        } else {
            cout << "  Final  : " << notas[i].examenFinal        << " / 35" << endl;
            cout << "  Total  : " << notas[i].notaFinal          << " / 100" << endl;
            cout << "  Estado : "
                 << (notas[i].aprobado ? "APROBADO" : "REPROBADO") << endl;

            // Acumula datos solo de alumnos que presentaron final
            sumaNotas += notas[i].notaFinal;
            conFinal++;

            if (notas[i].notaFinal > notaMasAlta) notaMasAlta = notas[i].notaFinal;
            if (notas[i].notaFinal < notaMasBaja) notaMasBaja = notas[i].notaFinal;
            if (notas[i].aprobado) aprobados++;
            else                   reprobados++;
        }
        cout << "  -----------------------------------------" << endl;
    }

    // Muestra resumen general de resultados
    cout << "\n  Aprobados      : " << aprobados     << endl;
    cout << "  Reprobados     : " << reprobados    << endl;
    cout << "  Sin der. final : " << noHabilitados << endl;

    // Calcula y muestra estadísticas solo si hay alumnos que presentaron final
    if (conFinal > 0) {
        float promedio            = sumaNotas / conFinal;
        float porcentajeAprobacion= ((float)aprobados / conFinal) * 100;

        cout << "\n--- Estadisticas del curso ---"                     << endl;
        cout << "  Promedio general     : " << promedio               << " pts" << endl;
        cout << "  Nota mas alta        : " << notaMasAlta            << " pts" << endl;
        cout << "  Nota mas baja        : " << notaMasBaja            << " pts" << endl;
        cout << "  Porcentaje aprobacion: " << porcentajeAprobacion   << "%"    << endl;
    } else {
        cout << "\n  Sin estadisticas: ningun alumno llego al examen final." << endl;
    }

    cout << "=================================================" << endl;
}
