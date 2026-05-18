
#include "Recepcion.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
#include <sstream>
#include <algorithm>

using namespace std;

string Recepcion::limpiarTexto(string texto)
{
    transform(texto.begin(), texto.end(), texto.begin(), ::tolower);

    string limpio = "";
    for(char c : texto)
    {
        if(c != '|' && c != '-')
        {
            limpio += c;
        }
    }

    while(!limpio.empty() && limpio[0] == ' ')
        limpio.erase(0,1);

    while(!limpio.empty() && limpio[limpio.size()-1] == ' ')
        limpio.erase(limpio.size()-1,1);

    return limpio;
}

string Recepcion::limpiarCarnet(string texto)
{
    string limpio = "";

    for(char c : texto)
    {
        if(isalnum(c))
        {
            limpio += c;
        }
    }

    return limpio;
}

bool Recepcion::nombreCoincide(string nombreArchivo, string nombreIngresado)
{
    nombreArchivo = limpiarTexto(nombreArchivo);
    nombreIngresado = limpiarTexto(nombreIngresado);

    return nombreArchivo.find(nombreIngresado) != string::npos;
}

bool Recepcion::existeAlumno(string carnetBuscar)
{
    ifstream file("RecepcionAlumnos.txt");

    if(!file.is_open())
        return false;

    string nombreArchivo, carnetArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, carnetArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(limpiarCarnet(carnetArchivo) == limpiarCarnet(carnetBuscar))
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool Recepcion::existeDocente(string codigoBuscar)
{
    ifstream file("RecepcionDocentes.txt");

    if(!file.is_open())
        return false;

    string nombreArchivo, codigoArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, codigoArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(codigoArchivo == codigoBuscar)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

bool Recepcion::alumnoRegistrado(string nombreBuscar, string carnetBuscar)
{
    ifstream file("Alumnos.txt");

    if(!file.is_open())
        return false;

    string linea;

    while(getline(file, linea))
    {
        if(linea.empty())
            continue;

        stringstream ss(linea);

        string carnetArchivo, nombreArchivo, carrera, correo, contra;

        getline(ss, carnetArchivo, '|');
        getline(ss, nombreArchivo, '|');
        getline(ss, carrera, '|');
        getline(ss, correo, '|');
        getline(ss, contra);

        if(limpiarCarnet(carnetArchivo) == limpiarCarnet(carnetBuscar))
        {
            if(nombreCoincide(nombreArchivo, nombreBuscar))
            {
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }
        }
    }

    file.close();
    return false;
}

bool Recepcion::maestroRegistrado(string nombreBuscar, string codigoBuscar)
{
    ifstream file("Maestros.txt");

    if(!file.is_open())
        return false;

    string linea;

    while(getline(file, linea))
    {
        if(linea.empty())
            continue;

        stringstream ss(linea);

        string idArchivo, nombreArchivo, apellidoArchivo, dpiArchivo, codigoArchivo;

        getline(ss, idArchivo, '|');
        getline(ss, nombreArchivo, '|');
        getline(ss, apellidoArchivo, '|');
        getline(ss, dpiArchivo, '|');
        getline(ss, codigoArchivo, '|');

        string nombreCompleto = nombreArchivo + " " + apellidoArchivo;

        if(codigoArchivo == codigoBuscar)
        {
            if(nombreCoincide(nombreCompleto, nombreBuscar))
            {
                file.close();
                return true;
            }
            else
            {
                file.close();
                return false;
            }
        }
    }

    file.close();
    return false;
}

double Recepcion::obtenerPagoAlumno(string carnetBuscar)
{
    ifstream file("Asignaciones.txt");

    if(!file.is_open())
        return 0;

    string linea;
    double total = 0;
    bool encontrado = false;

    while(getline(file, linea))
    {
        string lineaLimpia = limpiarCarnet(linea);

        if(lineaLimpia.find(limpiarCarnet(carnetBuscar)) != string::npos)
        {
            encontrado = true;
        }

        if(encontrado)
        {
            if(linea.find("Q") != string::npos)
            {
                string numero = "";

                for(char c : linea)
                {
                    if(isdigit(c) || c == '.')
                    {
                        numero += c;
                    }
                }

                if(!numero.empty())
                {
                    total += atof(numero.c_str());
                }
            }

            if(linea.find("====") != string::npos)
            {
                break;
            }
        }
    }

    file.close();
    return total;
}

double Recepcion::obtenerPagoMaestro(string codigoBuscar)
{
    return 4500.00;
}

void Recepcion::menu()
{
    int modulo, choice;

    do
    {
        system("cls");

        cout << "===== SISTEMA RECEPCION =====" << endl;
        cout << "1. Modulo Estudiantes" << endl;
        cout << "2. Modulo Docentes" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione opcion: ";
        cin >> modulo;

        switch(modulo)
        {
            case 1:
                system("cls");
                cout << "===== MODULO ESTUDIANTES =====" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Desplegar" << endl;
                cout << "3. Modificar" << endl;
                cout << "4. Buscar" << endl;
                cout << "5. Borrar" << endl;
                cout << "Seleccione opcion: ";
                cin >> choice;

                switch(choice)
                {
                    case 1: insertarpagosAlumnos(); break;
                    case 2: desplegarpagosAlumnos(); break;
                    case 3: modificarpagosAlumnos(); break;
                    case 4: buscarpagosAlumnos(); break;
                    case 5: borrarpagosAlumnos(); break;
                    default: cout << "Opcion invalida." << endl;
                }

                system("pause");
                break;

            case 2:
                system("cls");
                cout << "===== MODULO DOCENTES =====" << endl;
                cout << "1. Insertar" << endl;
                cout << "2. Desplegar" << endl;
                cout << "3. Modificar" << endl;
                cout << "4. Buscar" << endl;
                cout << "5. Borrar" << endl;
                cout << "Seleccione opcion: ";
                cin >> choice;

                switch(choice)
                {
                    case 1: insertarpagosDocentes(); break;
                    case 2: desplegarpagosDocentes(); break;
                    case 3: modificarpagosDocentes(); break;
                    case 4: buscarpagosDocentes(); break;
                    case 5: borrarpagosDocentes(); break;
                    default: cout << "Opcion invalida." << endl;
                }

                system("pause");
                break;

            case 3:
                cout << "Saliendo del sistema..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
                system("pause");
        }

    } while(modulo != 3);
}

void Recepcion::insertarpagosAlumnos()
{
    system("cls");

    cin.ignore();

    cout << "Nombre del alumno: ";
    getline(cin, name);

    cout << "Carnet: ";
    getline(cin, carnet);

    if(existeAlumno(carnet))
    {
        cout << "Este alumno ya tiene pago registrado." << endl;
        return;
    }

    if(!alumnoRegistrado(name, carnet))
    {
        cout << "Alumno no registrado." << endl;
        return;
    }

    double pago = obtenerPagoAlumno(carnet);

    if(pago <= 0)
    {
        cout << "No tiene cursos asignados." << endl;
        return;
    }

    cout << "\nNombre: " << name << endl;
    cout << "Carnet: " << carnet << endl;
    cout << "Usted debe pagar: Q" << pago << endl;

    ofstream file("RecepcionAlumnos.txt", ios::app);
    file << name << "|" << carnet << "|" << pago << endl;
    file.close();

    cout << "\nPago registrado exitosamente." << endl;
}

void Recepcion::desplegarpagosAlumnos()
{
    system("cls");

    ifstream file("RecepcionAlumnos.txt");

    if(!file.is_open())
    {
        cout << "No hay pagos registrados de alumnos." << endl;
        return;
    }

    string nombreArchivo, carnetArchivo, montoArchivo;

    cout << left << setw(30) << "Nombre"
         << setw(20) << "Carnet"
         << setw(15) << "Pago" << endl;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, carnetArchivo, '|') &&
          getline(file, montoArchivo))
    {
        cout << left << setw(30) << nombreArchivo
             << setw(20) << carnetArchivo
             << setw(15) << montoArchivo << endl;
    }

    file.close();
}

