#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#define CANT 10
typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldo;
    int idSector;
    int isEmpty;
} eEmpleado;

typedef struct
{
    int id;
    char descripcion[20];
} eSector;


void inicializarEmpleados( eEmpleado* x, int tam);
int buscarLibre( eEmpleado* x, int tam);
int buscarEmpleado(eEmpleado* x, int tam, int legajo);
void mostrarEmpleado(eEmpleado* emp, eSector* sectores, int tamSector);
void mostrarEmpleados(eEmpleado* nomina, int tam, eSector* sectores, int tamSector);
void agregarEmpleado(eEmpleado* empleados, int tam, eSector* sectores, int tamSector);
void eliminarEmpleado(eEmpleado *empleados, int tam, eSector* sectores, int tamSector);
void modificarEmpleado(eEmpleado* empleados, int tam, eSector* sectores, int tamSector);;
int elegirSector(eSector* sectores, int tam);
void cargarDescripcion(eSector* sectores, int tamSector, int idSector, char* cadena);
void listarEmpleadosXSector(eEmpleado* x,int tam, eSector* sectores, int tamSector);
void ordenarXSectorYNombre(eEmpleado* x,int tam, eSector* sectores, int tamSector);
void mostrarEmpleadosMasGanadores(eEmpleado* x,int tam, eSector* sectores, int tamSector);
//void harcodearEmpleados(eEmpleado x[]);
int menu();

int main()
{

    char seguir = 's';
    eEmpleado* lista=(eEmpleado*) malloc(sizeof(eEmpleado)*CANT);
    eSector sectores[] =
    {
        {1, "RRHH"},
        {2, "Ventas"},
        {3, "Compras"},
        {4, "Contable"},
        {5, "Sistemas"}
    };
    if(lista!=NULL){
        inicializarEmpleados(lista, CANT);
    }else{
        printf("No se hacer espacio en memoria  ");
        exit(1);
    }
    //harcodearEmpleados(lista);

    do
    {
        switch(menu())
        {

        case 1:
            agregarEmpleado(lista, CANT , sectores, 5);
            system("pause");
            break;
        case 2:
            eliminarEmpleado(lista, 10, sectores, 5);
            break;
        case 3:
            modificarEmpleado(lista, 10, sectores, 5);
            break;
        case 4:
            mostrarEmpleados(lista, 10, sectores, 5);
            system("pause");
            break;
        case 5:
            listarEmpleadosXSector(lista, 10, sectores, 5);
            system("pause");
            break;
        case 6:
            ordenarXSectorYNombre(lista, 10, sectores, 5);
            system("pause");
            break;
        case 7:
            mostrarEmpleadosMasGanadores(lista, 10, sectores, 5);
            system("pause");
            break;
        case 10:
            seguir = 'n';
            break;
        }

    }
    while(seguir == 's');

    free(lista);

    return 0;
}

void inicializarEmpleados( eEmpleado* x, int tam)
{
    for(int i=0; i < tam; i++)
    {
        (x+i) ->isEmpty=0;
    }
}

