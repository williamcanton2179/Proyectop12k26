#include "Respaldo.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>

// Nombre fijo del archivo final de bitácora
const std::string NOMBRE_BITACORA = "Respaldo.txt";

// Obtiene la fecha y hora actual (Formato: AAAA-MM-DD HH:MM:SS)
std::string obtenerFechaHora() {
    std::time_t t = std::time(nullptr);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

// Agrega un registro al final de Respaldo.txt
void registrarEnBitacora(const RegistroBitacora& registro) {
    std::ofstream archivo(NOMBRE_BITACORA, std::ios::app); // ios::app evita borrar lo anterior

    if (archivo.is_open()) {
        archivo << "[" << obtenerFechaHora() << "] "
                << "Carnet: " << registro.carnet << " | "
                << "Curso: " << registro.curso << " | "
                << "Acción: " << registro.accion << "\n";
        archivo.close();
    } else {
        std::cerr << "Error al abrir: " << NOMBRE_BITACORA << std::endl;
    }
}

// Abre, lee y procesa el archivo de un compañero (separado por comas)
bool procesarArchivoCompanero(const std::string& archivoOrigen) {
    std::ifstream archivoIn(archivoOrigen);

    if (!archivoIn.is_open()) {
        std::cerr << "No se encontró el archivo: " << archivoOrigen << std::endl;
        return false;
    }

    std::string linea;
    while (std::getline(archivoIn, linea)) {
        if (linea.empty()) continue; // Ignora líneas vacías

        std::stringstream ss(linea);
        RegistroBitacora reg;

        // Separa los datos usando las comas
        std::getline(ss, reg.carnet, ',');
        std::getline(ss, reg.curso, ',');
        std::getline(ss, reg.accion, ',');

        // Si tiene datos mínimos, lo guarda en el respaldo
        if (!reg.carnet.empty() && !reg.curso.empty()) {
            registrarEnBitacora(reg);
        }
    }

    archivoIn.close();
    return true;
}