void Recepcion::buscarpagosAlumnos()
{
    system("cls");

    cin.ignore();

    string carnetBuscar;
    bool encontrado = false;

    cout << "Ingrese carnet a buscar: ";
    getline(cin, carnetBuscar);

    ifstream file("RecepcionAlumnos.txt");

    string nombreArchivo, carnetArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, carnetArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(limpiarCarnet(carnetArchivo) == limpiarCarnet(carnetBuscar))
        {
            cout << "Nombre: " << nombreArchivo << endl;
            cout << "Carnet: " << carnetArchivo << endl;
            cout << "Pago: Q" << montoArchivo << endl;

            encontrado = true;
            break;
        }
    }

    if(!encontrado)
        cout << "Alumno no encontrado." << endl;

    file.close();
}

void Recepcion::modificarpagosAlumnos()
{
    system("cls");

    cin.ignore();

    string carnetBuscar;
    bool encontrado = false;

    cout << "Ingrese carnet del alumno a modificar: ";
    getline(cin, carnetBuscar);

    ifstream file("RecepcionAlumnos.txt");
    ofstream temp("TempAlumnos.txt");

    string nombreArchivo, carnetArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, carnetArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(limpiarCarnet(carnetArchivo) == limpiarCarnet(carnetBuscar))
        {
            encontrado = true;

            cout << "Nuevo nombre: ";
            getline(cin, nombreArchivo);

            montoArchivo = to_string(obtenerPagoAlumno(carnetArchivo));
        }

        temp << nombreArchivo << "|" << carnetArchivo << "|" << montoArchivo << endl;
    }

    file.close();
    temp.close();

    remove("RecepcionAlumnos.txt");
    rename("TempAlumnos.txt", "RecepcionAlumnos.txt");

    if(encontrado)
        cout << "Registro modificado exitosamente." << endl;
    else
        cout << "Alumno no encontrado." << endl;
}

