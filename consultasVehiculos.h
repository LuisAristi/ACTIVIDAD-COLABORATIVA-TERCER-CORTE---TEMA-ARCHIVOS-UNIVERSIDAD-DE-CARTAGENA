#include "consultarRutas.h"

void consultaPorVehiculo();
void listadoKmPorVehiculo();
void listadoKmPorConductor();

void consultaPorVehiculo(){
    char codigo[10];
    bool found = false;
    bool vision = false;
    int opciones;
    struct Vehiculo vehiculo;
    struct Revision revision;

    validar:
    std::cout<<"ingrese matricula del vehiculo: ";
    clear();
    std::cin.getline(codigo, 10);

    std::ifstream datosvehiculo("vehiculos.txt", std::ios::in | std::ios::binary);
    datosvehiculo.read(reinterpret_cast<char *>(&vehiculo), sizeof(Vehiculo));

    if(datosvehiculo.fail()){
        std::cout<<"el archivo no existe";
        exit(0);
    }

    while (!datosvehiculo.eof())
    {
        if (strcasecmp(codigo, vehiculo.matricula) == 0)
        {   
            found = true;
            datosvehiculo.close();
            std::ifstream archivo("revision.txt", std::ios::in | std::ios::binary);
            while (!archivo.eof())
            {
                if (strcasecmp(codigo, revision.matricula) == 0)
                {   
                    std::cout<<"matricula: "<<vehiculo.matricula;
                    std::cout<<"\nmodelo: "<<vehiculo.modelo;
                    std::cout<<"\nfabricante: "<<vehiculo.fabricante;
                    std::cout<<"\ncapacidad: "<<vehiculo.numero_plazas<<" personas";
                    std::cout<<"\ndescripcion del vehiculo: "<<vehiculo.caracteristicas;

                    std::cout<<"\ndiagnostico: "<<revision.diagnostico;
                    std::cout<<"\nreparaciones: "<<revision.reparaciones;
                    std::cout<<"\nnumero de reparaciones"<<revision.num_reparaciones;
                    std::cout<<"\nfecha: "<<revision.fecha_hora;
                    archivo.close();
                    break;
                }
                archivo.read(reinterpret_cast<char *>(&revision), sizeof(Revision));
            }
            archivo.close();
            break;
        }
        datosvehiculo.read(reinterpret_cast<char *>(&vehiculo), sizeof(Vehiculo));
    }
    datosvehiculo.close();

    if(!found){
        std::cout<<"la placa no fue encontrada, ";
        std::cout<<"quiere salir al menu?\n";
        std::cout<<"1. si\n";
        std::cout<<"2. no";
        opciones = ingresarNumero(opciones);
        if (opciones == 2){ goto validar; }
    }

    if(!vision){
        std::cout<<"no se encontraron servicios, ";
    }
}


void listadoKmPorVehiculo(){
    char placa[10];
    bool found = false;
    struct ruta Ruta;
    struct servicios Servicio;
    struct AsignacionDeConductores asignacion;

    while(true){
        std::cout<<"ingrese id placa del vehiculo";
        std::cin.getline(placa, 10);

        std::ifstream archivo("asignacion.txt", std::ios::in | std::ios::binary);
        if (!archivo) {
            std::cout << "Error al abrir el archivo para lectura" << std::endl;
            exit(0);
        }
        while (!archivo.eof()) {
            archivo.read(reinterpret_cast<char*>(&asignacion), sizeof(AsignacionDeConductores));
            if (std::strncmp(asignacion.matricula, placa, sizeof(asignacion.matricula)) == 0) {
                archivo.close();
                found = true;
                break;
            }
        } archivo.close();

        if(!found){
            std::cout<<"no se encontro el vehiculo asignado a algun viaje";
            break;
        }

        found = false;
        //servicios
        std::ifstream inFile("datosservicios.bin", std::ios::in | std::ios::binary);
        if (!inFile) {
            std::cerr << "Error al abrir el archivo para lectura" << std::endl;
        }
        while (!inFile.eof()) {
            inFile.read(reinterpret_cast<char*>(&Servicio), sizeof(servicios));
            if (Servicio.codigoDeServicio == asignacion.codigoDeServicio) {
                inFile.close();
                break;
            }
        } inFile.close();


        std::ifstream archivoRutas("datosruta.bin", std::ios::in | std::ios::binary);
        if (!archivoRutas) {
            std::cerr << "Error al abrir el archivo para lectura" << std::endl;
        }
        while (!archivoRutas.eof()) {
            archivoRutas.read(reinterpret_cast<char*>(&Ruta), sizeof(servicios));
            if (Ruta.codigoDeRuta == Servicio.codigoDeRuta) {
                archivoRutas.close();
                break;
            }
        } archivoRutas.close();

        int multiplicar = 0;
        for(int i=0; i<7; i++){
            if(Servicio.diasDeServicio.dias[i]){
                multiplicar++;
                dias(i);
                i < 6? std::cout<<", " : std::cout<<""; 
            }  
        }
        std::cout<<"los kilometros recorridos en una semana por este vehiculo son: "<<Ruta.kilometros*multiplicar<<" km";

    }
}

void listadoKmPorConductor(){
    long id;
    bool found = false;
    struct ruta Ruta;
    struct servicios Servicio;
    struct AsignacionDeConductores asignacion;

    while(true){
        std::cout<<"ingrese id del conductor";
        id = ingresarNumero(id);

        std::ifstream archivo("asignacion.txt", std::ios::in | std::ios::binary);
        if (!archivo) {
            std::cout << "Error al abrir el archivo para lectura" << std::endl;
            exit(0);
        }
        while (!archivo.eof()) {
            archivo.read(reinterpret_cast<char*>(&asignacion), sizeof(AsignacionDeConductores));
            if (asignacion.IDConductor == id) {
                archivo.close();
                found = true;
                break;
            }
        } archivo.close();

        if(!found){
            std::cout<<"no se encontro el id del conductor asignado a algun viaje";
            break;
        }

        //servicios
        std::ifstream inFile("datosservicios.bin", std::ios::in | std::ios::binary);
        if (!inFile) {
            std::cerr << "Error al abrir el archivo para lectura" << std::endl;
        }
        while (!inFile.eof()){
            inFile.read(reinterpret_cast<char*>(&Servicio), sizeof(servicios));
            if (Servicio.codigoDeServicio == asignacion.codigoDeServicio) {
                inFile.close();
                break;
            }
        } inFile.close();


        std::ifstream archivoRutas("datosruta.bin", std::ios::in | std::ios::binary);
        if (!archivoRutas) {
            std::cerr << "Error al abrir el archivo para lectura" << std::endl;
        }
        while (!archivoRutas.eof()) {
            archivoRutas.read(reinterpret_cast<char*>(&Ruta), sizeof(servicios));
            if (Ruta.codigoDeRuta == Servicio.codigoDeRuta) {
                archivoRutas.close();
            }
        } archivoRutas.close();
        int multiplicar = 0;
        for(int i=0; i<7; i++){
            if(Servicio.diasDeServicio.dias[i]){
                multiplicar +1;
                dias(i);
                i < 6? std::cout<<", " : std::cout<<""; 
            }  
        }
        std::cout<<"los kilometros recorridos en una semana por este vehiculo son: "<<Ruta.kilometros*multiplicar<<" km";
        break;
    }
}

