#include "MenuAsignaciones.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void MenuAsignaciones::ejecutarMenu() {
    string carnet;
    cout << "--- SISTEMA DE ASIGNACIONES ---" << endl;
    cout << "Ingrese su carnet: ";
    cin >> carnet;

    Cursos gestor;
    vector<Cursos> catalogoCompleto = gestor.catalagoCursosIngSistemas();

    vector<Cursos> primerCiclo;
    for(int i = 0; i < 5; i++) {
        primerCiclo.push_back(catalogoCompleto[i]);
    }

    cout << "\nCursos disponibles del Primer Ciclo:" << endl;
    for(size_t i = 0; i < primerCiclo.size(); i++) {
        cout << "[" << primerCiclo[i].getcodigoCurso() << "] " << primerCiclo[i].getnombreCurso() << endl;
    }

    int cantidad;
    cout << "\n¿Cuantos cursos desea asignarse?: ";
    cin >> cantidad;
    if(cantidad > 5) cantidad = 5;

    vector<Cursos> asignados;
    for(int i = 0; i < cantidad; i++) {
        string cod;
        cout << "Ingrese el codigo del curso " << i+1 << ": ";
        cin >> cod;
        for(size_t j = 0; j < primerCiclo.size(); j++) {
            if(primerCiclo[j].getcodigoCurso() == cod) {
                asignados.push_back(primerCiclo[j]);
            }
        }
    }

    ofstream archivo("asignacion_" + carnet + ".txt");
    if (archivo.is_open()) {
        archivo << "Carnet: " << carnet << endl;
        archivo << "Cursos Asignados:" << endl;
        for(size_t i = 0; i < asignados.size(); i++) {
            archivo << asignados[i].getcodigoCurso() << " - " << asignados[i].getnombreCurso() << endl;
        }
        archivo.close();
        cout << "\nArchivo generado: asignacion_" << carnet << ".txt" << endl;
    } else {
        cout << "Error al crear el archivo." << endl;
    }
}
