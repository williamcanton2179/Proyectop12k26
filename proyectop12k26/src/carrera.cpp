#include "Carrera.h"
#include <iostream>     //Creado por David Alegria
#include <vector>
using namespace std;

 Carrera::Carrera()
{
    //ctor
}

Carrera::Carrera(string codigoCarrera, string nombreCarrera, bool estadoCarrera)
{
    this -> codigoCarrera = codigoCarrera;
    this -> nombreCarrera = nombreCarrera;
    this -> estadoCarrera = estadoCarrera;

}


vector<Carrera> Carrera::datosCarreras()
{
    vector<Carrera> infoCarreras;
    infoCarreras.push_back(Carrera("9959", "Ingeniera en Sistemas", true));
    infoCarreras.push_back(Carrera("9975", "Ingeniera Industrial", true));
    infoCarreras.push_back(Carrera("9973", "Ingeniera Civil", true));
    return infoCarreras;
}

string Carrera::getnombreCarrera()
{
    return this -> nombreCarrera;
}
string Carrera::getcodigoCarrera()
{
    return this -> codigoCarrera;
}
bool Carrera::getestadoCarrera()
{
    return this -> estadoCarrera;
}
void Carrera::setnombreCarrera(string nombreCarrera)
{
    this -> nombreCarrera = nombreCarrera;
}
void Carrera::setcodigoCarrera(string codigoCarrera)
{
    this -> codigoCarrera = codigoCarrera;
}
void Carrera::setestadoCcarrera(bool estadoCarrera)
{
    this -> estadoCarrera = estadoCarrera;
}
