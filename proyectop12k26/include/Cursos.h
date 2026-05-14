//Creado por Fernando Castillo - 9959-25-288
//El 30/04/2006
#ifndef CURSOS_H
#define CURSOS_H
#include <string>
#include <vector>

//Clase cursos
class Cursos
{
    public:
        Cursos();
        Cursos(std::string nombreCurso, std::string codigoCurso, std::string preRequisitoDeCurso, double costoCurso, bool estadoCurso);
        //Getters
        std::string getnombreCurso();
        std::string getpreRequisitoDeCurso();
        std::string getcodigoCurso();
        double getcostoCurso();
        bool getestadoCurso();
        //Setters
        void setestadoCurso(bool estadoCurso);
        void setcodigoCurso(std::string codigoCurso);
        void  setnombreCurso(std::string nombreCurso);
        void setpreRequisitoDeCurso(std::string preRequisitoDeCursos);
        void setcostoCurso(double costoCurso);
        //Metodos
        std::vector<Cursos> catalagoCursosIngSistemas();
        //CRUD
        void menuCurso();
        void insertarCurso();
        void desplegarCurso();
        void modificarCurso();
        void buscarCurso();
        void borrarCurso();


    protected:

    private:
        std::string nombreCurso;
        std::string preRequisitoDeCurso;
        std::string codigoCurso;
        double costoCurso;
        bool estadoCurso;

};

#endif // CURSOS_H
