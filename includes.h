#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <locale.h>

//declarar strutcs que se usaran en todo el proyecto aqui

//struct de rutas
struct tiempo{
    int hora;
    int minuto;
};

struct semana{
    bool lunes;
    bool martes;
    bool miercoles;
    bool jueves; 
    bool viernes;
    bool sabado;
    bool domingo;
};

struct servicios{
    semana dias;
    tiempo salida;
    tiempo llegada;
    char lugarDeOrigen[50];
    char lugarDestino[50];


};