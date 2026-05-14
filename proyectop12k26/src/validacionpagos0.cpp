#include "validacionpagos0.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
using namespace std;


validacionpagos0::validacionpagos0()
{
    //ctor
}

void validacionpagos0::cargarCursosDesdeArchivo(std::string nombreArchivo){
    ifstream archivo(nombreArchivo);
    string lineacompleta;

     if (archivo.is_open()) {
        cursos.clear();
        precios1.clear();
        while (getline(archivo, lineacompleta)) {
            if (lineacompleta.empty()|| lineacompleta[0] == '='||lineacompleta.find("REGISTRO")!=string::npos) {
                continue;
            }
            stringstream ss(lineacompleta);
            string codigo, nombreCurso, precioTexto;
            if(getline(ss, codigo, '|')&& getline(ss, nombreCurso, '|')&& getline(ss,precioTexto)){

                size_t primero=nombreCurso.find_first_not_of(" ");
                size_t ultimo= nombreCurso.find_last_not_of(" ");
                if (primero != string::npos && ultimo != string::npos) {
                    nombreCurso = nombreCurso.substr(primero, (ultimo - primero + 1));
                }


            size_t posNumero= precioTexto.find_first_of("0123456789");

            if(posNumero != string::npos){
                string numeroLimpio = precioTexto.substr(posNumero);
                double precioDouble = stod(numeroLimpio);

                cursos.push_back(nombreCurso);
                precios1.push_back(precioDouble);
                }
            }
        }
        archivo.close();
        cout << "Cursos y precios cargados de forma exitosa." << endl;
    } else {
        cout << "Error: No se encontro el archivo " << nombreArchivo << endl;
    }

}
 void validacionpagos0::informaciondecursos()
{
     cout<< "--- Lista de cursos y precios---" << endl;
    for(int i = 0; i < cursos.size(); i++){
        cout<< i+1 <<"."<<cursos[i]<< endl; //"  -Precio: Q" << precios[i] << endl;
    }
}

void validacionpagos0::pagoAlumno1(double pago1, double precioscurso)
{
    do{
    if(pago1 > precioscurso){
        cout <<"No puedes pagar mas de: "<< precioscurso << endl;
    }
    else if(pago1 < precioscurso){
        cout <<"El precio a pagar es de: "<< precioscurso << endl;
    }
    if(pago1 != precioscurso){
        cout <<"intenta de nuevo. Ingresa el monto: " << endl;
        cin >> pago1;
    }
    } while (pago1 != precioscurso);
    cout <<"¡Pago validado con exito!¡Exitos en tus estudios!" << endl;
}

void validacionpagos0::tipodePago(int Tipotarjeta, int &numeroTarjeta, std::string &nombre, std::string &fecha, int &codigoSeguridad)
{
            char continuar;
            string mesColegiatura;
            string nombreArchivo;
            double resultado = 1020.00;
            double pagoalumno;

        if(Tipotarjeta==1){
            nombreArchivo = "tarjetadebito.txt";
        } else {
            nombreArchivo = "tarjetacredito.txt";
        }
        do{

        cout<<"\n---Nuevo pago de colegiatura---"<<endl;
        cout<<"Ingrese el Mes que va a pagar: "<<endl;
        cin >>mesColegiatura;

        cout <<"para pagar con tu tarjeta de debito ingresa lo siguiente:" << endl;
        cout <<"Ingresa el numero de Tarjeta: " << endl;
        cin >> numeroTarjeta;
        cout <<"Ingresa tu nombre COMO ESTA EN LA TARJETA: " << endl;
        cin.ignore();
        getline(cin, nombre);

        for(int i = 0; i < nombre.length(); i++) {
            if(nombre[i] == ' ') nombre[i] = '_';}

        cout <<"Fecha de vencimiento: " << endl;
        getline(cin, fecha);
        cout <<"Ingresa el codigo de seguridad: " << endl;
        cin >> codigoSeguridad;
        cout <<"Tu tarjeta ha sido confirmada" << endl;

        cout<<"Total a pagar: Q"<< resultado<<endl;
        cout << "Ingrese el monto: "<< endl;
        cin >> pagoalumno;
        pagoAlumno1(pagoalumno, resultado);

        ofstream file;
        file.open(nombreArchivo, ios::app);
        if(file.is_open()){
        file << left << setw(15) << numeroTarjeta << left << setw(20) << nombre << left << setw(15) << mesColegiatura << "\n";
        file.close();
        cout << "Pago de "<< mesColegiatura<<" guardado correctamente" << endl;

    }
    cout<<"¿Deseas realizar otro pago? (s/n); ";
    cin>>continuar;
    }while (continuar=='s'||continuar=='S');

cout <<"Proceso de pagos finalizado."<<endl;
}


