//Creado por Fernando Castillo - 9959-25-288
//El 30/04/2006
#include "Cursos.h"
#include <string>
#include <vector>
using namespace std;

//Constructor
Cursos::Cursos()
{
    this -> nombreCurso = "";
    this -> codigoCurso = "";
    this -> preRequisitoDeCurso = "";
    this -> estadoCurso = true;
}

//Constructor Sobrecargado
Cursos::Cursos(string nombreCurso, string codigoCurso, string preRequisitoDeCurso, bool estadoCurso)
{
    this -> nombreCurso = nombreCurso;
    this -> codigoCurso = codigoCurso;
    this -> preRequisitoDeCurso = preRequisitoDeCurso;
    this -> estadoCurso = estadoCurso;
}

//Crear vector
vector<Cursos> Cursos::catalagoCursosIngSistemas()
{
    //Se lleno el vector con todos los cursos de ingeniera en sistemas
    vector<Cursos> datosCursos;
    //Primer Ciclo
    datosCursos.push_back(Cursos("Desarrollo Humano y Profesional", "001", "Ninguno", true));
    datosCursos.push_back(Cursos("Metodologia de la Investigacion", "002", "Ninguno", true));
    datosCursos.push_back(Cursos("Contabilidad I", "003", "Ninguno", true));
    datosCursos.push_back(Cursos("Introduccion a los sistemas de computo", "004", "Ninguno", true));
    datosCursos.push_back(Cursos("Logica de Sistemas", "005", "Ninguno", true));
    //Segundo Ciclo
    datosCursos.push_back(Cursos("Precalculo", "006", "Ninguno", true));
    datosCursos.push_back(Cursos("Algebra Lineal", "007", "Ninguno", true));
    datosCursos.push_back(Cursos("Algoritmos", "008", "Ninguno", true));
    datosCursos.push_back(Cursos("Contabilidad II", "009","Ninguno", true));
    datosCursos.push_back(Cursos("Matematica Discreta", "010", "Ninguno", true));
    //Tercer Ciclo
    datosCursos.push_back(Cursos("Fisica I", "011", "006", true));
    datosCursos.push_back(Cursos("Programacion I", "012", "008", true));
    datosCursos.push_back(Cursos("Calculo I", "013", "006", true));
    datosCursos.push_back(Cursos("Proceso Administrativo", "014", "Ninguno", true));
    datosCursos.push_back(Cursos("Derecho Informatico", "015","Ninguno", true));
    //Cuarto Ciclo
    datosCursos.push_back(Cursos("Microeconomia", "016", "Ninguno", true));
    datosCursos.push_back(Cursos("Programacion II", "017", "012", true));
    datosCursos.push_back(Cursos("Calculo II", "018", "013", true));
    datosCursos.push_back(Cursos("Estadistica I", "019", "Ninguno", true));
    datosCursos.push_back(Cursos("Fisica II", "020","011", true));
    //Quinto Ciclo
    datosCursos.push_back(Cursos("Metodos Numericos", "021", "70 Crs.", true));
    datosCursos.push_back(Cursos("Programacion III", "022", "017", true));
    datosCursos.push_back(Cursos("Emprendedores de Negocios", "023", "Ninguno", true));
    datosCursos.push_back(Cursos("Electronica Analogia", "024", "020", true));
    datosCursos.push_back(Cursos("Estadistica II", "025","019", true));
    //Sexto Ciclo
    datosCursos.push_back(Cursos("Investigacion de Operaciones", "026", "80 Crs.", true));
    datosCursos.push_back(Cursos("Base de Datos I", "027", "022", true));
    datosCursos.push_back(Cursos("Automatas y Lenguaje Formales", "028", "80 Crs.", true));
    datosCursos.push_back(Cursos("Sistemas Operativos I", "029", "80 Crs.", true));
    datosCursos.push_back(Cursos("Electronica Digital", "030","024", true));
    //Septimo Ciclo
    datosCursos.push_back(Cursos("Base de Datos II", "031", "027", true));
    datosCursos.push_back(Cursos("Analisis de Sistemas I", "032", "100 Crs.", true));
    datosCursos.push_back(Cursos("Sistemas Operativos II", "033", "029", true));
    datosCursos.push_back(Cursos("Arquitectura de Computadoras I", "034", "100 Crs", true));
    datosCursos.push_back(Cursos("Compiladores", "035", "028", true));
    //Octavo Ciclo
    datosCursos.push_back(Cursos("Desarrollo Web", "036", "031", true));
    datosCursos.push_back(Cursos("Analisis de Sistemas II", "037", "032", true));
    datosCursos.push_back(Cursos("Redes de Computadora I", "038", "125 Crs.", true));
    datosCursos.push_back(Cursos("Etica Profesional", "039", "100 Crs.", true));
    datosCursos.push_back(Cursos("Arquitectura de Computadoras II", "040","034", true));
    //Noveno Ciclo
    datosCursos.push_back(Cursos("Administracion de Tecnologias de Informacion", "041", "150 Crs.", true));
    datosCursos.push_back(Cursos("Ingenieria de Software", "042", "150 Crs.", true));
    datosCursos.push_back(Cursos("Proyecto de Graduacion I", "043", "150 Crs.", true));
    datosCursos.push_back(Cursos("Redes de Computadoras II", "044", "038", true));
    datosCursos.push_back(Cursos("Inteligencia Artificial", "045","150 Crs.", true));
    //Decimo Ciclo
    datosCursos.push_back(Cursos("Telecomunicaciones", "046", "175 Crs.", true));
    datosCursos.push_back(Cursos("Seminario de Tecnoligias de Informacion", "047", "175 Crs.", true));
    datosCursos.push_back(Cursos("Aseguramiento de la Calidad de Software", "048", "175 Crs.", true));
    datosCursos.push_back(Cursos("Proyecto de Graduacion II", "049", "043", true));
    datosCursos.push_back(Cursos("Seguridad y Auditoria de Sistemas", "050","175 Crs.", true));
    return datosCursos;
}

//Getters
string Cursos::getnombreCurso()
{
    return this -> nombreCurso;
}
string Cursos::getpreRequisitoDeCurso()
{
    return this -> preRequisitoDeCurso;
}
string Cursos::getcodigoCurso()
{
    return this -> codigoCurso;
}
bool Cursos::getestadoCurso()
{
    return this -> estadoCurso;
}

//Setters
void Cursos::setnombreCurso(string nombreCurso)
{
    this -> nombreCurso = nombreCurso;
}
void Cursos::setpreRequisitoDeCurso(string preRequisitoDeCurso)
{
    this -> preRequisitoDeCurso = preRequisitoDeCurso;
}
void Cursos::setcodigoCurso(string codigoCurso)
{
    this -> codigoCurso = codigoCurso;
}
void Cursos::setestadoCurso(bool estadoCurso)
{
    this -> estadoCurso = estadoCurso;
}
