#include <iostream>   //Creado por David Alegria
#include <fstream>
#include <cstdio>
#include "inscipcion.h"

using namespace std;

// ================= MENU =================
void Inscripcion::menu()
{
    int opcion;

    do{
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
            case 1:
                insertar();
                break;

            case 2:
                mostrar();
                break;

            case 3:
                buscar();
                break;

            case 4:
                modificar();
                break;

            case 5:
                eliminar();
                break;

            case 6:
                cout << "\nSaliendo...\n";
                break;

            default:
                cout << "\nOpcion invalida\n";
        }

    }while(opcion != 6);
}

// ================= INSERTAR =================
void Inscripcion::insertar()
{
    ifstream alumnos("Alumnos.txt");

    if(!alumnos)
    {
        cout << "No se pudo abrir el archivo de alumnos\n";
        return;
    }

    ofstream file("inscripciones.txt", ios::app);

    string carnetBuscar;
    bool encontrado = false;

    cout << "Ingrese carnet del alumno: ";
    cin >> carnetBuscar;

    string carnetTemp;
    string nombreTemp;
    string carreraTemp;
    string correoTemp;
    string edadTemp;

    while(getline(alumnos, carnetTemp, '|'))
    {
        getline(alumnos, nombreTemp, '|');
        getline(alumnos, carreraTemp, '|');
        getline(alumnos, correoTemp, '|');
        getline(alumnos, edadTemp);

        // LIMPIAR ESPACIOS
        carnetTemp.erase(0, carnetTemp.find_first_not_of(" "));
        carnetTemp.erase(carnetTemp.find_last_not_of(" ") + 1);

        nombreTemp.erase(0, nombreTemp.find_first_not_of(" "));
        nombreTemp.erase(nombreTemp.find_last_not_of(" ") + 1);

        carreraTemp.erase(0, carreraTemp.find_first_not_of(" "));
        carreraTemp.erase(carreraTemp.find_last_not_of(" ") + 1);

        correoTemp.erase(0, correoTemp.find_first_not_of(" "));
        correoTemp.erase(correoTemp.find_last_not_of(" ") + 1);

        if(carnetTemp == carnetBuscar)
        {
            carnetEstudiante = carnetTemp;
            nombreEstudiante = nombreTemp;
            carrera = carreraTemp;
            correoElectronico = correoTemp;

            encontrado = true;
            break;
        }
    }

    alumnos.close();

    if(!encontrado)
    {
        cout << "\nAlumno no encontrado\n";
        return;
    }

    // MOSTRAR DATOS
    cout << "\n========= DATOS DEL ALUMNO =========\n";
    cout << "Carnet: " << carnetEstudiante << endl;
    cout << "Nombre: " << nombreEstudiante << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Correo: " << correoElectronico << endl;
    cout << "====================================\n";

    cin.ignore();

    cout << "Ciclo: ";
    getline(cin, ciclo);

    cout << "Jornada: ";
    getline(cin, jornada);

    cout << "Fecha: ";
    getline(cin, fechaInscripcion);

    cout << "Estado: ";
    getline(cin, estadoInscripcion);

    // GUARDAR
    file << carnetEstudiante << "|"
         << nombreEstudiante << "|"
         << carrera << "|"
         << correoElectronico << "|"
         << ciclo << "|"
         << jornada << "|"
         << fechaInscripcion << "|"
         << estadoInscripcion << endl;

    file.close();

    cout << "\nInscripcion guardada correctamente\n";
}

// ================= MOSTRAR =================
void Inscripcion::mostrar()
{
    ifstream file("inscripciones.txt");

    while(getline(file, carnetStr, '|'))
    {
        getline(file, nombreEstudiante, '|');
        getline(file, carrera, '|');
        getline(file, correoElectronico, '|');
        getline(file, ciclo, '|');
        getline(file, jornada, '|');
        getline(file, fechaInscripcion, '|');
        getline(file, estadoInscripcion);

        cout << "\n===================================";
        cout << "\nCarnet: " << carnetStr;
        cout << "\nNombre: " << nombreEstudiante;
        cout << "\nCarrera: " << carrera;
        cout << "\nCorreo: " << correoElectronico;
        cout << "\nCiclo: " << ciclo;
        cout << "\nJornada: " << jornada;
        cout << "\nFecha: " << fechaInscripcion;
        cout << "\nEstado: " << estadoInscripcion;
        cout << "\n===================================\n";
    }

    file.close();
}

