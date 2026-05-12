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
    bool saltar = false;
    if (!archivoEntrada.is_open()) return;
    while (getline(archivoEntrada, linea)) {
        if (linea.find("CARNET: " + carnetBuscar) != string::npos) {
            saltar = true;
            continue;
        }
        if (saltar) {
            if (linea.find("==========") != string::npos) saltar = false;
            continue;
        }
        archivoTemporal << linea << endl;
    }
    archivoEntrada.close();
    archivoTemporal.close();
    remove("Asignaciones.txt");
    rename("temp.txt", "Asignaciones.txt");
    cout << ">>> Operacion realizada." << endl;
}

void Asignacion::editarAsignacion() {
    eliminarAsignacion();
    cout << "Re-ingrese los datos correctos:" << endl;

}

void Asignacion::menuAsignacion() {
    int opcionSub;
    do {
        cout << "\n--- SUB-MODULO ASIGNACIONES (CRUD) ---" << endl;
        cout << "1. Crear Nueva Asignacion" << endl;
        cout << "2. Ver Listado" << endl;
        cout << "3. Editar (Eliminar y Re-crear)" << endl;
        cout << "4. Eliminar Registro" << endl;
        cout << "5. Regresar al Menu de Modulos" << endl;
        cout << "Opcion: ";
        cin >> opcionSub;

        if (opcionSub == 1 || (opcionSub == 3)) {
            if (opcionSub == 3) eliminarAsignacion();

            string carnet, codCurso;
            int cantidad;
            Cursos objCursos;
            vector<Cursos> catalogo = objCursos.catalagoCursosIngSistemas();

            cout << "Ingrese carnet: ";
            cin >> carnet;

            if (validarCarnetEnArchivo(carnet)) {
                cout << "\n==========================================================" << endl;
                cout << "           CURSOS DISPONIBLES (PRIMER CICLO)              " << endl;
                cout << "==========================================================" << endl;
                for (size_t i = 0; i < 5; i++) {
                    cout << left << setw(10) << catalogo[i].getcodigoCurso() << " | " << catalogo[i].getnombreCurso() << endl;
                }
                cout << "   ¿Cuantos cursos desea asignarse?: ";
                cin >> cantidad;
                cursosAsignados.clear();
                for(int i = 0; i < cantidad; i++) {
                    cout << "   (" << i+1 << "/" << cantidad << ") Ingrese codigo: ";
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
                            if(c.getnombreCurso() == nombreC)
                                archivoSalida << left << setw(15) << c.getcodigoCurso() << " | " << nombreC << "\n";
                        }
                    }
                    archivoSalida << "==========================================================\n";
                    archivoSalida.close();
                }
            }
        } else if (opcionSub == 2) {
            mostrarAsignaciones();
        } else if (opcionSub == 4) {
            eliminarAsignacion();
        }
    } while(opcionSub != 5);
}