int buscarLibre( eEmpleado* x, int tam)
{
    int indice = -1;

    for(int i=0; i< tam; i++)
    {

        if( (x+i)->isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleado(eEmpleado* x, int tam, int legajo)
{
    int indice = -1;
    for(int i=0; i < tam; i++)
    {


        if( (x+i)->legajo == legajo && (x+i)->isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta\n");
    printf("2- Baja\n");
    printf("3- Modificar\n");
    printf("4- Listar\n");
    printf("5- Listar todos los empleados de un sector\n");
    printf("6- Ordenar empleados por sector y dentro del sector por nombre\n");
    printf("7- Mostrar los datos de o los empleados que mas ganan por sector\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}

void agregarEmpleado(eEmpleado* empleados, int tam, eSector* sectores, int tamSector)
{
    eEmpleado* nuevoEmpleado =(eEmpleado*) malloc(sizeof(eEmpleado));
    int indice;
    int esta;
    int legajo;

    indice = buscarLibre(empleados, tam);

    if(indice == -1)
    {
        printf("No hay lugar\n\n");
    }
    else
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);

        esta = buscarEmpleado(empleados, tam, legajo);

        if(esta != -1)
        {
            printf("Existe un empleado con el legajo %d\n", legajo);
            mostrarEmpleado( empleados+esta, sectores, tamSector);
        }
        else
        {
            nuevoEmpleado->legajo = legajo;

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(nuevoEmpleado->nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &nuevoEmpleado->sexo);

            printf("Ingrese sueldo: ");
            fflush(stdin);
            scanf("%f", &nuevoEmpleado->sueldo);

            nuevoEmpleado->idSector = elegirSector(sectores, 5);

            nuevoEmpleado->isEmpty = 1;

            *(empleados+indice) = *nuevoEmpleado;
            free(nuevoEmpleado);
        }
    }

}

void mostrarEmpleado(eEmpleado* emp, eSector* sectores, int tamSector)
{
    char descripcion[20];

    cargarDescripcion(sectores, tamSector, emp->idSector, descripcion);

    printf("%d %s %c %.2f %s \n\n", emp->legajo, emp->nombre, emp->sexo, emp->sueldo, descripcion);

}


void mostrarEmpleados(eEmpleado* nomina, int tam, eSector* sectores, int tamSector)
{
    for(int i=0; i< tam; i++)
    {
        if( (nomina+i)->isEmpty == 1)
        {
            mostrarEmpleado(nomina+i, sectores, tamSector);
        }
    }
}

void eliminarEmpleado(eEmpleado* empleados, int tam, eSector* sectores, int tamSector)
{

    int legajo;
    int indice;
    char borrar;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados+indice, sectores, tamSector);

        printf("\nConfirma borrado?: ");
        fflush(stdin);
        scanf("%c", &borrar);
        if(borrar != 's')
        {
            printf("Borrado cancelado\n\n");
        }
        else
        {
            (empleados+indice)->isEmpty = 0;
            printf("Se ha eliminado el empleado\n\n");
        }
        system("pause");
    }

}

void modificarEmpleado(eEmpleado* empleados, int tam, eSector* sectores, int tamSector)
{

    int legajo;
    int indice;
    char modificar;
    float nuevoSueldo;

    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    indice = buscarEmpleado(empleados, tam, legajo);

    if( indice == -1)
    {
        printf("No hay ningun empleado con el legajo %d\n", legajo);
    }
    else
    {
        mostrarEmpleado( empleados+indice, sectores, tamSector);

        printf("\nModifica sueldo?: ");
        fflush(stdin);
        scanf("%c", &modificar);
        if(modificar != 's')
        {
            printf("Modificacion cancelada\n\n");
        }
        else
        {
            printf("Ingrese nuevo sueldo: ");
            scanf("%f", &nuevoSueldo);

            (empleados+indice)->sueldo = nuevoSueldo;
            printf("Se ha modificado el sueldo con exito\n\n");
        }

        system("pause");
    }

}


int elegirSector(eSector* sectores, int tam)
{
    int idSector;
    printf("\nSectores\n\n");
    for(int i=0; i < tam; i++)
    {
        printf("%d %s\n", (sectores+i)->id, (sectores+i)->descripcion);
    }
    printf("\nSeleccione sector: ");
    scanf("%d", &idSector);

    return idSector;
}

void cargarDescripcion(eSector* sectores, int tamSector, int idSector, char* cadena)
{

    for(int i=0; i < tamSector; i++)
    {
        if( (sectores+i)->id == idSector)
        {

            strcpy(cadena, (sectores+i)->descripcion);
            break;
        }
    }


}

void listarEmpleadosXSector(eEmpleado* x,int tam, eSector* sectores, int tamSector)
{

    int idSector;
    char descripcion[20];
    int flag = 0;

    idSector = elegirSector(sectores, tamSector);

    cargarDescripcion(sectores, tam, idSector, descripcion);

    system("cls");
    printf("Empleados del sector %s\n\n", descripcion);
    for(int i=0; i< tam; i++)
    {
        if((x+i)->isEmpty == 1 && (x+i)->idSector == idSector)
        {
            mostrarEmpleado(x+i, sectores, tamSector);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("No hay empleados que mostrar\n\n");
    }

}

void ordenarXSectorYNombre(eEmpleado* x,int tam, eSector* sectores, int tamSector)
{
    char descripcionI[20];
    char descripcionJ[20];
    eEmpleado* auxEmpleado=(eEmpleado*) malloc(sizeof(eEmpleado));

    for(int i=0; i<tam -1; i++)
    {
        for(int j = i +1; j < tam; j++)
        {
            cargarDescripcion(sectores, tamSector, (x+i)->idSector, descripcionI);
            cargarDescripcion(sectores, tamSector, (x+j)->idSector, descripcionJ);
            if( strcmp(descripcionI, descripcionJ) > 0)
            {
                *auxEmpleado = *(x+i);
                *(x+i) = *(x+j);
                *(x+j) = *auxEmpleado;
            }
            else if( strcmp(descripcionI, descripcionJ) == 0 && strcmp((x+i)->nombre, (x+j)->nombre) > 0)
            {
                *auxEmpleado = *(x+i);
                *(x+i) = *(x+j);
                *(x+j) = *auxEmpleado;
            }
        }
    }
    free(auxEmpleado);
}
/*void harcodearEmpleados(eEmpleado x[])
{

    eEmpleado y[]=
    {
        {1111, "ana", 'f', 15000, 5, 1},
        {3333, "luis", 'm', 25000, 4, 1},
        {4444, "alberto", 'm', 10000, 5, 1},
        {5555, "julia", 'f', 30000, 1, 1},
        {1313, "julieta", 'f', 23000, 2, 1},
        {4545, "andrea", 'f', 31000, 5, 1},
        {3232, "mauro", 'm', 27000, 5, 1},
    };

    for(int i=0; i<7; i++)
    {
        x[i] = y[i];
    }

}
*/
void mostrarEmpleadosMasGanadores(eEmpleado* x,int tam, eSector* sectores, int tamSector)
{
    float maxSueldo;
    char descripcion[20];
    int flag;

    for(int i=0; i < tamSector; i++){
         cargarDescripcion(sectores, tamSector, sectores[i].id, descripcion);
         printf("Sector %s\n", descripcion);
         flag = 0;
         for(int j=0; j < tam; j++){
            if( ((x+j)->sueldo > maxSueldo && (x+j)->isEmpty == 1 && (x+j)->idSector == (sectores+i)->id) || flag == 0){
                maxSueldo = (x+j)->sueldo;
                flag = 1;
            }
         }

          for(int j=0; j < tam; j++){
            if( (x+j)->sueldo == maxSueldo){
                mostrarEmpleado(x+j, sectores, tamSector);
            }
          }


          printf("\n\n");

    }

}
