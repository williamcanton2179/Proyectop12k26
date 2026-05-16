#ifndef VALIDACIONPAGOS0_H
#define VALIDACIONPAGOS0_H
#include<string>
#include<vector>


class validacionpagos0
{
    public:
        validacionpagos0();
        void cargarCursosDesdeArchivo(std::string nombreArchivo = "Asignaciones.txt");
        void informaciondecursos();
        void pagoAlumno1(double pago1, double preciocurso);
        void tipodePago(int Tipotarjeta,long long &numeroTarjeta, std::string &nombre, std::string &fecha, int &codigoSeguridad);
        void leerInformacion(long long tarjetaBuscada, int Tipotarjeta);
        void modificarInformacion(long long tarjetaBuscada, int Tipotarjeta);
        void menuGestionPagos(long long tarjetaBuscada, int Tipotarjeta);
        void borrar(long long tarjetabuscada, int Tipotarjeta);
        double CalculoTotal();

        virtual ~validacionpagos0();

    protected:

    private:
        std::vector<std::string>cursos;
        std::vector<double>precios1;
        std::string idEstudiante;
        std::string carnetEstudiante;

        double pagototal;
        double pagoalumno;
};

#endif // VALIDACIONPAGOS0_H
