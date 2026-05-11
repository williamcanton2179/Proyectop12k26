//Creado por Fernando Castillo - 9959-25-288
//El 30/04/2006
#include "Cursos.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
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

//CRUD
//Menu Principal del CRUD
void Cursos::menuCurso()
{
    int opcionUsuario = 0;
    char agregarCurso;
    do{
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t |   SISTEMA GESTION CURSOS  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Ingresar Cursos" << endl;
        cout << "\t\t\t 2. Desplegar Cursos" << endl;
        cout << "\t\t\t 3. Modificar Cursos" << endl;
        cout << "\t\t\t 4. Buscar Cursos" << endl;
        cout << "\t\t\t 5. Borrar Cursos" << endl;
        cout << "\t\t\t 6. Exit" << endl;

        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\tOpcion a escoger:[1/2/3/4/5/6]" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "Ingresa tu Opcion: "; cin >> opcionUsuario;

        switch(opcionUsuario)
        {
        case 1:
            do
            {
                insertarCurso();
                cout <<"\n\t\t\t Agregar otro curso(S,N): "; cin>> agregarCurso;
            }while(agregarCurso == 'S' || agregarCurso == 's' );
            break;
        case 2:
            desplegarCurso();
            break;
        case 3:
            modificarCurso();
            break;
        case 4:
            buscarCurso();
            break;
        case 5:
            borrarCurso();
            break;
        case 6:
            exit(0);
        default:
            cout<<"\n\t\t\t Opcion invalida...Por favor prueba otra vez..";
        }
        getch();
    }while(opcionUsuario != 6);
}

//Insertar
void Cursos::insertarCurso()
{
    cin.ignore();
    system("cls");
	fstream file;
	cout << "\n------------------------------------------------------------------------------------------------------------------------";
	cout << "\n-------------------------------------------------Agregar detalles Persona ---------------------------------------------" << endl;
	cout << "\t\t\tIngresa codigo del Curso: "; getline(cin, codigoCurso);
	cout << "\t\t\tIngresa nombre del Curso: "; getline(cin, nombreCurso);
	cout << "\t\t\tIngresa pre-requisito del curso: "; getline(cin, preRequisitoDeCurso);
	file.open("Cursos.txt", ios::app | ios::out);
	file << std::left<<std::setw(15) << codigoCurso << "| " <<std::left << std::setw(40) << nombreCurso << "| " << std::left << std::setw(15) << preRequisitoDeCurso << "\n";
	file.close();
}

//Desplegar
void Cursos::desplegarCurso()
{
    cin.ignore();
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n----------------------------------------Tabla de Detalles de Cursos-----------------------------------------" << endl;
    file.open("Cursos.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t No hay información...";
        file.close();
    }
    else
    {
        while(getline(file, codigoCurso, '|'))
        {
            getline(file, nombreCurso, '|');
            getline(file, preRequisitoDeCurso);

            total++;
            cout << "\n\n\t\t\t Codigo del curso: " << codigoCurso << endl;
            cout << "\t\t\t Nombre del curso " << nombreCurso << endl;
            cout << "\t\t\t Pre-requisito del curso: " << preRequisitoDeCurso  << endl;
        }
        if (total == 0)
        {
            cout << "\t\t\t No hay información...";
        }
    }
    file.close();
}

