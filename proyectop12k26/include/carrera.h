#ifndef CARRERA_H                 //Creado por David Alegria
#define CARRERA_H
#include <string>
#include <vector>

class Carrera
{
    public:
        //Constructor
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


    protected:

    private:
        std::string codigoCarrera;
        std::string nombreCarrera;
        bool estadoCarrera;
};

#endif // CARRERA_H
