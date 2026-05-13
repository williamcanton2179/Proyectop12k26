#include "ModuloPagos.h"
#include "validacionpagos0.h"
#include "validacionpagos0.cpp"
#include <iostream>
using namespace std;

void ModuloPagos::ejecutar()
{
    //double resultado = 1020.00;
    //double pagoalumno;
    int opcion;
    int opcion2;
    int numeroT;
    string nombrealumno;
    string date;
    int codseguro;
    validacionpagos0 asignaciones; //primer objeto de la clase
    // se usan las funciones en los objetos

    asignaciones.cargarCursosDesdeArchivo("asignacion_2179.txt");

   cout <<"---ASIGNACION DE CURSOS---" << endl;
   cout <<"1.Cursos asignados y tu carnet" << endl;
   cout <<"2.Pagar colegiatura" << endl;
   cin >> opcion;

    system("cls");
     if(opcion == 1) {
        asignaciones.informaciondecursos();
     } else {
        cout << endl << "Total a pagar es de: Q" << resultado << endl;
        cout << "Puedes pagar de la manera que prefieras,escoge debito o credito: " << endl;
        cout << "1. Debito" << endl;
        cout <<"2. Credito" << endl;
        cin >> opcion2;
        system("cls");
        asignaciones.tipodePago(opcion2,numeroT,nombrealumno,date,codseguro);
     }

}
