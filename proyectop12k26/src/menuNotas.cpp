#include "menuNotas.h"
#include <iostream>
using namespace std;

bool SistemaNotas::iniciar() {
    // Intenta iniciar sesión. Si falla, cierra el sistema.
    if (!sesion.loginUsuarios()) {
        cout << "Acceso denegado. Cerrando sistema." << endl;
        return false;
    }

    // Guarda el nombre del usuario que inició sesión
    usuarioActivo = sesion.getNombre();

    int cantAlumnos;
    cout << "\n¿Cuantos alumnos desea registrar en el sistema? ";
    cin >> cantAlumnos;
    cin.ignore();

    // Registra la cantidad de alumnos solicitada por el usuario
    for (int i = 0; i < cantAlumnos; i++) {
        Alumnos a;
        a.menuRegistro();           // Muestra el menú de registro de cada alumno
        cin.clear();
        cin.ignore(1000, '\n');     // Limpia el buffer de entrada
        listaAlumnos.push_back(a);  // Agrega el alumno a la lista
    }

    return true;
}

void SistemaNotas::ejecutarMenu() {
    int opcion;

    // Bucle principal del menú del sistema
    do {
        cout << "   SISTEMA DE GESTION DE NOTAS"         << endl;
        cout << "   Usuario: " << usuarioActivo           << endl;
        cout << "-------------------------------------"   << endl;
        cout << "  1. Configurar curso"                   << endl;
        cout << "  2. Seleccionar alumnos del curso"      << endl;
        cout << "  3. Ingresar notas"                     << endl;
        cout << "  4. Guardar y ver reporte"              << endl;
        cout << "  5. Consultar todos los reportes"       << endl;
        cout << "  6. Buscar nota por carnet"             << endl;
        cout << "  7. Modificar nota"                     << endl;
        cout << "  8. Eliminar nota"                      << endl;
        cout << "  9. Salir"                              << endl;
        cout << "--------------------------------------"   << endl;
        cout << "  Opcion: ";
        cin >> opcion;
        cin.ignore();

        // Ejecuta la opción seleccionada por el usuario
        switch (opcion) {
            case 1:
                // Configuración del curso y evaluación
                config = ConfiguracionEvaluacion();
                config.seleccionarCurso();
                config.configurarPeriodo();
                config.almacenarConfiguracion();
                break;

            case 2:
                // Selección de alumnos para el curso actual
                registro = RegistrarNotas();
                registro.seleccionarAlumnos(listaAlumnos);
                break;

            case 3:
                registro.ingresarNotas(config);
                break;

            case 4:
                registro.almacenarNotas(usuarioActivo);
                break;

            case 5:
                reporte.acceder();
                break;

            case 6:
                reporte.buscarPorCarnet();
                break;

            case 7:
                reporte.actualizar();
                break;

            case 8:
                reporte.borrar();
                break;

            case 9:
                cout << "\nCerrando sistema. Hasta luego." << endl;
                break;

            default:
                cout << "\nOpcion invalida." << endl;
        }
    } while (opcion != 9);
}

int main() {
    // Crea una instancia del sistema de gestión de notas
    SistemaNotas sistema;

    // Intenta inicializar el sistema (login + registro de alumnos)
    if (!sistema.iniciar())
        return 1;   // Sale del programa si la inicialización falla

    // Ejecuta el menú principal del sistema
    sistema.ejecutarMenu();

    return 0;   // Finaliza el programa correctamente
}
