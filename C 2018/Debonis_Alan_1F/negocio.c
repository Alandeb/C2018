#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "negocio.h"
#include "validaciones.h"
/**
 * \brief indica que todas las posiciones del array estan
 *  habilitadas poniendo todas las banderas(isEmpty) en 1 o true
 * \param user  Lista,estructura del sistema de clientes
 * \param cantidad de veces que debe interar
 * \return no retorna nada es vacio
 */
void init(eCliente* user,int cantidad,eJuego* game,int cantJuego)
{
    int i;
    for (i=0;i<cantidad;i++){
        user[i].isEmpty=1;
    }
    for (i=0;i<cantJuego;i++){
        game[i].isEmpty=1;
    }
}
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \return Retorna la posicion en la que hay espacio libres
*/
int obtenerEspacioLibre(eCliente user[] , int cantidad){
    int i, retorno=-1;
    for (i=0;i<cantidad;i++){
        if(user[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}
int obtenerEspacioLibre2(eJuego game[] , int cantidad){
    int i, retorno=-1;
    for (i=0;i<cantidad;i++){
        if(game[i].isEmpty==1){
            retorno=i;
            break;
        }
    }
    return retorno;
}
int menu()
{
    int opcion;
    system("cls");
    printf("***Menu de Opciones***\n\n");
    printf("1- Alta de clientes\n");
    printf("2- Baja de clientes\n");
    printf("3- Modificacion de clientes\n");
    printf("4- Listado de clientes\n");
    printf("1- Alta de juegos\n");
    printf("2- Baja de juegos\n");
    printf("3- Modificacion de juegos\n");
    printf("4- Listado de juegos\n");
    printf("9- Alquieres\n");
    printf("10- Salir\n");
    utn_getEntero(&opcion,"\nIngrese opcion: ","\nERROR Ingrese opcion valida: ",1,10);
    return opcion;
}
/**
* \brief agrega a la lista declientes eClientes los datos coloca la bandera IsEmpty en 0
* \param Employee empleado Lista , estructra del sistema de empleados
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
int addEmployee(eCliente* user,int cantidad)
{
    int index,valDom,retorno=-1,valTel,valNom,valApe,i;
    char nombreAux[51],apellidoAux[51],telAux[21],domAux[51];
    char salida;
    index=obtenerEspacioLibre(user,cantidad);
    if(index!=-1)
    {
        do{
            system("cls");
            printf("\tALTA\n\n");
            user[index].idCliente=index+1;
            printf("ID cliente: %d\n",user[index].idCliente);
            valApe=getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            valNom=getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            valTel=getStringTelefono("Ingrese telefo: ","ERROR reingrese telefo: ",telAux);
            valDom=getStringAlfaNumerico("Ingrese Dominicilio: ","ERROR Rengrese Dominicilio: ",domAux);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
                strcpy(user[index].nombre,nombreAux);
                strcpy(user[index].apellido,apellidoAux);
                strcpy(user[index].telefono,telAux);
                strcpy(user[index].domicilio,domAux);
            if(valApe==0&&valTel==0&&valDom==0&&valNom==0){
                system("cls");
                printEmployee(user,index);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            }
        }while(salida!='s');
        user[index].isEmpty=0;
        retorno=0;
    }

    return retorno;

}
void printEmployee(eCliente* user,int i)
{
    printf("\nID: %d",user[i].idCliente);
    printf("\tNombre:%s, %s",user[i].apellido,user[i].nombre);
    printf("\tDomicilio: %s",user[i].domicilio);
    printf("\tTelefono: %s\n",user[i].telefono);
}
/** \brief busca al cliente por el id en la estructura eCliente
* \param eCliente user Lista , estructra del sistema de cliente
* \param cantidad Total de base de datos del sistema
* \param id Numero del cliente buscado
* \return Retorna -1 si no encontro al cliente su no retorna la posicion del ckiente buscado
*
*/
int findEmployeeById(eCliente* user, int cantidad,int id)
{
    int i;
    for(i=0;i<cantidad;i++){
        if(id==user[i].idCliente && user[i].isEmpty==0)
        {
            printf("\nEmpleado encontrado... \n\n");
            system("pause");
            return i;

        }
    }
    printf("Empleado no encontrado...\n\n");
    system("pause");
    return -1;
}
/** \brief modifica al empleado buscado primero preguntando que datos quiere cambiar o si desea salir
* \param Employee empleado Lista , estructra del sistema de empleados
* \param posID Numero del empleado que se desea modificar
* \return np retorno ningun valor
*
*/
void modificationEmployee(eCliente* user,int index)
{
    char apellidoAux[51],nombreAux[51],telAux[51],domAux[51];
    char salida;
    int i,opcion;
    do{
    system("cls");
    printf("DATOS DEL EMPLEADO \n");
    printEmployee(user, index);
    printf("\nQUE DESEA MODIFICAR");
    printf("\n\n1. Apellido \n");
    printf("2. Nombre\n");
    printf("3. Telefono\n");
    printf("4. Domicilio\n");
    printf("5. Todas las opciones\n");
    printf("6. Salir");
    utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","\nERROR Seleccione una opcion valida: ",1,6);
    while(opcion==0)
        utn_getEntero(&opcion,"\nERROR Seleccione una opcion valida: ","\nERROR Seleccione una opcion valida: ",1,6);
    switch(opcion){
        case 1:
            getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            for(i=0;i<51;i++){
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(user[index].apellido,apellidoAux);
                break;
            }
            break;
        case 2:
            getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(user[index].nombre,nombreAux);
                break;
            }
            break;
        case 3:
            getStringTelefono("Ingrese telefo: ","ERROR reingrese telefo: ",telAux);
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(user[index].telefono,telAux);
                break;
            }
            break;
        case 4:
            getStringAlfaNumerico("Ingrese Dominicilio: ","ERROR Rengrese Dominicilio: ",domAux);
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(user[index].domicilio,domAux);
                break;
            }
        case 5:
            getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            getStringTelefono("Ingrese telefo: ","ERROR reingrese telefo: ",telAux);
            getStringAlfaNumerico("Ingrese Dominicilio: ","ERROR Rengrese Dominicilio: ",domAux);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            if(salida=='s'){
                system("cls");
                printf("Archivo modificado...\n\n");
                system("pause");
                strcpy(user[index].telefono,telAux);
                strcpy(user[index].domicilio,domAux);
                strcpy(user[index].nombre,nombreAux);
                strcpy(user[index].apellido,apellidoAux);
                break;
            }
            break;
        case 6:
            system("cls");
            printf("Volviendo al menu principal...\n");
            system("pause");
            break;
        default:
            break;
    }
    }while(opcion !=6 );
}
