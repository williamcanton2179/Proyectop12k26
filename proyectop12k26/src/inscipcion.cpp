#include <iostream>          //Creado por David Alegria
#include <fstream>
#include "inscipcion.h"

using namespace std;

// ================= MENU =================
void Inscripcion::menu()
{
    int opcion;

    do {
        cout << "\n===== SISTEMA INSCRIPCION =====\n";
        cout << "1. Insertar\n";
        cout << "2. Mostrar\n";
        cout << "3. Buscar\n";
        cout << "4. Modificar\n";
        cout << "5. Eliminar\n";
        cout << "6. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch(opcion)
        {
            case 1: insertar(); break;
            case 2: mostrar(); break;
            case 3: buscar(); break;
            case 4: modificar(); break;
            case 5: eliminar(); break;
        }

    } while(opcion != 6);
}

// ================= INSERTAR =================
void Inscripcion::insertar()
{
    ofstream file("inscripciones.txt", ios::app);

    ingresarDatos();

    file << codigoInscripcion << " "
         << carnetEstudiante << " "
         << nombreEstudiante << " "
         << correoElectronico << " "
         << carrera << " "
         << tipoInscripcion << " "
         << ciclo << " "
         << jornada << " "
         << fechaInscripcion << " "
         << estadoInscripcion << "\n";

    file.close();
}

// ================= MOSTRAR =================
void Inscripcion::mostrar()
{
    ifstream file("inscripciones.txt");

    while(file >> codigoInscripcion >> carnetEstudiante)
    {
        file.ignore();
        getline(file, nombreEstudiante, ' ');
        getline(file, correoElectronico, ' ');
        getline(file, carrera, ' ');
        getline(file, tipoInscripcion, ' ');
        getline(file, ciclo, ' ');
        getline(file, jornada, ' ');
        getline(file, fechaInscripcion, ' ');
        getline(file, estadoInscripcion);

        mostrarDatos();
    }

    file.close();
}

// ================= BUSCAR =================
void Inscripcion::buscar()
{
    ifstream file("inscripciones.txt");
    int codigo;
    bool encontrado = false;

    cout << "Ingrese codigo: ";
    cin >> codigo;

    while(file >> codigoInscripcion >> carnetEstudiante)
    {
        file.ignore();
        getline(file, nombreEstudiante, ' ');
        getline(file, correoElectronico, ' ');
        getline(file, carrera, ' ');
        getline(file, tipoInscripcion, ' ');
        getline(file, ciclo, ' ');
        getline(file, jornada, ' ');
        getline(file, fechaInscripcion, ' ');
        getline(file, estadoInscripcion);

        if(codigoInscripcion == codigo)
        {
            mostrarDatos();
            encontrado = true;
        }
    }

    if(!encontrado)
        cout << "No encontrado\n";

    file.close();
}

// ================= MODIFICAR =================
void Inscripcion::modificar()
{
    ifstream file("inscripciones.txt");
    ofstream temp("temp.txt");

    int codigo;
    cout << "Codigo a modificar: ";
    cin >> codigo;

    while(file >> codigoInscripcion >> carnetEstudiante)
    {
        file.ignore();
        getline(file, nombreEstudiante, ' ');
        getline(file, correoElectronico, ' ');
        getline(file, carrera, ' ');
        getline(file, tipoInscripcion, ' ');
        getline(file, ciclo, ' ');
        getline(file, jornada, ' ');
        getline(file, fechaInscripcion, ' ');
        getline(file, estadoInscripcion);

        if(codigoInscripcion == codigo)
        {
            cout << "Ingrese nuevos datos:\n";
            ingresarDatos();
        }

        temp << codigoInscripcion << " "
             << carnetEstudiante << " "
             << nombreEstudiante << " "
             << correoElectronico << " "
             << carrera << " "
             << tipoInscripcion << " "
             << ciclo << " "
             << jornada << " "
             << fechaInscripcion << " "
             << estadoInscripcion << "\n";
    }

    file.close();
    temp.close();

    remove("inscripciones.txt");
    rename("temp.txt", "inscripciones.txt");
}

// ================= ELIMINAR =================
void Inscripcion::eliminar()
{
    ifstream file("inscripciones.txt");
    ofstream temp("temp.txt");

    int codigo;
    cout << "Codigo a eliminar: ";
    cin >> codigo;

    while(file >> codigoInscripcion >> carnetEstudiante)
    {
        file.ignore();
        getline(file, nombreEstudiante, ' ');
        getline(file, correoElectronico, ' ');
        getline(file, carrera, ' ');
        getline(file, tipoInscripcion, ' ');
        getline(file, ciclo, ' ');
        getline(file, jornada, ' ');
        getline(file, fechaInscripcion, ' ');
        getline(file, estadoInscripcion);

        if(codigoInscripcion != codigo)
        {
            temp << codigoInscripcion << " "
                 << carnetEstudiante << " "
                 << nombreEstudiante << " "
                 << correoElectronico << " "
                 << carrera << " "
                 << tipoInscripcion << " "
                 << ciclo << " "
                 << jornada << " "
                 << fechaInscripcion << " "
                 << estadoInscripcion << "\n";
        }
    }

    file.close();
    temp.close();

    remove("inscripciones.txt");
    rename("temp.txt", "inscripciones.txt");
}

void Inscripcion::ingresarDatos()
{
    cout << "Codigo: "; cin >> codigoInscripcion;
    cout << "Carnet: "; cin >> carnetEstudiante;
    cin.ignore();

    cout << "Nombre: "; getline(cin, nombreEstudiante);
    cout << "Correo: "; getline(cin, correoElectronico);
    cout << "Carrera: "; getline(cin, carrera);
    cout << "Tipo: "; getline(cin, tipoInscripcion);
    cout << "Ciclo: "; getline(cin, ciclo);
    cout << "Jornada: "; getline(cin, jornada);
    cout << "Fecha: "; getline(cin, fechaInscripcion);
    cout << "Estado: "; getline(cin, estadoInscripcion);
}

void Inscripcion::mostrarDatos()
{
    cout << "\nCodigo: " << codigoInscripcion;
    cout << "\nCarnet: " << carnetEstudiante;
    cout << "\nNombre: " << nombreEstudiante;
    cout << "\nCorreo: " << correoElectronico;
    cout << "\nCarrera: " << carrera;
    cout << "\nTipo: " << tipoInscripcion;
    cout << "\nCiclo: " << ciclo;
    cout << "\nJornada: " << jornada;
    cout << "\nFecha: " << fechaInscripcion;
    cout << "\nEstado: " << estadoInscripcion << endl;
}
