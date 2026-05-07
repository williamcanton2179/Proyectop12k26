//Creado por Axel Fernando - 9959-25-8978

#include "GeneradorConstancias.h"
#include <cstdlib>
#include <ctime>

GeneradorConstancias::GeneradorConstancias() {
    nombre = "";
    monto = 0.0;
    tipoPersona = 0;
    srand(time(0));
}

GeneradorConstancias::~GeneradorConstancias() {}

void GeneradorConstancias::setNombre(string n) { nombre = n; }
void GeneradorConstancias::setMonto(float m) { monto = m; }
void GeneradorConstancias::setTipoPersona(int t) { tipoPersona = t; }

string GeneradorConstancias::getNombre() { return nombre; }
float GeneradorConstancias::getMonto() { return monto; }
int GeneradorConstancias::getTipoPersona() { return tipoPersona; }

void GeneradorConstancias::imprimirEncabezadoBanco() {
    cout << "      Sistema Bancario Universidad      " << endl;
    cout << "==========================================" << endl;
}

void GeneradorConstancias::constanciaAlumno() {
    imprimirEncabezadoBanco();
    cout << "Comprobante de pago" << endl;
    cout << "Alumno: " << nombre << endl;
    cout << "Monto: Q" << monto << endl;
    cout << "No. Boleta: " << (100 + rand() % 900) << endl;
}

void GeneradorConstancias::constanciaDocente() {
    imprimirEncabezadoBanco();
    cout << "Constancia de pago del sueldo (RRHH)" << endl;
    cout << "Catedratico: " << nombre << endl;
    cout << "Sueldo: Q" << monto << endl;
    cout << "No. Transferencia: " << (1000 + rand() % 9000) << endl;
}

void GeneradorConstancias::constanciaEmpleado() {
    imprimirEncabezadoBanco();
    cout << "Constancia de pago del sueldo (LIMPIEZA)" << endl;
    cout << "Empleado: " << nombre << endl;
    cout << "Monto pagado: Q" << monto << endl;
    cout << "No. Transferencia: " << (100 + rand() % 900) << endl;
}

void GeneradorConstancias::entregarConstancia() {
    if (tipoPersona == 1) {
        constanciaAlumno();
    } else if (tipoPersona == 2) {
        constanciaDocente();
    } else if (tipoPersona == 3) {
        constanciaEmpleado();
    } else {
        cout << "Error: No hay datos para generar constancia." << endl;
    }
}
