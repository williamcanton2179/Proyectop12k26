#ifndef VALIDACIONPAGOS0_H
#define VALIDACIONPAGOS0_H
#include<string>
#include<vector>


class validacionpagos0
{
    public:
        //declaracion de metodos para cursos y precios
        validacionpagos0();
        void cargarCursosDesdeArchivo(std::string nombreArchivo = "Asignaciones.txt");
        //void asignarCursos(std::string nombrecurso); //double preciocurso);
        void informaciondecursos();
        void pagoAlumno1(double pago1, double preciocurso);
        void tipodePago(int Tipotarjeta,long long &numeroTarjeta, std::string &nombre, std::string &fecha, int &codigoSeguridad);
        void leerInformacion(int tarjetaBuscada, int Tipotarjeta);
        void modificarInformacion(int tarjetaBuscada, int Tipotarjeta);
        void menuGestionPagos(int tarjetaBuscada, int Tipotarjeta);
        void borrar(int tarjetabuscada, int Tipotarjeta);
        double CalculoTotal();
        //void ejecutarMenuPrincipal();
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
