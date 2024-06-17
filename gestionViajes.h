#include "includes.h"

void registrarServicio(struct servicios &Servicio);
void registrarRutasTuristicas(struct ruta &Ruta);

// menu de opciones, registrar ruta o registrar servicio
void mostrarMenuRegistro(struct ruta Ruta, struct servicios Servicios)
{
    int opcion;
    do
    {
        std::cout << "Menu de Opciones\n";
        std::cout << "1. Registrar Ruta\n";
        std::cout << "2. Registrar Servicio\n";
        std::cout << "3. Salir\n";
        std::cout << "Seleccione una opcion: ";
        opcion = ingresarNumero(opcion);

        switch (opcion)
        {
        case 1:
            registrarRutasTuristicas(Ruta);
            break;
        case 2:
            registrarServicio(Servicios);
            break;
        case 3:
            std::cout << "Saliendo del programa.\n";
            break;
        default:
            std::cout << "Opcion no valida. Intente de nuevo.\n";
        }
    } while (opcion != 3);
}

// registro de rutas con binarios :)
void registrarRutasTuristicas(struct ruta &Ruta)
{
    int opcion;
    std::cout << "Registrando Ruta...\n";
    do
    {
        Ruta = {0}; // no quiero mandar basura a mi archivo binario
        clearScreen();
    nimodo:
        std::cout << "ingrese nombre de la ruta\n";
        clear();
        std::cin.getline(Ruta.nombreDeRuta, 50, '\n');
        std::cout << "ingrese codigo de la ruta";
        Ruta.codigoDeRuta = ingresarNumero(Ruta.codigoDeRuta);

        if (nombreRutaComparar(Ruta.nombreDeRuta, Ruta.codigoDeRuta))
        {
            std::cout << "ingrese codigo de ruta o nombre de ruta unicos\n";
            goto nimodo;
        }

        std::cout << "ingrese lugar de origen de ruta\n";
        clear();
        std::cin.getline(Ruta.lugarDeOrigen, 50);
        std::cout << "ingrese lugar de destino de ruta\n";
        std::cin.getline(Ruta.lugarDestino, 50);
        std::cout << "ingrese costo de la ruta";
        Ruta.costoDeViaje = ingresarNumero(Ruta.costoDeViaje);

        for (int j = 0; j < 70; j++)
        {
            std::cout << "<<lugares relevantes>>\n\n";
            std::cout << "ingrese nombre del lugar\n";
            clear();
            std::cin.getline(Ruta.DecripcionLugares[j].nombreLugar, 100);

            std::cout << "ingrese actividad a realizar\n";
            std::cin.getline(Ruta.DecripcionLugares[j].actividad, 200);

            std::cout << "ingrese hora prevista de llegada \n";
            ingresarTiempo(Ruta.DecripcionLugares[j].previstoDeLlegada); // structs por referencia :D

            std::cout << "ingrese hora prevista de parada\n";
            ingresarTiempo(Ruta.DecripcionLugares[j].previstoDeParada);

            // quiere continuar?
            std::cout << "quiere ingresar mas lugares?\n"; // se repite; i++
            std::cout << "1. si\n";
            std::cout << "2. no\n";
            ingresarNumero(opcion);

            if (opcion = 2)
                break; // no tengo creatividad
            clearScreen();
        }
        // escribiendo a archivo
        std::ofstream datosruta("datosruta.bin", std::ios::app | std::ios::binary);
        if (datosruta.fail())
        {
            std::cout << "\nEl archivo datosruta.bin no se pudo abrir. Cerrando programa...\n";
            exit(0);
        }
        datosruta.write(reinterpret_cast<char *>(&Ruta), sizeof(ruta));

    // quiere continuar?
    quieres:
        std::cout << "quiere ingresar mas rutas?\n";
        std::cout << "1. si\n";
        std::cout << "2. no\n";
        ingresarNumero(opcion);
        if (opcion > 2 || opcion < 1)
            goto quieres;
        if (opcion = 2)
            break;
    } while (true);
}

