// Antony Marcelo Yllescas Figueroa
// 9959-25-6813

#include "Horarios.h"

// Constructor vacío
Horarios::Horarios()
{
    this->dia = "";
    this->nombreCurso = "";
    this->horaInicio = "";
    this->horaFin = "";
}

// Constructor con parámetros
Horarios::Horarios(string dia,
                   string nombreCurso,
                   string horaInicio,
                   string horaFin)
{
    this->dia = dia;
    this->nombreCurso = nombreCurso;
    this->horaInicio = horaInicio;
    this->horaFin = horaFin;
}

// GENERAR HORARIO
vector<Horarios> Horarios::generar(
    vector<Cursos> cursos,
    bool pagoValidado
)
{
    vector<Horarios> lista;

    // VALIDAR PAGO
    if(!pagoValidado)
    {
        cout << "__________________________________" << endl;
        cout << " ERROR: CONSTANCIA NO VALIDADA " << endl;
        cout << "__________________________________\n" << endl;

        return lista;
    }

    vector<string> dias =
    {
        "Lunes",
        "Martes",
        "Miercoles",
        "Jueves",
        "Viernes"
    };

    int indiceCurso = 0;

    for (int d = 0; d < dias.size(); d++)
    {
        int cantidadClases;

        // Lunes y miércoles
        if (dias[d] == "Lunes" || dias[d] == "Miercoles")
        {
            cantidadClases = 3;
        }

        // Martes y jueves
        else if (dias[d] == "Martes" || dias[d] == "Jueves")
        {
            cantidadClases = 2;
        }

        // Viernes
        else
        {
            cantidadClases = 3;
        }

        int hora = 7;
        int minuto = 0;

        for (int c = 0; c < cantidadClases; c++)
        {
            if (indiceCurso >= cursos.size())
            {
                break;
            }

            // DESCANSO
            if (hora == 10 && minuto == 0)
            {
                minuto += 30;
            }

            int inicioHora = hora;
            int inicioMin = minuto;

            // CLASE DE 1 HORA Y MEDIA
            minuto += 90;

            while (minuto >= 60)
            {
                hora++;
                minuto -= 60;
            }

            int finHora = hora;
            int finMin = minuto;

            // FORMATO HORA INICIO
            string hInicio =
                (inicioHora < 10 ? "0" : "") +
                to_string(inicioHora) + ":" +
                (inicioMin == 0 ? "00" : to_string(inicioMin));

            // FORMATO HORA FINAL
            string hFin =
                (finHora < 10 ? "0" : "") +
                to_string(finHora) + ":" +
                (finMin == 0 ? "00" : to_string(finMin));

            // AGREGAR HORARIO
            lista.push_back(
                Horarios(
                    dias[d],
                    cursos[indiceCurso].getnombreCurso(),
                    hInicio,
                    hFin
                )
            );

            indiceCurso++;
        }
    }

    cout << "\nHorario generado correctamente.\n" << endl;

    return lista;
}

// MOSTRAR HORARIO
void Horarios::mostrar(vector<Horarios> lista)
{
    cout << "______________________________________" << endl;
    cout << "       HORARIO DEL ESTUDIANTE         " << endl;
    cout << "______________________________________\n" << endl;

    for (size_t i = 0; i < lista.size(); i++)
    {
        cout << lista[i].dia << " | "
             << lista[i].nombreCurso << " | "
             << lista[i].horaInicio << " - "
             << lista[i].horaFin << endl;
    }
}

// GUARDAR ARCHIVO
void Horarios::guardarEnArchivo(vector<Horarios> lista)
{
    ofstream archivo("HorarioSemanal.txt");

    if (!archivo)
    {
        cout << "\nError al crear archivo.\n" << endl;
        return;
    }

    archivo << "______________________________________" << endl;
    archivo << "       HORARIO DEL ESTUDIANTE         " << endl;
    archivo << "______________________________________\n" << endl;

    for (size_t i = 0; i < lista.size(); i++)
    {
        archivo << lista[i].dia << " | "
                << lista[i].nombreCurso << " | "
                << lista[i].horaInicio << " - "
                << lista[i].horaFin << endl;
    }

    archivo.close();

    cout << "\nHorario guardado correctamente.\n" << endl;
}

// MENU
void Horarios::menu()
{
    int opcion;

    bool pagoValidado = false;

    GeneradorConstancias constancia;

    Cursos catalogo;

    vector<Cursos> cursos;

    vector<Horarios> horario;

    do
    {
        cout << "______________________________________" << endl;
        cout << "     SISTEMA UNIVERSITARIO UMG        " << endl;
        cout << "______________________________________" << endl;

        cout << "1. Validar constancia" << endl;
        cout << "2. Generar horario" << endl;
        cout << "3. Mostrar horario" << endl;
        cout << "4. Guardar horario" << endl;
        cout << "5. Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch(opcion)
        {

        // VALIDAR CONSTANCIA
        case 1:
        {
            int boleta;

            cout << "\nIngrese numero de boleta: ";
            cin >> boleta;

            if(constancia.validarConstancia(boleta))
            {
                pagoValidado = true;

                cout << "\nCONSTANCIA VALIDADA.\n" << endl;
            }
            else
            {
                pagoValidado = false;

                cout << "\nCONSTANCIA INVALIDA.\n" << endl;
            }

            break;
        }

        // GENERAR HORARIO
        case 2:
        {
            cursos = catalogo.catalagoCursosIngSistemas();

            horario = generar(
                cursos,
                pagoValidado
            );

            break;
        }

        // MOSTRAR
        case 3:
        {
            mostrar(horario);

            break;
        }

        // GUARDAR
        case 4:
        {
            guardarEnArchivo(horario);

            break;
        }
        // SALIR
        case 5:
        {
            cout << "\nSaliendo...\n" << endl;
            break;
        }
        default:
        {
            cout << "\nOpcion invalida.\n" << endl;
        }
        }
    }
    while(opcion != 5);
}
