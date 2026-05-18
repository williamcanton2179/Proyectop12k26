//9959-25-7858 Jonathan Eladio Chamalé Del cid
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
const string TXT_HORARIOS     = "Horarios.txt"; // <-- Constante para el nuevo archivo
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

// Lógica compartida para procesar formatos estructurados con el separador '|'
bool leerYProcesarFormatoVisual(string nombreArchivo, string carnetPorDefecto, string prefijoAccion) {
    ifstream archivoIn(nombreArchivo);
    if (!archivoIn.is_open()) return false;

    string linea;
    while (getline(archivoIn, linea)) {
        if (linea.empty() || linea.find("==") != string::npos || linea.find("--") != string::npos) continue;
        if (linea.find("|") != string::npos) {
            stringstream ss(linea);
            string col1, col2;
            getline(ss, col1, '|'); getline(ss, col2);

            // Limpieza de espacios en blanco (Trim)
            col1.erase(0, col1.find_first_not_of(" \t")); col1.erase(col1.find_last_not_of(" \t") + 1);
            col2.erase(0, col2.find_first_not_of(" \t")); col2.erase(col2.find_last_not_of(" \t") + 1);

            RegistroBitacora aux;
            aux.carnet = carnetPorDefecto;
            aux.curso = col2;
            aux.accion = prefijoAccion + " (Ref: " + col1 + ")";
            registrarEnBitacora(aux);
        }
    }
    archivoIn.close();
    return true;
}

// Llama al procesador usando el archivo de asignaciones
bool respaldarAsignaciones() {
    return leerYProcesarFormatoVisual(TXT_ASIGNACIONES, "9959-26-1159", "Asignado");
}

// Llama al procesador usando el nuevo archivo de horarios
bool respaldarHorarios() {
    return leerYProcesarFormatoVisual(TXT_HORARIOS, "9959-26-1159", "Horario Importado");
}

// Procesa formatos separados por comas (CSV) de los cobros de tarjeta
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
    if(!f.is_open()) { cout << "Sin registros actuales." << endl; return; }
    while(getline(f, l)) cout << l << endl;
}

void crearRegistroManual() {
    RegistroBitacora n;
    cout << "\nCarnet: "; cin >> n.carnet; cin.ignore();
    cout << "Curso/Carrera: "; getline(cin, n.curso);
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
    if(f) cout << "Eliminacion completada con exito." << endl;
}

void menuRespaldo() {
    int op;
    do {
        cout << "\n--- MODULO AUDITORIA (INTERACTIVE WORLD) ---\n";
        cout << "1. Respaldar Asignaciones\n";
        cout << "2. Respaldar Cobros (TC/TD)\n";
        cout << "3. Respaldar Horarios\n"; // <-- Nueva opción añadida al menú
        cout << "4. Ver Bitacora (Respaldo.txt)\n";
        cout << "5. Registro Manual\n";
        cout << "6. Eliminar Registro\n";
        cout << "0. Volver\n";
        cout << "Opcion: ";
        cin >> op;
        switch(op) {
            case 1: respaldarAsignaciones(); break;
            case 2: respaldarCobroTarjeta(); break;
            case 3: respaldarHorarios(); break; // <-- Ejecuta la nueva función
            case 4: mostrarRespaldo(); break;
            case 5: crearRegistroManual(); break;
            case 6: eliminarRegistroPorCarnet(); break;
        }
    } while (op != 0);
}
