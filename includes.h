#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <locale.h>
#include <fstream>
#include <limits>

//prototipos porque el orden importa
long ingresarNumero(long numero);
void clear();


//declarar structs que se usaran en todo el proyecto aqui
//struct de rutas || ESTO VA PA LARGO DE 9 a 
struct tiempo{
    int hora;
    int minuto;
};

struct lugares{
char nombreLugar[100]; 
tiempo previstoDeLlegada; // quiero mostrar toda la informacion sobre los sitios de interes 
tiempo previstoDeParada;
char actividad[100];
};

//probando si esto funciona, creo que sera mejor usar un vector pero quiero ver si es viable asi
struct semana{
    bool lunes;
    bool martes;
    bool miercoles;
    bool jueves; 
    bool viernes;
    bool sabado;
    bool domingo;
};

// 1 ruta varios servicios que funcionan a diferentes horas, seria: tengo una ruta definida, le doy al cliente a elegir a que ruta quiere anadir un servicio
// asi que el struct servicio es diferente a rutas, necesito enlazarlos con codigoDeRuta
struct servicios{
    long codigoDeRuta; // quiero tener el mismo codigo aunque sean diferentes servicios (no tengo claro como organizar esto) 
    long codigoDeServicio; // 1 ruta puede tener varios servicios, por lo que el cambio seria de horarios duh
    semana diasDeServicio;             // el codigo de ruta ayudara a mostrar la informacion de la ruta :) 
    tiempo salida;
    tiempo llegada;
};

struct ruta{
    long codigoDeRuta;
    float costoDeViaje;
    char nombreDeRuta[50];
    char lugarDeOrigen[50];
    char lugarDestino[50];
    lugares DecripcionLugares[70];
};  

struct cliente{
	long idCliente;
    long idDeRuta;
    long codigoDeTiquete;
    long codigoDeServicio;
	char nombreCliente[50];
	long telefonoCliente;
};


// funciones de validaciones
long ingresarNumero(long numero){ //validar que es un numero
    malapraxi:
    std::cout<<"recuerde ingresar un numero\n";
    std::cin>>numero;
    if(std::cin.fail()){
        std::cin.clear();
        clear();
        std::cout<<"recuerde ingresar un numero valido, ingrese cualquier tecla para continuar\n";
        char c = getchar();
        clear();
        goto malapraxi; // oficial en mi defensa, mi vida corria peligro 
    }
    return numero;
}

// funciones utilitarias
void clear(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