//Modificar
void Cursos::modificarCurso()
{
    cin.ignore();
    system("cls");
    fstream file,file1;
    string participanteId = "";
    int found = 0;
    cout << "\n----------------------------------------Modificar Detalles Cursos-----------------------------------------" << endl;
    file.open("Cursos.txt", ios::in);
    if(!file)
    {
        cout << "\t\t\t No hay información...";
        file.close();
    }
    else
    {
        cout << "\n Ingrese el codigo del curso (000): "; cin >> participanteId;
        cin.ignore();
        file1.open("Record.txt", ios::app | ios::out);
        while(getline(file, codigoCurso, '|'))
        {
            getline(file, nombreCurso, '|');
            getline(file, preRequisitoDeCurso);
            //Borra los espacios sobrantes
            codigoCurso = codigoCurso.substr(0, codigoCurso.find_last_not_of(" ") + 1);
            nombreCurso = nombreCurso.substr(0, nombreCurso.find_last_not_of(" ") + 1);
            preRequisitoDeCurso = preRequisitoDeCurso.substr(0, preRequisitoDeCurso.find_last_not_of(" ") + 1);

            if(participanteId == codigoCurso)
            {
                cout << "\t\t\tIngresa codigo del Curso: "; getline(cin, codigoCurso);
                cout << "\t\t\tIngresa nombre del Curso: "; getline(cin, nombreCurso);
                cout << "\t\t\tIngresa pre-requisito del curso: "; getline(cin, preRequisitoDeCurso);
                found++;

            }
                file1 << std::left<<std::setw(15) << codigoCurso << "| " << std::left << std::setw(40) << nombreCurso << "| " << std::left << std::setw(15) << preRequisitoDeCurso << "\n";
        }
        file1.close();
        file.close();
        remove("Cursos.txt");
        rename("Record.txt", "Cursos.txt");
    }

}

//Buscar
void Cursos::buscarCurso()
{
    cin.ignore();
    system("cls");
    fstream file;
    int found = 0;
    file.open("Cursos.txt", ios::in);
    if(!file)
    {
        cout << "\n----------------------------------------Datos del Curso Buscado-----------------------------------------" << endl;
        cout << "\t\t\t No hay información...";
    }
    else
    {
        string participanteId = "";
        cout << "\n----------------------------------------Datos del Curso Buscado-----------------------------------------" << endl;
        cout << "\n Ingrese el codigo del curso que quiere buscar (000): "; cin >> participanteId;
        while(getline(file, codigoCurso, '|'))
        {
            getline(file, nombreCurso, '|');
            getline(file, preRequisitoDeCurso);
            //Borra los espacios sobrantes
            codigoCurso = codigoCurso.substr(0, codigoCurso.find_last_not_of(" ") + 1);
            nombreCurso = nombreCurso.substr(0, nombreCurso.find_last_not_of(" ") + 1);
            preRequisitoDeCurso = preRequisitoDeCurso.substr(0, preRequisitoDeCurso.find_last_not_of(" ") + 1);
            if (participanteId == codigoCurso)
            {
                cout << "\n\n\t\t\t Codigo del curso: " << codigoCurso << endl;
                cout << "\t\t\t Nombre del curso " << nombreCurso << endl;
                cout << "\t\t\t Pre-requisito del curso: " << preRequisitoDeCurso  << endl;
                found++;
            }
        }
        if (found == 0)
        {
            cout << "\t\t\t Curso no encontrado...";
        }
        file.close();
    }

}

//Borrar
void Cursos::borrarCurso()
{
    cin.ignore();
    system("cls");
    fstream file,file1;
    string participanteId = "";
    int found = 0;
    cout << "\n----------------------------------------Detalles del Curso a Borrar-----------------------------------------" << endl;
    file.open("Cursos.txt", ios::in);
    if(!file){
        cout << "\n\t\t\t\t No hay información..." << endl;
        file.close();
    }else{
        cout << "\n Ingrese el codigo del curso que quiere borrar (000): "; cin >> participanteId;
        file1.open("Record.txt", ios::app | ios::out);
        while(getline(file, codigoCurso, '|')){
                getline(file, nombreCurso, '|');
                getline(file, preRequisitoDeCurso);
                //Borra los espacios sobrantes
                codigoCurso = codigoCurso.substr(0, codigoCurso.find_last_not_of(" ") + 1);
            if (participanteId != codigoCurso){
                file1 << std::left<<std::setw(15) << codigoCurso << "| " <<std::left << std::setw(40   ) << nombreCurso << "| " << std::left << std::setw(15) << preRequisitoDeCurso << "\n";
            }else{
                found++;
                cout << "\n\t\t\t\t Borrado de informacion exitoso";
            }
        }
        if (found == 0){
            cout << "\n\t\t\t\t codigo del curso no econtrado...";
        }
        file1.close();
        file.close();
        remove("Cursos.txt");
        rename("Record.txt", "Cursos.txt");
    }

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
