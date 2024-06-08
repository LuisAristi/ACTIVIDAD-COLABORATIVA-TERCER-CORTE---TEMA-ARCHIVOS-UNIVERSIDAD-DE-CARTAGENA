#include "gestionViajes.h"
#include "gestionAutomoviles.h"
#include "consultarRutas.h"
#include "consultasVehiculos.h"
#include "premiosPromociones.h"

void mostrarMenuPrincipal();

int main() {
    int opcion;

    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                registrarRutasTuristicas();
                break;
            case 2:
                registrarViaje();
                break;
            case 3:
                imprimirRecorridoPorCliente();
                break;
            case 4:
                imprimirRecorridoFolleto();
                break;
            case 5:
                registrarVehiculo();
                break;
            case 6:
                registrarConductor();
                break;
            case 7:
                asignarConductores();
                break;
            case 8:
                registrarRevisionVehiculo();
                break;
            case 9:
                consultarRutasPorFecha();
                break;
            case 10:
                consultarRutasPorConductor();
                break;
            case 11:
                consultarRutasPorVehiculo();
                break;
            case 12:
                promedioViajerosPorRuta();
                break;
            case 13:
                consultaPorVehiculo();
                break;
            case 14:
                listadoKmPorVehiculo();
                break;
            case 15:
                listadoKmPorConductor();
                break;
            case 16:
                listadoMejoresClientes();
                break;
            case 17:
                ingresarClienteParaSorteo();
                break;
            case 18:
                generarSorteo();
                break;
            case 19:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 19);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\nMenú Principal\n";
    cout << "1. Registrar Rutas Turísticas\n";
    cout << "2. Registrar Viaje\n";
    cout << "3. Imprimir Recorrido del Viaje (Por Cliente)\n";
    cout << "4. Imprimir Recorrido del Viaje (Folleto)\n";
    cout << "5. Registrar Vehículo\n";
    cout << "6. Registrar Conductor\n";
    cout << "7. Asignación de Conductores\n";
    cout << "8. Registrar Revisión de Vehículo\n";
    cout << "9. Consultar Rutas (Según Fecha Indicada)\n";
    cout << "10. Consultar Rutas (Según Conductor)\n";
    cout << "11. Consultar Rutas (Según Vehículo)\n";
    cout << "12. Promedio de Viajeros por Ruta\n";
    cout << "13. Consultas Vehículo (Por Vehículo)\n";
    cout << "14. Consultas Vehículo (Listado de KM por Vehículo)\n";
    cout << "15. Consultas Vehículo (Listado de KM por Conductor)\n";
    cout << "16. Premios y Promociones (Listado de Mejores Clientes)\n";
    cout << "17. Premios y Promociones (Ingresar Cliente para Sorteo)\n";
    cout << "18. Premios y Promociones (Generar Sorteo)\n";
    cout << "19. Salir\n";
}