#include "includes.h"

void registrarServicio(struct servicios Servicios[], struct ruta Ruta[]);
void registrarRutasTuristicas(struct ruta Ruta[]);
void registrarViaje(); // NI IDEA
void imprimirRecorridoPorCliente();
void imprimirRecorridoFolleto();

//menu de opciones, registrar ruta o registrar servicio
void mostrarMenuRegistro(struct ruta Ruta[], struct servicios Servicios[]) {
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
                registrarServicio(Servicios, Ruta);
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
            ingresarNumero(opcion);
            
            if(opcion = 2) break; // no tengo creatividad
            clearScreen();
        }
        //quiere continuar?
        quieres:
        std::cout<<"quiere ingresar mas rutas?\n"; //se repite; i++
        std::cout<<"1. si\n";
        std::cout<<"2. no\n";
        ingresarNumero(opcion);
        if(opcion > 2 || opcion < 1) goto quieres;
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
    estoycansado:
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
                    std::cout<<"desea anadir el dia ";
                    dias(j); std::cout<<" --recuerde ingresar un valor valido :D";
                    std::cout<<"\n1. si\n";
                    std::cout<<"2. no\n";
                    opcionDia = ingresarNumero(opcionDia);
                    if(opcionDia > 2 || opcionDia < 1) goto perdonotravez;
                    (opcionDia == 1) ? Servicios[h].diasDeServicio.dias[j] = true : Servicios[h].diasDeServicio.dias[j] = false; //si opcion == 1 entonces dias[x] true, sino
                }
                std::cout<<"ingrese tiempo de salida\n";
                ingresarTiempo(Servicios[h].salida);

                std::cout<<"ingrese tiempo de llegada\n";
                ingresarTiempo(Servicios[h].llegada);

                bueno:
                std::cout<<"quiere seguir ingresando mas servicios?\n";
                std::cout<<"1. si\n";
                std::cout<<"2. no\n";
                opcionDia = ingresarNumero(opcionDia);
                if(opcionDia > 2 || opcionDia < 1) goto bueno;
                if(opcionDia == 2){ break;}
            }
        }
        else{ std::cout<<"ingrese un codigo de ruta que exista Bv   "; goto estoycansado; }
        
        efectivo:
        std::cout<<"quiere seguir ingresando mas servicios?\n";
        std::cout<<"1. si\n";
        std::cout<<"2. no\n";
        opcionDia = ingresarNumero(opcionDia);
        if(opcionDia > 2 || opcionDia < 1) goto efectivo;
        if(opcionDia == 2) break;
    }
}

