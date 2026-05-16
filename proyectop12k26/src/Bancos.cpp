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

bool Bancos::InfoTransferencia(string nombreCliente, long long numeroTarjeta, int numeroCarnet)
{
    fstream file;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch, movimientoArch;
    bool encontrado = false;

    file.open("CuentasBancarias.txt", ios::in);

    if(file.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> movimientoArch >> tarjetaArch >> bancoArch)
        {
            if(tarjetaArch == numeroTarjeta && clienteArch == nombreCliente)
            {
                this->idCuenta = idArch;
                this->saldo=saldoArch;
                this->nombreBanco = bancoArch;
                encontrado = true;
                break;
            }
        }
        file.close();
    }
    this->movimiento=montoCobro(numeroCarnet);
    if(encontrado)
    {
        cout<<"Cuenta encontrada con exito."<<endl;
        cout<<"Cliente: "<<nombreCliente<<endl;
        cout<<"cuenta No. "<<this->idCuenta<<endl;
        if (procesoTransferencia(numeroTarjeta, this->movimiento))
        {
            cout<<"transaccion exitosa"<<endl;
            return true;
        }else{
            cout<<"error con la transferencia"<<endl;
            return false;
        }
    }
    else{
        cout<<"Error, La cuenta no se ha encontrado"<<endl;
        return false;
    }
}

bool Bancos::InfoPagoPlanilla(string nombreCliente, int idCuenta, int codigoCatedratico)
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
            if (idArch == idCuenta && clienteArch == nombreCliente)
            {
                this->nombreCliente = clienteArch;
                encontrado = true;
                break;
            }
        }
        file.close();
    }
    this->movimiento = montoPago(codigoCatedratico);
    if (encontrado)
    {
        cout << "Cuenta encontrada: " << this->nombreCliente << endl;
        if (procesoPagoPlanilla(idCuenta, this->movimiento))
        {
            cout<<"pago realizado con exito"<<endl;
            return true;
        }
        else{
            cout<<"Error. El pago no pudo realizarse con exito"<<endl;
            return false;
        }
    }
    else
    {
        cout << "Error: No se encontro el ID de cuenta." << endl;
        return false;
    }
}


bool Bancos::procesoTransferencia(long long numeroTarjeta, double monto)
{
    fstream file;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch, movimientoArch;
    bool transaccion = false;

    file.open("CuentasBancarias.txt", ios::in);

    if(file.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> movimientoArch >> tarjetaArch >> bancoArch)
        {
            if(tarjetaArch == numeroTarjeta && monto<=saldoArch)
            {
                ///modificar el saldo en el archivo bancos
                transaccion = true;;
                break;
            }
            else
            {
                transaccion = false;
            }
        }
        file.close();
    }
}

bool Bancos::procesoPagoPlanilla(int idCuentaReq, double monto)
{
    //pendiente
}

double Bancos::montoCobro(int Carnet)
{
    //pendiente
}

double Bancos::montoPago(int codigo)
{
    //pendiente
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

//Parte de constancias
    string carnetIngresado;
    cout << "\n>>> PROCESO DE CONSTANCIA <<<" << endl;
    cout << "Ingrese el carnet para el comprobante: ";
    cin >> carnetIngresado;

    GeneradorConstancias miConstancia;
    miConstancia.recibirDatos(nombreCliente, carnetIngresado, monto, 1);

    miConstancia.disenoConstancia();
    cout << endl;
    system("pause");

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
