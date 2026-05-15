#include "Bancos.h"
#include "GeneradorConstancias.h"
#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <iomanip>
#include <sstream>

const int ID_CUENTA_UMG = 50622293;
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
    double saldoArch;
    bool encontrado = false;

    file.open("CuentasBancarias.txt", ios::in);

    if(file.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
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
    double saldoArch;
    long long tarjetaArch;
    bool encontrado = false;

    file.open("CuentasBancarias.txt", ios::in);

    if (file.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
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

bool Bancos::procesoTransferencia(long long numeroTarjetaOrigen, double monto)
{
    fstream file, tempFile;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch;

    bool origenProcesado = false;
    bool destinoProcesado = false;

    file.open("CuentasBancarias.txt", ios::in);
    tempFile.open("Temp.txt", ios::out);

    if (file.is_open() && tempFile.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if (tarjetaArch == numeroTarjetaOrigen)
            {
                if (saldoArch >= monto)
                {
                    saldoArch -= monto;
                    origenProcesado = true;
                }
                else
                {
                    cout << "Error: Saldo insuficiente en la cuenta de origen." << endl;
                }
            }
            else if (idArch == ID_CUENTA_UMG)
            {
                saldoArch += monto;
                destinoProcesado = true;
            }
            tempFile << left << setw(15) << idArch
                     << left << setw(20) << clienteArch
                     << left << setw(15) << saldoArch
                     << left << setw(20) << tarjetaArch
                     << left << setw(20) << bancoArch << "\n";
        }

        file.close();
        tempFile.close();

if (origenProcesado && destinoProcesado)
        {
            remove("CuentasBancarias.txt");
            rename("Temp.txt", "CuentasBancarias.txt");
            return true;
        }
        else
        {
            remove("Temp.txt");

            if (!destinoProcesado && origenProcesado) {
                cout << "Error critico: Transaccion cancelada. La cuenta UMG no existe en la base de datos." << endl;
            }
            return false;
        }
    }
    return false;
}

bool Bancos::procesoPagoPlanilla(int idCuenta, double monto)
{
    fstream file, tempFile;
    int idArch;
    long long tarjetaArch;
    string clienteArch, bancoArch;
    double saldoArch;

    bool origenProcesado = false;
    bool destinoProcesado = false;

    file.open("CuentasBancarias.txt", ios::in);
    tempFile.open("Temp.txt", ios::out);

    if (file.is_open() && tempFile.is_open())
    {
        while (file >> idArch >> clienteArch >> saldoArch >> tarjetaArch >> bancoArch)
        {
            if (idArch == ID_CUENTA_UMG)
            {
                if (saldoArch >= monto)
                {
                    saldoArch -= monto;
                    origenProcesado = true;
                }
                else
                {
                    cout << "Error: Saldo insuficiente en la cuenta de UMG." << endl;
                }
            }
            else if (idArch == idCuenta)
            {
                saldoArch += monto;
                destinoProcesado = true;
            }

            tempFile << left << setw(15) << idArch
                     << left << setw(20) << clienteArch
                     << left << setw(15) << saldoArch
                     << left << setw(20) << tarjetaArch
                     << left << setw(20) << bancoArch << "\n";
        }

        file.close();
        tempFile.close();

        if (origenProcesado && destinoProcesado)
        {
            remove("CuentasBancarias.txt");
            rename("Temp.txt", "CuentasBancarias.txt");
            return true;
        }
        else
        {
            remove("Temp.txt");

            if (!destinoProcesado && origenProcesado) {
                cout << "Error critico: Transaccion cancelada. La cuenta destino no existe." << endl;
            }
            return false;
        }
    }

    cout << "Error: No se pudo acceder a la base de datos." << endl;
    return false;
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
    return guardarCuenta(idCuenta, nombreCliente, saldo, numeroTarjeta, nombreBanco);
}


bool Bancos::guardarCuenta(int idCuenta, string nombreCliente, double saldo, long long numeroTarjeta, string nombreBanco)
{
    fstream file;
    file.open("CuentasBancarias.txt", ios::app | ios::out);

    if (file.is_open())
    {
        file << left << setw(15) << idCuenta
             << left << setw(20) << nombreCliente
             << left << setw(15) << saldo
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