void registrarServicio(struct servicios &Servicio)
{
    struct ruta Ruta;
    long codigoDeRuta;
    int opcionDia;
    int i = 0;
    std::cout << "Registrando Servicio...\n";
// Aquí va el código para registrar un servicio
estoycansado:
    std::cout << "ingrese codigo de la ruta a la que quiere agregar un nuevo servicio";
    codigoDeRuta = ingresarNumero(codigoDeRuta); // quiero saber si la ruta existe

    if (compararRutaCodigo(Ruta, codigoDeRuta))
    {
        for (;;)
        {
            Servicio = {0};
            Servicio.codigoDeRuta = codigoDeRuta;

        quierodormir:
            std::cout << "ingrese codigo del servicio";
            Servicio.codigoDeServicio = ingresarNumero(Servicio.codigoDeServicio);

            if (compararServicioCodigo(Servicio.codigoDeServicio))
            {
                std::cout << "por favor no ingrese codigos de deservicio repetidos\n";
                goto quierodormir;
            }

            std::cout << "ingrese dias de servicio\n";
            for (int j = 0; j < 7; j++)
            {
            perdonotravez:
                std::cout << "desea anadir el dia ";
                dias(j);
                std::cout << " --recuerde ingresar un valor valido :D";
                std::cout << "\n1. si\n";
                std::cout << "2. no\n";
                opcionDia = ingresarNumero(opcionDia);
                if (opcionDia > 2 || opcionDia < 1)
                {
                    goto perdonotravez;
                }
                (opcionDia == 1) ? Servicio.diasDeServicio.dias[j] = true : Servicio.diasDeServicio.dias[j] = false; // si opcion == 1 entonces dias[x] true, sino
            }
            std::cout << "ingrese tiempo de salida\n";
            ingresarTiempo(Servicio.salida);
            std::cout << "ingrese tiempo de llegada\n";
            ingresarTiempo(Servicio.llegada);

            // escribiendo a archivo
            std::ofstream servicio("datosservicios.bin", std::ios::app | std::ios::binary);
            if (servicio.fail())
            {
                std::cout << "\nEl archivo datosservicios.bin no se pudo abrir. Cerrando programa...\n";
                exit(0);
            }
            servicio.write(reinterpret_cast<char *>(&Servicio), sizeof(servicios));

        // opciones
        bueno:
            std::cout << "quiere seguir ingresando mas servicios?\n";
            std::cout << "1. si\n";
            std::cout << "2. no\n";
            opcionDia = ingresarNumero(opcionDia);
            if (opcionDia > 2 || opcionDia < 1)
                goto bueno;
            if (opcionDia == 2)
            {
                break;
            }
        }
    }
    else
    {
        std::cout << "ingrese un codigo de ruta que exista ";
        goto estoycansado;
    }
}

