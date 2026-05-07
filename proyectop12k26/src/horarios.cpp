#include "Horarios.h"
//antony marcelo yllescas figueroa
// 9959 25 6813
// Constructor vacío
Horarios::Horarios()
{
    this->nombreCurso = "";
    this->horaInicio = "";
    this->horaFin = "";
}

// Constructor con parámetros
Horarios::Horarios(string nombreCurso, string horaInicio, string horaFin)
{
    this->nombreCurso = nombreCurso;
    this->horaInicio = horaInicio;
    this->horaFin = horaFin;
}

// Genera horarios automáticamente (1 hora por curso)
vector<Horarios> Horarios::generar(vector<Cursos> cursos, string jornada, bool pagoRealizado)
{
    vector<Horarios> lista;

    // Validar si el estudiante ya pagó
    if (!pagoRealizado)
    {
        cout << "\nNo puede generar horario: pago pendiente.\n";
        return lista;
    }

    int horaBase;

    // Definir hora inicial según jornada
    if (jornada == "Matutina")
        horaBase = 7;
    else if (jornada == "Vespertina")
        horaBase = 13;
    else
        horaBase = 18; // Nocturna

    // Asignar una hora por cada curso
    for (int i = 0; i < cursos.size(); i++)
    {
        int inicio = horaBase + i;
        int fin = inicio + 1;

        string hInicio = to_string(inicio) + ":00";
        string hFin = to_string(fin) + ":00";

        // Crear horario para cada curso
        lista.push_back(Horarios(cursos[i].getnombreCurso(), hInicio, hFin));
    }

    return lista;
}

// Muestra los horarios en consola
void Horarios::mostrar(vector<Horarios> lista)
{
    cout << "\n=========== HORARIO ===========" << endl;

    for (int i = 0; i < lista.size(); i++)
    {
        cout << lista[i].nombreCurso << " | "
             << lista[i].horaInicio << " - "
             << lista[i].horaFin << endl;
    }
}
