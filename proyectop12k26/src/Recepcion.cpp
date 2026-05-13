#include "Recepcion.h"
#include <iostream>              //Creado por 9959-25-3251 y 9959-25-2015
#include <string>
#include<fstream>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<iomanip>

using namespace std;

void Recepcion::validarAlumno(Alumnos alumno)
{
    string nombreIngresado;
    string carnetIngresado;

    cout << "\n===== RECEPCION ALUMNO / SISTEMA DE PAGOS =====" << endl;
;
    cout << "Ingrese nombre completo registrado: ";
    getline(cin, nombreIngresado);

    cout << "Ingrese carnet registrado: ";
    getline(cin, carnetIngresado);

    if(nombreIngresado == alumno.getnombreAlumno() &&
       carnetIngresado == alumno.getcarnetPersonal())
    {
        double montoPago = 300.00;

        cout << "\nDatos correctos." << endl;
        cout << "Acceso autorizado." << endl;

        cout << "Simulacion de Datos a Enviar a Banco...." <<endl;

        cout << "\n===== DATOS ENVIADOS A BANCOS =====" << endl;
        cout << "Nombre: " << alumno.getnombreAlumno() << endl;
        cout << "Carnet: " << alumno.getcarnetPersonal() << endl;
        cout << "Monto: Q" << montoPago << endl;

        cout << "\nEsperando integracion con clase Bancos..." << endl;
    }
    else
    {
        cout << "\nError: datos incorrectos." << endl;
        cout << "Acceso denegado." << endl;
    }
}

void Recepcion::validarMaestro(Maestros maestro)
{
    string nombreInsertado;
    string codigoInsertado;

    cout << "\n===== MODULO DOCENTE =====" << endl;

    cout << "Ingrese nombre del docente: ";
    getline(cin, nombreInsertado);

    cout<<"Ingrese codigo del docente: ";
    getline(cin, codigoInsertado);

    if(nombreInsertado == maestro.getNombre() &&
        stoi(codigoInsertado) == maestro.getCodigo())
    {
        double salario =4500;
        cout <<"Docente ingresado correctamente"<<endl;

        cout<<"=====Datos de Pago====="<<endl;
        cout << "Nombre: " << maestro.getNombre() << endl;
        cout << "Codigo: " << maestro.getCodigo() << endl;
        cout <<"Monto a pagar: " <<salario <<endl;

        cout<<"Enviando la informacion a bancos..." <<endl;

        }
        else
        {
            cout <<" Error, docente no encontrado" <<endl;
        }

};

