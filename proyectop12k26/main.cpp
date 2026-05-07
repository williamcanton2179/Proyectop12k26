#include <iostream>
#include <fstream>

#include "usuarios.h"
#include "bitacora.h"
#include "Bancos.h"
#include "Recepcion.h"
#include "GeneradorConstancias.h"
#include "Alumnos.h"

using namespace std;

void creditosModulo();
void menuGeneral();
void menuTesoreria();

usuarios usuarioRegistrado;

int main()
{
    bool accesoUsuarios;

    accesoUsuarios = usuarioRegistrado.loginUsuarios();

    if (accesoUsuarios){
        menuGeneral();
    }

    system("cls");
    cout << "** Hasta la proxima **";

    creditosModulo();

    return 0;
}

void menuGeneral()
{
    system("cls");

    int choice;

    do
    {
        system("cls");

        cout << "\t\t\t\t\tUsuario: " << usuarioRegistrado.getNombre() << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t |   SISTEMA GESTION DE VENTAS  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Registro e Inscripciòn" << endl;
        cout << "\t\t\t 2. Asignaciòn de Cursos" << endl;
        cout << "\t\t\t 3. Notas" << endl;
        cout << "\t\t\t 4. Tesoreria" << endl;
        cout << "\t\t\t 5. Salir del Sistema" << endl;

        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpcion a escoger:[1/2/3/4/5]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tIngresa tu Opcion: ";

        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
            cout << "Aqui se colocara el modulo de registro" << endl;
            system("pause");
            break;

        case 2:
            cout << "Aqui se colocara el modulo de asignacion" << endl;
            system("pause");
            break;

        case 3:
            cout << "Aqui se colocara el modulo de notas" << endl;
            system("pause");
            break;

        case 4:
            menuTesoreria();
            break;

        case 5:
            break;

        default:
            cout << "\n\t\t\t Opcion invalida...Por favor prueba otra vez.." << endl;
            system("pause");
        }

    }while(choice != 5);
}

void menuTesoreria()
{
    int opcion;

    Bancos banco;
    Recepcion recepcion;
    GeneradorConstancias constancia;
    Alumnos alumno;

    do
    {
        system("cls");

        cout << "\n======================================" << endl;
        cout << "        MODULO TESORERIA              " << endl;
        cout << "======================================" << endl;
        cout << "1. Crear Cuenta Bancaria" << endl;
        cout << "2. Recepcion y Validacion de Pago" << endl;
        cout << "3. Generar Constancia" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "======================================" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;
        cin.ignore();

        switch(opcion)
        {
        case 1:
        {
            string nombre;
            string nombreBanco;
            double monto;

            cout << "\n===== CREAR CUENTA =====" << endl;

            cout << "Ingrese nombre del cliente: ";
            getline(cin, nombre);

            cout << "Ingrese banco (BAC / G&T / Banco Industrial): ";
            getline(cin, nombreBanco);

            cout << "Ingrese monto inicial: ";
            cin >> monto;
            cin.ignore();

            if(banco.crearCuenta(nombre, monto, nombreBanco))
            {
                cout << "\nCuenta creada exitosamente." << endl;
            }
            else
            {
                cout << "\nError al crear cuenta." << endl;
            }

            system("pause");
            break;
        }

        case 2:
        {
            cout << "\n===== REGISTRO Y VALIDACION =====" << endl;

            recepcion.validarAlumno(alumno);

            system("pause");
            break;
        }

        case 3:
        {
            string nombre;
            float monto;

            cout << "\n===== GENERAR CONSTANCIA =====" << endl;

            cout << "Ingrese nombre: ";
            getline(cin, nombre);

            cout << "Ingrese monto pagado: ";
            cin >> monto;
            cin.ignore();

            constancia.setNombre(nombre);
            constancia.setMonto(monto);
            constancia.setTipoPersona(1);

            cout << endl;

            constancia.entregarConstancia();

            system("pause");
            break;
        }

        case 4:
            break;

        default:
            cout << "\nOpcion invalida." << endl;
            system("pause");
        }

    }while(opcion != 4);
}

void creditosModulo()
{
    string line;

    ifstream myFile("creditos.txt");

    if(myFile.is_open())
    {
        while(getline(myFile, line))
        {
            cout << line << endl;
        }

        myFile.close();

        cout << "Presione cualquier tecla para continuar";
        cin.get();
    }
    else
    {
        cout << "Error FATAL: el archivo de modulo no pudo ser cargado" << endl;
        cin.get();
    }
}
