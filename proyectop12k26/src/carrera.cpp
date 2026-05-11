#include "Carrera.h"
#include <stdlib.h>
#include <vector> //Creado por David Alegria 9959-23-11277

 Carrera::Carrera()
{
    //ctor
}

Carrera::Carrera(string codigoCarrera, string nombreCarrera, bool estadoCarrera)
{
    this -> codigoCarrera = codigoCarrera;
    this -> nombreCarrera = nombreCarrera;
    this -> estadoCarrera = estadoCarrera;

}


vector<Carrera> Carrera::datosCarreras()
{
    vector<Carrera> infoCarreras;
    infoCarreras.push_back(Carrera("9959", "Ingeniera en Sistemas", true));
    infoCarreras.push_back(Carrera("9975", "Ingeniera Industrial", true));
    infoCarreras.push_back(Carrera("9973", "Ingeniera Civil", true));
    return infoCarreras;
}

void Carrera::menu()
{
    int opcion;
    char x;

    do
    {
        system("cls");

        cout << "\n\t\t----------------------------------" << endl;
        cout << "\t\t |   SISTEMA DE CARRERAS   |" << endl;
        cout << "\t\t----------------------------------" << endl;
        cout << "\t\t 1. Ingresar Carrera" << endl;
        cout << "\t\t 2. Mostrar Carreras" << endl;
        cout << "\t\t 3. Modificar Carrera" << endl;
        cout << "\t\t 4. Buscar Carrera" << endl;
        cout << "\t\t 5. Eliminar Carrera" << endl;
        cout << "\t\t 6. Salir" << endl;
        cout << "\t\t----------------------------------" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1:
                do
                {
                    insertar();

                    cout << "\nDesea agregar otra carrera (Y/N): ";
                    cin >> x;

                }while(x == 'y' || x == 'Y');

                break;

            case 2:
                desplegar();
                break;

            case 3:
                modificar();
                break;

            case 4:
                buscar();
                break;

            case 5:
                borrar();
                break;

            case 6:
                exit(0);
                break;

            default:
                cout << "\nOpcion invalida...";
        }

        getch();

    }while(opcion != 6);
}

void Carrera::insertar()
{
    system("cls");

    fstream file;

    cout << "\n---------------- AGREGAR CARRERA ----------------" << endl;

    cout << "Ingrese codigo de la carrera: ";
    cin >> codigoCarrera;

    cin.ignore();

    cout << "Ingrese nombre de la carrera: ";
    getline(cin, nombreCarrera);

    cout << "Ingrese estado de la carrera (1 = Activa, 0 = Inactiva): ";
    cin >> estadoCarrera;

    file.open("Carreras.txt", ios::app | ios::out);

    file << left << setw(15) << codigoCarrera
         << left << setw(30) << nombreCarrera
         << left << setw(10) << estadoCarrera << "\n";

    file.close();
}

void Carrera::desplegar()
{
    system("cls");

    fstream file;
    int total = 0;

    cout << "\n---------------- LISTA DE CARRERAS ----------------" << endl;

    file.open("Carreras.txt", ios::in);

    if(!file)
    {
        cout << "\nNo hay informacion...";
    }
    else
    {
        file >> codigoCarrera >> nombreCarrera >> estadoCarrera;

        while(!file.eof())
        {
            total++;

            cout << "\nCodigo Carrera: " << codigoCarrera << endl;
            cout << "Nombre Carrera: " << nombreCarrera << endl;
            cout << "Estado Carrera: " << estadoCarrera << endl;

            file >> codigoCarrera >> nombreCarrera >> estadoCarrera;
        }

        if(total == 0)
        {
            cout << "\nNo hay informacion...";
        }
    }

    file.close();
}