void Recepcion::borrarpagosAlumnos()
{
    system("cls");

    cin.ignore();

    string carnetBuscar;
    bool encontrado = false;

    cout << "Ingrese carnet del alumno a borrar: ";
    getline(cin, carnetBuscar);

    ifstream file("RecepcionAlumnos.txt");
    ofstream temp("TempAlumnos.txt");

    string nombreArchivo, carnetArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, carnetArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(limpiarCarnet(carnetArchivo) == limpiarCarnet(carnetBuscar))
        {
            encontrado = true;
        }
        else
        {
            temp << nombreArchivo << "|" << carnetArchivo << "|" << montoArchivo << endl;
        }
    }

    file.close();
    temp.close();

    remove("RecepcionAlumnos.txt");
    rename("TempAlumnos.txt", "RecepcionAlumnos.txt");

    if(encontrado)
        cout << "Registro eliminado exitosamente." << endl;
    else
        cout << "Alumno no encontrado." << endl;
}

void Recepcion::insertarpagosDocentes()
{
    system("cls");

    cin.ignore();

    cout << "Nombre del docente: ";
    getline(cin, name);

    cout << "Codigo: ";
    getline(cin, codigo);

    if(existeDocente(codigo))
    {
        cout << "Este docente ya tiene pago registrado." << endl;
        return;
    }

    if(!maestroRegistrado(name, codigo))
    {
        cout << "Docente no registrado." << endl;
        return;
    }

    double pago = obtenerPagoMaestro(codigo);

    cout << "\nNombre: " << name << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Usted recibira: Q" << pago << endl;

    ofstream file("RecepcionDocentes.txt", ios::app);
    file << name << "|" << codigo << "|" << pago << endl;
    file.close();

    cout << "\nPago registrado exitosamente." << endl;
}

