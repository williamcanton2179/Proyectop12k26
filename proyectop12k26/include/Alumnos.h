#ifndef ALUMNOS_H
#define ALUMNOS_H
#include <string>
#include <vector>


class Alumnos
{
    public:
        //Contructor
        Alumnos();
        Alumnos(std::string nombreCompletoAlumno, std::string sexoAlumno, std::string numeroDpi, std::string correoPersonal, std::string carnetPersonal, std::string carreraAsignada);
        //Getters
        std::string getnombreCompletoAlumno();
        std::string getnombreAlumno();
        std::string getapellidoAlumno();
        std::string getsexoAlumno();
        int getdiaNacimiento();
        int getmesNacimiento();
        int getanioNacimiento();
        std::string getnumeroDpi();
        std::string getcorreoPersonal();
        std::string getfechaNacimientoAlumno();
        std::string getcarnetPersonal();
        std::string getcarreraAsignada();
        //Setters
        void setnombreAlumno(std::string nombreAlumno);
        void setapellidoAlumno(std::string apellidoAlumno);
        void setsexoAlumno(std::string sexoAlumno);
        void setdiaNacimiento(int diaNacimiento);
        void setmesNacimiento(int mesNacimiento);
        void setanioNacimiento(int anioNacimiento);
        void setnumeroDpi(std::string numeroDpi);
        void setcorreoPersonal(std::string correoPersonal);
        void setfechaNacimientoAlumno(std::string fechaNacimientoAlumno);
        void setcarnetPersonal(std::string carnetPersonal);
        void setnombreCompletoAlumno(std::string nombreCompletoAlumno);
        void setcarreraAsignada(std::string carreraAsignada);
        //Metodos
        void registroDatos();
        void menuRegistro();
        void obtenerFechaNacimiento();
        int obtenerAnioCorto();
        void creaCorreoPersonal();
        void crearCarnetPersonal(std::string codigoCarrera);
        void obtenerNombreCompleto();
        void registroExitoso();
        std::vector<Alumnos> alumnosPrueba();
        //Metodos CRUD
        void menuInsertar();
        void insertarAlumno();
        void desplegarAlumno();
        void modificarAlumno();
        void buscarAlumno();
        void borrarAlumno();

    protected:

    private:
        //Datos personales del alumno
        std::string nombreCompletoAlumno;
        std::string nombreAlumno;
        std::string apellidoAlumno;
        std::string sexoAlumno;
        int diaNacimiento;
        int mesNacimiento;
        int anioNacimiento;
        std::string numeroDpi;
        std::string correoPersonal;
        std::string fechaNacimientoAlumno;
        std::string carnetPersonal;
        std::string carreraAsignada;
        std::string contraseniaUnica;
        std::string idUnico;
        int anioCorto;
        //Constantes
        static const int ANIO_ACTUAL = 26;
        //Numeros Aleatorios
        int numeroAleatorio(int minimo, int maximo);

};

#endif // ALUMNOS_H
