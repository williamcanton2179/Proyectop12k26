//Creado por Axel Andrino - 9959-25-8978
#include "GeneradorConstancias.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

// CONSTRUCTOR: Aquí inicializamos las variables
GeneradorConstancias::GeneradorConstancias() {
    id = "";
    nombre = "";
    carnet = "";
    monto = 0.0;
    tipoPersona = 0;
    srand(time(0));
}

// DESTRUCTOR
GeneradorConstancias::~GeneradorConstancias() {}

void GeneradorConstancias::imprimirEncabezadoBanco() {
    cout << "\n      SISTEMA BANCARIO UNIVERSIDAD (UMG)      " << endl;
    cout << "================================================" << endl;
}

void GeneradorConstancias::disenoConstancia() {
    system("cls");
    imprimirEncabezadoBanco();
    if (tipoPersona == 1) cout << "           COMPROBANTE DE PAGO - ALUMNO         " << endl;
    else cout << "        CONSTANCIA DE PAGO - CATEDRATICO        " << endl;

    cout << "ID Registro: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Identificacion: " << carnet << endl;
    cout << "Monto: Q" << monto << endl;
    cout << "No. Operacion: " << (1000 + rand() % 9000) << endl;
    cout << "================================================" << endl;
}

void GeneradorConstancias::insertar() {
    system("cls");
    fstream file;
    char respuesta;

    cout << "--- Registro de Nuevo Pago ---" << endl;
    cout << "ID de Operacion: "; cin >> id;
    cout << "Nombre: "; cin >> nombre;
    cout << "Carnet/DPI: "; cin >> carnet;
    cout << "Monto: Q"; cin >> monto;
    cout << "Tipo (1.Alumno / 2.Catedratico): "; cin >> tipoPersona;

    file.open("Constancias.txt", ios::app | ios::out);
    file << id << " " << nombre << " " << carnet << " " << monto << " " << tipoPersona << "\n";
    file.close();

    cout << "\n[!] Datos guardados correctamente." << endl;
    cout << "\xbfDesea imprimir la constancia en este momento? (S/N): ";
    cin >> respuesta;

    if (respuesta == 'S' || respuesta == 's') {
        disenoConstancia();
    }
}

void GeneradorConstancias::desplegar() {
    system("cls");
    fstream file;
    file.open("Constancias.txt", ios::in);
    if (!file) {
        cout << "No hay registros guardados." << endl;
    } else {
        cout << "ID\tNombre\t\tMonto" << endl;
        cout << "------------------------------------" << endl;
        while (file >> id >> nombre >> carnet >> monto >> tipoPersona) {
            cout << id << "\t" << nombre << "\t\tQ" << monto << endl;
        }
    }
    file.close();
}

void GeneradorConstancias::buscar() {
    system("cls");
    fstream file;
    string target;
    bool found = false;
    cout << "ID a buscar: "; cin >> target;
    file.open("Constancias.txt", ios::in);
    while (file >> id >> nombre >> carnet >> monto >> tipoPersona) {
        if (target == id) {
            cout << "\nRegistro Encontrado: " << nombre << " | Monto: Q" << monto << endl;
            found = true;
        }
    }
    file.close();
    if (!found) cout << "No se encontro el ID." << endl;
}

void GeneradorConstancias::borrar() {
    system("cls");
    fstream file, file1;
    string target;
    int found = 0;
    file.open("Constancias.txt", ios::in);
    if (file) {
        cout << "ID a borrar: "; cin >> target;
        file1.open("Temp.txt", ios::out);
        while (file >> id >> nombre >> carnet >> monto >> tipoPersona) {
            if (target != id) file1 << id << " " << nombre << " " << carnet << " " << monto << " " << tipoPersona << "\n";
            else found++;
        }
        file.close(); file1.close();
        remove("Constancias.txt");
        rename("Temp.txt", "Constancias.txt");
        if (found) cout << "\nRegistro eliminado con exito." << endl;
    }
}

void GeneradorConstancias::seleccionarEImprimir() {
    system("cls");
    fstream file;
    string target;
    bool found = false;
    cout << "ID para imprimir: "; cin >> target;
    file.open("Constancias.txt", ios::in);
    while (file >> id >> nombre >> carnet >> monto >> tipoPersona) {
        if (target == id) {
            disenoConstancia();
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "\n[!] ID no encontrado." << endl;
}

void GeneradorConstancias::menu() {
    int choice;
    do {
        system("cls");
        cout << "\t-------------------------------" << endl;
        cout << "\t |   SISTEMA GESTION CONSTANCIAS  |" << endl;
        cout << "\t-------------------------------" << endl;
        cout << "1. Registrar Pago" << endl;
        cout << "2. Ver Listado" << endl;
        cout << "3. Buscar por ID" << endl;
        cout << "4. Borrar Registro " << endl;
        cout << "5. Seleccionar e Imprimir" << endl;
        cout << "6. Salir" << endl;
        cout << "\n\t Opcion: "; cin >> choice;

        switch(choice) {
            case 1: insertar(); break;
            case 2: desplegar(); break;
            case 3: buscar(); break;
            case 4: borrar(); break;
            case 5: seleccionarEImprimir(); break;
        }
        if (choice != 6) { system("pause"); }
    } while (choice != 6);
}
bool GeneradorConstancias::validarConstancia(int numeroBoleta) {

    if (numeroBoleta > 0) {
        return true;
    }
    return false;
}
void GeneradorConstancias::recibirDatos(string n, string c, float m, int t) {
    nombre = n;
    carnet = c;
    monto = m;
    tipoPersona = t;
    fstream file;
    file.open("Constancias.txt", ios::app | ios::out);
    file << "AUTO" << " " << nombre << " " << carnet << " " << monto << " " << tipoPersona << "\n";
    file.close();
}