void registrarViaje()
{
    clearScreen();
    int opcion;
    bool found;
    long codigoServicio;
    long codigoDeCliente;

    struct ruta Ruta;
    struct viajes Viaje;
    struct cliente Cliente;
    struct servicios Servicio;

    for (;;)
    {
        Ruta = {0};
        Viaje = {0};
        Cliente = {0};
        Servicio = {0};

    nopuedeser0:
        std::cout << "\nIngrese el ID del cliente: ";
        codigoDeCliente = ingresarNumero(codigoDeCliente);
        if (codigoDeCliente == 0)
        {
            std::cout << "el id de cliente no puede ser 0";
            goto nopuedeser0;
        }

        // ver si el cliente ya esta en el registro
        std::ifstream servicio("datoscliente.bin", std::ios::in | std::ios::binary);
        servicio.read(reinterpret_cast<char *>(&Cliente), sizeof(cliente));
        while (!servicio.eof())
        {
            if (codigoDeCliente == Cliente.idCliente)
            {
                found = true;
                servicio.close();
                break;
            }
            else
            {
                servicio.read(reinterpret_cast<char *>(&Cliente), sizeof(cliente));
                found = false;
            }
        }
        servicio.close();

        // si no esta en el registro, ingresarlo
        if (!found)
        {
            std::cout << "Ingrese el nombre del cliente: ";
            clear();
            std::cin.getline(Cliente.nombreCliente, 50);

            std::cout << "Ingrese el telefono del cliente: ";
            Cliente.telefonoCliente = ingresarNumero(Cliente.telefonoCliente);

            Cliente.idCliente = codigoDeCliente;

            std::ofstream datoscliente("datoscliente.bin", std::ios::app | std::ios::binary);
            if (datoscliente.fail())
            {
                std::cout << "\nEl archivo datoscliente.bin no se pudo abrir. Cerrando programa...\n";
                exit(0);
            }
            datoscliente.write(reinterpret_cast<char *>(&Cliente), sizeof(cliente));
            datoscliente.close();
        }

    notengocreatividad:                                  // quiero un codigo de servicio que ya exista
        std::cout << "Ingrese el codigo del servicio: "; // de esto sacare muchas cosas, costo, nombre ruta, salida, llegada
        codigoServicio = ingresarNumero(codigoServicio);

        // quiero tener el struct del servicio requerido
        std::ifstream servicio2("datosservicios.bin", std::ios::in | std::ios::binary);
        servicio2.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios));

        while (!servicio2.eof())
        {
            if (codigoServicio == Servicio.codigoDeServicio)
            {
                servicio2.close();
                found = true;
                break;
            }
            else
            {
                servicio2.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios));
                found = false;
            }
        }
        servicio2.close();

        if (!found)
        {
            std::cout << "ingrese un codigo de servicio valido";
            goto notengocreatividad;
        }

        // necesito el struct ruta ahora
        std::ifstream ruta("datosruta.bin", std::ios::in | std::ios::binary);
        ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
        while (!ruta.eof())
        {
            if (Servicio.codigoDeRuta == Ruta.codigoDeRuta)
            {
                ruta.close();
                break;
            }
            else
            {
                ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
            }
        }
        ruta.close();

        Viaje.codigoDeRuta = Ruta.codigoDeRuta;        
        generarCodigoTiquete(Viaje.codigoDeTiquete, Cliente.idCliente, Servicio.codigoDeServicio);

        std::cout << "===== Tiquete de Viaje =====" << std::endl;
        std::cout << "Codigo del tiquete: " << Viaje.codigoDeTiquete << std::endl;
        std::cout << "ID del cliente: " << Cliente.idCliente << std::endl;
        std::cout << "Nombre del cliente: " << Cliente.nombreCliente << std::endl;
        std::cout << "Nombre de la ruta: " << Ruta.nombreDeRuta << std::endl;
        std::cout << "hora de salida: ";
        mostrarTiempo(Servicio.salida);
        std::cout << "\nhora de llegada: ";
        mostrarTiempo(Servicio.llegada);
        std::cout << "\nValor de viaje: " << Ruta.costoDeViaje;
        std::cout << "\n============================\n";

        Viaje.idCliente = Cliente.idCliente;
        Viaje.codigoDeServicio = Servicio.codigoDeServicio;

        // guardar struct viajes
        std::ofstream datosviaje("datosviaje.bin", std::ios::app | std::ios::binary);
        if (datosviaje.fail())
        {
            std::cout << "\nEl archivo datosviaje.bin no se pudo abrir. Cerrando programa...\n";
            exit(0);
        }
        datosviaje.write(reinterpret_cast<char *>(&Viaje), sizeof(viajes));

    pregunta:
        std::cout << "quiere seguir registrando mas viajes?\n";
        std::cout << "1. si\n";
        std::cout << "2. no\n";
        opcion = ingresarNumero(opcion);
        if (opcion > 2 || opcion < 1)
            goto pregunta;
        if (opcion == 2)
            break;
    }
}

