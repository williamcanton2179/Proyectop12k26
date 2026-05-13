//Archivo .h de jonathan
#ifndef RESPALDO_H
#define RESPALDO_H

#include <string>

//Estructura para almacenar datos de cada alumno
struct RegistroBitacora {
    std::string carnet;
    std::string curso;
    std::string accion; //Ej: "Pago" etc
};

//Lee el archivo de algun compañero y lo pasa al respaldo general
bool procesarArchivoCompanero(const std::string& archivoOrigen);

//Guarda un registro individual en "Respaldo.txt"
void registrarEnBitacora(const RegistroBitacora& registro);

#endif
