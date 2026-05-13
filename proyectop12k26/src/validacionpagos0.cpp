#include "validacionpagos0.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;


validacionpagos0::validacionpagos0()
{
    //ctor
}

//void  validacionpagos0::asignarCursos(std::string nombrecurso) // double preciocurso)
//{
   // cursos.push_back(nombrecurso);
    //precios.push_back(preciocurso);
//


void validacionpagos0::cargarCursosDesdeArchivo(std::string nombreArchivo){
    ifstream archivo(nombreArchivo);
    string nombreCurso;
     if (archivo.is_open()) {
        cursos.clear();
        while (getline(archivo, nombreCurso)) {
            if (!nombreCurso.empty()) {
                cursos.push_back(nombreCurso);
            }
        }
        archivo.close();
        cout << "Cursos cargados desde " << nombreArchivo << " con exito." << endl;
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

void validacionpagos0::tipodePago(int Tipotarjeta, int numeroTarjeta, std::string nombre, std::string fecha, int codigoSeguridad)
{
    if(Tipotarjeta == 1){
           fstream file;
        cout <<"para pagar con tu tarjeta de debito ingresa lo siguiente:" << endl;
        cout <<"Ingresa el numero de Tarjeta: " << endl;
        cin >> numeroTarjeta;
        cout <<"Ingresa tu nombre COMO ESTA EN LA TARJETA: " << endl;
        cin.ignore();
        getline(cin, nombre);
        cout <<"Fecha de vencimiento: " << endl;
        getline(cin, fecha);
        cout <<"Ingresa el codigo de seguridad: " << endl;
        cin >> codigoSeguridad;
        cout <<"Tu tarjeta ha sido confirmada" << endl;

        file.open("../tarjetadebito.txt", ios::app | ios::out);
        file<< numeroTarjeta << "," << nombre << "\n";
        file.close();
        cout << "Guardando en archivo..." << endl;

    } else {
        fstream file2;
        cout <<"para pagar con tu tarjeta de credito ingresa lo siguiente:" << endl;
        cout <<"Ingresa el numero de Tarjeta: " << endl;
        cin >> numeroTarjeta;
        cout <<"Ingresa tu nombre COMO ESTA EN LA TARJETA: " << endl;
        cin.ignore();
        getline(cin, nombre);
        cout <<"Fecha de vencimiento: " << endl;
        getline(cin, fecha);
        cout <<"Ingresa el codigo de seguridad: " << endl;
        cin >> codigoSeguridad;
        cout <<"Tu tarjeta ha sido confirmada" << endl;

        file2.open("../tarjetacredito.txt", ios::app | ios::out);
        file2<< numeroTarjeta << "," << nombre << "\n";
        file2.close();
        cout << "Guardando en archivo..." << endl;
    }

}

validacionpagos0::~validacionpagos0()
{
    //dtor
}
