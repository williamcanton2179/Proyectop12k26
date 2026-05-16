#include "maestros.h"
#include "Carrera.h"
#include "Cursos.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;
// Creado por Abner Muñoz
// Despegar ya funcionando
Maestros::Maestros()
{
    id = "";
    nombre = "";
    apellido = "";
    dpi = "";
    codigo = 0;
    sede = "";
    diasSemana = 3;
    horasClase = 2;
    cursosAsignados = vector<Cursos>();
}

void Maestros::menu()
{
    int choice;
    do {
        system("cls");
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t |   SISTEMA GESTION MAESTROS  |" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "\t\t\t 1. Ingreso de maestro" << endl;
        cout << "\t\t\t 2. Desplegar maestros" << endl;
        cout << "\t\t\t 3. Modificar maestro" << endl;
        cout << "\t\t\t 4. Buscar maestro" << endl;
        cout << "\t\t\t 5. Borrar maestro" << endl;
        cout << "\t\t\t 6. Asignar carrera y curso" << endl;
        cout << "\t\t\t 7. Ingresar notas" << endl;
        cout << "\t\t\t 8. Ver salarios" << endl;
        cout << "\t\t\t 9. Salir" << endl;
        cout << "\t\t\t-------------------------------" << endl;
        cout << "Ingresa tu Opcion: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insertar();
                break;
            case 2:
                desplegar();
                break;
            case 3:
                modificar();
                break;
            case 4:
                buscar();
                break;
            case 5:
                borrar();
                break;
            case 6:
                asignarCurso();
                break;
            case 7:
                ingresarNotas();
                break;
            case 8:
                mostrarTodosLosSalarios();
                break;
            case 9:
                cout << "\n\t\t\t Saliendo del sistema..." << endl;
                exit(0);
            default:
                cout << "\n\t\t\t Opcion invalida...";
        }
        system("pause");
    } while (choice != 9);
}

void Maestros::insertar()
{
    system("cls");
    cout << "\n-------- AGREGAR NUEVO MAESTRO ---------" << endl;

    cout << "Ingrese ID del maestro: ";
    cin >> id;
    cout << "Ingrese nombre: ";
    cin >> nombre;
    cout << "Ingrese apellido: ";
    cin >> apellido;
    cout << "Ingrese DPI (13 digitos): ";
    cin >> dpi;

    generarCodigo();

    ofstream file;
    file.open("Maestros.txt", ios::app);

    if (file.is_open()) {
        file << id << "|"
             << nombre << "|"
             << apellido << "|"
             << dpi << "|"
             << codigo << "|"
             << "SIN ASIGNAR|"
             << "0" << "\n";
        file.close();

        cout << "\n\t\t\t¡Maestro registrado exitosamente!" << endl;
        cout << "Codigo de seguridad: " << codigo << endl;
    } else {
        cout << "\n\t\t\tError al abrir el archivo" << endl;
    }
}

void Maestros::desplegar()
{
    system("cls");
    ifstream file;
    int total = 0;

    cout << "\n----------------- LISTA DE MAESTROS -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay maestros registrados..." << endl;
    } else {
        string linea;


        while (getline(file, linea)) {
            if (linea.empty()) continue;

            stringstream ss(linea);
            string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede, temp_cursos_str;
            int temp_codigo, temp_cursos;

            getline(ss, temp_id, '|');
            getline(ss, temp_nombre, '|');
            getline(ss, temp_apellido, '|');
            getline(ss, temp_dpi, '|');
            ss >> temp_codigo;
            ss.ignore();
            getline(ss, temp_sede, '|');
            getline(ss, temp_cursos_str, '|');

            temp_cursos = atoi(temp_cursos_str.c_str());

            total++;
            cout << "\n\t\t\t ID: " << temp_id << endl;
            cout << "\t\t\t Nombre: " << temp_nombre << " " << temp_apellido << endl;
            cout << "\t\t\t DPI: " << temp_dpi << endl;
            cout << "\t\t\t Codigo: " << temp_codigo << endl;
            cout << "\t\t\t Carrera: " << temp_sede << endl;
            cout << "\t\t\t Cursos: " << temp_cursos << endl;
            cout << "\t\t\t ------------------------------------" << endl;
        }

        if (total == 0) {
            cout << "\n\t\t\tNo hay maestros registrados..." << endl;
        } else {
            cout << "\n\t\t\t Total de maestros: " << total << endl;
        }
    }
    file.close();
}

