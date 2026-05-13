#include "MenuAsignaciones.h"
#include "ModuloPagos.h" // Se agrega el encabezado de modulos
#include <iostream>

using namespace std;

void MenuAsignaciones::ejecutarMenu() {
    int opcion;
    do {
        cout << "\n--- MENU DE MODULOS ---" << endl;
        cout << "1. Asignarse (Mi programa)" << endl;
        cout << "2. Realizar Pagos (Modulo de Pagos)" << endl; // Nueva opción para conectar los módulos
        cout << "3. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Asignacion miAsig;
            miAsig.menuAsignacion();
        }
        // Se añade la lógica para llamar al módulo de pagos
        else if (opcion == 2) {
            ModuloPagos pagos;
            pagos.ejecutar(); // Llama a la función principal de modulos
        }
    } while(opcion != 3); // Se ajusta para que el 3 sea la salida
}