#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <locale.h>
#include <stdio.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

void clearScreen()
{
#ifdef _WIN32
    // Para Windows
    system("cls");
#else
    // Para Linux y otros sistemas UNIX
    system("clear");
#endif
}

// prototipos porque el orden importa
long ingresarNumero(long numero);
void clear();

// declarar structs que se usaran en todo el proyecto aqui
// struct de tiempo que permitira no partirse el cerebro con las horas
struct Tiempo
{
    int hora;
    int minuto;
};

// quiero mostrar toda la informacion sobre los sitios de interes
struct lugares
{
    char nombreLugar[100];
    Tiempo previstoDeLlegada;
    Tiempo previstoDeParada;
    char actividad[200];
};

// probando si esto funciona, creo que sera mejor usar un vector pero quiero ver
// si es viable asi
struct semana
{
    bool dias[7];
};

// una ruta varios servicios que funcionan a diferentes horas, seria: tengo una
// ruta definida, le doy al cliente a elegir a que ruta quiere anadir un
// servicio

// asi que el struct servicio es diferente a rutas, necesito enlazarlos con
// codigoDeRuta quiero tener el mismo codigo aunque sean diferentes servicios
// (no tengo claro como organizar esto) 1 ruta puede tener varios servicios, por
// lo que el cambio seria de horarios duh el codigo de ruta ayudara a mostrar la
// informacion de la ruta :)

struct servicios
{
    long codigoDeRuta;
    long codigoDeServicio;
    semana diasDeServicio;
    Tiempo salida;
    Tiempo llegada;
};

struct ruta
{
    long kilometros;
    long codigoDeRuta;
    long costoDeViaje;
    char nombreDeRuta[50];
    char lugarDeOrigen[50];
    char lugarDestino[50];
    lugares DecripcionLugares[70];
};

struct Sorteo {
    char codigo_tiquete[128];
    long ID;
    char apellidosnombre[50];
    long telefono;
    char email[128];
    Tiempo horas_de_viaje;
    long codigo_ruta;
};

struct viajes
{
    long idCliente;
    char codigoDeTiquete[128];
    long codigoDeServicio;
    long codigoDeRuta;
};

struct cliente
{
    long idCliente;
    long telefonoCliente;
    char nombreCliente[50];
    long horasViaje;
    int totalHoras;
};

struct Vehiculo
{
    char matricula[10];
    char modelo[50];
    char fabricante[50];
    int numero_plazas;
    char caracteristicas[200];
};

struct Conductor
{
    int ID;
    char nombre[50];
    long telefono;
    char direccion[100];
};

struct Reparacion
{
    int codigo;
    int tiempo;
    char comentario[100];
};

struct Revision
{
    char matricula[10];
    char fecha_hora[128];
    char diagnostico[100];
    Reparacion reparaciones[10];
    int num_reparaciones;
};

struct AsignacionDeConductores
{
	char nombrec[50];
    long codigoDeServicio;
    long IDConductor;
    char matricula[10];
};

// funciones de validaciones
// numeros LONG
long ingresarNumero(long numero)
{ // validar que es un numero y manejar errores
malapraxi:
    std::cout << "<<<recuerde ingresar un numero>>>\n";
    std::cin >> numero;
    if (std::cin.fail())
    {
        std::cin.clear();
        clear();
        std::cout << "recuerde ingresar un numero valido, ingrese cualquier tecla "
                     "para continuar\n";
        char c = getchar();
        clear();
        goto malapraxi;
    }
    return numero;
}

// mi objetvo es hacer una funcion que me acepte el struct viajes y pueda poner
// valores de tiempo como? ni idea :D, no puede ser de tipo int, si es void
// funciona con punteros? -> a probar
void ingresarTiempo(struct Tiempo &tiempo)
{
perdon:
    std::cout << "ingrese hora 0 - 23\n";
    tiempo.hora = ingresarNumero(tiempo.hora);
    clear();
    if (tiempo.hora < 0 || tiempo.hora > 23)
        goto perdon; // no quiero reventarme la cabeza con un bucle

perdon2:
    std::cout << "ingrese minuto 0 - 60\n";
    tiempo.minuto = ingresarNumero(tiempo.minuto);
    clear();
    if (tiempo.minuto < 0 || tiempo.minuto > 60)
        goto perdon2;
}

int enlaceServicioRuta(struct ruta Ruta[], long codigoServicio)
{
    for (int i = 0; i < 30; i++)
    {
        if (codigoServicio == Ruta[i].codigoDeRuta)
            return i;
    }
    return -1;
}

int enlaceCodigoCliente(struct cliente Cliente[], long codigoCliente)
{
    for (int i = 0; i < 1000; i++)
    {
        if (Cliente[i].idCliente == codigoCliente)
            return i;
    }
    return -1;
}

bool nombreRutaComparar(char nombreRuta[], long codigoDeRuta)
{
    struct ruta Ruta;
    std::ifstream ruta("datosruta.bin", std::ios::in | std::ios::binary);
    ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));

    while (!ruta.eof())
    {
        if (strcasecmp(nombreRuta, Ruta.nombreDeRuta) == 0 ||
            codigoDeRuta == Ruta.codigoDeRuta)
        {
            ruta.close();
            return true;
        }
        ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
    }
    ruta.close();
    return false;
}

