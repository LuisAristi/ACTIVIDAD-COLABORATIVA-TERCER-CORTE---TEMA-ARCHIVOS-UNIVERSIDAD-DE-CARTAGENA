#include "main.h"

int main(){
    setlocale(LC_ALL, "spanish");
    int opcion;
    // inicializando de los structs gestion de viajes:
    struct ruta Rutas[30]; //habra que implementar un validador que 
    struct servicios Servicio[90];  //no permita ingresar mas de [x] -> hecho
    struct cliente Cliente[1000]; //muchos clientes, pobre memoria ram

    //inicializacion de los structs del punto 2 TRABAJEN PA HOY
    //inicializacion de los structs del punto 3 TRABAJEN PA HOY
    //inicializacion de los structs del punto 4 TRABAJEN PA HOY
    //inicializacion de los structs del punto 5 TRABAJEN PA HOY
    do {
        mostrarMenuPrincipal();
        std::cout << "Seleccione una opción: ";
        opcion = ingresarNumero(opcion);
        switch (opcion) {
            case 1:
                std::cout<<"1";
                mostrarMenuRegistro(Rutas);
                break;
            case 2:
                //std::cout<<"2";
                std::cout<<Rutas[0].DecripcionLugares[0].previstoDeLlegada.hora<<"\n";
                std::cout<<Rutas[0].DecripcionLugares[0].previstoDeLlegada.minuto<<"\n";
                //registrarViaje();
                break;
            case 3:
                std::cout<<"3";
                //imprimirRecorridoPorCliente();
                break;
            case 4:
                std::cout<<"4";
                //imprimirRecorridoFolleto();
                break;
            case 5:
                std::cout<<"5";
                //registrarVehiculo();
                break;
            case 6:
                std::cout<<"6";
                //registrarConductor();
                break;
            case 7:
                std::cout<<"7";
                //asignarConductores();
                break;
            case 8:
                std::cout<<"8";
                //registrarRevisionVehiculo();
                break;
            case 9:
                std::cout<<"9";
                //consultarRutasPorFecha();
                break;
            case 10:
                std::cout<<"10";
                //consultarRutasPorConductor();
                break;
            case 11:
                std::cout<<"11";
                //consultarRutasPorVehiculo();
                break;
            case 12:
                std::cout<<"12";
                //promedioViajerosPorRuta();
                break;
            case 13:
                std::cout<<"13";
                //consultaPorVehiculo();
                break;
            case 14:
                std::cout<<"14";
                //listadoKmPorVehiculo();
                break;
            case 15:
                std::cout<<"15";
                //listadoKmPorConductor();
                break;
            case 16:
                std::cout<<"16";
                //listadoMejoresClientes();
                break;
            case 17:
                std::cout<<"17";
                //ingresarClienteParaSorteo();
                break;
            case 18:
                std::cout<<"18";
                //generarSorteo();
                break;
            case 19:
                std::cout << "Saliendo del sistema...\n";
                break;
            default:
                std::cout << "Opción inválida. Intente de nuevo.\n";
                break;
    
        }
    } while (opcion != 19);

    return 0;
}