void Carrera::modificar()
{
    system("cls");

    fstream file, file1;
    string codigoBuscar;
    int encontrado = 0;

    cout << "\n---------------- MODIFICAR CARRERA ----------------" << endl;

    file.open("Carreras.txt", ios::in);

    if(!file)
    {
        cout << "\nNo hay informacion...";
    }
    else
    {
        cout << "Ingrese el codigo de la carrera a modificar: ";
        cin >> codigoBuscar;

        file1.open("Temporal.txt", ios::app | ios::out);

        file >> codigoCarrera >> nombreCarrera >> estadoCarrera;

        while(!file.eof())
        {
            if(codigoBuscar != codigoCarrera)
            {
                file1 << left << setw(15) << codigoCarrera
                      << left << setw(30) << nombreCarrera
                      << left << setw(10) << estadoCarrera << "\n";
            }
            else
            {
                cout << "\nIngrese nuevo codigo: ";
                cin >> codigoCarrera;

                cin.ignore();

                cout << "Ingrese nuevo nombre: ";
                getline(cin, nombreCarrera);

                cout << "Ingrese nuevo estado (1 = Activa, 0 = Inactiva): ";
                cin >> estadoCarrera;

                file1 << left << setw(15) << codigoCarrera
                      << left << setw(30) << nombreCarrera
                      << left << setw(10) << estadoCarrera << "\n";

                encontrado++;
            }

            file >> codigoCarrera >> nombreCarrera >> estadoCarrera;
        }

        file.close();
        file1.close();

        remove("Carreras.txt");
        rename("Temporal.txt", "Carreras.txt");

        if(encontrado == 0)
        {
            cout << "\nCarrera no encontrada...";
        }
        else
        {
            cout << "\nCarrera modificada correctamente...";
        }
    }
}

void Carrera::buscar()
{
    system("cls");

    fstream file;
    string codigoBuscar;
    int encontrado = 0;

    file.open("Carreras.txt", ios::in);

    if(!file)
    {
        cout << "\nNo hay informacion...";
    }
    else
    {
        cout << "Ingrese el codigo de la carrera a buscar: ";
        cin >> codigoBuscar;

        file >> codigoCarrera >> nombreCarrera >> estadoCarrera;

        while(!file.eof())
        {
            if(codigoBuscar == codigoCarrera)
            {
                cout << "\nCodigo Carrera: " << codigoCarrera << endl;
                cout << "Nombre Carrera: " << nombreCarrera << endl;
                cout << "Estado Carrera: " << estadoCarrera << endl;

                encontrado++;
            }

            file >> codigoCarrera >> nombreCarrera >> estadoCarrera;
        }

        if(encontrado == 0)
        {
            cout << "\nCarrera no encontrada...";
        }
    }

    file.close();
}

void Carrera::borrar()
{
    system("cls");

    fstream file, file1;
    string codigoBuscar;
    int encontrado = 0;

    file.open("Carreras.txt", ios::in);

    if(!file)
    {
        cout << "\nNo hay informacion...";
    }
    else
    {
        cout << "Ingrese el codigo de la carrera a eliminar: ";
        cin >> codigoBuscar;

        file1.open("Temporal.txt", ios::app | ios::out);

        file >> codigoCarrera >> nombreCarrera >> estadoCarrera;

        while(!file.eof())
        {
            if(codigoBuscar != codigoCarrera)
            {
                file1 << left << setw(15) << codigoCarrera
                      << left << setw(30) << nombreCarrera
                      << left << setw(10) << estadoCarrera << "\n";
            }
            else
            {
                encontrado++;
            }

            file >> codigoCarrera >> nombreCarrera >> estadoCarrera;
        }

        file.close();
        file1.close();

        remove("Carreras.txt");
        rename("Temporal.txt", "Carreras.txt");

        if(encontrado == 0)
        {
            cout << "\nCarrera no encontrada...";
        }
        else
        {
            cout << "\nCarrera eliminada correctamente...";
        }
    }

}
string Carrera::getnombreCarrera()
{
    return this -> nombreCarrera;
}
string Carrera::getcodigoCarrera()
{
    return this -> codigoCarrera;
}
bool Carrera::getestadoCarrera()
{
    return this -> estadoCarrera;
}
void Carrera::setnombreCarrera(string nombreCarrera)
{
    this -> nombreCarrera = nombreCarrera;
}
void Carrera::setcodigoCarrera(string codigoCarrera)
{
    this -> codigoCarrera = codigoCarrera;
}
void Carrera::setestadoCcarrera(bool estadoCarrera)
{
    this -> estadoCarrera = estadoCarrera;
}
