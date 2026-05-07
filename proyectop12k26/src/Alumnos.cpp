//Creado por Fernando Castillo - 9959 - 25 - 288
#include "Alumnos.h"
#include "Carrera.h"
//Biblotecas
#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
#include <vector>
#include <iomanip>
#include <conio.h>

using namespace std;

//Constructor
Alumnos::Alumnos()
{
    //inicializar varibles
    this -> nombreAlumno = "";
    this -> apellidoAlumno = "";
    this -> diaNacimiento = 0;
    this -> mesNacimiento = 0;
    this -> anioNacimiento = 0;
    this -> numeroDpi = "";
    this -> correoPersonal = "";
    this -> fechaNacimientoAlumno = "";
    this -> carnetPersonal = "";
    this -> sexoAlumno = "";
}


//Constructor sobrecargado
Alumnos::Alumnos(string nombreCompletoAlumno, string sexoAlumno, string numeroDpi, string correoPersonal, string carnetPersonal, string carreraAsignada)
{
    this -> nombreCompletoAlumno = nombreCompletoAlumno;
    this -> sexoAlumno = sexoAlumno;
    this -> numeroDpi = numeroDpi;
    this -> correoPersonal = correoPersonal;
    this -> carnetPersonal = carnetPersonal;
    this -> carreraAsignada = carreraAsignada;
}

//Creando Alumnos Prueba
vector<Alumnos> Alumnos::alumnosPrueba()
{
    //Almacena en un vector datos de unos alumnos de prueba
    //Los datos se almacenara en el constructor sobrecargado
    vector<Alumnos> alumnos;
    alumnos.push_back(Alumnos("Carlos Roberto Méndez Ruiz", "Maculino", "2584910230101", "cmendez001@miumg.edu.gt", "9959-26-001", "Ingenieria en Sistemas"));
    alumnos.push_back(Alumnos("Ana Lucia Villagran Sosa", "Femenino", "3015427891702", "avillagran002@miumg.edu.gt", "9975-26-002", "Ingenieria Industrial"));
    alumnos.push_back(Alumnos("Sergio Alejandro Torres Paz", "Maculino", "1992553010401", "storres003@miumg.edu.gt", "9973-26-003", "Ingenieria Civil"));
    alumnos.push_back(Alumnos("Maria Fernanda Lopez Herrera", "Femenino", "2240189650101", "mlopez004@miumg.edu.gt", "9959-26-004", "Ingenieria en Sistemas"));
    alumnos.push_back(Alumnos("Gustavo Adolfo Xitumul Calel", "Masculino", "2833041121501", "gxitumul005@miumg.edu.gt", "9975-26-005", "Ingenieria Industrial"));
    return alumnos;
}

//Menu registro alumno
void Alumnos::menuRegistro()
{
    //Variables
    int opcionCarrera = 0;//Para obtener la opcion del alumno
    int indice = 0;//Para recorrer el vector
    //Instancia de clase carrera y obtener los datos del vector
    Carrera configCarrera;
    vector<Carrera> obtenerCarrera = configCarrera.datosCarreras();

    //Inicio del do-while
    do{
        //Carreras Disponibles
        system("cls");
        cout << "--- Seleccione la Carrera ---" << endl;
        cout << "1. Ingenieria en Sistemas" << endl;
        cout << "2. Ingenieria Industrial" << endl;
        cout << "3. Ingenieria Civil" << endl;
        cout << "¿Que carrera desea escoger?:" << endl;
        cin >> opcionCarrera;//Obtener el digito
        cin.ignore(1000, '\n');//Ingonra los espaciones del usuario
        //Validacion del menu
        if (opcionCarrera < 1 || opcionCarrera > 3){
            //Capturamos el error del usuario y le mostramos el error
            cout << "Error. escoga una carrera (1-3)" << endl;
            this_thread::sleep_for(chrono::seconds(2));
        }else {
            //Sino se cumple la condicion recorre el vector
            indice = opcionCarrera - 1;//Como empieza el vector en 0 le restamos 1 la opcionCarrera
        }
    }while (!(opcionCarrera >= 1 && opcionCarrera <= 3));//Fin del do while

    //Llamada de los metodos
    registroDatos();
    creaCorreoPersonal();//La funcion crear un correo
    crearCarnetPersonal(obtenerCarrera[indice].getcodigoCarrera());//En la clase carrera buscara el codigo de la carrera
    this -> carreraAsignada = obtenerCarrera[indice].getnombreCarrera();//En la clase carrera buscara el nombre de la carrera y lo aguardamos en esta variable
    registroExitoso();//Muestra que el registro fue exitoso y genera su carnet y correo de uso personal
}

