//Creado por el alumno 9959-25-4900: Jhonny Flores el día 4 de mayo de 2026

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include "reportes.h"
using namespace std;

// Convierte float a string con un decimal
string reportes::floatAString(float v) {
    ostringstream ss;
    ss << fixed << setprecision(1) << v;
    return ss.str();
}

// Muestra un registro formateado
void mostrarRegistro(const string& c,   const string& n,
                     const string& p1,  const string& p2,
                     const string& tar, const string& z,
                     const string& exF, const string& nF,
                     const string& est) {
    cout << "\n  Carnet  : " << c             << endl;
    cout << "  Nombre  : " << n             << endl;
    cout << "  P1      : " << p1  << " / 20" << endl;
    cout << "  P2      : " << p2  << " / 25" << endl;
    cout << "  Tareas  : " << tar << " / 20" << endl;
    cout << "  Zona    : " << z   << " / 65" << endl;
    cout << "  Final   : " << exF << " / 35" << endl;
    cout << "  Total   : " << nF  << " / 100"<< endl;
    cout << "  Estado  : " << est            << endl;
    cout << "  ---------------------------------" << endl;
}

// Parsea una linea del archivo en sus campos
bool parsearLinea(const string& linea, char SEP,
                  string& c,   string& n,
                  string& p1,  string& p2,  string& tar,
                  string& z,   string& exF, string& nF,
                  string& est) {
    if (linea.empty()) return false;
    istringstream ss(linea);
    getline(ss, c,   SEP);
    getline(ss, n,   SEP);
    getline(ss, p1,  SEP);
    getline(ss, p2,  SEP);
    getline(ss, tar, SEP);
    getline(ss, z,   SEP);
    getline(ss, exF, SEP);
    getline(ss, nF,  SEP);
    getline(ss, est);
    return true;
}

// CREATE — llamado desde RegistrarNotas
void reportes::generarDesdeNota(const string& carnet, const string& nombre,
                                 float p1,   float p2,  float tareas,
                                 float zona, float examenFinal,
                                 float notaFinal, const string& estado) {
    fstream file;
    file.open(ARCHIVO, ios::app | ios::out);
    if (!file) {
        cout << "Error al abrir el archivo de reportes." << endl;
        return;
    }

    file << carnet          << SEP
         << nombre          << SEP
         << floatAString(p1)        << SEP
         << floatAString(p2)        << SEP
         << floatAString(tareas)    << SEP
         << floatAString(zona)      << SEP
         << floatAString(examenFinal) << SEP
         << floatAString(notaFinal) << SEP
         << estado << "\n";

    file.close();
    cout << "  Reporte guardado: " << carnet << " - " << nombre << endl;
}

// READ — ver todos los registros
void reportes::acceder() {
    fstream file;
    file.open(ARCHIVO, ios::in);
    if (!file) {
        cout << "\nNo hay reportes guardados aun." << endl;
        return;
    }

    string linea;
    int total = 0;
    cout << "\n===== Reporte de Notas =====" << endl;

    while (getline(file, linea)) {
        string c, n, p1, p2, tar, z, exF, nF, est;
        if (!parsearLinea(linea, SEP, c, n, p1, p2, tar, z, exF, nF, est))
            continue;
        mostrarRegistro(c, n, p1, p2, tar, z, exF, nF, est);
        total++;
    }

    if (total == 0)
        cout << "No hay registros." << endl;
    else
        cout << "\nTotal de registros: " << total << endl;

    file.close();
}

// READ — buscar por carnet
void reportes::buscarPorCarnet() {
    fstream file;
    file.open(ARCHIVO, ios::in);
    if (!file) {
        cout << "\nNo hay reportes guardados aun." << endl;
        return;
    }

    string buscar;
    cout << "Ingrese el carnet a buscar: ";
    getline(cin, buscar);

    string linea;
    bool encontrado = false;

    while (getline(file, linea)) {
        string c, n, p1, p2, tar, z, exF, nF, est;
        if (!parsearLinea(linea, SEP, c, n, p1, p2, tar, z, exF, nF, est))
            continue;
        if (c == buscar) {
            mostrarRegistro(c, n, p1, p2, tar, z, exF, nF, est);
            encontrado = true;
            break;
        }
    }

    if (!encontrado)
        cout << "Carnet no encontrado." << endl;

    file.close();
}

