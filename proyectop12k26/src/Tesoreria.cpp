#include "Tesoreria.h"
#include "Bancos.h"
#include "Recepcion.h"
#include "GeneradorConstancias.h"

#include <iostream>
#include <string>

using namespace std;

// Constructor
Tesoreria::Tesoreria()
{
}

// Menu principal de Tesoreria
void Tesoreria::menu()
{
    int opcion;

    Bancos banco;
    Recepcion recepcion;
    GeneradorConstancias constancia;

    do
    {
        system("cls");

        cout << "==========================================" << endl;
        cout << "              MODULO TESORERIA            " << endl;
        cout << "==========================================" << endl;
        cout << "1. Crear Cuenta Bancaria" << endl;
        cout << "2. Recepcion de Pagos" << endl;
        cout << "3. Generar Constancia" << endl;
        cout << "4. Regresar al Menu Principal" << endl;
        cout << "==========================================" << endl;
        cout << "Seleccione una opcion: ";

        cin >> opcion;
        cin.ignore();

        switch(opcion)
        {
            case 1:
            {
                string nombreCliente;
                string nombreBanco;
                double montoInicial;

                system("cls");

                cout << "===== CREACION DE CUENTA BANCARIA =====" << endl;

                cout << "Ingrese nombre del cliente: ";
                getline(cin, nombreCliente);

                cout << "Ingrese banco (BAC / G&T / Banco Industrial): ";
                getline(cin, nombreBanco);

                cout << "Ingrese monto inicial: ";
                cin >> montoInicial;
                cin.ignore();

                if(banco.crearCuenta(nombreCliente, montoInicial, nombreBanco))
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
                system("cls");

                cout << "===== RECEPCION DE PAGOS =====" << endl;
                cout << "Validando datos del alumno previamente registrado..." << endl;

                // Aqui Recepcion solo valida datos ya registrados
                // El alumno debe venir desde Registro general del sistema
                cout << "\nNOTA: Integrar con modulo Registro para datos reales." << endl;

                recepcion.menu();

                system("pause");
                break;
            }

     case 3:
{
    constancia.menu();
    // No necesita system("pause") aqui porque tu menu() ya los tiene adentro
    break;
}
            case 4:
                cout << "\nRegresando al menu principal..." << endl;
                break;

            default:
                cout << "\nOpcion invalida. Intente nuevamente." << endl;
                system("pause");
                break;
        }

    } while(opcion != 4);
}