void Maestros::modificar()
{
    system("cls");
    ifstream file;
    ofstream fileTemp;
    string search_id;
    int found = 0;

    cout << "\n----------------- MODIFICAR MAESTRO -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
        file.close();
        return;
    }

    cout << "\n Ingrese ID del maestro a modificar: ";
    cin >> search_id;

    fileTemp.open("Temp.txt", ios::out);

    string linea;

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede, temp_cursos_str;
        int temp_codigo, temp_cursos;

        getline(ss, temp_id, '|');
        getline(ss, temp_nombre, '|');
        getline(ss, temp_apellido, '|');
        getline(ss, temp_dpi, '|');
        ss >> temp_codigo;
        ss.ignore();
        getline(ss, temp_sede, '|');
        getline(ss, temp_cursos_str, '|');
        temp_cursos = atoi(temp_cursos_str.c_str());

        if (search_id == temp_id) {
            found++;
            cout << "\n\t\t\t Modificando datos..." << endl;

            cout << "Nuevo ID: ";
            cin >> id;
            cout << "Nuevo nombre: ";
            cin >> nombre;
            cout << "Nuevo apellido: ";
            cin >> apellido;
            cout << "Nuevo DPI: ";
            cin >> dpi;

            generarCodigo();

            fileTemp << id << "|"
                     << nombre << "|"
                     << apellido << "|"
                     << dpi << "|"
                     << codigo << "|"
                     << temp_sede << "|"
                     << temp_cursos << "\n";

            cout << "\n\t\t\t¡Modificacion exitosa!" << endl;
        } else {
            fileTemp << linea << "\n";
        }
    }

    if (found == 0) {
        cout << "\n\t\t\t ID no encontrado..." << endl;
    }

    fileTemp.close();
    file.close();
    remove("Maestros.txt");
    rename("Temp.txt", "Maestros.txt");
}

void Maestros::buscar()
{
    system("cls");
    ifstream file;
    int found = 0;

    cout << "\n----------------- BUSCAR MAESTRO -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
        return;
    }

    string search_id;
    cout << "\n Ingrese ID del maestro a buscar: ";
    cin >> search_id;

    string linea;

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede, temp_cursos_str;
        int temp_codigo, temp_cursos;

        getline(ss, temp_id, '|');
        getline(ss, temp_nombre, '|');
        getline(ss, temp_apellido, '|');
        getline(ss, temp_dpi, '|');
        ss >> temp_codigo;
        ss.ignore();
        getline(ss, temp_sede, '|');
        getline(ss, temp_cursos_str, '|');
        temp_cursos = atoi(temp_cursos_str.c_str());

        if (search_id == temp_id) {
            found++;
            cout << "\n\t\t\t === DATOS DEL MAESTRO ===" << endl;
            cout << "\t\t\t ID: " << temp_id << endl;
            cout << "\t\t\t Nombre: " << temp_nombre << " " << temp_apellido << endl;
            cout << "\t\t\t DPI: " << temp_dpi << endl;
            cout << "\t\t\t Codigo: " << temp_codigo << endl;
            cout << "\t\t\t Carrera: " << temp_sede << endl;
            cout << "\t\t\t Cursos: " << temp_cursos << endl;
        }
    }

    if (found == 0) {
        cout << "\n\t\t\t Maestro no encontrado..." << endl;
    }
    file.close();
}

