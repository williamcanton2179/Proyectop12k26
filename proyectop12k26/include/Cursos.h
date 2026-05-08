//Creado por Fernando Castillo - 9959-25-288
//El 30/04/2006
#ifndef CURSOS_H
#define CURSOS_H
#include <string>
#include <vector>

class Cursos
{
    public:
        Cursos();
        Cursos(std::string nombreCurso, std::string codigoCurso, std::string preRequisitoDeCurso, bool estadoCurso);
        //Getters
        std::string getnombreCurso();
        std::string getpreRequisitoDeCurso();
        std::string getcodigoCurso();
        bool getestadoCurso();
        //Setters
        void setestadoCurso(bool estadoCurso);
        void setcodigoCurso(std::string codigoCurso);
        void  setnombreCurso(std::string nombreCurso);
        void setpreRequisitoDeCurso(std::string preRequisitoDeCursos);
        //Metodos
        std::vector<Cursos> catalagoCursosIngSistemas();


    protected:

    private:
        std::string nombreCurso;
        std::string preRequisitoDeCurso;
        std::string codigoCurso;
        bool estadoCurso;

};

#endif // CURSOS_H
