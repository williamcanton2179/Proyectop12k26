// Creado por Axel Andrino - 9959-25-8978
#include "GeneradorConstancias.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

GeneradorConstancias::GeneradorConstancias() {
    nombre = "";
    carnet = "";
    monto = 0.0;
    estado = 1;
    tipoPersona = 0;
    srand(time(0));
}

GeneradorConstancias::~GeneradorConstancias() {}

void GeneradorConstancias::setNombre(string n) { nombre = n; }
void GeneradorConstancias::setCarnet(string c) { carnet = c; }
void GeneradorConstancias::setMonto(float m) { monto = m; }
void GeneradorConstancias::setEstado(int e) { estado = e; }
void GeneradorConstancias::setTipoPersona(int t) { tipoPersona = t; }

string GeneradorConstancias::getNombre() { return nombre; }
float GeneradorConstancias::getMonto() { return monto; }
int GeneradorConstancias::getTipoPersona() { return tipoPersona; }

string GeneradorConstancias::getTextoEstado() {
    if (estado == 1) return "SOLVENTE";
    if (estado == 2) return "PENDIENTE";
    return "FALTANTE";
}

void GeneradorConstancias::imprimirEncabezadoBanco() {
    cout << "\n      Sistema Bancario Universidad      " << endl;
    cout << "==========================================" << endl;
}

// Constancia del pago del alumno
void GeneradorConstancias::constanciaAlumno() {
    imprimirEncabezadoBanco();
    cout << "COMPROBANTE DE PAGO" << endl;
    cout << "Alumno: " << nombre << endl;
    cout << "Carnet: " << carnet << endl;
    cout << "Monto: Q" << monto << endl;
    cout << "Estado: " << getTextoEstado() << endl;
    cout << "No. Boleta: " << (100 + rand() % 900) << endl;
    cout << "==========================================" << endl;
}

// Constancia del pago del salario del Catedratico
void GeneradorConstancias::constanciaDocente() {
    imprimirEncabezadoBanco();
    cout << "CONSTANCIA DE PAGO (SALARIO)" << endl;
    cout << "Catedratico: " << nombre << endl;
    cout << "ID: " << carnet << endl;
    cout << "Sueldo: Q" << monto << endl;
    cout << "Estado: " << getTextoEstado() << endl;
    cout << "No. Transferencia: " << (1000 + rand() % 9000) << endl;
    cout << "==========================================" << endl;
}

void GeneradorConstancias::entregarConstancia() {
    if (tipoPersona == 1) {
        constanciaAlumno();
    } else if (tipoPersona == 2) {
        constanciaDocente();
    } else {
        cout << "Error: No hay datos para generar constancia." << endl;
    }
}
