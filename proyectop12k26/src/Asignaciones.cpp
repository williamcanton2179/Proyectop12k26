#include "Asignaciones.h"
#include <iostream>
#include <vector>

using namespace std;

bool Asignacion::validarCarnet(string carnet, vector<Alumnos> listaAlumnos) {
    for (size_t i = 0; i < listaAlumnos.size(); i++) {
        if (listaAlumnos[i].getcarnetPersonal() == carnet) {
            return true;
        }
    }
    return false;
}

void Asignacion::asignarCurso(string carnet, string codCurso, vector<Cursos> catalogo, vector<string> cursosAprobados) {
    for (size_t i = 0; i < catalogo.size(); i++) {
        if (catalogo[i].getcodigoCurso() == codCurso) {
            string preReq = catalogo[i].getpreRequisitoDeCurso();
            if (preReq == "Ninguno") {
                cout << "Asignacion exitosa: " << catalogo[i].getnombreCurso() << endl;
                cursosAsignados.push_back(codCurso);
            } else {
                bool cumplido = false;
                for (const string& codigo : cursosAprobados) {
                    if (codigo == preReq) {
                        cumplido = true;
                        break;
                    }
                }
                if (cumplido) {
                    cout << "Asignacion exitosa: " << catalogo[i].getnombreCurso() << endl;
                    cursosAsignados.push_back(codCurso);
                } else {
                    cout << "Error: No cumple con el prerequisito: " << preReq << endl;
                }
            }
            return;
        }
    }
}

vector<string> Asignacion::getCursosAsignados() {
    return cursosAsignados;
}
