#include "Horarios.h"
//antony marcelo yllescas fiqueroa 9959-25-6813...
Horarios::Horarios()
{
    this->dia = "";
    this->nombreCurso = "";
    this->horaInicio = "";
    this->horaFin = "";
}

Horarios::Horarios(string dia,string nombreCurso,string horaInicio,string horaFin)
{
    this->dia = dia;
    this->nombreCurso = nombreCurso;
    this->horaInicio = horaInicio;
    this->horaFin = horaFin;
}

vector<Horarios> Horarios::generar(vector<Cursos> cursos,bool pagoValidado,bool finDeSemana)
{
    vector<Horarios> lista;

    if(!pagoValidado)
    {
        cout<<"__________________________________"<<endl;
        cout<<" CONSTANCIA NO VALIDADA "<<endl;
        cout<<"__________________________________"<<endl;

        return lista;
    }

    vector<string> dias;

    if(finDeSemana)
    {
        dias = {"Sabado","Domingo"};
    }
    else
    {
        dias = {"Lunes","Martes","Miercoles","Jueves","Viernes"};
    }

    int indiceCurso = 0;

    for(int d=0; d<dias.size(); d++)
    {
        int cantidadClases;

        if(finDeSemana)
        {
            cantidadClases = 3;
        }
        else
        {
            if(dias[d]=="Lunes" || dias[d]=="Miercoles")
            {
                cantidadClases = 3;
            }
            else
            {
                cantidadClases = 2;
            }
        }

        int hora = 7;

        for(int c=0; c<cantidadClases; c++)
        {
            if(indiceCurso>=cursos.size())
            {
                break;
            }

            int inicio = hora;

            int fin = inicio + 2;

            string hInicio = (inicio<10?"0":"") + to_string(inicio) + ":00";

            string hFin = (fin<10?"0":"") + to_string(fin) + ":00";

            lista.push_back(Horarios(
                dias[d],
                cursos[indiceCurso].getnombreCurso(),
                hInicio,
                hFin
            ));

            indiceCurso++;

            hora = fin + 1;
        }
    }

    cout<<"Horario generado correctamente."<<endl;

    return lista;
}

void Horarios::mostrar(vector<Horarios> lista)
{
    cout<<"______________________________________"<<endl;
    cout<<"       HORARIO DEL ESTUDIANTE         "<<endl;
    cout<<"______________________________________"<<endl;

    for(size_t i=0; i<lista.size(); i++)
    {
        cout<<i+1
            <<". "
            <<lista[i].dia
            <<" | "
            <<lista[i].nombreCurso
            <<" | "
            <<lista[i].horaInicio
            <<" - "
            <<lista[i].horaFin
            <<endl;
    }
}

void Horarios::modificar(vector<Horarios>& lista)
{
    if(lista.empty())
    {
        cout<<"No hay horarios."<<endl;

        return;
    }

    mostrar(lista);

    int opcion;

    cout<<"Seleccione clase a modificar: ";

    cin>>opcion;

    if(opcion<1 || opcion>lista.size())
    {
        cout<<"Opcion invalida."<<endl;

        return;
    }

    cout<<"1. Cambiar hora"<<endl;
    cout<<"2. Cambiar dia"<<endl;

    int tipo;

    cin>>tipo;

    if(tipo==1)
    {
        cout<<"Nueva hora inicio: ";

        cin>>lista[opcion-1].horaInicio;

        cout<<"Nueva hora fin: ";

        cin>>lista[opcion-1].horaFin;
    }
    else if(tipo==2)
    {
        cout<<"Nuevo dia: ";

        cin>>lista[opcion-1].dia;
    }
    else
    {
        cout<<"Opcion invalida."<<endl;

        return;
    }

    cout<<"Horario modificado correctamente."<<endl;
}

void Horarios::guardarEnArchivo(vector<Horarios> lista)
{
    ofstream archivo("HorarioSemanal.txt");

    if(!archivo)
    {
        cout<<"Error al crear archivo."<<endl;

        return;
    }

    archivo<<"HORARIO DEL ESTUDIANTE"<<endl;

    for(size_t i=0; i<lista.size(); i++)
    {
        archivo
            <<lista[i].dia
            <<" | "
            <<lista[i].nombreCurso
            <<" | "
            <<lista[i].horaInicio
            <<" - "
            <<lista[i].horaFin
            <<endl;
    }

    archivo.close();

    cout<<"Horario guardado correctamente."<<endl;
}

void Horarios::menu()
{
    int opcion;

    bool pagoValidado = false;

    bool finDeSemana = false;

    GeneradorConstancias constancia;

    Asignacion asignacion;//arreglado

    Cursos catalogo;

    vector<Horarios> horario;

    while(true)
    {
        cout<<"______________________________________"<<endl;
        cout<<"     SISTEMA UNIVERSITARIO UMG        "<<endl;
        cout<<"______________________________________"<<endl;

        cout<<"1. Validar constancia"<<endl;
        cout<<"2. Elegir jornada"<<endl;
        cout<<"3. Generar horario"<<endl;
        cout<<"4. Mostrar horario"<<endl;
        cout<<"5. Modificar horario"<<endl;
        cout<<"6. Guardar horario"<<endl;
        cout<<"7. Salir"<<endl;

        cout<<"Seleccione opcion: ";

        cin>>opcion;

        switch(opcion)
        {
        case 1:
        {
            int boleta;

            cout<<"Ingrese numero de boleta: ";

            cin>>boleta;

            if(constancia.validarConstancia(boleta))
            {
                pagoValidado = true;

                cout<<"CONSTANCIA VALIDADA."<<endl;
            }
            else
            {
                pagoValidado = false;

                cout<<"CONSTANCIA INVALIDA."<<endl;
            }

            break;
        }

        case 12222:
        {
            asignacion.menuAsignacion();

            break;
        }

        case 2:
        {
            int jornada;

            cout<<"1. Entre semana"<<endl;
            cout<<"2. Fin de semana"<<endl;

            cin>>jornada;

            if(jornada==2)
            {
                finDeSemana = true;
            }
            else
            {
                finDeSemana = false;
            }

            break;
        }

        case 3:
        {
            vector<Cursos> catalogoCompleto =
                catalogo.catalagoCursosIngSistemas();

            vector<Cursos> cursosSeleccionados;

            for(int i=0; i<asignacion.cursosAsignados.size(); i++)
            {
                for(int j=0; j<catalogoCompleto.size(); j++)
                {
                    if(asignacion.cursosAsignados[i] ==
                       catalogoCompleto[j].getnombreCurso())
                    {
                        cursosSeleccionados.push_back(
                            catalogoCompleto[j]
                        );
                    }
                }
            }

            horario = generar(
                cursosSeleccionados,
                pagoValidado,
                finDeSemana
            );

            break;
        }

        case 4:
        {
            mostrar(horario);

            break;
        }

        case 5:
        {
            modificar(horario);

            break;
        }

        case 6:
        {
            guardarEnArchivo(horario);

            break;
        }

        case 7:
        {
            cout<<"Saliendo..."<<endl;

            return;
        }

        default:
        {
            cout<<"Opcion invalida."<<endl;
        }

        }
    }
}
//ff
