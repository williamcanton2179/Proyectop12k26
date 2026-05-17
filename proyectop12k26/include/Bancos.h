#ifndef BANCOS_H
#define BANCOS_H

#include <string>
#include "GeneradorConstancias.h"

using namespace std;

class Bancos
{
    public:
        Bancos();
        virtual ~Bancos();

        // Métodos de Información y Procesos
        bool InfoTransferencia(string nombreCliente, long long numeroTarjeta, int numeroCarnet);
        bool InfoPagoPlanilla(string nombreCliente, int idCuenta, int codigoCatedratico);
        bool procesoTransferencia(long long numeroTarjeta, double monto);
        bool procesoPagoPlanilla(int idCuenta, double monto);
        double montoCobro(string nombreAlumno);
        double montoPago(int codigo);

        // Métodos de Gestión de Cuenta
        bool crearCuenta(string nombreCliente, double monto, string nombreBanco);
        bool guardarCuenta(int idCuenta, string nombreCliente, double saldo, long long numeroTarjeta, string nombreBanco);
        int generadorTarjetasCuentas();

    private:
        string nombreCliente;
        string nombreBanco;
        double saldo, movimiento;
        int idCuenta;
        long long numeroTarjeta;
        int numeroCarnet;
};

#endif