// ================= BUSCAR =================
void Inscripcion::buscar()
{
    ifstream file("inscripciones.txt");

    string carnetBuscar;
    bool encontrado = false;

    cout << "Ingrese carnet: ";
    cin >> carnetBuscar;

    while(getline(file, carnetStr, '|'))
    {
        getline(file, nombreEstudiante, '|');
        getline(file, carrera, '|');
        getline(file, correoElectronico, '|');
        getline(file, ciclo, '|');
        getline(file, jornada, '|');
        getline(file, fechaInscripcion, '|');
        getline(file, estadoInscripcion);

        if(carnetStr == carnetBuscar)
        {
            encontrado = true;

            cout << "\n===================================";
            cout << "\nCarnet: " << carnetStr;
            cout << "\nNombre: " << nombreEstudiante;
            cout << "\nCarrera: " << carrera;
            cout << "\nCorreo: " << correoElectronico;
            cout << "\nCiclo: " << ciclo;
            cout << "\nJornada: " << jornada;
            cout << "\nFecha: " << fechaInscripcion;
            cout << "\nEstado: " << estadoInscripcion;
            cout << "\n===================================\n";
        }
    }

    if(!encontrado)
    {
        cout << "\nNo encontrado\n";
    }

    file.close();
}

// ================= MODIFICAR =================
void Inscripcion::modificar()
{
    ifstream file("inscripciones.txt");
    ofstream temp("temp.txt");

    string carnetBuscar;
    bool encontrado = false;

    cout << "Carnet a modificar: ";
    cin >> carnetBuscar;

    while(getline(file, carnetStr, '|'))
    {
        getline(file, nombreEstudiante, '|');
        getline(file, carrera, '|');
        getline(file, correoElectronico, '|');
        getline(file, ciclo, '|');
        getline(file, jornada, '|');
        getline(file, fechaInscripcion, '|');
        getline(file, estadoInscripcion);

        if(carnetStr == carnetBuscar)
        {
            encontrado = true;

            cin.ignore();

            cout << "Nuevo Ciclo: ";
            getline(cin, ciclo);

            cout << "Nueva Jornada: ";
            getline(cin, jornada);

            cout << "Nueva Fecha: ";
            getline(cin, fechaInscripcion);

            cout << "Nuevo Estado: ";
            getline(cin, estadoInscripcion);
        }

        temp << carnetStr << "|"
             << nombreEstudiante << "|"
             << carrera << "|"
             << correoElectronico << "|"
             << ciclo << "|"
             << jornada << "|"
             << fechaInscripcion << "|"
             << estadoInscripcion << endl;
    }

    file.close();
    temp.close();

    remove("inscripciones.txt");
    rename("temp.txt", "inscripciones.txt");

    if(encontrado)
    {
        cout << "\nRegistro modificado\n";
    }
    else
    {
        cout << "\nCarnet no encontrado\n";
    }
}

// ================= ELIMINAR =================
void Inscripcion::eliminar()
{
    ifstream file("inscripciones.txt");
    ofstream temp("temp.txt");

    string carnetBuscar;
    bool encontrado = false;

    cout << "Carnet a eliminar: ";
    cin >> carnetBuscar;

    while(getline(file, carnetStr, '|'))
    {
        getline(file, nombreEstudiante, '|');
        getline(file, carrera, '|');
        getline(file, correoElectronico, '|');
        getline(file, ciclo, '|');
        getline(file, jornada, '|');
        getline(file, fechaInscripcion, '|');
        getline(file, estadoInscripcion);

        if(carnetStr != carnetBuscar)
        {
            temp << carnetStr << "|"
                 << nombreEstudiante << "|"
                 << carrera << "|"
                 << correoElectronico << "|"
                 << ciclo << "|"
                 << jornada << "|"
                 << fechaInscripcion << "|"
                 << estadoInscripcion << endl;
        }
        else
        {
            encontrado = true;
        }
    }

    file.close();
    temp.close();

    remove("inscripciones.txt");
    rename("temp.txt", "inscripciones.txt");

    if(encontrado)
    {
        cout << "\nRegistro eliminado\n";
    }
    else
    {
        cout << "\nCarnet no encontrado\n";
    }
}
