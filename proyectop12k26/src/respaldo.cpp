#include "../include/respaldo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

// Archivos físicos configurados
const string TXT_ASIGNACIONES = "Asignaciones.txt";
const string TXT_CREDITO      = "tarjetacredito.txt";
const string TXT_DEBITO       = "tarjetadebito.txt";
const string ARCHIVO_FINAL    = "Respaldo.txt";

string obtenerFechaHora() {
    time_t t = time(nullptr);
    tm tm = *localtime(&t);
    ostringstream oss;
    oss << put_time(&tm, "%d/%m/%Y %H:%M:%S");
    return oss.str();
}

void registrarEnBitacora(const RegistroBitacora &reg) {
    ofstream archivo(ARCHIVO_FINAL, ios::app);
    if (archivo.is_open()) {
        archivo << "[" << obtenerFechaHora() << "] "
                << "Carnet: " << reg.carnet << " | "
                << "Carrera/Curso: " << reg.curso << " | "
                << "Accion: " << reg.accion << "\n";
        archivo.close();
    }
}

// Procesa el formato visual de Asignaciones (separador '|')
bool respaldarAsignaciones() {
    ifstream archivoIn(TXT_ASIGNACIONES);
    if (!archivoIn.is_open()) return false;

    string linea;
    string carnetFijo = "9959-26-1159";

    while (getline(archivoIn, linea)) {
        if (linea.empty() || linea.find("==") != string::npos || linea.find("--") != string::npos) continue;
        if (linea.find("|") != string::npos) {
            stringstream ss(linea);
            string cod, curso;
            getline(ss, cod, '|'); getline(ss, curso);

            // Limpieza de espacios
            cod.erase(0, cod.find_first_not_of(" \t")); cod.erase(cod.find_last_not_of(" \t") + 1);
            curso.erase(0, curso.find_first_not_of(" \t")); curso.erase(curso.find_last_not_of(" \t") + 1);

            RegistroBitacora aux = {carnetFijo, curso, "Asignado (Cod: " + cod + ")"};
            registrarEnBitacora(aux);
        }
    }
    archivoIn.close();
    return true;
}

// Procesa formatos CSV de cobros
bool respaldarCobroTarjeta() {
    auto proc = [](string nom) {
        ifstream f(nom); string l;
        while(getline(f, l)) {
            if(l.empty()) continue;
            stringstream ss(l); RegistroBitacora a;
            getline(ss, a.carnet, ','); getline(ss, a.curso, ','); getline(ss, a.accion, ',');
            registrarEnBitacora(a);
        }
    };
    proc(TXT_CREDITO); proc(TXT_DEBITO);
    return true;
}

void mostrarRespaldo() {
    ifstream f(ARCHIVO_FINAL); string l;
    cout << "\n--- BITACORA DE RESPALDO ---" << endl;
    if(!f.is_open()) { cout << "Sin registros." << endl; return; }
    while(getline(f, l)) cout << l << endl;
}

void crearRegistroManual() {
    RegistroBitacora n;
    cout << "\nCarnet: "; cin >> n.carnet; cin.ignore();
    cout << "Curso: "; getline(cin, n.curso);
    cout << "Accion: "; getline(cin, n.accion);
    registrarEnBitacora(n);
}

void eliminarRegistroPorCarnet() {
    string id; cout << "\nCarnet a eliminar: "; cin >> id;
    ifstream in(ARCHIVO_FINAL); ofstream out("Temp.txt");
    string l; bool f = false;
    while(getline(in, l)) {
        if(l.find(id) == string::npos) out << l << "\n";
        else f = true;
    }
    in.close(); out.close();
    remove(ARCHIVO_FINAL.c_str()); rename("Temp.txt", ARCHIVO_FINAL.c_str());
    if(f) cout << "Eliminado con exito." << endl;
}

void menuRespaldo() {
    int op;
    do {
        cout << "\n--- MODULO AUDITORIA ---\n";
        cout << "1. Respaldar Asignaciones\n2. Respaldar Cobros\n3. Ver Bitacora\n4. Registro Manual\n5. Eliminar Registro\n0. Volver\nOpcion: ";
        cin >> op;
        switch(op) {
            case 1: respaldarAsignaciones(); break;
            case 2: respaldarCobroTarjeta(); break;
            case 3: mostrarRespaldo(); break;
            case 4: crearRegistroManual(); break;
            case 5: eliminarRegistroPorCarnet(); break;
        }
    } while (op != 0);
}
