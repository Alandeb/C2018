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
}eJuego;
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
int addUser(eCliente* user,int cantidad);
void printUser(eCliente* user,int i);
int findUserById(eCliente* user, int cantidad,int id);
void menuDownModific(eCliente* user,int cantidad);
void modificationUser(eCliente* user,int index);
void removeUser(eCliente* user,int posID);
void sortUser(eCliente* user, int cantidad ,int order);
void menuDos(eCliente* user,int cantidad);
int addGame(eJuego* game,int cantidad);
void printGame(eJuego* game,int i);
int findGameById(eJuego* game, int cantidad,int id);
void menuDownModific2(eJuego* game,int cantidad);
void modificationGame(eJuego* game,int index);
void removeGame(eJuego* game,int posID);
void sortGame(eJuego* game, int cantidad ,int order);
void menuDosGame(eJuego* game,int cantidad);
#endif // NEGOCIO_H_INCLUDE

