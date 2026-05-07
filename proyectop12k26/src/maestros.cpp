#include "maestros.h" // Creado por Abner Muñoz 9959-25-13959
#include "carrera.h"
#include "Cursos.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;

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
        cout << "\t\t\t 8. Salir" << endl;
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
                cout << "\n\t\t\t Saliendo del sistema..." << endl;
                exit(0);
            default:
                cout << "\n\t\t\t Opcion invalida...";
        }
        system("pause");
    } while (choice != 8);
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

    fstream file;
    file.open("Maestros.txt", ios::app | ios::out);
    file << left << setw(15) << id
         << left << setw(20) << nombre
         << left << setw(20) << apellido
         << left << setw(15) << dpi
         << left << setw(10) << codigo
         << left << setw(20) << "SIN ASIGNAR"
         << left << setw(10) << "0" << "\n";
    file.close();

    cout << "\n\t\t\t¡Maestro registrado exitosamente!" << endl;
    cout << "Codigo de seguridad: " << codigo << endl;
}

void Maestros::desplegar()
{
    system("cls");
    fstream file;
    int total = 0;

    cout << "\n----------------- LISTA DE MAESTROS -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay maestros registrados..." << endl;
        file.close();
    } else {
        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede;
        int temp_codigo, temp_cursos;

        file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;

        while (!file.eof()) {
            total++;
            cout << "\n\t\t\t ID: " << temp_id << endl;
            cout << "\t\t\t Nombre: " << temp_nombre << " " << temp_apellido << endl;
            cout << "\t\t\t DPI: " << temp_dpi << endl;
            cout << "\t\t\t Codigo: " << temp_codigo << endl;
            cout << "\t\t\t Carrera: " << temp_sede << endl;
            cout << "\t\t\t Cursos: " << temp_cursos << endl;
            cout << "\t\t\t ------------------------------------" << endl;

            file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;
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
    fstream file, file1;
    string search_id;
    int found = 0;

    cout << "\n----------------- MODIFICAR MAESTRO -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
        file.close();
    } else {
        cout << "\n Ingrese ID del maestro a modificar: ";
        cin >> search_id;

        file1.open("Record.txt", ios::app | ios::out);

        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede;
        int temp_codigo, temp_cursos;

        file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;

        while (!file.eof()) {
            if (search_id != temp_id) {
                file1 << left << setw(15) << temp_id
                      << left << setw(20) << temp_nombre
                      << left << setw(20) << temp_apellido
                      << left << setw(15) << temp_dpi
                      << left << setw(10) << temp_codigo
                      << left << setw(20) << temp_sede
                      << left << setw(10) << temp_cursos << "\n";
            } else {
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

                file1 << left << setw(15) << id
                      << left << setw(20) << nombre
                      << left << setw(20) << apellido
                      << left << setw(15) << dpi
                      << left << setw(10) << codigo
                      << left << setw(20) << temp_sede
                      << left << setw(10) << temp_cursos << "\n";

                cout << "\n\t\t\t¡Modificacion exitosa!" << endl;
            }
            file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;
        }

        if (found == 0) {
            cout << "\n\t\t\t ID no encontrado..." << endl;
        }

        file1.close();
        file.close();
        remove("Maestros.txt");
        rename("Record.txt", "Maestros.txt");
    }
}

void Maestros::buscar()
{
    system("cls");
    fstream file;
    int found = 0;

    cout << "\n----------------- BUSCAR MAESTRO -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
    } else {
        string search_id;
        cout << "\n Ingrese ID del maestro a buscar: ";
        cin >> search_id;

        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede;
        int temp_codigo, temp_cursos;

        file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;

        while (!file.eof()) {
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
            file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;
        }

        if (found == 0) {
            cout << "\n\t\t\t Maestro no encontrado..." << endl;
        }
        file.close();
    }
}

