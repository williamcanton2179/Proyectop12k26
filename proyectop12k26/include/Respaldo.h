//9959-25-7858 Jonathan Eladio Chamalé Del cid
#ifndef RESPALDO_H
#define RESPALDO_H

#include <string>

struct RegistroBitacora {
    std::string carnet;
    std::string curso;
    std::string accion;
};

// Funciones de control y procesamiento
void menuRespaldo();
bool respaldarAsignaciones();
bool respaldarCobroTarjeta();
bool respaldarHorarios(); // <-- Nueva firma añadida
void mostrarRespaldo();
void crearRegistroManual();
void eliminarRegistroPorCarnet();
void registrarEnBitacora(const RegistroBitacora &reg);
std::string obtenerFechaHora();

#endif
