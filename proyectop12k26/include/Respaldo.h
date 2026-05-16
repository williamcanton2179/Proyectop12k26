#ifndef RESPALDO_H
#define RESPALDO_H

#include <string>

struct RegistroBitacora {
    std::string carnet;
    std::string curso;
    std::string accion;
};

// Funciones de gestión y procesamiento
void menuRespaldo();
bool respaldarAsignaciones();
bool respaldarCobroTarjeta();
void mostrarRespaldo();
void crearRegistroManual();
void eliminarRegistroPorCarnet();
void registrarEnBitacora(const RegistroBitacora &reg);
std::string obtenerFechaHora();

#endif