//devolvere un char con codigo1 primero y codigo2 despues idCliente-codigoservicio
void generarCodigoTiquete(char codigoTiquete[128], long idCliente, long codigoServicio){ 
    char codigo1[64];
    char codigo2[64];
    snprintf(codigo1, sizeof(codigo1), "%ld", idCliente);
    snprintf(codigo2, sizeof(codigo2), "%ld", codigoServicio);
    // convertir y triunfar
    strcat(codigoTiquete, codigo1);
    strcat(codigoTiquete, "-");
    strcat(codigoTiquete, codigo2);
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


void registrarViaje(struct cliente Cliente[], struct ruta Ruta[], struct servicios Servicio[]) {
    clearScreen();
    static int i;
    int opcion;
    long codigoServicio;
    int valorIndiceServicio;
    int valorRuta;


    for(int i = 0; i < 500; i++){
        std::cout << "Ingrese el ID del cliente: ";
        Cliente[i].idCliente = ingresarNumero(Cliente[i].idCliente);

        std::cout << "Ingrese el nombre del cliente: ";
        clear();
        std::cin.getline(Cliente[i].nombreCliente, 50);

        notengocreatividad:
        std::cout << "Ingrese el codigo del servicio: "; //de esto sacare muchas cosas, costo, nombre ruta, salida, llegada
        codigoServicio = ingresarNumero(codigoServicio);
        for(int i = 0; i<90; i++){
            if (codigoServicio == Servicio[i].codigoDeServicio) valorIndiceServicio = i; break; 
        }

        valorRuta = enlaceServicioRuta(Ruta, Servicio[i].codigoDeRuta); 
        if(valorRuta == -1) goto notengocreatividad; //ahora es bipolar
        
        for(int j=0; j<100; j++){ //esto seria con archivos binarios -> pendiente
            //hay que solucionar el problema de codigoTiquete
            generarCodigoTiquete(Cliente[i].Tiquete[i].codigoDeTiquete, Cliente[i].idCliente, Servicio[valorIndiceServicio].codigoDeServicio); 
        }

        std::cout << "===== Tiquete de Viaje =====" << std::endl;
        //std::cout << "Código del tiquete: " << ticketCode << std::endl;
        std::cout << "Codigo del tiquete: " << Cliente[i].Tiquete[i].codigoDeTiquete << std::endl;
        std::cout << "ID del cliente: " << Cliente[i].idCliente << std::endl;
        std::cout << "Nombre del cliente: " << Cliente[i].nombreCliente << std::endl;
        std::cout << "Nombre de la ruta: " << Ruta[valorRuta].nombreDeRuta << std::endl;
        std::cout << "hora de salida: " << Servicio[valorIndiceServicio].salida.hora <<":"<<Servicio[valorIndiceServicio].salida.minuto;
        std::cout << "\nhora de llegada: " << Servicio[valorIndiceServicio].llegada.hora <<":"<<Servicio[valorIndiceServicio].llegada.minuto;
        std::cout << "\nValor de viaje: " << Ruta[valorRuta].costoDeViaje;
        std::cout << "\n============================" << std::endl;
        
        pregunta:
        std::cout<<"quiere seguir ingresando mas servicios?\n";
        std::cout<<"1. si\n";
        std::cout<<"2. no\n";
        opcion = ingresarNumero(opcion);
        if(opcion > 2 || opcion < 1) goto pregunta;
        if(opcion == 2) break;

    } //quiere seguir ingresando clientes?
}

/*
requiero 
Imprimir Recorrido del viaje
1.3.1
Por Cliente (mostrar por orden cronológico, los lugares más relevantes del
recorrido. La descripción consiste en el nombre del lugar, la hora prevista de llegada (el
tiempo entre dos lugares concretos es fijo para cada ruta) y además, en algunos casos, la
actividad a realizar (comida, visita, etc.) y el tiempo de parada previsto.)
1.3.2
Folleto (lista de servicios diarios ofertados (hora y ruta), junto con la descripción
de los días en que están programados.)
*/

/*
struct cliente{
	long idCliente; 
    char codigoDeTiquete[128]; //char porque nadie podra cambiarlo, solo yo muajajajjajajaja
    long codigoDeServicio[100]; // si tengo 100 codigos de servicios, 100 registros de viaje pal cliente
	char nombreCliente[50];
	long telefonoCliente;
};
*/

void imprimirRecorrido(struct ruta Ruta[], struct servicios Servicio[], struct cliente Cliente[]) {
    long idTemporal;
    int prueba;
    int indiceCliente;
    int rutaInfo;

    //ingrese id cliente
    std::cout<<"ingrese id del cliente";  
    ingresarNumero(idTemporal);
    //buscar cliente
    indiceCliente = enlaceCodigoCliente(Cliente, idTemporal);
    
    //tengo el indice para acceder a la info del cliente, necesito saber que ruta quiere mostrar -> hecho
    //para eso necesito mostrar todos los servicios y de esos servicios mostrar los nombres de rutas -> hecho
    //con sus respectivos indices, de modo que el usuario seleccionara el indice de ruta que quiere mostrar -> prendiente

    std::cout<<"estas son las rutas encontradas\n\n";

    for(int i=0; i<100; i++){
        if(Cliente[indiceCliente].codigoDeServicio[i] != 0){
            prueba = enlaceServicioRuta(Ruta, Cliente[indiceCliente].codigoDeServicio[i]);

            if(prueba>=0 || prueba<100){
                std::cout<<prueba<<". ";
                std::cout<<Ruta[prueba].nombreDeRuta;
            }
        }
        else break; //favor no permitir al usuario ingresar codigo de ruta = 0 -> pendiente
    }
    entradaMala:
    std::cout<<"seleccione que ruta quiere mostrar: ";
    rutaInfo =ingresarNumero(rutaInfo);
    if(rutaInfo < 0 || rutaInfo > prueba){std::cout<<"ingrese un indice correcto\n\n"; goto entradaMala;}

    /*
    struct lugares{
    char nombreLugar[100]; 
    tiempo previstoDeLlegada; // quiero mostrar toda la informacion sobre los sitios de interes 
    tiempo previstoDeParada;
    char actividad[100];
    };
    */

    for(int i=0; i<70; i++){
        if(Ruta[rutaInfo].DecripcionLugares[i].nombreLugar != '\0'){
            std::cout<<"nombre de lugar: ";
            std::cout<<Ruta[rutaInfo].DecripcionLugares[i].nombreLugar;
            std::cout<<"\n\ntiempo previsto de llegada: ";
            std::cout<<Ruta[rutaInfo].DecripcionLugares[i].previstoDeLlegada.hora<<":";
            std::cout<<Ruta[rutaInfo].DecripcionLugares[i].previstoDeLlegada.minuto;
            std::cout<<"\n\ntiempo previsto de parada: ";
            std::cout<<Ruta[rutaInfo].DecripcionLugares[i].previstoDeParada.hora<<":";
            std::cout<<Ruta[rutaInfo].DecripcionLugares[i].previstoDeParada.minuto;
            std::cout<<"\n\nactividad a realizar: \n";
            std::cout<<Ruta[rutaInfo].DecripcionLugares[i].actividad;
        }
        else break; //pues no habra info escrita en lo que sigue del array
    }
}

/*
1.3.2
Folleto (lista de servicios diarios ofertados (hora y ruta), junto con la descripción
de los días en que están programados.)
*/

// Función para imprimir la estructura servicios
void mostrarServicios(struct servicios Servicio[]) {
    for(int i=0; i<90; i++){
        if(Servicio[i].codigoDeRuta != 0){
            std::cout << "Código de Ruta: " << Servicio[i].codigoDeRuta << std::endl;
            std::cout << "Código de Servicio: " << Servicio[i].codigoDeServicio << std::endl;
            std::cout << "Días de Servicio: ";
            for (int j = 0; j < 7; ++j) {
                if (Servicio[i].diasDeServicio.dias[j]) {
                    dias(i);
                    std::cout<<", ";
                }
            }
            std::cout << std::endl;
            std::cout << "Hora de Salida: ";
            mostrarTiempo(Servicio[i].salida);
            std::cout << std::endl;
            std::cout << "Hora de Llegada: ";
            mostrarTiempo(Servicio[i].llegada);
            std::cout <<"\n\n\n\n";
        }
        else break; //todo lo que queda esta vacio
    }
}
