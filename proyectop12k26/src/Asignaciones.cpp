#include "Asignaciones.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// Revisa si el alumno existe en el archivo de texto
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

// Muestra lo que ya esta guardado en el txt
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

// Borra el bloque completo del carnet sin arruinar el formato
void Asignacion::eliminarAsignacion() {
    string carnetBuscar;
    cout << "Ingrese carnet a eliminar: ";
    cin >> carnetBuscar;

    ifstream archivoEntrada("Asignaciones.txt");
    ofstream archivoTemporal("temp.txt");
    string linea;
    bool saltarBloque = false;
    bool encontrado = false;
    string ID = "ID:" + carnetBuscar;

    if (!archivoEntrada.is_open()) return;

    while (getline(archivoEntrada, linea)) {
        if (linea.find(ID) != string::npos) {
            saltarBloque = true;
            encontrado = true;
            continue;
        }

        if (saltarBloque) {
            if (linea.find("==========================================================") != string::npos) {
                saltarBloque = false;
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

    if (encontrado) {
        cout << "   [+] Asignacion de carnet " << carnetBuscar << " eliminada con exito." << endl;
    } else {
        cout << "   [!] No se encontro el registro." << endl;
    }
}

// Menu principal de mi modulo
void Asignacion::menuAsignacion() {
    int opcionSub;
    Cursos cursoObj;
    // Cargo todos los cursos del catalogo de Fernando
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
                int ciclo;
                cout << "   Que ciclo desea consultar? (1-10): ";
                cin >> ciclo;

                // Cada ciclo tiene exactamente 5 cursos segun Cursos.cpp
                int inicio = (ciclo - 1) * 5;
                int fin = inicio + 5;
                int cursosDisponiblesEnCiclo = 5;

                if (inicio >= 0 && inicio < (int)catalogo.size()) {
                    cout << "\n   --- CURSOS DISPONIBLES (CICLO " << ciclo << ") ---" << endl;
                    cout << left << setw(10) << "CODIGO" << " | " << setw(35) << "NOMBRE DEL CURSO" << " | " << "REQUISITO" << endl;
                    cout << "   ----------------------------------------------------------------------------" << endl;

                    for (int i = inicio; i < fin && i < (int)catalogo.size(); i++) {
                        cout << "   " << left << setw(7) << catalogo[i].getcodigoCurso()
                             << " | " << setw(35) << catalogo[i].getnombreCurso()
                             << " | " << catalogo[i].getpreRequisitoDeCurso() << endl; // Usando getter de pre-requisito
                    }

                    int numCursos;
                    cout << "\n   Cuantos cursos desea asignar? (Maximo " << cursosDisponiblesEnCiclo << "): ";
                    cin >> numCursos;

                    // VALIDACION 1: No dejar que pida mas cursos de los que tiene el ciclo
                    while (numCursos < 1 || numCursos > cursosDisponiblesEnCiclo) {
                        cout << "   [!] Cantidad invalida. Ingrese un numero entre 1 y " << cursosDisponiblesEnCiclo << ": ";
                        cin >> numCursos;
                    }

                    vector<string> seleccionados;
                    for (int i = 0; i < numCursos; i++) {
                        string cod;
                        cout << "   Codigo curso " << i+1 << ": ";
                        cin >> cod;

                        bool encontradoEnCiclo = false;
                        // VALIDACION 2: Solo buscar dentro del rango del ciclo (inicio a fin)
                        for (int j = inicio; j < fin && j < (int)catalogo.size(); j++) {
                            if (catalogo[j].getcodigoCurso() == cod) {
                                // Valido si tiene requisito
                                if (catalogo[j].getpreRequisitoDeCurso() != "Ninguno") {
                                    char resp;
                                    cout << "   [!] Este curso pide: " << catalogo[j].getpreRequisitoDeCurso() << ". ¿Ya lo aprobo? (s/n): ";
                                    cin >> resp;
                                    if (resp == 'n' || resp == 'N') {
                                        cout << "   [!] No se puede asignar este curso por falta de requisito." << endl;
                                        encontradoEnCiclo = true;
                                        break;
                                    }
                                }
                                seleccionados.push_back(catalogo[j].getnombreCurso());
                                encontradoEnCiclo = true;
                                break;
                            }
                        }

                        if (!encontradoEnCiclo) {
                            cout << "   [!] El codigo " << cod << " no pertenece al Ciclo " << ciclo << "." << endl;
                            i--; // Repetir este turno para que el conteo de cursos sea correcto
                        }
                    }

                    // Escribo al archivo manteniendo el formato original
                    if (!seleccionados.empty()) {
                        ofstream archivoSalida("Asignaciones.txt", ios::app);
                        if (archivoSalida.is_open()) {
                            archivoSalida << "ID:" << carnet << "\n";
                            archivoSalida << "REGISTRO DE ASIGNACION - CARNET: " << carnet << "\n";
                            archivoSalida << "----------------------------------------------------------\n";

                            for (const string& nombreC : seleccionados) {
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
                    }
                } else {
                    cout << "   [!] Ciclo fuera de rango." << endl;
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