void Maestros::borrar()
{
    system("cls");
    fstream file, file1;
    string delete_id;
    int found = 0;

    cout << "\n----------------- ELIMINAR MAESTRO -----------------" << endl;
    file.open("Maestros.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay informacion..." << endl;
        file.close();
    } else {
        cout << "\n Ingrese ID del maestro a eliminar: ";
        cin >> delete_id;

        file1.open("Record.txt", ios::app | ios::out);

        string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede;
        int temp_codigo, temp_cursos;

        file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;

        while (!file.eof()) {
            if (delete_id != temp_id) {
                file1 << left << setw(15) << temp_id
                      << left << setw(20) << temp_nombre
                      << left << setw(20) << temp_apellido
                      << left << setw(15) << temp_dpi
                      << left << setw(10) << temp_codigo
                      << left << setw(20) << temp_sede
                      << left << setw(10) << temp_cursos << "\n";
            } else {
                found++;
                cout << "\n\t\t\t¡Maestro eliminado!" << endl;
            }
            file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;
        }

        if (found == 0) {
            cout << "\n\t\t\t ID no encontrado..." << endl;
        }

        file1.close();
        file.close();
        remove("Maestros.txt");
        rename("Record.txt", "Maestros.txt");
    }
}

void Maestros::ingresarDatosPersonales()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "DPI: " << dpi << endl;
}

