#include "GeneradorConstancias.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

// CONSTRUCTOR
GeneradorConstancias::GeneradorConstancias() {
    nombre = "";
    carnet = "";
    monto = 0.0;
    estado = 1; // 1: SOLVENTE por defecto
    tipoPersona = 0;
    srand(time(0)); // Inicializa la semilla para los números aleatorios
}

// DESTRUCTOR
GeneradorConstancias::~GeneradorConstancias() {
}

// SETTERS
void GeneradorConstancias::setNombre(string n) { nombre = n; }
void GeneradorConstancias::setCarnet(string c) { carnet = c; }
void GeneradorConstancias::setMonto(float m) { monto = m; }
void GeneradorConstancias::setEstado(int e) { estado = e; }
void GeneradorConstancias::setTipoPersona(int t) { tipoPersona = t; }

// GETTERS
string GeneradorConstancias::getNombre() { return nombre; }
string GeneradorConstancias::getCarnet() { return carnet; }
float GeneradorConstancias::getMonto() { return monto; }
int GeneradorConstancias::getTipoPersona() { return tipoPersona; }

string GeneradorConstancias::getTextoEstado() {
    if (estado == 1) return "SOLVENTE";
    if (estado == 2) return "PENDIENTE";
    return "FALTANTE";
}

// MÉTODOS PRIVADOS
void GeneradorConstancias::imprimirEncabezadoBanco() {
    cout << "\n      SISTEMA BANCARIO UNIVERSIDAD (UMG)      " << endl;
    cout << "================================================" << endl;
}

void GeneradorConstancias::constanciaAlumno() {
    imprimirEncabezadoBanco();
    cout << "           COMPROBANTE DE PAGO - ALUMNO         " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Carnet: " << carnet << endl;
    cout << "Monto Pagado: Q" << monto << endl;
    cout << "Estatus Actual: " << getTextoEstado() << endl;
    cout << "No. Boleta: " << (100 + rand() % 900) << endl;
    cout << "================================================" << endl;
}

void GeneradorConstancias::constanciaDocente() {
    imprimirEncabezadoBanco();
    cout << "        CONSTANCIA DE PAGO - CATEDRATICO        " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "ID Docente: " << carnet << endl;
    cout << "Sueldo Depositado: Q" << monto << endl;
    cout << "Estado de Pago: " << getTextoEstado() << endl;
    cout << "No. Referencia: " << (1000 + rand() % 9000) << endl;
    cout << "================================================" << endl;
}

// MÉTODOS PÚBLICOS
void GeneradorConstancias::entregarConstancia() {
    if (tipoPersona == 1) {
        constanciaAlumno();
    }
    else if (tipoPersona == 2) {
        constanciaDocente();
    }
    else {
        cout << "\n[!] Error: No se puede generar la constancia." << endl;
        cout << "Asegurese de asignar el tipo de persona (1 o 2)." << endl;
    }
}

bool GeneradorConstancias::validarConstancia(int numeroBoleta) {
    // Simulación simple de validación
    if (numeroBoleta >= 100 && numeroBoleta <= 9999) {
        return true;
    }
    return false;
}
