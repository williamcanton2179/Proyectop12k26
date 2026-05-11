#include "Bancos.h"
#include "GeneradorConstancias.h"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

using namespace std;

Bancos::Bancos()
{
    // constructor
}

bool Bancos::InfoPagoPlanilla(string nombreBancoReq, string nombreClienteReq, int idCuentaReq)
{
    fstream file;
    int idArch;
    string clienteArch, bancoArch;
    double saldoArch, movArch;
    long long tarjetaArch;
    bool encontrado = false;

    file.open("CuentasBancarias.txt", ios::in);

    if (file.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> movArch >> tarjetaArch >> bancoArch)
        {
            if (idArch == idCuentaReq)
            {
                this->idCuenta = idArch;
                this->nombreCliente = clienteArch;
                this->saldo = saldoArch;
                this->nombreBanco = bancoArch;
                this->numeroTarjeta = tarjetaArch;

                encontrado = true;
                break;
            }
        }
        file.close();
    }

    if (encontrado)
    {
        cout << "Cuenta encontrada: " << this->nombreCliente << endl;
        return true;
    }
    else
    {
        cout << "Error: No se encontro el ID de cuenta." << endl;
        return false;
    }
}

bool Bancos::procesoPagoPlanilla(int idCuentaReq, double monto, double saldoCuenta)
{

}

bool Bancos::crearCuenta(string nombreCliente, double monto, string nombreBanco)
{
    this->idCuenta = generadorTarjetasCuentas();
    this->nombreCliente = nombreCliente;
    this->saldo = monto;
    this->movimiento = monto;
    this->nombreBanco = nombreBanco;
    this->numeroTarjeta = 0;

    if (nombreBanco == "BAC") {
        numeroTarjeta = 5547961400000000LL + generadorTarjetasCuentas();
    }
    else if (nombreBanco == "G&T") {
        numeroTarjeta = 7511451800000000LL + generadorTarjetasCuentas();
    }
    else if (nombreBanco == "Banco Industrial") {
        numeroTarjeta = 9655147700000000LL + generadorTarjetasCuentas();
    }
    else {
        numeroTarjeta = 7414220100000000LL + generadorTarjetasCuentas();
    }


    string carnetIngresado;
    cout << "\n>>> PROCESO DE CONSTANCIA <<<" << endl;
    cout << "Ingrese el carnet para el comprobante: ";
    cin >> carnetIngresado;

    GeneradorConstancias miConstancia;
    miConstancia.setNombre(nombreCliente);
    miConstancia.setCarnet(carnetIngresado);
    miConstancia.setMonto(monto);
    miConstancia.setTipoPersona(1);
    miConstancia.setEstado(1);

    miConstancia.entregarConstancia();
    cout << ">>> FIN DE CONSTANCIA <<<\n" << endl;

    return guardarCuenta(idCuenta, nombreCliente, saldo, movimiento, numeroTarjeta, nombreBanco);
}

bool Bancos::guardarCuenta(int idCuenta, string nombreCliente, double saldo, double movimiento, long long numeroTarjeta, string nombreBanco)
{
    fstream file;
    file.open("CuentasBancarias.txt", ios::app | ios::out);

    if (file.is_open())
    {
        file << left << setw(15) << idCuenta
             << left << setw(20) << nombreCliente
             << left << setw(15) << saldo
             << left << setw(15) << movimiento
             << left << setw(20) << numeroTarjeta
             << left << setw(20) << nombreBanco
             << "\n";

        file.close();
        return true;
    }

    return false;
}

int Bancos::generadorTarjetasCuentas()
{
    static random_device numero;
    static mt19937 gen(numero());
    uniform_int_distribution<int> dis(10000000, 99999999);

    return dis(gen);
}

Bancos::~Bancos()
{
    // dtor
}
