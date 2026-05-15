//Creado por Axel Andrino - 9959-25-8978
#include "GeneradorConstancias.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using namespace std;

GeneradorConstancias::GeneradorConstancias() {
    id = "";
    nombre = "";
    carnet = "";
    monto = 0.0;
    tipoPersona = 0;
    srand(time(0));
}

GeneradorConstancias::~GeneradorConstancias() {}

void GeneradorConstancias::imprimirEncabezadoBanco() {
    cout << "\n      SISTEMA BANCARIO UNIVERSIDAD (UMG)      " << endl;
    cout << "================================================" << endl;
}

// Version que limpia pantalla (para Buscar e Insertar)
void GeneradorConstancias::disenoConstancia() {
    system("cls");
    imprimirEncabezadoBanco();
    if (tipoPersona == 1) cout << "           COMPROBANTE DE PAGO - ALUMNO         " << endl;
    else cout << "        CONSTANCIA DE PAGO - CATEDRATICO        " << endl;

    cout << "ID Registro: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Carnet: " << carnet << endl;
    cout << "Monto: Q" << monto << endl;
    cout << "No. Operacion: " << (1000 + rand() % 9000) << endl;
    cout << "================================================" << endl;
}

// Version que NO limpia pantalla (para el Listado)
void GeneradorConstancias::disenoConstanciaListado() {
    imprimirEncabezadoBanco();
    if (tipoPersona == 1) cout << "           COMPROBANTE DE PAGO - ALUMNO         " << endl;
    else cout << "        CONSTANCIA DE PAGO - CATEDRATICO        " << endl;

    cout << "ID Registro: " << id << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Carnet: " << carnet << endl;
    cout << "Monto: Q" << monto << endl;
    cout << "No. Operacion: " << (1000 + rand() % 9000) << endl;
    cout << "================================================" << endl;
}
// Nueva función para validar que el ID sea único
bool GeneradorConstancias::idExiste(string searchId) {
    ifstream file("Constancias.txt");
    string f_id, f_nombre, f_carnet;
    float f_monto;
    int f_tipo;
    while (file >> f_id >> f_nombre >> f_carnet >> f_monto >> f_tipo) {
        if (f_id == searchId) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

void GeneradorConstancias::insertar() {
    system("cls");
    // Usamos fstream con app para asegurar que ESCRIBA AL FINAL siempre
    ofstream file("Constancias.txt", ios::app);
    char respuesta;
    string nuevoId;

    cout << "--- Registro de Nuevo Pago ---" << endl;

    // Validación de ID único para evitar errores en el banco
    do {
        cout << "ID de Operacion: "; cin >> nuevoId;
        if (idExiste(nuevoId)) {
            cout << "[!] El ID ya existe. Ingrese uno diferente." << endl;
        }
    } while (idExiste(nuevoId));

    id = nuevoId;
    cout << "Nombre: "; cin >> nombre;
    cout << "Carnet: "; cin >> carnet;
    cout << "Monto: Q"; cin >> monto;
    cout << "Tipo (1.Alumno / 2.Catedratico): "; cin >> tipoPersona;

    // Guardado forzando el salto de línea al final
    file << id << " " << nombre << " " << carnet << " " << monto << " " << tipoPersona << endl;
    file.close();

    cout << "\n[!] Datos guardados exitosamente en la base de datos." << endl;
    cout << "Desea visualizar el comprobante ahora? (S/N): ";
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
        cout << "[!] No hay registros guardados." << endl;
    } else {
        while (file >> id >> nombre >> carnet >> monto >> tipoPersona) {
            disenoConstanciaListado();
            cout << "\n";
        }
    }
    file.close();
}

void GeneradorConstancias::buscar() {
    ifstream file("Constancias.txt");
    string searchId;
    bool found = false;
    cout << "Ingrese el ID para buscar e imprimir: ";
    cin >> searchId;

    while (file >> id >> nombre >> carnet >> monto >> tipoPersona) {
        if (id == searchId) {
            disenoConstancia();
            found = true;
            break;
        }
    }
    file.close();
    if (!found) cout << "\n[!] No se encontro ninguna constancia con ese ID." << endl;
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
        else cout << "\nNo se encontro el ID para borrar." << endl;
    }
}

void GeneradorConstancias::menu() {
    int choice;
    do {
        system("cls");
        cout << "========================================" << endl;
        cout << "      SISTEMA GESTION CONSTANCIAS" << endl;
        cout << "========================================" << endl;
        cout << "1. Crear Constancia" << endl;
        cout << "2. Desplegar Todas las Constancias" << endl;
        cout << "3. Buscar constancias" << endl;
        cout << "4. Borrar Constancia" << endl;
        cout << "5. Regresar al Menu de Tesoreria" << endl;
        cout << "========================================" << endl;
        cout << "\n\t Opcion: ";
        cin >> choice;

        switch(choice) {
            case 1: insertar(); break;
            case 2: desplegar(); break;
            case 3: buscar(); break;
            case 4: borrar(); break;
            case 5: cout << "Regresando a Tesoreria..." << endl; break;
            default: cout << "Opcion no valida." << endl;
        }

        if (choice != 5) {
            cout << "\nPresione ENTER para volver al menu...";
            system("pause > nul");
        }

    } while (choice != 5);
}

bool GeneradorConstancias::validarConstancia(int numeroBoleta) {
    return (numeroBoleta > 0);
}

void GeneradorConstancias::recibirDatos(string n, string c, float m, int t) {
    nombre = n; carnet = c; monto = m; tipoPersona = t;
    fstream file;
    file.open("Constancias.txt", ios::app | ios::out);
    file << "AUTO" << " " << nombre << " " << carnet << " " << monto << " " << tipoPersona << "\n";
    file.close();
}
