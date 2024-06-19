#include "consultasVehiculos.h"

#include <string>
#include <iomanip> // Para setw


// Función para calcular las horas de viaje
int calcularHorasDeViaje(int horaSalida, int horaLlegada) {
    if (horaLlegada >= horaSalida) {
        return horaLlegada - horaSalida;
    } else {
        // Si la llegada es al día siguiente
        return (24 - horaSalida) + horaLlegada;
    }
}

// Función para acumular las horas de viaje
void acumularHorasDeViaje() {
    struct cliente Clientes;
    struct servicios Servicios; 
    struct viajes gestiones;

    int horas;

    std::ifstream archivoGestiones("datosviaje.bin", std::ios::binary);

    if (!archivoGestiones){
        std::cout<<"Error al abrir los archivos binarios.\n";
        return;
    }

    while(!archivoGestiones.eof()){
        archivoGestiones.read(reinterpret_cast<char *>(&gestiones), sizeof(viajes));
        compararServicioCodigo(Servicios, gestiones.codigoDeServicio);
        compararClienteCodigo(Clientes, gestiones.idCliente);
        
        int horas = calcularHorasDeViaje(Servicios.salida.hora, Servicios.llegada.hora);
        Clientes.totalHoras += horas;
    }

    archivoGestiones.close();
}

void mostrarMejoresClientes() {

    acumularHorasDeViaje();

    std::ifstream archivo("datos.bin", std::ios::in | std::ios::binary);
    if (!archivo)
    {
        std::cout << "Error al abrir el archivo\n";
        exit(0);
    }

    struct cliente cliente_leido;
    struct cliente mayor;
    mayor.totalHoras = 0;

    // Leer el struct cliente desde el archivo
    while (archivo.read(reinterpret_cast<char*>(&cliente_leido), sizeof(cliente)))
    {
        if(cliente_leido.totalHoras > mayor.totalHoras){ mayor = cliente_leido; }
        // Mostrar los datos del cliente, incluyendo totalHoras
        std::cout << "\nID: "<<cliente_leido.idCliente;
        std::cout << "\nTeléfono: "<<cliente_leido.telefonoCliente;
        std::cout << "\nNombre: "<<cliente_leido.nombreCliente;
        std::cout << "\nHoras de viaje: "<<cliente_leido.horasViaje;
        std::cout << "\nTotal de horas: "<<cliente_leido.totalHoras;
    }
    std::cout<<"el cliente con mayor horas es: "<<mayor.nombreCliente;
    std::cout<<"identificado con "<<mayor.idCliente;
    std::cout<<"telefono: "<<mayor.telefonoCliente;
    std::cout<<"horas totales: "<<mayor.totalHoras;

    archivo.close();
}

void guardarDatosSorteo() {
    Sorteo sorteo;
    while(true){
        // Ingresar datos
        std::cout << "Ingrese el codigo del tiquete: ";
        std::cin.getline(sorteo.codigo_tiquete, 128);
        std::cout << "Ingrese el ID: ";
        sorteo.ID = ingresarNumero(sorteo.ID);
        clear();
        std::cout << "Ingrese apellidos y nombre: ";
        std::cin.getline(sorteo.apellidosnombre, 50);
        std::cout << "Ingrese el telefono: ";
        sorteo.telefono = ingresarNumero(sorteo.telefono);
        clear();
        std::cout << "Ingrese el email: ";
        std::cin.getline(sorteo.email, 128);
        std::cout << "Ingrese las horas de viaje: ";
        std::cin >> sorteo.horas_de_viaje.hora;
        sorteo.horas_de_viaje.hora = ingresarNumero(sorteo.horas_de_viaje.hora);
        std::cout << "Ingrese el codigo de ruta: ";
        sorteo.codigo_ruta = ingresarNumero(sorteo.codigo_ruta);

        // Guardar en archivo binario
        std::ofstream archivo("datossorteo.bin", std::ios::binary);
        if (archivo) {
            archivo.write(reinterpret_cast<char*>(&sorteo), sizeof(Sorteo));
            archivo.close();
            std::cout << "Datos guardados correctamente en datossorteo.bin";
        } else {
            std::cout << "No se pudo abrir el archivo para escritura.";
            exit(0);
        }

        int opcion;
        std::cout<<"\nquiere salir?";
        std::cout<<"\n1. si";
        std::cout<<"\ncualquier otro numero es no";
        opcion = ingresarNumero(opcion);
        if(opcion == 1){ break; }
    }
}


//5.3

int generarNumeroAleatorio(int i) {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % i;
}


void ganador() {
    struct Sorteo sorteo[300];

    std::ifstream archivo("datossorteo.bin", std::ios::in | std::ios::binary);
    if (!archivo.is_open()) {
        std::cout << "error al abrir el archivo\n";
        exit(0);
    }

    int cantidad = 0;
    while (archivo.read(reinterpret_cast<char *>(&sorteo[cantidad]), sizeof(Sorteo)) && cantidad < 300) {
        cantidad++;
    }
    archivo.close();
    
    int i = generarNumeroAleatorio(i);

    std::cout << "Codigo de tiquete: " << sorteo[i].codigo_tiquete << "\n";
    std::cout << "ID: " << sorteo[i].ID << "\n";
    std::cout << "Apellidos y nombre: " << sorteo[i].apellidosnombre << "\n";
    std::cout << "Telefono: " << sorteo[i].telefono << "\n";
    std::cout << "Email: " << sorteo[i].email << "\n";
    std::cout << "Horas de viaje: " << sorteo[i].horas_de_viaje.hora;
    std::cout << "\nCodigo de ruta: " << sorteo[i].codigo_ruta << "\n";
    
}