void imprimirRecorrido()
{
    long idTemporal;
    long codigoDeRuta[50] = {0};
    long codigoDeServicio[50] = {0};
    int i = 0;
    int opcion;

    struct ruta Ruta = {0};
    struct viajes Viaje = {0};
    struct cliente Cliente = {0};
    struct servicios Servicio = {0};

// ingrese id cliente
dormir:
    std::cout << "ingrese id del cliente";
    idTemporal = ingresarNumero(idTemporal);

    // buscar cliente en el archivo, como un cliente puede tener varios viajes...
    std::ifstream datosviaje("datosviaje.bin", std::ios::in | std::ios::binary);
    datosviaje.read(reinterpret_cast<char *>(&Viaje), sizeof(viajes));
    while (!datosviaje.eof())
    {
        if (idTemporal == Viaje.idCliente)
        {
            codigoDeServicio[i] = Viaje.codigoDeServicio;
            i++; // me indica la cantidad de viajes que tiene el cliente
            datosviaje.read(reinterpret_cast<char *>(&Viaje), sizeof(viajes));
        }
        else
        {
            datosviaje.read(reinterpret_cast<char *>(&Viaje), sizeof(viajes));
        }
    }
    datosviaje.close();

    if (i == 0)
    {
        std::cout << "ingrese una identificacion de cliente valida";
        goto dormir;
    }

    i = 0;
    // buscar los servicios que el cliente tiene en el archivo
    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    servicio.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios));
    while (!servicio.eof())
    {
        if (codigoDeServicio[i] == Servicio.codigoDeServicio)
        {
            codigoDeRuta[i] = Servicio.codigoDeRuta;
            i++;
        }
        else
        {
            servicio.read(reinterpret_cast<char *>(&Servicio), sizeof(servicios));
        }
    }
    servicio.close();

    i = 0;
    // buscar las rutas para mostrar
    std::ifstream ruta("datosruta.bin", std::ios::in | std::ios::binary);
    ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
    while (!ruta.eof())
    {
        if (codigoDeRuta[i] == Ruta.codigoDeRuta)
        {
        porfavor:
            std::cout << "quiere mostar la ruta " << Ruta.nombreDeRuta << "?\n";
            std::cout << "1. si\n";
            std::cout << "2. no\n";
            opcion = ingresarNumero(opcion);
            if (opcion > 2 || opcion < 1)
            {
                goto porfavor;
            }
            if (opcion == 1)
            {
                for (int i = 0; i < 70; i++)
                {
                    if (Ruta.DecripcionLugares[i].nombreLugar[0] != '\0')
                    {
                        std::cout << "\n\n\nnombre de lugar: ";
                        std::cout << Ruta.DecripcionLugares[i].nombreLugar;
                        std::cout << "\ntiempo previsto de llegada: ";
                        mostrarTiempo(Ruta.DecripcionLugares[i].previstoDeLlegada);
                        std::cout << "\ntiempo previsto de parada: ";
                        mostrarTiempo(Ruta.DecripcionLugares[i].previstoDeParada);
                        std::cout << "\nactividad a realizar: \n";
                        std::cout << Ruta.DecripcionLugares[i].actividad;
                    }
                    else
                        break; // pues no habra info escrita en lo que sigue del array
                }
                break;
            }
            else
            {
                ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
            }
        }
        else
        {
            ruta.read(reinterpret_cast<char *>(&Ruta), sizeof(ruta));
        }
    }
    ruta.close();
}

// Función para imprimir la estructura servicios
void mostrarServicios()
{
    int contador = 0;
    struct servicios Servicio[90] = {0};
    // struct ruta Ruta[90] = {0};

    // std::ifstream ruta("datosruta.bin", std::ios::in | std::ios::binary);
    std::ifstream servicio("datosservicios.bin", std::ios::in | std::ios::binary);
    // while (ruta.read(reinterpret_cast<char*>(&Ruta[90]), sizeof(ruta))) {
    //     contador++;
    //     if (contador >= 90) {
    //         std::cout<<"Se ha alcanzado el número máximo de rutas\n";
    //         break;
    //     }
    // }

    contador = 0;
    while (servicio.read(reinterpret_cast<char *>(&Servicio[contador]), sizeof(servicios)))
    {
        contador++;
        if (contador >= 90)
        {
            std::cout << "Se ha alcanzado el número máximo de servicios\n";
            break;
        }
    }

    for (int i = 0; i < 90; i++)
    {
        if (Servicio[i].codigoDeRuta != 0)
        {
            std::cout << "Código de Ruta: " << Servicio[i].codigoDeRuta << std::endl;
            std::cout << "Código de Servicio: " << Servicio[i].codigoDeServicio << std::endl;
            std::cout << "Días de Servicio: ";
            for (int j = 0; j < 7; ++j)
            {
                if (Servicio[i].diasDeServicio.dias[j])
                {
                    dias(j);
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;
            std::cout << "Hora de Salida: ";
            mostrarTiempo(Servicio[i].salida);
            std::cout << std::endl;
            std::cout << "Hora de Llegada: ";
            mostrarTiempo(Servicio[i].llegada);
            std::cout << "\n\n\n\n";
        }
        else
            break; // todo lo que queda esta vacio
    }
}
