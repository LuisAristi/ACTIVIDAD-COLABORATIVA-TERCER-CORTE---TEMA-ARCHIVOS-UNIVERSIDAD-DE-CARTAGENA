#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <locale.h>
#include <fstream>
#include <limits>
#include <cstring>

#ifdef _WIN32
    #include <windows.h>
#endif

void clearScreen() {
    #ifdef _WIN32
        // Para Windows
        system("cls");
    #else
        // Para Linux y otros sistemas UNIX
        system("clear");
    #endif
}

//prototipos porque el orden importa
long ingresarNumero(long numero);
void clear();


//declarar structs que se usaran en todo el proyecto aqui
//struct de tiempo que permitira no partirse el cerebro con las horas
struct tiempo{
    int hora;
    int minuto;
};

// quiero mostrar toda la informacion sobre los sitios de interes 
struct lugares{
char nombreLugar[100]; 
tiempo previstoDeLlegada;
tiempo previstoDeParada;
char actividad[100];
};

//probando si esto funciona, creo que sera mejor usar un vector pero quiero ver si es viable asi
struct semana{
    bool dias[7];
};

// 1 ruta varios servicios que funcionan a diferentes horas, seria: tengo una ruta definida, le doy al cliente a elegir a que ruta quiere anadir un servicio

// asi que el struct servicio es diferente a rutas, necesito enlazarlos con codigoDeRuta
// quiero tener el mismo codigo aunque sean diferentes servicios (no tengo claro como organizar esto)
// 1 ruta puede tener varios servicios, por lo que el cambio seria de horarios duh
// el codigo de ruta ayudara a mostrar la informacion de la ruta :)

struct servicios{
    long codigoDeRuta; 
    long codigoDeServicio; 
    semana diasDeServicio;              
    tiempo salida;
    tiempo llegada;
};

struct ruta{
    long codigoDeRuta;
    long costoDeViaje;
    char nombreDeRuta[50];
    char lugarDeOrigen[50];
    char lugarDestino[50];
    lugares DecripcionLugares[70];
};  

struct tiquete{
    char codigoDeTiquete[128];
};

struct cliente{
	long idCliente; 
    tiquete Tiquete[100]; //char porque nadie podra cambiarlo, solo yo muajajajjajajaja
    long codigoDeServicio[100]; // si tengo 100 codigos de servicios, 100 registros de viaje pal cliente
	char nombreCliente[50];
	long telefonoCliente;
};


// funciones de validaciones
// numeros LONG
long ingresarNumero(long numero){ //validar que es un numero y manejar errores
    malapraxi:
    std::cout<<"<<<recuerde ingresar un numero>>>\n";
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

// mi objetvo es hacer una funcion que me acepte el struct viajes y pueda poner valores de tiempo
// como? ni idea :D, no puede ser de tipo int, si es void funciona con punteros? -> a probar
void ingresarTiempo(struct tiempo &Tiempo){ 
    perdon:
    std::cout<<"ingrese hora 0 - 23\n";
    Tiempo.hora = ingresarNumero(Tiempo.hora);
    clear();
    if(Tiempo.hora < 0 || Tiempo.hora > 23) goto perdon; // no quiero reventarme la cabeza con un bucle

    perdon2:
    std::cout << "ingrese minuto 0 - 60\n";
    Tiempo.minuto = ingresarNumero(Tiempo.minuto);
    clear();
    if(Tiempo.minuto < 0 || Tiempo.minuto > 60) goto perdon2;
}

int enlaceServicioRuta(struct ruta Ruta[], long codigoServicio){
    for(int i = 0; i<30; i++){
        if(codigoServicio == Ruta[i].codigoDeRuta) return i;
    }
    return -1;
}

/*
struct cliente{
	long idCliente; 
    char codigoDeTiquete[128]; //char porque nadie podra cambiarlo, solo yo muajajajjajajaja
    long codigoDeServicio[100]; // si tengo 100 codigos de servicios, 100 registros de viaje pal cliente
	char nombreCliente[50];
	long telefonoCliente;
};
*/

int enlaceCodigoCliente(struct cliente Cliente[], long codigoCliente){
    for(int i=0; i<1000; i++){  
        if(Cliente[i].idCliente == codigoCliente) return i;
    }
    return -1;
}

// funciones utilitarias
void clear(){
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void dias(int indice){ //esta funcion mostrara los dias de un array de 0 a 7
    switch (indice)
    {
    case 0:
        std::cout<<"lunes\n";
        break;
    case 1:
        std::cout<<"martes\n";
        break;
    case 2:
        std::cout<<"miercoles\n";
        break;
    case 3:
        std::cout<<"jueves\n";
        break;
    case 4:
        std::cout<<"viernes\n";
        break;
    case 5:
        std::cout<<"sabado\n";
        break;
    case 6:
        std::cout<<"domingo\n";
        break;
    default:
        break;
    }
}

void mostrarTiempo(struct tiempo& Tiempo) {
    std::cout << Tiempo.hora << ":" << (Tiempo.minuto < 10 ? "0" : "") << Tiempo.minuto;
}