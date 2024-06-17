#include "gestionViajes.h"

void registrarVehiculo();
void registrarConductor();
void asignacionDeConductores();
void registrarRevisionVehiculo();
int verificarid(long id, char *nombre);
int verificarMatricula(const char *matricula);
void convertirMayusculas(char *cadena);

/******************************************************/

time_t tiempo = time(0); // recibirá como parámetro un puntero nulo (es decir, NULL o 0) y devolverá el tiempo actual en una variable de tipo "time_t".
struct tm *tlocal = localtime(&tiempo);

/*****************************************************/

void registrarVehiculo()
{
    Vehiculo vehiculo;
    char matv[50];
    system("cls");
    std::cout << "Matricula: ";
    fflush(stdin);
    std::cin.getline(matv, 50);
    convertirMayusculas(matv);
    // strcpy(may,matv);
    if (verificarMatricula(matv) == 1)
    {
        std::cout << "Vehiculo " << matv << " ya esta registrado" << std::endl;
    }
    else
    {
        strcpy(vehiculo.matricula, matv);
        std::cout << "Modelo: ";
        fflush(stdin);
        std::cin.getline(vehiculo.modelo, 50);
        std::cout << "Fabricante: ";
        fflush(stdin);
        std::cin.getline(vehiculo.fabricante, 19);
        std::cout << "Numero de plazas: ";
        std::cin >> vehiculo.numero_plazas;
        std::cout << "Descripcion del vehiculo: ";
        fflush(stdin);
        std::cin.getline(vehiculo.caracteristicas, 200);
        std::ofstream archivo("vehiculos.txt", std::ios::app | std::ios::binary);
        if (archivo.fail())
        {
            std::cout << "Error para abrir archivo vehiculos.txt" << std::endl;
            system("pause");
            exit(0);
        }
        archivo.write(reinterpret_cast<char *>(&vehiculo), sizeof(Vehiculo));
        archivo.close();
    }
}

void registrarConductor()
{
    Conductor conductor;
    char nombre[50];
    system("cls");
    std::cout << "Id: ";
    std::cin >> conductor.ID;
    if (verificarid(conductor.ID, nombre) == 1)
    {
        std::cout << "Conductor " << nombre << " ya existente" << std::endl;
    }
    else
    {
        std::cout << "Nombre: ";
        fflush(stdin);
        std::cin.getline(conductor.nombre, 50);
        std::cout << "Telefono: ";
        std::cin >> conductor.telefono;
        std::cout << "Direccion: ";
        fflush(stdin);
        std::cin.getline(conductor.direccion, 100);
        std::ofstream archivo("conductores.txt", std::ios::app | std::ios::binary);
        if (archivo.fail())
        {
            std::cout << "Error para abrir archivo conductores.txt" << std::endl;
            system("pause");
            exit(0);
        }
        archivo.write(reinterpret_cast<char *>(&conductor), sizeof(Conductor));
        archivo.close();
    }
}

int verificarid(long id, char *nombre)
{
    Conductor conductor;
    std::ifstream archivo("conductores.txt", std::ios::in | std::ios::binary);
    if (archivo.fail())
    {
        std::cout << "Error para abrir archivo conductores.txt" << std::endl;
        system("pause");
        exit(0);
    }
    archivo.read(reinterpret_cast<char *>(&conductor), sizeof(Conductor));
    while (!archivo.eof())
    {
        if (conductor.ID == id)
        {
            strcpy(nombre, conductor.nombre);
            return 1; // se encontró el cliente
        }
        archivo.read(reinterpret_cast<char *>(&conductor), sizeof(Conductor));
    }
    archivo.close();
    return 0;
}

int verificarMatricula(const char *matricula)
{
    Vehiculo vehiculo;
    std::ifstream archivo("vehiculos.txt", std::ios::in | std::ios::binary);
    if (archivo.fail())
    {
        std::cout << "Error para abrir archivo vehiculos.txt" << std::endl;
        system("pause");
        exit(0);
    }
    archivo.read(reinterpret_cast<char *>(&vehiculo), sizeof(Vehiculo));
    while (!archivo.eof())
    {
        if (strcmp(vehiculo.matricula, matricula) == 0)
        {
            return 1; // matrícula encontrada
        }
        archivo.read(reinterpret_cast<char *>(&vehiculo), sizeof(Vehiculo));
    }
    archivo.close();
    return 0;
}

