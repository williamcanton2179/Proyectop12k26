#include "Bancos.h"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

Bancos::Bancos()
{
    //ctor
}

bool Bancos::crearCuenta(string nombreCliente, double monto, string nombreBanco)
{
    this->idCuenta = generadorTarjetasCuentas();
    this->nombreCliente = nombreCliente;
    this->saldo = monto;
    this->movimiento = monto;
    this->nombreBanco = nombreBanco;
    this->numeroTarjeta = 0;

    if(nombreBanco == "BAC"){
        numeroTarjeta = 5547961400000000LL + generadorTarjetasCuentas();
    }
    else if(nombreBanco == "G&T"){
        numeroTarjeta = 7511451800000000LL + generadorTarjetasCuentas();
    }
    else if(nombreBanco == "Banco Industrial"){
        numeroTarjeta = 9655147700000000LL + generadorTarjetasCuentas();
    }
    else{
        numeroTarjeta = 7414220100000000LL + generadorTarjetasCuentas();
    }

    return guardarCuenta(idCuenta, nombreCliente, saldo, movimiento, numeroTarjeta, nombreBanco);
}

bool Bancos::guardarCuenta(int idCuenta, string nombreCliente, double saldo, double movimiento, long long numeroTarjeta, string nombreBanco)
{
    fstream file;
    file.open("CuentasBancarias.txt", ios::app | ios::out);

    if(file.is_open())
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
    //dtor
}
