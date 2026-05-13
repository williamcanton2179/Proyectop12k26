// clase creada por Freddy Muy el dia lunes 4/05/2026


#ifndef CONFIGURACION_EVALUACION_H
#define CONFIGURACION_EVALUACION_H

#include <string>
#include <vector>
#include "Cursos.h"    //es la llamada del .h de otra clase en este caso cursos
using namespace std;

//clase llamada configuracion evaluacion que nos dara el desgloce de notas como por ejemplo primer parcial etc.
class ConfiguracionEvaluacion {
private:
    string periodo;    // se refiere al semestre
    string codigoCurso;
    string nombreCurso;


    //Constantes para las notas
    static const int MAX_PRIMER_PARCIAL  = 20;
    static const int MAX_SEGUNDO_PARCIAL = 25;
    static const int MAX_ZONA_TAREAS     = 20;
    static const int MAX_EXAMEN_FINAL    = 35;
    static const int MIN_ZONA_FINAL      = 26;
    static const int NOTA_APROBACION     = 61;

public:
    ConfiguracionEvaluacion();

    void seleccionarCurso();   //que curso se quiere usar
    void configurarPeriodo();  //el periodo que se va a usar
    bool almacenarConfiguracion();  //guarda la condiguracion


    //prototipos de los metodos
    string getCodigoCurso()      const;
    string getNombreCurso()      const;
    string getPeriodo()          const;
    int    getMaxPrimerParcial() const;
    int    getMaxSegundoParcial()const;
    int    getMaxZonaTareas()    const;
    int    getMaxExamenFinal()   const;
    int    getMinZonaFinal()     const;
    int    getNotaAprobacion()   const;
};

#endif
