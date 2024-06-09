#include "gestionViajes.h"
#include "gestionAutomoviles.h"
#include "consultarRutas.h"
#include "consultasVehiculos.h"
#include "premiosPromociones.h"

void mostrarMenuPrincipal();

int main(){
    setlocale(LC_ALL, "spanish");
    int opcion;
    char c;

    do {
        mostrarMenuPrincipal();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;
        if (std::cin.fail()){
            std::cin.clear(); //cin lanza codigos de error que no permitiria continuar
            std::cin.ignore(300, '\n'); 
            std::cout << "Opción inválida, ingrese un número\n";
            c = getchar();
            std::cin.ignore(300, '\n'); 
        }
        else{
            switch (opcion) {
                case 1:
                    std::cout<<"1";
                    //registrarRutasTuristicas();
                    break;
                case 2:
                    std::cout<<"2";
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
        }
    } while (opcion != 19);

    return 0;
}

void mostrarMenuPrincipal() {
    std::cout << "\nMenú Principal\n";
    std::cout << "Gestión Viaje\n";
    std::cout << "---- 1. Registrar Rutas Turísticas\n";
    std::cout << "---- 2. Registrar Viaje\n";
    std::cout << "------- 3. Imprimir Recorrido del Viaje (Por Cliente)\n";
    std::cout << "------- 4. Imprimir Recorrido del Viaje (Folleto)\n";
    std::cout << "Gestión De Automóviles\n";
    std::cout << "---- 5. Registrar Vehículo\n";
    std::cout << "---- 6. Registrar Conductor\n";
    std::cout << "---- 7. Asignación de Conductores\n";
    std::cout << "---- 8. Registrar Revisión de Vehículo\n";
    std::cout << "Consultar Rutas\n";
    std::cout << "---- 9.  Según Fecha Indicada\n";
    std::cout << "---- 10. Según Conductor\n";
    std::cout << "---- 11. Según Vehículo\n";
    std::cout << "---- 12. Promedio de Viajeros por Ruta\n";
    std::cout << "Consultas Vehículo\n";
    std::cout << "---- 13. Por Vehículo\n";
    std::cout << "---- 14. Listado de KM por Vehículo\n";
    std::cout << "---- 15. Listado de KM por Conductor\n";
    std::cout << "Premios y Promociones\n";
    std::cout << "---- 16. Listado de Mejores Clientes\n";
    std::cout << "---- 17. Ingresar Cliente para Sorteo\n";
    std::cout << "---- 18. Generar Sorteo\n";
    std::cout << "19. Salir\n";
}