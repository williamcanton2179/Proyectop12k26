#include "menuNotas.h"
#include <iostream>
using namespace std;

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
