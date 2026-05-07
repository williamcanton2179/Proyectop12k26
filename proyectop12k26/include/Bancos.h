#ifndef BANCOS_H
#define BANCOS_H

#include <string>
using namespace std;

class Bancos
{
    public:
        Bancos();
        virtual~Bancos();
        bool InfoTransferencia(string nombreBanco, string nombreCliente, long long numeroTarjeta);
        bool InfoPagoPlanilla(string nombreBanco, string nombreCliente, int idCuenta);
        bool procesoTransferencia(long long numeroTarjeta, double monto, double saldo);
        bool procesoPagoPlanilla(int idCuenta, double monto
                                 , double saldoCuenta);

        bool crearCuenta(string nombreCliente, double monto, string nombreBanco);
        bool guardarCuenta(int idCuenta, string nombreCliente, double saldo, double movimiento, long long numeroTarjeta, string nombreBanco);
        int generadorTarjetasCuentas();

    private:
        string nombreCliente;
        string nombreBanco;
        double saldo;
        double movimiento;
        int idCuenta;
        long long numeroTarjeta;
};

#endif