void convertirMayusculas(char *cadena)
{
    int longitud = std::strlen(cadena);
    for (int i = 0; i < longitud; ++i)
    {
        cadena[i] = std::toupper(cadena[i]);
    }
}

void registrarRevisionVehiculo()
{
    Revision revision;
    Reparacion reparacion;
    char matv[50];
    int opc, opc2;
    system("cls");
    std::cout << "Matricula: ";
    fflush(stdin);
    std::cin.getline(matv, 50);
    convertirMayusculas(matv);
    if (verificarMatricula(matv) == 1)
    {

        strftime(revision.fecha_hora, 128, "%d/%m/%y %H:%M:%S", tlocal);
        std::cout << "Fecha de revision: " << revision.fecha_hora << std::endl;
        strcpy(revision.matricula, matv);
        std::cout << "Diagnostico: ";
        fflush(stdin);
        std::cin.getline(revision.diagnostico, 100);
        std::cout << "¿Necesita reparación? 1=SI Cualquier otro valor=No: ";
        std::cin >> opc;
        switch (opc)
        {
        case 1:
            std::cout << "Cdoigo de la reparación: ";
            std::cin >> reparacion.codigo;
            std::cout << "Tiempo empleado (Minutos): ";
            std::cin >> reparacion.tiempo;
            std::cout << "¿Desea ingresar un comentario? 1=SI Cualquier otro valor=No: ";
            std::cin >> opc2;
            switch (opc2)
            {
            case 1:
                std::cout << "Comentario: ";
                fflush(stdin);
                std::cin.getline(reparacion.comentario, 100);
                break;

            default:
                break;
            }
            break;

        default:
            std::cout << "No necesita reparación" << std::endl;
            break;
        }
        // archivos revision
        std::ofstream archivo("revision.txt", std::ios::app | std::ios::binary);
        if (archivo.fail())
        {
            std::cout << "Error para abrir archivo revision.txt" << std::endl;
            system("pause");
            exit(0);
        }
        archivo.write(reinterpret_cast<char *>(&revision), sizeof(Revision));
        archivo.close();

        // archivos  reparacion
        std::ofstream archivo1("reparacion.txt", std::ios::app | std::ios::binary);
        if (archivo1.fail())
        {
            std::cout << "Error para abrir archivo reparacion.txt" << std::endl;
            system("pause");
            exit(0);
        }
        archivo1.write(reinterpret_cast<char *>(&reparacion), sizeof(Reparacion));
        archivo1.close();
    }
    else
    {
        std::cout << "Matricula no registrada" << std::endl;
    }
}

void asignacionDeConductores()
{

    long idv;
    long codv;
    char nombre[50], matv[10];
    AsignacionDeConductores asignacion;
    // ingresar codigo del servicio
    system("cls");
    std::cout << "Ingrese codigo del servicio: ";
    codv = ingresarNumero(codv);
    if (!compararServicioCodigo(codv))
    {
        std::cout << "El codigo de servicio no existe" << std::endl;
    }
    else
    {
        std::cout << "ingrese id del conductor: ";
        std::cin >> idv;
        if (verificarid(idv, nombre) == 1)
        {
            std::cout << "Ingrese la matricula del vehiculo: ";
            fflush(stdin);
            std::cin.getline(matv, 10);
            convertirMayusculas(matv);
            if (verificarMatricula(matv) == 0)
            {
                std::cout << "Matricula no registrada" << std::endl;
            }
            else
            {
                strcpy(asignacion.placa, matv);
                asignacion.codigoDeServicio = codv;
                asignacion.IDConductor = idv;
                std::cout << "Asinación completada" << std::endl;
                std::ofstream archivo("asignacion.txt", std::ios::app | std::ios::binary);
                if (archivo.fail())
                {
                    std::cout << "Error para abrir archivo asignacion.txt" << std::endl;
                    system("pause");
                    exit(0);
                }
                archivo.write(reinterpret_cast<char *>(&asignacion), sizeof(AsignacionDeConductores));
                archivo.close();
            }
        }
        else
        {
            std::cout << "Id no registrado" << std::endl;
        }
    }
}
