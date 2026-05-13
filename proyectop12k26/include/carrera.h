#ifndef CARRERA_H
#define CARRERA_H        //Creado por David Alegria 9959-23-11277

#include <iostream>
#include <fstream>
#include <iomanip>
#include <conio.h>
#include <vector>
using namespace std;

class Carrera
{
    private:
        string codigoCarrera;
        string nombreCarrera;
        bool estadoCarrera;

    public:
         Carrera();
        Carrera(std::string codigoCarrera, std::string nombreCarrera, bool estadoCarrea);
        //Get
        std::string getcodigoCarrera();
        std::string getnombreCarrera();
        bool getestadoCarrera();
        //Set
        void setcodigoCarrera(std::string codigoCarera);
        void setnombreCarrera(std::string nombreCarerra);
        void setestadoCcarrera(bool estadoCarrera);
        //Metodos
        std::vector<Carrera> datosCarreras();

        void menu();
        void insertar();
        void desplegar();
        void modificar();
        void buscar();
        void borrar();
};

#endif // CARRERA_H