void Maestros::borrar()
{
    system("cls");
    ifstream file;
    ofstream fileTemp;
    string delete_id;
    int found = 0;

    cout << "\n----------------- ELIMINAR MAESTRO -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
        return;
    }

    cout << "\n Ingrese ID del maestro a eliminar: ";
    cin >> delete_id;

    fileTemp.open("Temp.txt", ios::out);

    string linea;

    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string temp_id;
        getline(ss, temp_id, '|');

        if (delete_id != temp_id) {
            fileTemp << linea << "\n";
        } else {
            found++;
            cout << "\n\t\t\t¡Maestro eliminado!" << endl;
        }
    }

    if (found == 0) {
        cout << "\n\t\t\t ID no encontrado..." << endl;
    }

    fileTemp.close();
    file.close();
    remove("Maestros.txt");
    rename("Temp.txt", "Maestros.txt");
}

void Maestros::generarCodigo()
{
    srand(time(0));
    codigo = 1000 + rand() % 9000;
}

void Maestros::mostrarCarreras()
{
    cout << "\nCarreras disponibles:" << endl;
    Carrera objCarrera;
    vector<Carrera> carreras = objCarrera.datosCarreras();

    for (int i = 0; i < carreras.size(); i++) {
        if (carreras[i].getestadoCarrera()) {
            cout << i + 1 << ". " << carreras[i].getnombreCarrera()
                 << " (Codigo: " << carreras[i].getcodigoCarrera() << ")" << endl;
        }
    }
}

void Maestros::mostrarCursosPorCarrera(string codigoCarrera)
{
    cout << "\nCursos disponibles:" << endl;

    if (codigoCarrera == "9959") {
        Cursos cursoTemp;
        vector<Cursos> cursos = cursoTemp.catalagoCursosIngSistemas();

        for (int i = 0; i < cursos.size(); i++) {
            if (cursos[i].getestadoCurso()) {
                cout << i + 1 << ". " << cursos[i].getnombreCurso()
                     << " (Codigo: " << cursos[i].getcodigoCurso() << ")" << endl;
            }
        }
    }
}

void Maestros::asignarHorario()
{
    cout << "\n--- Asignacion de Horario ---" << endl;
    cout << "Seleccione la sede:" << endl;
    cout << "1- Sede Zona Portales (Bono Q400)" << endl;
    cout << "2- Central (Bono Q500)" << endl;
    cout << "3- Sede Antigua (Bono Q300)" << endl;
    cout << "4- Sede San Jose Pinula (Bono Q200)" << endl;
    cout << "Opcion: ";
    int opcionSede;
    cin >> opcionSede;

    diasSemana = 3;
    horasClase = 2;

    switch (opcionSede) {
        case 1: sede = "Sede Zona Portales"; break;
        case 2: sede = "Central"; break;
        case 3: sede = "Sede Antigua"; break;
        case 4: sede = "Sede San Jose Pinula"; break;
        default: sede = "No especificada"; break;
    }

    cout << "Sede asignada: " << sede << endl;
    cout << "Dias a la semana: " << diasSemana << endl;
    cout << "Horas por clase: " << horasClase << endl;
}

double Maestros::calcularSalario()
{
    double salarioBase = (diasSemana * horasClase * 4 * 150);
    double bonoSede = 0;
    double bonoCursos = cursosAsignados.size() * 200;

    if (sede == "Central")
        bonoSede = 500;
    else if (sede == "Sede Antigua")
        bonoSede = 300;
    else if (sede == "Sede Zona Portales")
        bonoSede = 400;
    else if (sede == "Sede San Jose Pinula")
        bonoSede = 200;

    return salarioBase + bonoSede + bonoCursos;
}

void Maestros::guardarSalarioEnArchivo()
{
    ofstream archivoSalario;
    archivoSalario.open("Salarios_Maestros.txt", ios::app);

    if (archivoSalario.is_open()) {
        double salarioTotal = calcularSalario();

        archivoSalario << "Maestro: " << nombre << " " << apellido << " | ";
        archivoSalario << "ID: " << id << " | ";
        archivoSalario << "Carrera: " << carreraAsignada.getnombreCarrera() << " | ";
        archivoSalario << "Sede: " << sede << " | ";
        archivoSalario << "Salario: Q" << salarioTotal << endl;

        archivoSalario.close();
    }
}