bool compararRutaCodigo(struct ruta &Ruta, long codigoDeRuta)
{
    std::ifstream archivo("datosruta.bin", std::ios::in | std::ios::binary);
    while (!archivo.eof())
    {
        if (codigoDeRuta == Ruta.codigoDeRuta)
        {
            archivo.close();
            return true;
        }
        archivo.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
    }
    archivo.close();
    return false;
}

bool compararServicioCodigo(struct servicios &Servicio, long codigoDeServicio)
{
    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    servicio.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios));

    while (!servicio.eof())
    {
        if (codigoDeServicio == Servicio.codigoDeServicio)
        {
            servicio.close();
            return true;
        }
        servicio.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios));
    }
    servicio.close();
    return false;
}

bool compararClienteCodigo(struct cliente &Cliente, long codigoDeCliente)
{
    std::ifstream datoscliente("datoscliente.bin",
                               std::ios::in | std::ios::binary);
    datoscliente.read(reinterpret_cast<char *>(&Cliente), sizeof(cliente));

    while (!datoscliente.eof())
    {
        if (codigoDeCliente == Cliente.idCliente)
        {
            datoscliente.close();
            return true;
        }
        datoscliente.read(reinterpret_cast<char *>(&Cliente), sizeof(cliente));
    }
    datoscliente.close();
    return false;
}

//conseguir datos de asignacion
void getAsignacionConductores(struct AsignacionDeConductores &conductorAsignado, long ID){
    std::ifstream servicio("asignacion.txt", std::ios::in | std::ios::binary);
    servicio.read(reinterpret_cast<char *>(&conductorAsignado),
                  sizeof(AsignacionDeConductores));
    while (!servicio.eof())
    {
        if (ID == conductorAsignado.IDConductor)
        {
            break;
        }
        else
        {
            servicio.read(reinterpret_cast<char *>(&conductorAsignado),
                          sizeof(AsignacionDeConductores));
        }
    }
    servicio.close();
}


// funciones utilitarias
void clear()
{
    std::cin.ignore(1000);
}

void dias(int indice)
{ // esta funcion mostrara los dias de un array de 0 a 7
    switch (indice)
    {
    case 0:
        std::cout << "lunes";
        break;
    case 1:
        std::cout << "martes";
        break;
    case 2:
        std::cout << "miercoles";
        break;
    case 3:
        std::cout << "jueves";
        break;
    case 4:
        std::cout << "viernes";
        break;
    case 5:
        std::cout << "sabado";
        break;
    case 6:
        std::cout << "domingo";
        break;
    default:
        break;
    }
}

// una ayuda para no estar enloqueciendo
void mostrarTiempo(struct Tiempo &tiempo)
{
    std::cout << tiempo.hora << ":" << (tiempo.minuto < 10 ? "0" : "")
              << tiempo.minuto; // el operador ternario es un amor
}

// una inicializacion particularmente util
void archivo()
{
    std::ofstream datosruta("datosruta.bin", std::ios::app | std::ios::binary);
    if (datosruta.fail())
    {
        std::cout << "\nEl archivo datosruta.bin no se pudo abrir. Cerrando "
                     "programa...\n";
        exit(0);
    }
    datosruta.close();
    std::ofstream datosservicios("datosservicios.bin",
                                 std::ios::app | std::ios::binary);
    if (datosruta.fail())
    {
        std::cout << "\nEl archivo datosservicios.bin no se pudo abrir. Cerrando "
                     "programa...\n";
        exit(0);
    }
    datosservicios.close();
    std::ofstream datoscliente("datoscliente.bin",
                               std::ios::app | std::ios::binary);
    if (datoscliente.fail())
    {
        std::cout << "\nEl archivo datoscliente.bin no se pudo abrir. Cerrando "
                     "programa...\n";
        exit(0);
    }
    datoscliente.close();
    std::ofstream datosviaje("datosviaje.bin", std::ios::app | std::ios::binary);
    if (datosviaje.fail())
    {
        std::cout << "\nEl archivo datosviaje.bin no se pudo abrir. Cerrando "
                     "programa...\n";
        exit(0);
    }
    datosviaje.close();
    std::ofstream datosconductor("conductores.txt",
                                 std::ios::app | std::ios::binary);
    if (datosconductor.fail())
    {
        std::cout << "\nEl archivo conductores.txt no se pudo abrir. Cerrando "
                     "programa...\n";
        exit(0);
    }
    datosconductor.close();

    std::ofstream datosvehiculo("datosvehiculo.bin",
                                std::ios::app | std::ios::binary);
    if (datosvehiculo.fail())
    {
        std::cout << "\nEl archivo datosvehiculo.bin no se pudo abrir. Cerrando "
                     "programa...\n";
        exit(0);
    }
    datosvehiculo.close();
}

// devolvere un char con codigo1 primero y codigo2 despues
// idCliente-codigoservicio
void generarCodigoTiquete(char codigoTiquete[128], long id, long codigo)
{
    char codigo1[64];
    char codigo2[64];
    snprintf(codigo1, sizeof(codigo1), "%ld", id);
    snprintf(codigo2, sizeof(codigo2), "%ld", codigo);
    // convertir y triunfar
    strcat(codigoTiquete, codigo1);
    strcat(codigoTiquete, "-");
    strcat(codigoTiquete, codigo2);
}
