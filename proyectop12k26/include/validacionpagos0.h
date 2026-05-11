#ifndef VALIDACIONPAGOS0_H
#define VALIDACIONPAGOS0_H
#include<string>
#include<vector>


class validacionpagos0
{
    public:
        //declaracion de metodos para cursos y precios
        validacionpagos0();
        void cargarCursosDesdeArchivo(std::string nombreArchivo = "asignacion_2179.txt");
        //void asignarCursos(std::string nombrecurso); //double preciocurso);
        void informaciondecursos();
        void pagoAlumno1(double pago1, double preciocurso);
        void tipodePago(int Tipotarjeta,int numeroTarjeta, std::string nombre, std::string fecha, int codigoSeguridad);
        //void ejecutarMenuPrincipal();
        virtual ~validacionpagos0();

    protected:

    private:
        std::vector<std::string>cursos;
        //std::vector<double>precios;

        double pagototal;
        double pagoalumno;
};

#endif // VALIDACIONPAGOS0_H