void Maestros::mostrarTodosLosSalarios()
{
    system("cls");
    cout << "\n========= HISTORIAL DE SALARIOS =========" << endl;

    ifstream archivoSalario("Salarios_Maestros.txt");

    if (!archivoSalario.is_open()) {
        cout << "\n\t\t\tNo hay registros de salarios aun..." << endl;
    } else {
        string linea;
        while (getline(archivoSalario, linea)) {
            cout << linea << endl;
        }
        archivoSalario.close();
    }
}

void Maestros::asignarCurso()
{
    system("cls");
    cout << "\n--- ASIGNAR CARRERA Y CURSO A MAESTRO ---" << endl;

    int codigoIngresado;
    cout << "Ingrese su codigo de seguridad: ";
    cin >> codigoIngresado;

    ifstream file;
    string linea;
    bool encontrado = false;

    file.open("Maestros.txt", ios::in);

    if (!file.is_open()) {
        cout << "\n\t\t\tNo hay maestros registrados..." << endl;
        file.close();
        return;
    }

    // Primero buscar el maestro por codigo
    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede, temp_cursos_str;
        int temp_codigo, temp_cursos;

        getline(ss, temp_id, '|');
        getline(ss, temp_nombre, '|');
        getline(ss, temp_apellido, '|');
        getline(ss, temp_dpi, '|');
        ss >> temp_codigo;

        if (temp_codigo == codigoIngresado) {
            encontrado = true;
            id = temp_id;
            nombre = temp_nombre;
            apellido = temp_apellido;
            dpi = temp_dpi;
            codigo = temp_codigo;
            break;
        }
    }
    file.close();

    if (!encontrado) {
        cout << "\n\t\t\tCodigo incorrecto o no encontrado..." << endl;
        return;
    }

    mostrarCarreras();

    int opcionCarrera;
    cout << "\nSeleccione la carrera: ";
    cin >> opcionCarrera;

    Carrera objCarrera;
    vector<Carrera> carreras = objCarrera.datosCarreras();

    if (opcionCarrera >= 1 && opcionCarrera <= carreras.size()) {
        carreraAsignada = carreras[opcionCarrera - 1];
        cout << "\nCarrera seleccionada: " << carreraAsignada.getnombreCarrera() << endl;

        mostrarCursosPorCarrera(carreraAsignada.getcodigoCarrera());

        int opcionCurso;
        cout << "\nSeleccione el curso: ";
        cin >> opcionCurso;

        if (carreraAsignada.getcodigoCarrera() == "9959") {
            Cursos cursoTemp;
            vector<Cursos> cursos = cursoTemp.catalagoCursosIngSistemas();

            if (opcionCurso >= 1 && opcionCurso <= cursos.size()) {
                Cursos cursoSeleccionado = cursos[opcionCurso - 1];
                cursosAsignados.push_back(cursoSeleccionado);

                cout << "\nCurso asignado: " << cursoSeleccionado.getnombreCurso() << endl;

                asignarHorario();

                double salario = calcularSalario();

                cout << "\n=== RESUMEN DE ASIGNACION ===" << endl;
                cout << "Maestro: " << nombre << " " << apellido << endl;
                cout << "Carrera: " << carreraAsignada.getnombreCarrera() << endl;
                cout << "Curso: " << cursoSeleccionado.getnombreCurso() << endl;
                cout << "Sede: " << sede << endl;
                cout << "Salario mensual: Q" << salario << endl;

                // Guardar salario en archivo
                guardarSalarioEnArchivo();

                // Actualizar el archivo de maestros
                ifstream fileRead;
                ofstream fileTemp;
                fileRead.open("Maestros.txt", ios::in);
                fileTemp.open("Temp.txt", ios::out);

                string line;
                while (getline(fileRead, line)) {
                    if (line.empty()) continue;

                    stringstream ss2(line);
                    string tid;
                    getline(ss2, tid, '|');

                    if (tid == id) {
                        fileTemp << id << "|" << nombre << "|" << apellido << "|" << dpi << "|"
                                 << codigo << "|" << carreraAsignada.getnombreCarrera() << "|"
                                 << cursosAsignados.size() << "\n";
                    } else {
                        fileTemp << line << "\n";
                    }
                }

                fileRead.close();
                fileTemp.close();
                remove("Maestros.txt");
                rename("Temp.txt", "Maestros.txt");
            }
        }
    }
}

