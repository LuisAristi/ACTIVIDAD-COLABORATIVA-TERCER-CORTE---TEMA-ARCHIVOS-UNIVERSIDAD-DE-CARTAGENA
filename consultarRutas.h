#include "gestionAutomoviles.h"

void menuConsultaHora();
void consultarRutasPorHoraSalida();
void consultarRutasPorConductor();
void consultarRutasPorVehiculo();
void promedioViajerosPorRuta();

/*3.
Consultar rutas
3.1 Según fecha indicada (Indicar todas los viajes asignados a una hora o rango
de hora específica)
3.2 Según Conductor (Mostrar todos los viajes asignados a un
conductor, ruta, el día y hora)
3.3 Según Vehículo (Mostrar todos los viajes
asignados a un autobús, conductor, ruta, el día y hora)
3.4 Promedio de Viajeros
por ruta (mostrar el promedio de clientes que solicitaron una ruta específica)
*/

void menuConsultaHora()
{
    int opcion;
    std::cout << "1. Consultar por hora de salida\n";
    std::cout << "2. Consultar por hora de llegada\n";
    std::cout << "3. Consultar un rango de hora\n";
    opcion = ingresarNumero(opcion);
    do{
        switch (opcion)
        {
        case 1:
            consultarRutasPorHoraSalida();
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            std::cout << "ingrese una opcion valida\n";
        }
    }while(opcion != 3);
}

void consultarRutasPorHoraSalida()
{
    int contador;
    struct servicios Servicio[90];
    struct ruta Ruta;
    struct Tiempo tiempo;

    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    contador = 0;
    while (servicio.read(reinterpret_cast<char *>(&Servicio[contador]),
                         sizeof(servicios)))
    {
        contador++;
        if (contador >= 90)
        {
            std::cout << "Se ha alcanzado el número máximo de servicios\n";
            break;
        }
    }
    servicio.close();

    // ahora que tenemos el array de servicios, podemos hacer lo que queramos
    std::cout << "ingrese las horas de salida a buscar\n";
    ingresarTiempo(tiempo);
    for (int i = 0; i < contador; i++)
    {
        if (tiempo.hora == Servicio[i].salida.hora && tiempo.minuto == Servicio[i].llegada.minuto)
        {
            compararRutaCodigo(Ruta, Servicio[i].codigoDeRuta);
            std::cout<<"ruta "<<Ruta.nombreDeRuta<<"\n";
            std::cout << Servicio[i].codigoDeRuta << "\n";
            std::cout<<"hora de salida: ";
            mostrarTiempo(Servicio[i].salida);
            std::cout<<"hora de llegada: ";
            mostrarTiempo(Servicio[i].llegada);
        }
    }
}

void consultarRutasPorHoraLlegada()
{
    int contador;
    struct servicios Servicio[90];
    struct ruta Ruta;
    struct Tiempo tiempo;

    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    contador = 0;
    while (servicio.read(reinterpret_cast<char *>(&Servicio[contador]),
                         sizeof(servicios)))
    {
        contador++;
        if (contador >= 90)
        {
            std::cout << "Se ha alcanzado el número máximo de servicios\n";
            break;
        }
    }
    servicio.close();

    // ahora que tenemos el array de servicios, podemos hacer lo que queramos
    std::cout << "ingrese las horas de salida a buscar\n";
    ingresarTiempo(tiempo);
    for (int i = 0; i < contador; i++)
    {
        if (tiempo.hora == Servicio[i].llegada.hora && tiempo.minuto == Servicio[i].llegada.minuto)
        {
            compararRutaCodigo(Ruta, Servicio[i].codigoDeRuta);
            std::cout<<"ruta "<<Ruta.nombreDeRuta<<"\n";
            std::cout << Servicio[i].codigoDeRuta << "\n";
            std::cout<<"hora de salida: ";
            mostrarTiempo(Servicio[i].salida);
            std::cout<<"hora de llegada: ";
            mostrarTiempo(Servicio[i].llegada);
        }
    }
}

void consultarRutasPorRango()
{
    int contador;
    struct servicios Servicio[90];
    struct ruta Ruta;
    struct Tiempo tiempo1;
    struct Tiempo tiempo2;
    struct Tiempo aux;

    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    contador = 0;
    while (servicio.read(reinterpret_cast<char *>(&Servicio[contador]),
                         sizeof(servicios)))
    {
        contador++;
        if (contador >= 90)
        {
            std::cout << "Se ha alcanzado el número máximo de servicios\n";
            break;
        }
    }
    servicio.close();

    // ahora que tenemos el array de servicios, podemos hacer lo que queramos
    std::cout << "ingrese la hora a buscar\n";
    ingresarTiempo(tiempo1);
    std::cout<<"ingrese el rango de tiempo\n";
    ingresarTiempo(tiempo2);

    if(tiempo2.hora > tiempo1.hora){
        aux = tiempo2;
        tiempo2 = tiempo1;
        tiempo1 = aux;
    }

    for (int i = 0; i < contador; i++)
    {
        if ((tiempo1.hora >= Servicio[i].salida.hora && tiempo1.minuto >= Servicio[i].llegada.minuto) 
                || tiempo2.hora <= Servicio[i].salida.hora && tiempo2.minuto >= Servicio[i].llegada.minuto)
        {
            compararRutaCodigo(Ruta, Servicio[i].codigoDeRuta);
            std::cout<<"ruta "<<Ruta.nombreDeRuta<<"\n";
            std::cout << Servicio[i].codigoDeRuta << "\n";
            std::cout<<"hora de salida: ";
            mostrarTiempo(Servicio[i].salida);
            std::cout<<"hora de llegada: ";
            mostrarTiempo(Servicio[i].llegada);
        }
    }
}


void consultarRutasPorConductor()
{
    struct AsignacionDeConductores conductorAsignado;
    struct Conductor conductor;
    struct servicios Servicio;
    struct ruta Ruta;
    long ID;
    std::cout << "Ingrese el ID del conductor\n";
    ID = ingresarNumero(ID);

    // buscar conductor en el archivo -----es asignacion quiero saber la ruta a la
    // que estan asignados
    getAsignacionConductores(conductorAsignado, ID);

    //debo buscar en el archivo servicio
    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    while (servicio.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios)))
    {
        if (conductorAsignado.codigoDeServicio == Servicio.codigoDeServicio)
        {
            compararRutaCodigo(Ruta, Servicio.codigoDeRuta);
            
            std::cout<<"ruta: "<<Ruta.nombreDeRuta<<"\n";
            std::cout<<"lugar de origen: "<< Ruta.lugarDeOrigen<<"\n";
            std::cout<<"lugar de destino"<<Ruta.lugarDestino<<"\n";

            //dias asignados
            std::cout<<"los dias asignados al conductor son\n";
            for(int i = 0; i<7; i++){
                if(Servicio.diasDeServicio.dias[i]){ dias(i);}
                std::cout<<",";
            }
            
            std::cout<<"\nhora de salida: ";
            mostrarTiempo(Servicio.salida);

            std::cout<<"\nhora de llegada: ";
            mostrarTiempo(Servicio.llegada);
        }
    }
    servicio.close();
}