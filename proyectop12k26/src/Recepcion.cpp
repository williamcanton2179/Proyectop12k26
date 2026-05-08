#include "Recepcion.h"
#include <iostream>              //Creado por 9959-25-3251 y 9959-25-2015
#include <string>

using namespace std;

void Recepcion::validarAlumno(Alumnos alumno)
{
    string nombreIngresado;
    string carnetIngresado;

    cout << "\n===== RECEPCION ALUMNO / SISTEMA DE PAGOS =====" << endl;

    cout << "Ingrese nombre completo registrado: ";
    getline(cin, nombreIngresado);

    cout << "Ingrese carnet registrado: ";
    getline(cin, carnetIngresado);

    if(nombreIngresado == alumno.getnombreAlumno() &&
       carnetIngresado == alumno.getcarnetPersonal())
    {
        double montoPago = 300.00;

        cout << "\nDatos correctos." << endl;
        cout << "Acceso autorizado." << endl;

        cout << "Simulacion de Datos a Enviar a Banco...." <<endl;

        cout << "\n===== DATOS ENVIADOS A BANCOS =====" << endl;
        cout << "Nombre: " << alumno.getnombreAlumno() << endl;
        cout << "Carnet: " << alumno.getcarnetPersonal() << endl;
        cout << "Monto: Q" << montoPago << endl;

        cout << "\nEsperando integracion con clase Bancos..." << endl;
    }
    else
    {
        cout << "\nError: datos incorrectos." << endl;
        cout << "Acceso denegado." << endl;
    }
}

void Recepcion::validarDocente()
{
    cout << "\n===== MODULO DOCENTE =====" << endl;
    cout << "Modulo Docente en construccion..." << endl;
}