void Recepcion::menu()
{
    int modulo;
    int choice;

    do
    {
        system("cls");

        cout << "===== SISTEMA DE RECEPCION =====" << endl;
        cout << "1. Modulo Estudiantes" << endl;
        cout << "2. Modulo Docentes" << endl;
        cout << "3. Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> modulo;

        cin.ignore();

        // MODULO ESTUDIANTES
        if(modulo == 1)
        {
            system("cls");

            cout << "===== MODULO ESTUDIANTES =====" << endl;
            cout << "1. Insertar Pagos" << endl;
            cout << "2. Desplegar Pagos" << endl;
            cout << "3. Modificar Pagos" << endl;
            cout << "4. Buscar Pagos" << endl;
            cout << "5. Borrar Pagos" << endl;

            cout << "\nIngrese opcion: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    insertarpagosAlumnos();
                    break;

                case 2:
                    desplegarpagosAlumnos();
                    break;

                case 3:
                    modificarpagosAlumnos();
                    break;

                case 4:
                    buscarpagosAlumnos();
                    break;

                case 5:
                    borrarpagosAlumnos();
                    break;

                default:
                    cout << "Opcion invalida";
            }
        }

        // MODULO DOCENTES
        else if(modulo == 2)
        {
            system("cls");

            cout << "===== MODULO DOCENTES =====" << endl;
            cout << "1. Insertar Pagos" << endl;
            cout << "2. Desplegar Pagos" << endl;
            cout << "3. Modificar Pagos" << endl;
            cout << "4. Buscar Pagos" << endl;
            cout << "5. Borrar Pagos" << endl;

            cout << "\nIngrese opcion: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    insertarpagosDocentes();
                    break;

                case 2:
                    desplegarpagosDocentes();
                    break;

                case 3:
                    modificarpagosDocentes();
                    break;

                case 4:
                    buscarpagosDocentes();
                    break;

                case 5:
                    borrarpagosDocentes();
                    break;

                default:
                    cout << "Opcion invalida";
            }
        }

        else if(modulo == 3)
        {
            cout << "\nSaliendo del sistema..." << endl;
        }

        else
        {
            cout << "\nOpcion invalida." << endl;
        }

        getch();

    } while(modulo != 3);
}
void Recepcion::insertarpagosAlumnos()
{
	system("cls");
	fstream file;
	cout<<"-----Agregar detalles del Estudiante-----"<<endl;
	cout<<"Ingrese Nombre del Estudiante: ";
	cin>>name;
	cout<<"Ingresa Carnet del Estudiante: ";
	cin>>carnet;
	cout<<"Ingresa el Monto Pagado: ";
	cin>>monto;
	file.open("Usuarios.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< carnet << std::left<<std::setw(15)<< monto<< "\n";
	file.close();
}
void Recepcion::desplegarpagosAlumnos()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"----- Tabla de Detalles del Estudiante -----"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"No se encontro informacion";
		file.close();
	}
	else
	{
		file >> name >> carnet >> monto;
		while(!file.eof())
		{
			total++;
			cout<<"Nombre del Estudiante: "<<name<<endl;
			cout<<"Carnet del Estudiante: "<<carnet<<endl;
			cout<<"Monto Pagado del Estudiante: "<<monto<<endl;
			file >> name >> carnet >>monto;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	file.close();
}
void Recepcion::modificarpagosAlumnos()
{
	system("cls");
	fstream file,file1;
	string participant_carnet;
	int found=0;
	cout<<"-----Modificacion Detalles del Estudiante-----"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"Ingrese carnet del Estudiante que quiere modificar: ";
		cin>>participant_carnet;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> carnet >> monto;
		while(!file.eof())
		{
			if(participant_carnet!=carnet)
			{
			 file <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< carnet <<std::left<<std::setw(15)<< monto << "\n";
			}
			else
			{
				cout<<"Ingrese Nombre del Estudiante: ";
				cin>>name;
				cout<<"Ingrese Carnet del Estudiante: ";
				cin>>carnet;
				cout<<"Ingrese Monto Pagado del Estudiante: ";
				cin>>monto;
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< carnet <<std::left<<std::setw(15)<< monto << "\n";
				found++;
			}
			file >> name >> carnet >> monto;

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
void Recepcion::buscarpagosAlumnos()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"-----Datos del Estudiante-----"<<endl;
		cout<<"No hay informacion...";
	}
	else
	{
		string participant_carnet;
		cout<<"-----Datos del Estudiante buscado-----"<<endl;
		cout<<"Ingrese carnet del Estudiante que quiere buscar: ";
		cin>>participant_carnet;
		file >> name >> carnet >> monto;
		while(!file.eof())
		{
			if(participant_carnet==carnet)
			{

				cout<<"Nombre del Estudiante: "<<name<<endl;
				cout<<"Carnet del Estudiante: "<<carnet<<endl;
				cout<<"Monto Pagado del Estudiante: "<<monto<<endl;
				found++;
			}
			file >> name >> carnet >> monto;
		}
		if(found==0)
		{
			cout<<"Persona no encontrada...";
		}
		file.close();
	}
}
void Recepcion::borrarpagosAlumnos()
{
	system("cls");
	fstream file,file1;
	string participant_carnet;
	int found=0;
	cout<<"-----Detalles del Estudiante a Borrar-----"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"No hay informacion...";
		file.close();
	}
	else
	{
		cout<<"Ingrese el carnet de la Persona que quiere borrar: ";
		cin>>participant_carnet;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> carnet >>monto;
		while(!file.eof())
		{
			if(participant_carnet!= carnet)
			{
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< carnet <<std::left<<std::setw(15)<< monto << "\n";
			}
			else
			{
				found++;
				cout << "Borrado de informacion exitoso";
			}
			file >> name >> carnet >> monto;
		}
		if(found==0)
		{
			cout<<"Carnet del Estudiante no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
void Recepcion::insertarpagosDocentes()
{
	system("cls");
	fstream file;
	cout<<"-----Agregar detalles del Docente-----"<<endl;
	cout<<"Ingrese Nombre del Docente: ";
	cin>>name;
	cout<<"Ingresa Codigo del Docente: ";
	cin>>codigo;
	cout<<"Ingresa el Monto Pagado: ";
	cin>>monto;
	file.open("Usuarios.txt", ios::app | ios::out);
	file <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< codigo << std::left<<std::setw(15)<< monto<< "\n";
	file.close();
}
void Recepcion::desplegarpagosDocentes()
{
	system("cls");
	fstream file;
	int total=0;
	cout<<"----- Tabla de Detalles del Docente -----"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"No se encontro informacion";
		file.close();
	}
	else
	{
		file >> name >> codigo >> monto;
		while(!file.eof())
		{
			total++;
			cout<<"Nombre del Docente: "<<name<<endl;
			cout<<"Codigo del Docente: "<<codigo<<endl;
			cout<<"Monto Pagado del Estudiante: "<<monto<<endl;
			file >> name >> codigo >>monto;
		}
		if(total==0)
		{
			cout<<"No hay informacion...";
		}
	}
	file.close();
}
void Recepcion::modificarpagosDocentes()
{
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"-----Modificacion Detalles del Docente-----"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"No hay informacion..,";
		file.close();
	}
	else
	{
		cout<<"Ingrese codigo del Docente que quiere modificar: ";
		cin>>participant_codigo;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> codigo >> monto;
		while(!file.eof())
		{
			if(participant_codigo!=codigo)
			{
			 file <<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< monto << "\n";
			}
			else
			{
				cout<<"Ingrese Nombre del Docente: ";
				cin>>name;
				cout<<"Ingrese Codigo del Docente: ";
				cin>>codigo;
				cout<<"Ingrese Monto Pagado del Estudiante: ";
				cin>>monto;
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< monto << "\n";
				found++;
			}
			file >> name >> codigo >> monto;

		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
void Recepcion::buscarpagosDocentes()
{
	system("cls");
	fstream file;
	int found=0;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"-----Datos del Docente-----"<<endl;
		cout<<"No hay informacion...";
	}
	else
	{
		string participant_codigo;
		cout<<"-----Datos del Docente buscado-----"<<endl;
		cout<<"Ingrese codigo del Docente que quiere buscar: ";
		cin>>participant_codigo;
		file >> name >> codigo >> monto;
		while(!file.eof())
		{
			if(participant_codigo==codigo)
			{

				cout<<"Nombre del Docente: "<<name<<endl;
				cout<<"Carnet del Docente: "<<codigo<<endl;
				cout<<"Monto Pagado del Docente: "<<monto<<endl;
				found++;
			}
			file >> name >> codigo >> monto;
		}
		if(found==0)
		{
			cout<<"Persona no encontrada...";
		}
		file.close();
	}
}
void Recepcion::borrarpagosDocentes()
{
	system("cls");
	fstream file,file1;
	string participant_codigo;
	int found=0;
	cout<<"-----Detalles del Docente a Borrar-----"<<endl;
	file.open("Usuarios.txt",ios::in);
	if(!file)
	{
		cout<<"No hay informacion...";
		file.close();
	}
	else
	{
		cout<<"Ingrese el codigo del Docente que quiere borrar: ";
		cin>>participant_codigo;
		file1.open("Record.txt",ios::app | ios::out);
		file >> name >> codigo >>monto;
		while(!file.eof())
		{
			if(participant_codigo!= codigo)
			{
				file1<<std::left<<std::setw(15)<< name <<std::left<<std::setw(15)<< codigo <<std::left<<std::setw(15)<< monto << "\n";
			}
			else
			{
				found++;
				cout << "Borrado de informacion exitoso";
			}
			file >> name >> carnet >> monto;
		}
		if(found==0)
		{
			cout<<"Codigo del Docente no encontrado...";
		}
		file1.close();
		file.close();
		remove("Usuarios.txt");
		rename("Record.txt","Usuarios.txt");
	}
}