//Obtner los datos ingresados por el usuario
void Alumnos::registroDatos()
{
    //Variables
    bool validarInformacion;//Para validar los digitos del dpi
    char confirmarDatos;//Confirmacion de los datos del usuario
    //Inicio del do-while
    do{
        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese sus nombres: " << endl;//Pedir los nombres
            getline(cin, this -> nombreAlumno);//S
            if (this -> nombreAlumno == ""){
                cout << "Error, el nombre no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }else{
                if (this -> nombreAlumno == " "){
                    cout << "Error, solo coloco un espacio ingrese sus nombres" << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                }
            }
        }while (this -> nombreAlumno == "" || this -> nombreAlumno == " ");//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese sus apellidos: " << endl;//Pedir los apellidos
            getline(cin, this -> apellidoAlumno);
            if (this -> apellidoAlumno == ""){
                cout << "Error, el apellido no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }else{
                if (this -> apellidoAlumno == " "){
                    cout << "Error, el apellido no puede ir vacio" << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                }
            }
        }while (this -> apellidoAlumno == "" || this -> apellidoAlumno == " ");//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su sexo (Masculino/Femenino): " << endl;//Pedir su genero
            getline(cin, this -> sexoAlumno);
            if (this -> sexoAlumno == ""){
                cout << "Error, el sexo no puede ir vacio" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }else {
                if (this -> sexoAlumno == "M" || this -> sexoAlumno == "m"){
                    cout << "Error, dato no valido" << endl;
                    this_thread::sleep_for(chrono::seconds(2));
                }else{
                    if (this -> sexoAlumno == " "){
                        cout << "Error, solo coloco un espacio ingrese su sexo" << endl;
                        this_thread::sleep_for(chrono::seconds(2));
                    }
                }
            }
        }while (this -> sexoAlumno == "" || this -> sexoAlumno == "M" || this -> sexoAlumno == "m" || this -> sexoAlumno == " ");//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su numero de DPI: " << endl;//Pedir su numero de dpi
            getline(cin, this -> numeroDpi);
            //Valida digitos del dpi
            if (this -> numeroDpi.size() != 13){
                cout << "Error, su numero de DPI tiene que tener 13 digitos" << endl;
                validarInformacion = false;
            }else{
                validarInformacion = true;
            }

            if (!validarInformacion){
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (validarInformacion != true || this -> numeroDpi == "" || this -> numeroDpi == " ");//Fin del do-while

        //Inicio del do-while
         do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su dia de nacimiento (1-31): " << endl;//Pedir dia nacimiento
            cin >> this -> diaNacimiento;
            if (this -> diaNacimiento < 1 || this -> diaNacimiento > 31){
                cout << "Error, dia no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (!(this -> diaNacimiento >= 1 && this -> diaNacimiento <= 31));//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su mes de nacimiento (1-12): " << endl;//Pedir mes de nacimiento
            cin >> this -> mesNacimiento;
            if (this -> mesNacimiento < 1 || this -> mesNacimiento > 12){
                cout << "Error, mes no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (!(this -> mesNacimiento >= 1 && this -> mesNacimiento <= 12));//Fin del do-while

        //Inicio del do-while
        do{
            system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
            cout << "Ingrese su año de nacimiento (1940-2009): " << endl;//Pedir año de nacimiento
            cin >> this -> anioNacimiento;
            if (this -> anioNacimiento < 1940 || this -> anioNacimiento > 2009){
                cout << "Error, mes no valido" << endl;
                this_thread::sleep_for(chrono::seconds(2));
            }
        }while (!(this -> anioNacimiento >= 1940 && this -> anioNacimiento <= 2009));//Fin del do-while

        //Se llama estas dos funciones para llenar los datos segun la funcion
        obtenerFechaNacimiento();
        obtenerNombreCompleto();

        system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
        //Se muestra los datos del usuario y le preguntamos si son correctos
        //Si dice que no lo regresamos otra vez para que ingrese sus datos
        cout << "--- Datos Personales ---" << endl;
        cout << "Nombres: " << this -> getnombreCompletoAlumno() << endl;//Muestra sus nombres que ingreso
        cout << "Apellidos: " << this -> getapellidoAlumno() << endl;//Muestra sus apellidos que ingreso
        cout << "Sexo: " << this -> getsexoAlumno() << endl;//Muestra su genero que ingreso
        cout << "DPI: " << this -> getnumeroDpi() << endl;//Muestra su dpi
        cout << "Fecha nacimiento: " << this -> getfechaNacimientoAlumno() << endl;//Muestra su fecha de nacimiento
        cout << "¿Los datos son correctos (S/N)?: " << endl;//Preguntamos si son correctos
        cin >> confirmarDatos;
        cin.ignore(1000, '\n');

    }while (confirmarDatos == 'n' || confirmarDatos == 'N');//Fin del do-while

    cout << "Verificando datos... por favor espere." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Generando carnet..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
	cout << "Generando correo..." << endl;
	this_thread::sleep_for(chrono::seconds(2));
}

//Obtiene la fecha completa del alumno
void Alumnos::obtenerFechaNacimiento()
{
    this -> fechaNacimientoAlumno = to_string(this -> diaNacimiento) + "/" + to_string(this -> mesNacimiento) + "/" + to_string(this -> anioNacimiento);
}

//Genera correo personal
void Alumnos::creaCorreoPersonal()
{
    size_t i = 0;
    string nombreInicial = "";
    int numAleatorioCorreo = numeroAleatorio(100, 2000);
    string primerApellido = "";
    nombreInicial = this -> nombreAlumno.substr(0, 1);
    while ( i < this -> apellidoAlumno.size() && this -> apellidoAlumno[i] != ' '){
        primerApellido += this -> apellidoAlumno[i];
        i++;
    }
    this -> correoPersonal = nombreInicial + primerApellido + to_string(numAleatorioCorreo) + "@miumg.edu.gt";

    //Un ciclo for para crear el correo en minusculas
    for (size_t j = 0 ; j < this -> correoPersonal.length(); j++){
        this -> correoPersonal[j] = tolower(this -> correoPersonal[j]);
    }
}

//Genera Carnet Personal
void Alumnos::crearCarnetPersonal(string codigoCarrera)
{
    int numAleatorio =  numeroAleatorio(100, 2000);
    this -> carnetPersonal = codigoCarrera + "-" + to_string(obtenerAnioCorto()) + "-" + to_string(numAleatorio);
}

//Genera numeros Aleatorios
int Alumnos::numeroAleatorio(int minimo, int maximo)
{
    return minimo + rand() % (maximo - minimo + 1);
}

//Obtener el año corto (ej.26) para el codigo del carnet
int Alumnos::obtenerAnioCorto()
{
    return this -> ANIO_ACTUAL % 100;
}

//Almacena el nombre y apellido dentro de una sola variable
void Alumnos::obtenerNombreCompleto()
{
    this -> nombreCompletoAlumno = this -> nombreAlumno + " " + this -> apellidoAlumno;
}

//Muestra que se registro se hizo correctamente
void Alumnos::registroExitoso()
{
    system("cls");//Borra informacion del compilador y no llenarla de tanta informacion
    cout << "--- Universidad UMG - Registro Exitoso ---" << endl;
    cout << "Alumno: " << this -> getnombreAlumno() << " " << this -> getapellidoAlumno() << endl;
    cout << "Carnet: " << this -> getcarnetPersonal() << endl;
    cout << "Correo: " << this -> getcorreoPersonal() << endl;
    cout << "Carrera: " << this -> getcarreraAsignada() << endl;

}

//Menu principal CRUD
void Alumnos::menuInsertar()
{
    int escogerOpcion = 0;
    char validacionAgregar;
    do{
        system("cls");
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t |   SISTEMA GESTION ALUMNO    | " << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t 1. Ingresar Alumno" << endl;
        cout << "\t\t\t\t\t 2. Despliegue Alumno" << endl;
        cout << "\t\t\t\t\t 3. Modificar Alumno" << endl;
        cout << "\t\t\t\t\t 4. Buscar Alumno" << endl;
        cout << "\t\t\t\t\t 5. Borrar Alumno" << endl;
        cout << "\t\t\t\t\t 6. Exit" << endl;

        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "\t\t\t\t\t Opciones a Escoger: [1/2/3/4/5/6]" << endl;
        cout << "\t\t\t\t\t---------------------------------" << endl;
        cout << "¿Que opcion desea escoger?: "; cin >> escogerOpcion;

        switch(escogerOpcion)
        {
            case 1:
                do
                {
                    insertarAlumno();
                    cout << "\n\t\t\t\t Agregar otro Alumno (S/N): "; cin >> validacionAgregar;
                }while (validacionAgregar == 's' || validacionAgregar == 'S');
                break;
            case 2:
                desplegarAlumno();
                break;
            case 3:
                modificarAlumno();
                break;
            case 4:
                buscarAlumno();
                break;
            case 5:
                borrarAlumno();
                break;
            case 6:
                exit(0);
            default:
                cout << "\n\t\t\t\t Opcion invalida... Por favor pruebe otra vez" << endl;
        }
        getch();
    }while (escogerOpcion != 6);

}

//Crear
void Alumnos::insertarAlumno()
{
        cin.ignore();
        system("cls");
        fstream file;
        cout << "\n------------------------------------------------------------------------------------------------------------";
        cout << "\n----------------------------------------Agregar Detalles del Alumno-----------------------------------------" << endl;
        cout << "\t\t\t Ingrese id unico del alumno: "; cin >> idUnico;
        cin.ignore();
        cout << "\t\t\t Ingrese nombre del alumno: "; getline(cin, nombreAlumno);
        cout << "\t\t\t Ingrese carnet del alumno: "; getline(cin, carnetPersonal);
        cout << "\t\t\t Ingrese correo del alumno: "; getline(cin, correoPersonal);
        cout << "\t\t\t Ingrese constraseña del alumno: "; getline(cin, contraseniaUnica);
        file.open("Alumnos.txt", ios::app | ios::out);
        file << std::left << std::setw(15) << idUnico << std::left << std::setw(15) << nombreAlumno <<
        std::left << std::setw(15) << carnetPersonal <<
        std::left << std::setw(30) << correoPersonal <<
        std::left << std::setw(15) << contraseniaUnica << "\n";
        file.close();
}

//Desplegar
void Alumnos::desplegarAlumno()
{
    cin.ignore();
    system("cls");
    fstream file;
    int total = 0;
    cout << "\n----------------------------------------Tabla de Detalles de Personas-----------------------------------------" << endl;
    file.open("Alumnos.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\t\t No hay información...";
        file.close();
    }
    else
    {
        file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        while(!file.eof())
        {
            total++;
            cout << "\n\n\t\t\t Id del alumno: " << idUnico << endl;
            cout << "\t\t\t Nombre del alumno: " << nombreAlumno << endl;
            cout << "\t\t\t Carnet del alumno: " << carnetPersonal << endl;
            cout << "\t\t\t Correo del alumno: " << correoPersonal << endl;
            cout << "\t\t\t Contraseña del alumno: " << contraseniaUnica << endl;
            file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        }
        if (total == 0)
        {
            cout << "\t\t\t No hay información...";
        }
    }
    file.close();
}

//Modificar
void Alumnos::modificarAlumno()
{
    cin.ignore();
    system("cls");
    fstream file,file1;
    string participanteId = "";
    int found = 0;
    cout << "\n----------------------------------------Modificar Detalles Alumno-----------------------------------------" << endl;
    file.open("Alumnos.txt", ios::in);
    if(!file)
    {
        cout << "\t\t\t No hay información...";
        file.close();
    }
    else
    {
        cout << "\n Ingrese el id del alumno que quiere modificar: "; cin >> participanteId;
        file1.open("Record.txt", ios::app | ios::out);
        file >> idUnico >> nombreAlumno >> carreraAsignada >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        while(!file.eof())
        {
            cout << "\t\t\t Ingrese nombre del alumno: "; getline(cin, nombreAlumno);
            cout << "\t\t\t Ingrese carnet del alumno: "; getline(cin, carnetPersonal);
            cout << "\t\t\t Ingrese correo del alumno: "; getline(cin, correoPersonal);
            cout << "\t\t\t Ingrese constraseña del alumno: "; getline(cin, contraseniaUnica);
            file1 << std::left << std::setw(15) << idUnico << std::left << std::setw(15) << nombreAlumno <<
            std::left << std::setw(15) << carnetPersonal <<
            std::left << std::setw(30) << correoPersonal <<
            std::left << std::setw(15) << contraseniaUnica << "\n";
            found++;
        }
        file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
    }
    file1.close();
    file.close();
    remove("Alumnos.txt");
    rename("Record.txt", "Alumnos.txt");
}

//Buscar
void Alumnos::buscarAlumno()
{
    cin.ignore();
    system("cls");
    fstream file;
    int found = 0;
    file.open("Alumnos.txt", ios::in);
    if(!file)
    {
        cout << "\n----------------------------------------Datos del Alumno Buscado-----------------------------------------" << endl;
        cout << "\t\t\t No hay información...";
    }
    else
    {
        string participanteId = "";
        cout << "\n----------------------------------------Datos del Alumno Buscado-----------------------------------------" << endl;
        cout << "\n Ingrese el id del alumno que quiere buscar: "; cin >> participanteId;
        file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        while(!file.eof())
        {
            if (participanteId == idUnico)
            {
                cout << "\n\n\t\t\t Id del alumno: " << idUnico << endl;
                cout << "\t\t\t Nombre del alumno: " << nombreAlumno << endl;
                cout << "\t\t\t Carnet del alumno: " << carnetPersonal << endl;
                cout << "\t\t\t Correo del alumno: " << correoPersonal << endl;
                cout << "\t\t\t Contraseña del alumno: " << contraseniaUnica << endl;
                found++;
            }
            file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        }
        if (found == 0)
        {
            cout << "\t\t\t Alumno encontrado...";
        }
        file.close();

    }
}

//Borrar
void Alumnos::borrarAlumno()
{
    cin.ignore();
    system("cls");
    fstream file,file1;
    string participanteId = "";
    int found = 0;
    cout << "\n----------------------------------------Detalles del Alumno a Borrar-----------------------------------------" << endl;
    file.open("Alumnos.txt", ios::in);
    if(!file){
        cout << "\n\t\t\t\t No hay información..." << endl;
        file.close();
    }else{
        cout << "\n Ingrese el id del alumno que quiere borrar: "; cin >> participanteId;
        file1.open("Record.txt", ios::app | ios::out);
        file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        while(!file.eof()){
            if (participanteId != idUnico){
                file1 << std::left << std::setw(15) << idUnico << std::left << std::setw(15) << nombreAlumno <<
                        std::left << std::setw(15) << carnetPersonal <<
                        std::left << std::setw(30) << correoPersonal <<
                        std::left << std::setw(15) << contraseniaUnica << "\n";
            }else{
                found++;
                cout << "\n\t\t\t\t Borrado de informacion exitoso";
            }
            file >> idUnico >> nombreAlumno >> carnetPersonal >> correoPersonal >> contraseniaUnica;
        }
        if (found == 0){
            cout << "\n\t\t\t\t Id alumno no econtrado...";
        }
        file1.close();
        file.close();
        remove("Alumnos.txt");
        rename("Record.txt", "Alumnos.txt");
    }
}

//Getters
string Alumnos::getnombreCompletoAlumno()
{
    return this -> nombreCompletoAlumno;
}
string Alumnos::getnombreAlumno()
{
    return this -> nombreAlumno;
}
string Alumnos::getapellidoAlumno()
{
    return this -> apellidoAlumno;
}
string Alumnos::getsexoAlumno()
{
    return this -> sexoAlumno;
}
int Alumnos::getdiaNacimiento()
{
    return this -> diaNacimiento;
}
string Alumnos::getnumeroDpi()
{
    return this -> numeroDpi;
}
int Alumnos::getmesNacimiento()
{
    return this -> mesNacimiento;
}
int Alumnos::getanioNacimiento()
{
    return this -> anioNacimiento;
}
string Alumnos::getcorreoPersonal()
{
    return this -> correoPersonal;
}

string Alumnos::getfechaNacimientoAlumno()
{
    return this -> fechaNacimientoAlumno;
}
string Alumnos::getcarnetPersonal()
{
    return this -> carnetPersonal;
}
string Alumnos::getcarreraAsignada()
{
    return this -> carreraAsignada;
}
//Setters
void Alumnos::setnombreCompletoAlumno(string nombreCompletoAlumno)
{
    this -> nombreCompletoAlumno = nombreCompletoAlumno;
}
void Alumnos::setnombreAlumno(string nombreAlumno)
{
    this -> nombreAlumno = nombreAlumno;
}
void Alumnos::setapellidoAlumno(string apellidoAlumno)
{
    this -> apellidoAlumno = apellidoAlumno;
}
void Alumnos::setsexoAlumno(string sexoAlumno)
{
    this -> sexoAlumno = sexoAlumno;
}
void Alumnos::setdiaNacimiento(int diaNacimiento)
{
    this -> diaNacimiento = diaNacimiento;
}
void Alumnos::setmesNacimiento(int mesNacimiento)
{
    this -> mesNacimiento = mesNacimiento;
}
void Alumnos::setanioNacimiento(int anioNacimiento)
{
    this -> anioNacimiento = anioNacimiento;
}
void Alumnos::setnumeroDpi(string numeroDpi)
{
    this -> numeroDpi = numeroDpi;
}
void Alumnos::setcorreoPersonal(string correoPersonal)
{
    this -> correoPersonal = correoPersonal;
}
void Alumnos::setfechaNacimientoAlumno(string fechaNacimientoAlumno)
{
    this -> fechaNacimientoAlumno = fechaNacimientoAlumno;
}
void Alumnos::setcarnetPersonal(string carnetPersonal)
{
    this -> carnetPersonal = carnetPersonal;
}
void Alumnos::setcarreraAsignada(string carreraAsignada)
{
    this -> carreraAsignada = carreraAsignada;
}
