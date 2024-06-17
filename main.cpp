#include "main.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    int opcion;
    // inicializando de los structs gestion de viajes:
    struct ruta Rutas = {0};
    struct cliente Cliente = {0};
    struct servicios Servicio = {0};
    archivo();
    do
    {
        mostrarMenuPrincipal();
        std::cout << "Seleccione una opción: ";
        opcion = ingresarNumero(opcion);
        switch (opcion)
        {
        case 1:
            mostrarMenuRegistro(Rutas, Servicio);
            break;
        case 2:
            registrarViaje();
            break;
        case 3:
            imprimirRecorrido();
            break;
        case 4:
            mostrarServicios();
            break;
        case 5:
            std::cout << "5";
            // registrarVehiculo();
            break;
        case 6:
            std::cout << "6";
            // registrarConductor();
            break;
        case 7:
            std::cout << "7";
            // asignarConductores();
            break;
        case 8:
            std::cout << "8";
            // registrarRevisionVehiculo();
            break;
        case 9:
            std::cout << "9";
            // consultarRutasPorFecha();
            break;
        case 10:
            std::cout << "10";
            // consultarRutasPorConductor();
            break;
        case 11:
            std::cout << "11";
            // consultarRutasPorVehiculo();
            break;
        case 12:
            std::cout << "12";
            // promedioViajerosPorRuta();
            break;
        case 13:
            std::cout << "13";
            // consultaPorVehiculo();
            break;
        case 14:
            std::cout << "14";
            // listadoKmPorVehiculo();
            break;
        case 15:
            std::cout << "15";
            // listadoKmPorConductor();
            break;
        case 16:
            std::cout << "16";
            // listadoMejoresClientes();
            break;
        case 17:
            std::cout << "17";
            // ingresarClienteParaSorteo();
            break;
        case 18:
            std::cout << "18";
            // generarSorteo();
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
