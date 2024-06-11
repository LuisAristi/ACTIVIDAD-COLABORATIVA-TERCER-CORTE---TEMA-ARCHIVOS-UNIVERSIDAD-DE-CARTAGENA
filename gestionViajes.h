#include "includes.h"

int registrarViaje();
void imprimirRecorridoPorCliente();
void imprimirRecorridoFolleto();

/*
La opción 1 plantea todo lo que se debe gestionar viaje 
Rutas turísticas definir la ruta de los diferentes recorridos lugar origen y destino, horario, etc 

Viaje: registro del viaje de cliente con los datos que se indican 

Imprimir recorrido de viaje:  si es por cliente de acuerdo al recorrido o ruta seleccionado mostrar para ese cliente la información indicada en el enunciado 

Folleto: mostrar en pantalla los servicios (recorridos)  ofertados diarios, algo así como cuando le entregan un folleto turístico impreso
*/

/*
1.
Gestión Viaje
1.1 Registrar rutas turísticas (cada uno de los servicios diarios realiza el recorrido de una ruta
con el mismo horario todos los días en que está programado. Recuerde, algunos sólo
funcionan en días festivos y que las rutas con mayor demanda tienen varios servicios diarios)
1.2 Registrar Viaje (Debe imprimir tiquete de viaje donde figuran el código del tiquete, ID del
cliente, nombre, el nombre de la ruta, la fecha y hora de salida, el valor (fijo para cada ruta),
y la hora de llegada prevista.)e
1.3 Imprimir Recorrido del viaje
Por Cliente (mostrar por orden cronológico, los lugares más relevantes del
recorrido. La descripción consiste en el nombre del lugar, la hora prevista de llegada (el
tiempo entre dos lugares concretos es fijo para cada ruta) y además, en algunos casos, la
actividad a realizar (comida, visita, etc.) y el tiempo de parada previsto.)
1.3.1.
Folleto (lista de servicios diarios ofertados (hora y ruta), junto con la descripción
de los días en que están programados.)
*/

/* CHAT GPT BAJO Y DIJO
Gestión de Viajes
1. Registrar Rutas Turísticas
Cada servicio diario realiza el recorrido de una ruta con el mismo horario todos los días en que está programado.
Recuerde:
Algunos servicios sólo funcionan en días festivos.
Las rutas con mayor demanda tienen varios servicios diarios.
2. Registrar Viaje
Debe imprimir un tiquete de viaje que incluya:
Código del tiquete
ID del cliente
Nombre del cliente
Nombre de la ruta
Fecha y hora de salida
Valor (fijo para cada ruta)
Hora de llegada prevista
3. Imprimir Recorrido del Viaje
3.1 Por Cliente
Mostrar en orden cronológico los lugares más relevantes del recorrido.
La descripción debe incluir:
Nombre del lugar
Hora prevista de llegada (el tiempo entre dos lugares es fijo para cada ruta)
En algunos casos, la actividad a realizar (comida, visita, etc.) y el tiempo de parada previsto.
3.2 Folleto
Lista de servicios diarios ofrecidos (hora y ruta), junto con la descripción de los días en que están programados.
*/

//menu de opciones, registrar ruta o registrar servicio

void mostrarMenuRegistro() {
    int opcion;
    
    do {
        std::cout << "Menu de Opciones\n";
        std::cout << "1. Registrar Ruta\n";
        std::cout << "2. Registrar Servicio\n";
        std::cout << "3. Salir" << std::endl;
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;
        
        switch(opcion) {
            case 1:
                registrarRutasTuristicas();
                break;
            case 2:
                registrarServicio();
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
void registrarRutasTuristicas(){
    // Implementación de la función para registrar una ruta
    std::cout << "Registrando Ruta...\n";
    // Aquí va el código para registrar una ruta
    // una funcion que haga validaciones tipos de datos?
    // por ejemplo de tiempo y de numero -> las principales donde hay
    // error del usuario
    // me gustaria que las rutas turisticas tengan nombres y codigos diferentes
    std::cout<<"ingrese nombre de la ruta\n";
    std::cout<<"ingrese codigo de la ruta\n";
    std::cout<<"ingrese lugar de origen de ruta\n";
    std::cout<<"ingrese lugar de destino de ruta\n";
    std::cout<<"ingrese costo de la ruta\n";

    std::cout<<"desea ingresar lugares relevantes\n";

    //sera que debo permitir modificacion?
    std::cout<<"ingrese nombre del lugar\n";
    std::cout<<"ingrese hora prevista de llegada \n";
    std::cout<<"ingrese hora prevista de parada\n";
    std::cout<<"ingrese actividad a realizar\n";

    std::cout<<"quiere ingresar mas lugares?\n"; //se repite; i++

}

void registrarServicio(){
    // Implementación de la función para registrar un servicio
    std::cout << "Registrando Servicio...\n";
    // Aquí va el código para registrar un servicio
}

