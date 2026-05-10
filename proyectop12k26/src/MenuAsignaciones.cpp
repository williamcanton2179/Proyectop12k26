#include "MenuAsignaciones.h"
#include <iostream>

using namespace std;

void MenuAsignaciones::ejecutarMenu() {
    int opcion;
    do {
        cout << "\n--- MENU DE MODULOS ---" << endl;
        cout << "1. Asignarse (Mi programa)" << endl;
        cout << "2. Volver" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Asignacion miAsig;
            miAsig.menuAsignacion();
        }
    } while(opcion != 2);
}
