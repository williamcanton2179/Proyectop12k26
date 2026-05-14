#include "MenuAsignaciones.h"
#include "ModuloPagos.h"
#include "Horarios.h"
#include "modulomenurespaldo.h"
#include <iostream>

using namespace std;

void MenuAsignaciones::ejecutarMenu() {
    int opcion;
    do {
        cout << "\n--- MENU DE MODULOS ---" << endl;
        cout << "1. Asignarse (Mi programa)" << endl;
        cout << "2. Realizar Pagos (Modulo de Pagos)" << endl;
        cout << "3. Gestionar Horarios (Modulo Horarios)" << endl;
        cout << "4. Gestionar Respaldos (Modulo Respaldo)" << endl;
        cout << "5. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Asignacion miAsig;
            miAsig.menuAsignacion();
        }
        else if (opcion == 2) {
            ModuloPagos pagos;
            pagos.ejecutar();
        }
        else if (opcion == 3) {
            Horarios::menu();
        }
        else if (opcion == 4) {
            ejecutarModuloRespaldo();
        }
    } while(opcion != 5);
}