void Recepcion::desplegarpagosDocentes()
{
    system("cls");

    ifstream file("RecepcionDocentes.txt");

    if(!file.is_open())
    {
        cout << "No hay pagos registrados de docentes." << endl;
        return;
    }

    string nombreArchivo, codigoArchivo, montoArchivo;

    cout << left << setw(30) << "Nombre"
         << setw(20) << "Codigo"
         << setw(15) << "Pago" << endl;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, codigoArchivo, '|') &&
          getline(file, montoArchivo))
    {
        cout << left << setw(30) << nombreArchivo
             << setw(20) << codigoArchivo
             << setw(15) << montoArchivo << endl;
    }

    file.close();
}

void Recepcion::buscarpagosDocentes()
{
    system("cls");

    cin.ignore();

    string codigoBuscar;
    bool encontrado = false;

    cout << "Ingrese codigo a buscar: ";
    getline(cin, codigoBuscar);

    ifstream file("RecepcionDocentes.txt");

    string nombreArchivo, codigoArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, codigoArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(codigoArchivo == codigoBuscar)
        {
            cout << "Nombre: " << nombreArchivo << endl;
            cout << "Codigo: " << codigoArchivo << endl;
            cout << "Pago: Q" << montoArchivo << endl;

            encontrado = true;
            break;
        }
    }

    if(!encontrado)
        cout << "Docente no encontrado." << endl;

    file.close();
}

void Recepcion::modificarpagosDocentes()
{
    system("cls");

    cin.ignore();

    string codigoBuscar;
    bool encontrado = false;

    cout << "Ingrese codigo del docente a modificar: ";
    getline(cin, codigoBuscar);

    ifstream file("RecepcionDocentes.txt");

    if(!file.is_open())
    {
        cout << "No hay registros de docentes." << endl;
        return;
    }

    ofstream temp("TempDocentes.txt");

    string nombreArchivo, codigoArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, codigoArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(codigoArchivo == codigoBuscar)
        {
            encontrado = true;

            cout << "Nuevo nombre del docente: ";
            getline(cin, nombreArchivo);

            double nuevoPago = obtenerPagoMaestro(codigoArchivo);

            stringstream ss;
            ss << nuevoPago;
            montoArchivo = ss.str();
        }

        temp << nombreArchivo << "|"
             << codigoArchivo << "|"
             << montoArchivo << endl;
    }

    file.close();
    temp.close();

    remove("RecepcionDocentes.txt");
    rename("TempDocentes.txt", "RecepcionDocentes.txt");

    if(encontrado)
    {
        cout << "Registro modificado exitosamente." << endl;
    }
    else
    {
        cout << "Docente no encontrado." << endl;
    }
}

void Recepcion::borrarpagosDocentes()
{
    system("cls");

    cin.ignore();

    string codigoBuscar;
    bool encontrado = false;

    cout << "Ingrese codigo del docente a borrar: ";
    getline(cin, codigoBuscar);

    ifstream file("RecepcionDocentes.txt");

    if(!file.is_open())
    {
        cout << "No hay registros de docentes." << endl;
        return;
    }

    ofstream temp("TempDocentes.txt");

    string nombreArchivo, codigoArchivo, montoArchivo;

    while(getline(file, nombreArchivo, '|') &&
          getline(file, codigoArchivo, '|') &&
          getline(file, montoArchivo))
    {
        if(codigoArchivo == codigoBuscar)
        {
            encontrado = true;
        }
        else
        {
            temp << nombreArchivo << "|"
                 << codigoArchivo << "|"
                 << montoArchivo << endl;
        }
    }

    file.close();
    temp.close();

    remove("RecepcionDocentes.txt");
    rename("TempDocentes.txt", "RecepcionDocentes.txt");

    if(encontrado)
    {
        cout << "Registro eliminado exitosamente." << endl;
    }
    else
    {
        cout << "Docente no encontrado." << endl;
    }
}