void Maestros::ingresarNotas()
{
    system("cls");
    cout << "\n----------------- INGRESO DE NOTAS -----------------" << endl;

    string carnet, nombreAlumno;
    double nota1, nota2, nota3, notaFinal;

    cout << "Ingrese carnet del alumno: ";
    cin >> carnet;
    cout << "Ingrese nombre del alumno: ";
    cin.ignore();
    getline(cin, nombreAlumno);
    cout << "\n--- Ingrese las notas ---" << endl;
    cout << "Nota 1 (0-100): ";
    cin >> nota1;
    cout << "Nota 2 (0-100): ";
    cin >> nota2;
    cout << "Nota 3 (0-100): ";
    cin >> nota3;

    notaFinal = (nota1 + nota2 + nota3) / 3;

    ofstream file;
    file.open("Notas.txt", ios::app);
    file << carnet << "|" << nombreAlumno << "|" << nota1 << "|" << nota2 << "|" << nota3 << "|" << notaFinal;

    if (notaFinal >= 60) {
        file << "|APROBADO" << "\n";
        cout << "\n\t\t\t Alumno APROBADO con " << notaFinal << " puntos" << endl;
    } else {
        file << "|REPROBADO" << "\n";
        cout << "\n\t\t\t Alumno REPROBADO con " << notaFinal << " puntos" << endl;
    }

    file.close();
    cout << "\n\t\t\t¡Notas guardadas exitosamente!" << endl;
}

void Maestros::mostrarCursosAsignados()
{
    if (cursosAsignados.empty()) {
        cout << "No hay cursos asignados" << endl;
        return;
    }

    cout << "\n--- CURSOS ASIGNADOS ---" << endl;
    for (int i = 0; i < cursosAsignados.size(); i++) {
        cout << i + 1 << ". " << cursosAsignados[i].getnombreCurso()
             << " (Codigo: " << cursosAsignados[i].getcodigoCurso() << ")" << endl;
    }
}

void Maestros::mostrarResultados()
{
    cout << "\n=== DATOS DEL MAESTRO ===" << endl;
    cout << "ID: " << id << endl;
    cout << "Nombre: " << nombre << " " << apellido << endl;
    cout << "DPI: " << dpi << endl;
    cout << "Codigo: " << codigo << endl;
    cout << "Carrera: " << carreraAsignada.getnombreCarrera() << endl;
    mostrarCursosAsignados();
    cout << "Sede: " << sede << endl;
    cout << "Salario: Q" << calcularSalario() << endl;
}

int Maestros::getCodigo()
{
    return codigo;
}

string Maestros::getNombreCurso()
{
    if (!cursosAsignados.empty()) {
        return cursosAsignados[0].getnombreCurso();
    }
    return "Ninguno";
}

string Maestros::getNombre()
{
    return nombre;
}

string Maestros::getApellido()
{
    return apellido;
}

string Maestros::getId()
{
    return id;
}

string Maestros::getDpi()
{
    return dpi;
}

Carrera Maestros::getCarreraAsignada()
{
    return carreraAsignada;
}

vector<Cursos> Maestros::getCursosAsignados()
{
    return cursosAsignados;
}

void Maestros::setId(string id)
{
    this->id = id;
}

void Maestros::setDpi(string dpi)
{
    this->dpi = dpi;
}

void Maestros::ingresarDatosPersonales()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "DPI: " << dpi << endl;
}
