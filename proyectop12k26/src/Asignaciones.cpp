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

void Asignacion::menuAsignacion() {
    string carnet, codCurso;
    int cantidad;

    Cursos objCursos;
    vector<Cursos> catalogo = objCursos.catalagoCursosIngSistemas();

    cout << "\n--- MODULO DE ASIGNACIONES ---" << endl;
    cout << "Ingrese carnet: ";
    cin >> carnet;

    if (validarCarnetEnArchivo(carnet)) {
        cout << "\n[SISTEMA] Carnet verificado exitosamente." << endl;

        // 1. MOSTRAR LISTA DE CURSOS
        cout << "\n==========================================================" << endl;
        cout << "           CURSOS DISPONIBLES (PRIMER CICLO)              " << endl;
        cout << "==========================================================" << endl;
        cout << left << setw(10) << "CODIGO" << " | " << "NOMBRE DEL CURSO" << endl;
        cout << "----------------------------------------------------------" << endl;
        for (size_t i = 0; i < 5; i++) {
            cout << left << setw(10) << catalogo[i].getcodigoCurso()
                 << " | " << catalogo[i].getnombreCurso() << endl;
        }
        cout << "==========================================================\n" << endl;

        // 2. PREGUNTAR CUANTOS Y ASIGNAR
        cout << "   ¿Cuantos cursos desea asignarse?: ";
        cin >> cantidad;

        for(int i = 0; i < cantidad; i++) {
            cout << "   (" << i+1 << "/" << cantidad << ") Ingrese codigo: ";
            cin >> codCurso;

            bool encontrado = false;
            for (auto& curso : catalogo) {
                if (curso.getcodigoCurso() == codCurso) {
                    cursosAsignados.push_back(curso.getnombreCurso()); // Guardamos nombre para el TXT
                    cout << "   >> OK: " << curso.getnombreCurso() << endl;
                    encontrado = true;
                    break;
                }
            }
            if (!encontrado) {
                cout << "   [!] Codigo no existe, repita entrada." << endl;
                i--;
            }
        }

        // 3. GENERAR ARCHIVO DE TEXTO
        ofstream archivoSalida("Asignaciones.txt", ios::app);
        if (archivoSalida.is_open()) {
            archivoSalida << "\n==========================================================\n";
            archivoSalida << "REGISTRO DE ASIGNACION - CARNET: " << carnet << "\n";
            archivoSalida << "----------------------------------------------------------\n";
            archivoSalida << left << setw(15) << "CODIGO" << " | " << "NOMBRE DEL CURSO" << "\n";
            archivoSalida << "----------------------------------------------------------\n";

            for (const string& nombreC : cursosAsignados) {
                for(auto& c : catalogo) {
                    if(c.getnombreCurso() == nombreC) {
                        archivoSalida << left << setw(15) << c.getcodigoCurso()
                                      << " | " << nombreC << "\n";
                    }
                }
            }
            archivoSalida << "==========================================================\n";
            archivoSalida.close();
            cout << "\n>>> PROCESO FINALIZADO. Se ha actualizado Asignaciones.txt <<<" << endl;
        }

    } else {
        cout << "\n[!] ERROR: El carnet no existe en la base de datos." << endl;
    }
}
