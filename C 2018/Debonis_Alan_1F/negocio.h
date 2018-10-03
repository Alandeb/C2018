#ifndef NEGOCIO_H_INCLUDE
#define NEGOCIO_H_INCLUDE
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;
} eJuego;
typedef struct
{
    int idCliente;
    char nombre[51];
    char apellido[51];
    char domicilio[51];
    char telefono[21];
    int isEmpty;

}eCliente;
typedef struct
{
    int idAlquier;
    int idJuego;
    int idCliente;
    eFecha fecha;
}eAlquileres;
int menu();
int obtenerEspacioLibre(eCliente user[] , int cantidad);
int obtenerEspacioLibre2(eJuego game[] , int cantidad);
void init(eCliente* user,int cantidad,eJuego* game,int cantJuego);
int addEmployee(eCliente* user,int cantidad);
void printEmployee(eCliente* user,int i);
int findEmployeeById(eCliente* user, int cantidad,int id);
#endif // NEGOCIO_H_INCLUDE


