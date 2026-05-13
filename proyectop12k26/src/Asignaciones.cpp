#include "Asignaciones.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

bool Asignacion::validarCarnetEnArchivo(string carnet) {
    ifstream archivo("Alumnos.txt");
    string linea;
    if (!archivo.is_open()) return false;
    while (getline(archivo, linea)) {
        if (linea.find(carnet) != string::npos) {
            archivo.close();
            return true;
        }
    }
    archivo.close();
    return false;
}

void Asignacion::mostrarAsignaciones() {
    ifstream archivo("Asignaciones.txt");
    string linea;
    if (!archivo.is_open()) {
        cout << "No hay registros todavia." << endl;
        return;
    }
    while (getline(archivo, linea)) {
        cout << linea << endl;
    }
    archivo.close();
}

void Asignacion::eliminarAsignacion() {
    string carnetBuscar;
    cout << "Ingrese carnet a eliminar: ";
    cin >> carnetBuscar;

    ifstream archivoEntrada("Asignaciones.txt");
    ofstream archivoTemporal("temp.txt");
    string linea;
    bool bloqueEncontrado = false;

    if (!archivoEntrada.is_open()) return;

    while (getline(archivoEntrada, linea)) {
        if (linea.find("REGISTRO DE ASIGNACION - CARNET: " + carnetBuscar) != string::npos) {
            bloqueEncontrado = true;
            continue;
        }

        if (bloqueEncontrado) {
            if (linea.find("==========================================================") != string::npos) {
                bloqueEncontrado = false;
            }
            continue;
        }

        if (!linea.empty() && linea != "\r") {
            archivoTemporal << linea << endl;
        }
    }

    archivoEntrada.close();
    archivoTemporal.close();

    remove("Asignaciones.txt");
    rename("temp.txt", "Asignaciones.txt");
    cout << "   [+] Asignacion de carnet " << carnetBuscar << " eliminada con exito." << endl;
}

void Asignacion::menuAsignacion() {
    int opcionSub;
    Cursos cursoObj;
    vector<Cursos> catalogo = cursoObj.catalagoCursosIngSistemas();

    do {
        cout << "\n   --- SUBMENU ASIGNACIONES ---" << endl;
        cout << "   1. Realizar Asignacion" << endl;
        cout << "   2. Ver Asignaciones" << endl;
        cout << "   4. Eliminar Asignacion" << endl;
        cout << "   5. Regresar" << endl;
        cout << "   Opcion: ";
        cin >> opcionSub;

        if (opcionSub == 1) {
            string carnet;
            cout << "   Ingrese carnet del alumno: ";
            cin >> carnet;
            if (validarCarnetEnArchivo(carnet)) {

                cout << "\n   --- CURSOS DISPONIBLES (PRIMER CICLO) ---" << endl;
                cout << left << setw(10) << "CODIGO" << " | " << setw(35) << "NOMBRE DEL CURSO" << " | " << "COSTO" << endl;
                cout << "   --------------------------------------------------------------" << endl;

                for (int i = 0; i < 5 && i < (int)catalogo.size(); i++) {
                    cout << "   " << left << setw(7) << catalogo[i].getcodigoCurso()
                         << " | " << setw(35) << catalogo[i].getnombreCurso()
                         << " | Q" << fixed << setprecision(2) << catalogo[i].getcostoCurso() << endl;
                }

                int numCursos;
                cout << "\n   Cuantos cursos desea asignar? ";
                cin >> numCursos;
                vector<string> cursosAsignados;
                for (int i = 0; i < numCursos; i++) {
                    string codCurso;
                    cout << "   Codigo curso " << i+1 << ": ";
                    cin >> codCurso;
                    bool encontrado = false;
                    for (auto& curso : catalogo) {
                        if (curso.getcodigoCurso() == codCurso) {
                            cursosAsignados.push_back(curso.getnombreCurso());
                            encontrado = true;
                            break;
                        }
                    }
                    if (!encontrado) { cout << "   [!] Codigo no existe." << endl; i--; }
                }

                ofstream archivoSalida("Asignaciones.txt", ios::app);
                if (archivoSalida.is_open()) {
                    archivoSalida << "\n==========================================================\n";
                    archivoSalida << "REGISTRO DE ASIGNACION - CARNET: " << carnet << "\n";
                    archivoSalida << "----------------------------------------------------------\n";

                    for (const string& nombreC : cursosAsignados) {
                        for(auto& c : catalogo) {
                            if(c.getnombreCurso() == nombreC) {
                                archivoSalida << left << setw(10) << c.getcodigoCurso()
                                              << " | " << setw(35) << nombreC
                                              << " | Q" << fixed << setprecision(2) << c.getcostoCurso() << "\n";
                            }
                        }
                    }

                    archivoSalida << "==========================================================\n";
                    archivoSalida.close();
                    cout << "   [+] Asignacion guardada con exito." << endl;
                }
            } else {
                cout << "   [!] Carnet no encontrado en Alumnos.txt" << endl;
            }
        } else if (opcionSub == 2) {
            mostrarAsignaciones();
        } else if (opcionSub == 4) {
            eliminarAsignacion();
        }
    } while(opcionSub != 5);
}
