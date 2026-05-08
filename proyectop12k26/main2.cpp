#include <iostream>
#include "Alumnos.h"
#include "Carrera.h"
#include "Cursos.h"
#include "facultades.h"
#include "inscipcion.h"
#include "Recepcion.h"

//main de prueba
using namespace std;

int main()
{
    int opcion;

    Alumnos alumnoGlobal;

    bool alumnoRegistrado = false;

    do{
        system("cls");

        cout << "======================================" << endl;
        cout << " UNIVERSIDAD MARIANO GALVEZ - SISTEMA " << endl;
        cout << "======================================" << endl;
        cout << "1. Registro de Alumno" << endl;
        cout << "2. Carrera" << endl;
        cout << "3. Cursos" << endl;
        cout << "4. Facultad" << endl;
        cout << "5. Inscripcion" << endl;
        cout << "6. Recepcion / Sistema de Pagos" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch(opcion)
        {
            case 1:
            {
                alumnoGlobal.menuRegistro();

                alumnoRegistrado = true;

                system("pause");
                break;
            }

            case 2:
            {
                Carreras carrera;
                carrera.ingresarDatos();
                carrera.mostrarDatos();

                system("pause");
                break;
            }

            case 3:
            {
                Cursos curso("Programacion", 101, "Ninguno", true);

                cout << "\n--- DATOS DEL CURSO ---" << endl;
                cout << "Nombre: " << curso.getnombreCurso() << endl;
                cout << "Codigo: " << curso.getcodigoCurso() << endl;
                cout << "Pre-Requisito: " << curso.getpreRequisitoDeCurso() << endl;
                cout << "Estado: " << (curso.getestadoCurso() ? "Activo" : "Inactivo") << endl;

                system("pause");
                break;
            }

            case 4:
            {
                Facultad facultad;
                facultad = Facultad(101, "Ingenieria en Sistemas", true, "Privado");
                facultad.mostrarInformacion();

                system("pause");
                break;
            }

            case 5:
            {
                Inscripcion inscripcion;
                inscripcion.ingresarDatos();
                inscripcion.mostrarDatos();

                system("pause");
                break;
            }

            case 6:
            {
                int opcionRecepcion;

                do{
                    system("cls");

                    cout << "===== RECEPCION / SISTEMA DE PAGOS =====" << endl;
                    cout << "1. Alumno" << endl;
                    cout << "2. Docente / Maestro" << endl;
                    cout << "3. Empleado" << endl;
                    cout << "0. Regresar" << endl;
                    cout << "Seleccione una opcion: ";
                    cin >> opcionRecepcion;
                    cin.ignore();

                    switch(opcionRecepcion)
                    {
                        case 1:
                        {
                            Recepcion recepcion;


                            if(alumnoRegistrado)
                            {
                                recepcion.validarAlumno(alumnoGlobal);
                            }
                            else
                            {
                                cout << "No hay alumno registrado aun." << endl;
                            }

                            system("pause");
                            break;
                        }

                        case 2:
                        {
                            Recepcion recepcion;
                            recepcion.validarDocente();

                            system("pause");
                            break;
                        }

                        case 3:
                        {
                            Recepcion recepcion;
                            recepcion.validarEmpleado();

                            system("pause");
                            break;
                        }

                        case 0:
                            break;

                        default:
                        {
                            cout << "Opcion invalida." << endl;
                            system("pause");
                        }
                    }

                }while(opcionRecepcion != 0);

                break;
            }

            case 0:
            {
                cout << "Saliendo del sistema..." << endl;
                break;
            }

            default:
            {
                cout << "Opcion invalida." << endl;
                system("pause");
            }
        }

    }while(opcion != 0);

    return 0;
}
