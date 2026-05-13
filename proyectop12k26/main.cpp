#include <iostream>
#include<fstream>

#include "Tesoreria.h"
#include "usuarios.h"
#include "bitacora.h"
#include "menuRegistro.h"
#include "MenuAsignaciones.h"

using namespace std;

void creditosModulo();
void menuGeneral();

usuarios usuarioRegistrado;

int main()
{
    bool accesoUsuarios;
    //creditosModulo();

    accesoUsuarios = usuarioRegistrado.loginUsuarios();

    if (accesoUsuarios){
        menuGeneral();
    }

    system("cls");
    cout<<"** Hasta la proxima **";

    creditosModulo();

    return 0;
}

void menuGeneral()
{
    system("cls");

    int choice;
	//char x;

	do
    {
        system("cls");

        cout<<"\t\t\t\t\tUsuario: "<< usuarioRegistrado.getNombre() <<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t |   SISTEMA GESTION DE VENTAS  |"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\t 1. Registro e Inscripciòn"<<endl;
        cout<<"\t\t\t 2. Asignaciòn de Cursos"<<endl;
        cout<<"\t\t\t 3. Notas"<<endl;
        cout<<"\t\t\t 4. Tesoreria"<<endl;
        cout<<"\t\t\t 5. Salir del Sistema"<<endl;

        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\tOpcion a escoger:[1/2/3/4/5]"<<endl;
        cout<<"\t\t\t-------------------------------"<<endl;
        cout<<"\t\t\tIngresa tu Opcion: ";

        cin>>choice;

        switch(choice)
        {
        case 1:
            {
            menuRegistro registro;
            registro.menuPrincipalRegistro();
            }
            break;
        case 2:
            {
            MenuAsignaciones asignaciones;
            asignaciones.ejecutarMenu();
            }
            break;

        case 3:
            cout << "Aqui se colocara el modulo de notas" << endl;
            cin.get();
            break;

        case 4:
            {
            Tesoreria tesoreria;
            tesoreria.menu();
            }
            break;

        case 5:
            cin.get();
            break;

        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
            cin.get();
        }

    }while(choice!= 5);
}

void creditosModulo()
{
    string line;

    //char userInput = ' ';
    ifstream myFile("creditos.txt");

    if(myFile.is_open())
    {
        //Se obtiene el mapa externo y se general el mapa de celdas
        while(getline(myFile, line))
        {
            cout << line << endl;
        }

        myFile.close();

        cout<<"Presione cualquier tecla para continuar";
        cin.get();
    }
    else
    {
        cout << "Error FATAL: el archivo de modulo no pudo ser cargado" << endl;
        cin.get();
    }
}