// UPDATE — modificar un registro
void reportes::actualizar() {
    fstream file, temp;
    file.open(ARCHIVO, ios::in);
    if (!file) {
        cout << "\nNo hay reportes guardados aun." << endl;
        return;
    }

    string buscar;
    cout << "Ingrese el carnet a modificar: ";
    getline(cin, buscar);

    temp.open("Temp.txt", ios::out);
    string linea;
    bool encontrado = false;

    while (getline(file, linea)) {
        string c, n, p1, p2, tar, z, exF, nF, est;
        if (!parsearLinea(linea, SEP, c, n, p1, p2, tar, z, exF, nF, est)) {
            temp << linea << "\n";
            continue;
        }

        if (c == buscar) {
            encontrado = true;
            cout << "\nDatos actuales:" << endl;
            mostrarRegistro(c, n, p1, p2, tar, z, exF, nF, est);

            // Pedir nuevos valores y recalcular
            float np1, np2, ntar, nexF;
            cout << "\nIngrese nuevos valores:" << endl;

            cout << "  Nuevo P1 (0-20): ";   cin >> np1;
            cout << "  Nuevo P2 (0-25): ";   cin >> np2;
            cout << "  Nuevas Tareas (0-20): "; cin >> ntar;
            cin.ignore();

            float nzona = np1 + np2 + ntar;
            string nest;

            if (nzona < 26) {
                cout << "  Zona: " << nzona << " — NO habilitado para final." << endl;
                nexF = 0;
                nest = "REPROBADO";
            } else {
                cout << "  Zona: " << nzona << " — Habilitado para final." << endl;
                cout << "  Nuevo Final (0-35): "; cin >> nexF;
                cin.ignore();
                float ntotal = nzona + nexF;
                nest = (ntotal >= 61) ? "APROBADO" : "REPROBADO";
            }

            float ntotal = nzona + nexF;

            temp << c              << SEP
                 << n              << SEP
                 << floatAString(np1)   << SEP
                 << floatAString(np2)   << SEP
                 << floatAString(ntar)  << SEP
                 << floatAString(nzona) << SEP
                 << floatAString(nexF)  << SEP
                 << floatAString(ntotal)<< SEP
                 << nest << "\n";

            cout << "Registro actualizado correctamente." << endl;
        } else {
            temp << linea << "\n";
        }
    }

    if (!encontrado)
        cout << "Carnet no encontrado." << endl;

    file.close();
    temp.close();
    remove(ARCHIVO.c_str());
    rename("Temp.txt", ARCHIVO.c_str());
}

// DELETE — borrar un registro
void reportes::borrar() {
    fstream file, temp;
    file.open(ARCHIVO, ios::in);
    if (!file) {
        cout << "\nNo hay reportes guardados aun." << endl;
        return;
    }

    string buscar;
    cout << "Ingrese el carnet a eliminar: ";
    getline(cin, buscar);

    temp.open("Temp.txt", ios::out);
    string linea;
    bool encontrado = false;

    while (getline(file, linea)) {
        if (linea.empty()) continue;
        istringstream ss(linea);
        string c;
        getline(ss, c, SEP);

        if (c == buscar) {
            encontrado = true;
            cout << "Registro de " << buscar << " eliminado correctamente." << endl;
        } else {
            temp << linea << "\n";
        }
    }

    if (!encontrado)
        cout << "Carnet no encontrado." << endl;

    file.close();
    temp.close();
    remove(ARCHIVO.c_str());
    rename("Temp.txt", ARCHIVO.c_str());
}