void validacionpagos0::leerInformacion(int tarjetaBuscada, int Tipotarjeta){
    system("cls");
    string nombreArchivo;
    if(Tipotarjeta==1){
            nombreArchivo = "tarjetadebito.txt";
        } else {
            nombreArchivo = "tarjetacredito.txt";
        }

    ifstream archivo(nombreArchivo);
    //char num[16], nombre[21], mes[16];
    string num, nombre, mes;
    int total = 0;

    cout << "\n------------------------- Detalle de Pagos -------------------------\n";
    cout << left << setw(15) << "Tarjeta" << setw(20) << "Nombre" << setw(15) << "Mes" << endl;
    cout << "--------------------------------------------------------------------\n";

    if (!archivo) {
        cout << "\t\t\tNo hay informacion..." << endl;
    } else {
        while (archivo >> num >> nombre >> mes) {
             if (num.empty()) {
                    continue;}
            try {
                if (stoi(num) == tarjetaBuscada) {

                    for(int i = 0; i < nombre.length(); i++) {
                        if(nombre[i] == '_') nombre[i] = ' ';
                    }

                    cout << left << setw(15) << num << setw(20) << nombre << setw(15) << mes << endl;
                    total++;
                }
            } catch (...) {
                continue;
            }
        }
    }
    archivo.close();
    cout << "\n--------------------------------------------------------------------\n";
    system("pause");
}

void validacionpagos0::modificarInformacion(int tarjetaBuscada, int Tipotarjeta){
    system("cls");
    string nombreArchivo;
    if (Tipotarjeta == 1){
        nombreArchivo = "tarjetadebito.txt";
    } else nombreArchivo = "tarjetacredito.txt";

    fstream file, file1;
    string num, nombre, mes;
    int found = 0;

    cout << "\n------------------------- Modificar Titular -------------------------\n";
    file.open(nombreArchivo, ios::in);

    if (!file) {
        cout << "\n\t\t\tNo hay informacion...";
    } else {
        file1.open("temporal0.txt", ios::app | ios::out);

    while (file >> num >> nombre >> mes) {
    if (stoi(num) != tarjetaBuscada) {
                file1 << left << setw(15) << num << left << setw(20) << nombre << left << setw(15) << mes << "\n";
        } else {
            cout << "\n Tarjeta encontrada: " << num;
            cout << "\n Ingrese el nuevo nombre del titular: ";
            cin.ignore();
            getline(cin, nombre);

            file1 << left << setw(15) << num << left << setw(20) << nombre << left << setw(15) << mes << "\n";
            found++;
            }
        }
        file1.close();
        file.close();

        remove(nombreArchivo.c_str());
        rename("temporal0.txt", nombreArchivo.c_str());

        if (found > 0) cout << "\n\t\t\tRegistro actualizado con exito!";
        else cout << "\n\t\t\tNo se encontro el registro...";
    }

}

void validacionpagos0::borrar(int tarjetabuscada, int Tipotarjeta){
    system("cls");
    string nombreArchivo;
    if (Tipotarjeta == 1){
        nombreArchivo = "tarjetadebito.txt";
    } else nombreArchivo = "tarjetacredito.txt";

    fstream file, file2;
    string num,nombre,mes,mesBorrar;
    int found =0;


    cout<<"\n------------------------- Eliminar Registro de Pago -------------------------\n";
    file.open(nombreArchivo, ios::in);

    if(!file){
        cout <<"n\t\t\tNo hay informacion...";
    } else {
        cout<<"\n Ingrese el MES del pago que desea elminar: ";
        cin >> mesBorrar;
    }

    file2.open("temporal0.txt", ios::app|ios::out);

    while(file >>num >> nombre >> mes){
        if(stoi(num)== tarjetabuscada && mes==mesBorrar){
            found++;
            cout<<"\n\t\tRegistro de "<<mes<<" encontrado y eliminado.";

        }else {
            file2<<left<<setw(15)<<num<<left<<setw(20)<<nombre<<left<<setw(15)<< mes<<"\n";
        }
    }
    file2.close();
        file.close();
        remove(nombreArchivo.c_str());
        rename("temporal0.txt", nombreArchivo.c_str());

        if (found == 0) {
            cout << "\n\t\t\tNo se encontro ningun pago de " << mesBorrar << " para esta tarjeta.";
        }
         cout<< "\n-----------------------------------------------------------------------------\n";
    }


void validacionpagos0::menuGestionPagos(int tarjetaBuscada, int Tipotarjeta){
    int opcion;
    do{
        cout << "\n--- Menu Gestion de pagos ---" << endl;
        cout << "1. Ver mi historial de pagos (Leer)" << endl;
        cout << "2. Modificar nombre del titular (Actualizar)" << endl;
        cout << "3. Eliminar un pago (Borrar)" << endl;
        cout << "4. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if(opcion == 1){
            leerInformacion(tarjetaBuscada,Tipotarjeta);
        }
        if(opcion == 2){
            modificarInformacion(tarjetaBuscada,Tipotarjeta);
        }
        if(opcion == 3){
            borrar(tarjetaBuscada,Tipotarjeta);
        }
        if(opcion==4){
            cout<<"Regresar al menu anterior"<<endl;
        }
        else{
            cout << "Opcion no valida. Intente de nuevo." << endl;
            system("pause");
        }

    }while(opcion !=4);
}





validacionpagos0::~validacionpagos0()
{
    //dtor
}
