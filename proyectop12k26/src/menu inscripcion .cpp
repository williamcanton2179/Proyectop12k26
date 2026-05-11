#include "menu inscripcion .h"
#include "inscipcion.h"
#include <iostream>
#include <conio.h>
using namespace std;

menuInscripcion ::menuInscripcion ()
{
    //ctor
}

void menuInscripcion::menuIncripcionPrincipal()
{
    int escogerOpcion = 0;
    Inscripcion obtenerInscripcion;



    do{
        system("cls");
        cout << "\t\t\t\t\t----------------------------------" << endl;
        cout << "\t\t\t\t\t |   ¿COMO DESEA INSCRIBIRSE?   |" << endl;
        cout << "\t\t\t\t\t----------------------------------" << endl;
        cout << "\t\t\t\t\t1.Nuevo ingreso" << endl;
        cout << "\t\t\t\t\t2.Reingreso" << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t Opciones a Escoger: [1/2]" << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\n\t\t\t\t¿Que opcion desea escoger?: "; cin >> escogerOpcion;
        switch (escogerOpcion)
        {
        case 1:
            obtenerInscripcion.menu();
            break;
        case 2:
            obtenerInscripcion.menu();
            break;
        default:
            cout << "\n\t\t\t\t Opcion invalida... Por favor pruebe otra vez" << endl;
        }
        getch();
        }while(escogerOpcion != 2);
}