void Maestros::generarCodigo()
{
    srand(time(0));
    codigo = 1000 + rand() % 9000;
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

void Maestros::mostrarCarreras()
{
    cout << "\nCarreras disponibles:" << endl;
    carrera objCarrera;
    vector<carrera> carreras = objCarrera.datoscarreras();

    for (int i = 0; i < carreras.size(); i++) {
        if (carreras[i].getestadocarrera()) {
            cout << i + 1 << ". " << carreras[i].getnombrecarrera()
                 << " (Codigo: " << carreras[i].getcodigocarrera() << ")" << endl;
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

void Maestros::asignarCurso()
{
    system("cls");
    cout << "\n--- ASIGNAR CARRERA Y CURSO A MAESTRO ---" << endl;

    int codigoIngresado;
    cout << "Ingrese su codigo de seguridad: ";
    cin >> codigoIngresado;

    fstream file;
    string temp_id, temp_nombre, temp_apellido, temp_dpi, temp_sede;
    int temp_codigo, temp_cursos;
    bool encontrado = false;

    file.open("Maestros.txt", ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay maestros registrados..." << endl;
        file.close();
        return;
    }

    vector<string> lineas;
    file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;

    while (!file.eof()) {
        if (temp_codigo == codigoIngresado) {
            encontrado = true;
            id = temp_id;
            nombre = temp_nombre;
            apellido = temp_apellido;
            dpi = temp_dpi;
            codigo = temp_codigo;
            break;
        }
        file >> temp_id >> temp_nombre >> temp_apellido >> temp_dpi >> temp_codigo >> temp_sede >> temp_cursos;
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

    carrera objCarrera;
    vector<carrera> carreras = objCarrera.datoscarreras();

    if (opcionCarrera >= 1 && opcionCarrera <= carreras.size()) {
        carreraAsignada = carreras[opcionCarrera - 1];
        cout << "\nCarrera seleccionada: " << carreraAsignada.getnombrecarrera() << endl;

        mostrarCursosPorCarrera(carreraAsignada.getcodigocarrera());

        int opcionCurso;
        cout << "\nSeleccione el curso: ";
        cin >> opcionCurso;

        if (carreraAsignada.getcodigocarrera() == "9959") {
            Cursos cursoTemp;
            vector<Cursos> cursos = cursoTemp.catalagoCursosIngSistemas();

            if (opcionCurso >= 1 && opcionCurso <= cursos.size()) {
                Cursos cursoSeleccionado = cursos[opcionCurso - 1];
                cursosAsignados.push_back(cursoSeleccionado);

                cout << "\nCurso asignado: " << cursoSeleccionado.getnombreCurso() << endl;

                asignarHorario();

                cout << "\n=== RESUMEN DE ASIGNACION ===" << endl;
                cout << "Maestro: " << nombre << " " << apellido << endl;
                cout << "Carrera: " << carreraAsignada.getnombrecarrera() << endl;
                cout << "Curso: " << cursoSeleccionado.getnombreCurso() << endl;
                cout << "Sede: " << sede << endl;
                cout << "Salario mensual: Q" << calcularSalario() << endl;

                fstream fileOut, tempFile;
                fileOut.open("Maestros.txt", ios::in);
                tempFile.open("Temp.txt", ios::app | ios::out);

                string t_id, t_nombre, t_apellido, t_dpi, t_sede;
                int t_codigo, t_cursos;

                fileOut >> t_id >> t_nombre >> t_apellido >> t_dpi >> t_codigo >> t_sede >> t_cursos;

                while (!fileOut.eof()) {
                    if (t_codigo == codigoIngresado) {
                        tempFile << left << setw(15) << t_id
                                << left << setw(20) << t_nombre
                                << left << setw(20) << t_apellido
                                << left << setw(15) << t_dpi
                                << left << setw(10) << t_codigo
                                << left << setw(20) << carreraAsignada.getnombrecarrera()
                                << left << setw(10) << cursosAsignados.size() << "\n";
                    } else {
                        tempFile << left << setw(15) << t_id
                                << left << setw(20) << t_nombre
                                << left << setw(20) << t_apellido
                                << left << setw(15) << t_dpi
                                << left << setw(10) << t_codigo
                                << left << setw(20) << t_sede
                                << left << setw(10) << t_cursos << "\n";
                    }
                    fileOut >> t_id >> t_nombre >> t_apellido >> t_dpi >> t_codigo >> t_sede >> t_cursos;
                }

                fileOut.close();
                tempFile.close();
                remove("Maestros.txt");
                rename("Temp.txt", "Maestros.txt");
            }
        }
    }
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

void Maestros::ingresarNotas()
{
    system("cls");
    cout << "\n----------------- INGRESO DE NOTAS -----------------" << endl;

    string carnet, nombreAlumno;
    double nota1, nota2, nota3, notaFinal;

    cout << "Ingrese carnet del alumno: ";
    cin >> carnet;
    cout << "Ingrese nombre del alumno: ";
    cin >> nombreAlumno;
    cout << "\n--- Ingrese las notas ---" << endl;
    cout << "Nota 1 (0-100): ";
    cin >> nota1;
    cout << "Nota 2 (0-100): ";
    cin >> nota2;
    cout << "Nota 3 (0-100): ";
    cin >> nota3;

    notaFinal = (nota1 + nota2 + nota3) / 3;

    fstream file;
    file.open("Notas.txt", ios::app | ios::out);
    file << left << setw(15) << carnet
         << left << setw(25) << nombreAlumno
         << left << setw(10) << nota1
         << left << setw(10) << nota2
         << left << setw(10) << nota3
         << left << setw(10) << notaFinal;

    if (notaFinal >= 60) {
        file << left << setw(10) << "APROBADO" << "\n";
        cout << "\n\t\t\t Alumno APROBADO con " << notaFinal << " puntos" << endl;
    } else {
        file << left << setw(10) << "REPROBADO" << "\n";
        cout << "\n\t\t\t Alumno REPROBADO con " << notaFinal << " puntos" << endl;
    }

    file.close();
    cout << "\n\t\t\t¡Notas guardadas exitosamente!" << endl;

    char verNotas;
    cout << "\n¿Desea ver las notas del alumno? (s/n): ";
    cin >> verNotas;

    if (verNotas == 's' || verNotas == 'S') {
        fstream fileRead;
        fileRead.open("Notas.txt", ios::in);

        if (!fileRead) {
            cout << "\n\t\t\tNo hay notas registradas..." << endl;
        } else {
            string temp_carnet, temp_nombre, temp_estado;
            double temp_n1, temp_n2, temp_n3, temp_nf;

            cout << "\n--- HISTORIAL DE NOTAS ---" << endl;
            fileRead >> temp_carnet >> temp_nombre >> temp_n1 >> temp_n2 >> temp_n3 >> temp_nf >> temp_estado;

            while (!fileRead.eof()) {
                if (temp_carnet == carnet) {
                    cout << "\nCarnet: " << temp_carnet << endl;
                    cout << "Alumno: " << temp_nombre << endl;
                    cout << "Nota 1: " << temp_n1 << endl;
                    cout << "Nota 2: " << temp_n2 << endl;
                    cout << "Nota 3: " << temp_n3 << endl;
                    cout << "Nota Final: " << temp_nf << endl;
                    cout << "Estado: " << temp_estado << endl;
                    break;
                }
                fileRead >> temp_carnet >> temp_nombre >> temp_n1 >> temp_n2 >> temp_n3 >> temp_nf >> temp_estado;
            }
            fileRead.close();
        }
    }
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
    cout << "Carrera: " << carreraAsignada.getnombrecarrera() << endl;
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

carrera Maestros::getCarreraAsignada()
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
