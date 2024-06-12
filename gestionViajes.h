#include "includes.h"

void registrarServicio(struct servicios Servicios[]);
void registrarRutasTuristicas(struct ruta Ruta[]);
void registrarViaje(); // NI IDEA
void imprimirRecorridoPorCliente();
void imprimirRecorridoFolleto();

//menu de opciones, registrar ruta o registrar servicio
void mostrarMenuRegistro(struct ruta Ruta[]) {
    int opcion;
    do {
        std::cout << "Menu de Opciones\n";
        std::cout << "1. Registrar Ruta\n";
        std::cout << "2. Registrar Servicio\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1:
                registrarRutasTuristicas(Ruta);
                break;
            case 2:
                //registrarServicio();
                break;
            case 3:
                std::cout << "Saliendo del programa.\n";
                break;
            default:
                std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while(opcion != 3);
}

//llamar a 01-800-915-5704
void registrarRutasTuristicas(struct ruta Ruta[]){
    // Implementación de la función para registrar una ruta
    int opcion;
    std::cout << "Registrando Ruta...\n";
    // Aquí va el código para registrar una ruta                            | quiero validar que no se ingresen codigos de rutas repetidos
    // una funcion que haga validaciones tipos de datos?                    | porque ave maria ome imaginate codigos de ruta repetidos INACEPTABLE
    // por ejemplo de tiempo y de numero -> las principales donde puede     |
    // haber error del usuario                                              |
    // me gustaria que las rutas turisticas tengan nombres y codigos diferentes
    for(int i = 0; i < 20; i++){
        clearScreen(); 
        std::cout<<"ingrese nombre de la ruta\n";
        //aqui es cuando el cin.ignore salva el dia
        clear(); std::cin.getline(Ruta[i].nombreDeRuta, 50, '\n'); //despues de ingresar cadenas PORFAVOR LIMPIAR EL BUFER
        std::cout<<"ingrese codigo de la ruta";
        nimodo:
        Ruta[i].codigoDeRuta = ingresarNumero(Ruta[i].codigoDeRuta);        //decidi que todo en el programa sea long, porque yolo; de
        if(i > 0){ //que una funcion se encargue de comparar codigoDeRuta   //int a long no problem, por eso todas las funciones
            for(int a = 0; a<i; a++){                                                //son long, pensandolo bien, puede ser mala idea, no he dormido na me da igual
                if(Ruta[a].codigoDeRuta == Ruta[i].codigoDeRuta){
                    std::cout<<"por favor no ingrese codigos de ruta repetidos\n";
                    goto nimodo;
                }
            }
        }
        std::cout<<"ingrese lugar de origen de ruta\n";  
        clear(); std::cin.getline(Ruta[i].lugarDeOrigen, 50, '\n'); 
        std::cout<<"ingrese lugar de destino de ruta\n"; 
        clear(); std::cin.getline(Ruta[i].lugarDestino, 50, '\n');
        std::cout<<"ingrese costo de la ruta";
        Ruta[i].costoDeViaje = ingresarNumero(Ruta[i].costoDeViaje);

        for(int j = 0; j<70; j++){
            std::cout<<"<<lugares relevantes>>\n\n";
            //sera que debo permitir modificacion? -> preguntar profesora
            std::cout<<"ingrese nombre del lugar\n";
            clear();
            std::cin.getline(Ruta[i].DecripcionLugares[j].nombreLugar, 100);
            
            std::cout<<"ingrese hora prevista de llegada \n";
            ingresarTiempo(Ruta[i].DecripcionLugares[j].previstoDeLlegada); //structs por referencia :D
            
            std::cout<<"ingrese hora prevista de parada\n";
            ingresarTiempo(Ruta[i].DecripcionLugares[j].previstoDeParada);
           
            std::cout<<"ingrese actividad a realizar\n";
            clear();
            std::cin.getline(Ruta[i].DecripcionLugares[j].actividad, 100);

            //quiere continuar?
            std::cout<<"quiere ingresar mas lugares?\n"; //se repite; i++
            std::cout<<"1. si\n";
            std::cout<<"2. no\n";
            clear();
            std::cin>>opcion;
            if(opcion = 2) break; // no tengo creatividad
            clearScreen();
        }
        //quiere continuar?
        std::cout<<"quiere ingresar mas rutas?\n"; //se repite; i++
        std::cout<<"1. si\n";
        std::cout<<"2. no\n";
        clear();
        std::cin>>opcion;
        if(opcion = 2) break; // no tengo creatividad
    }
}

/* para tener en cuenta
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
*/

void registrarServicio(struct servicios Servicios[], struct ruta Ruta[]){ //hay muchos servicios
    // Implementación de la función para registrar un servicio
    long codigoDeRuta; int opcionDia; int i = 0;
    std::cout << "Registrando Servicio...\n";
    // Aquí va el código para registrar un servicio
    std::cout<<"ingrese codigo de la ruta a la que quiere agregar un nuevo servicio";
    codigoDeRuta = ingresarNumero(codigoDeRuta); //quiero saber si la ruta existe
    
    for(int i = 0; i<30; i++){
        if(codigoDeRuta == Ruta[i].codigoDeRuta){
            for(int h = 0; h < 90; h++){
                Servicios[h].codigoDeRuta = codigoDeRuta; 
                quierodormir:
                std::cout<<"ingrese codigo del servicio";
                Servicios[h].codigoDeServicio = ingresarNumero(Servicios[h].codigoDeServicio);
                if(i > 0){ //que una funcion se encargue de comparar codigoDeRuta   //int a long no problem, por eso todas las funciones
                    for(int a = 0; a<i; a++){                                                //son long, pensandolo bien, puede ser mala idea, no he dormido na me da igual
                        if(Servicios[a].codigoDeServicio == Servicios[i].codigoDeServicio){
                        std::cout<<"por favor no ingrese codigos de deservicio repetidos\n";
                        goto quierodormir;
                        }
                    }
                }
                std::cout<<"ingrese dias de servicio\n";
                for(int j=0; j<7; j++){
                    perdonotravez:
                    std::cout<<"desea anadir el dia";
                    dias(j); std::cout<<"recuerde ingresar un valor valido :D";
                    std::cout<<"1. \nsi\n";
                    std::cout<<"2. no\n";
                    opcionDia = ingresarNumero(opcionDia);
                    if(opcionDia > 2 || opcionDia < 1) goto perdonotravez;
                    (opcionDia == 1) ? Servicios[h].diasDeServicio.dias[j] = true : Servicios[h].diasDeServicio.dias[j] = false; //si opcion == 1 entonces dias[x] true, sino
                }
                std::cout<<"ingrese tiempo de salida\n";
                ingresarTiempo(Servicios[h].salida);

                std::cout<<"ingrese tiempo de llegada\n";
                ingresarTiempo(Servicios[h].llegada);
            }
        }
    }
}

//devolvere un char con codigo1 primero y codigo2 despues
char* generarCodigoTiquete(int codigo1, int codigo){ 
    //ni idea
    
}

/*Registrar Viaje (Debe imprimir tiquete de viaje donde figuran el código del tiquete, ID del
cliente, nombre, el nombre de la ruta, la fecha y hora de salida, el valor (fijo para cada ruta),
y la hora de llegada prevista.) */

/*
2. Registrar Viaje
Debe imprimir un tiquete de viaje que incluya:
Código del tiquete
ID del cliente
Nombre del cliente
Nombre de la ruta
Fecha y hora de salida
Valor (fijo para cada ruta)
Hora de llegada prevista
*/


void registrarViaje(struct cliente Cliente[], struct ruta Ruta) {
    clearScreen();

    std::string clientId;
    char clientName;
    std::string routeName;
    std::string departureTime;
    int routeValue;
    int travelDuration;

    for(int i = 0; i < 1000; i++){
        std::cout << "Ingrese el ID del cliente: ";
        ingresarNumero(Cliente[i].idCliente);
        //ingresar numero

        std::cout << "Ingrese el nombre del cliente: ";
        std::cin.getline(Cliente[i].nombreCliente, 50);

        std::cout << "Ingrese el nombre de la ruta: ";
        std::getline(std::cin, routeName);

        std::cout << "Ingrese la fecha y hora de salida (YYYY-MM-DD HH:MM:SS): ";
        std::getline(std::cin, departureTime);

        std::cout << "Ingrese el valor de la ruta: ";
        std::cin >> routeValue;

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        //std::tm departure = parseDateTime(departureTime);
        //std::string arrivalTime = calculateArrivalTime(departure, travelDuration);

        clearScreen();
    }

    std::cout << "===== Tiquete de Viaje =====" << std::endl;
    //std::cout << "Código del tiquete: " << ticketCode << std::endl;
    std::cout << "ID del cliente: " << clientId << std::endl;
    std::cout << "Nombre del cliente: " << clientName << std::endl;
    std::cout << "Nombre de la ruta: " << routeName << std::endl;
    std::cout << "Fecha y hora de salida: " << departureTime << std::endl;
    std::cout << "Valor: " << routeValue << std::endl;
    std::cout << "============================" << std::endl;
}