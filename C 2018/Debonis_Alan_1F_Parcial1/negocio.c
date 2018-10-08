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
 * \param eCliente user Lista,estructura del sistema de clientes
 * \param cantidad de veces que debe interar
 * \return no retorna nada es vacio
 */
void init(eCliente* user,int cantidad,eJuego* game,int cantJuego,eAlquileres* alquiler)
{
    int i;
    for (i=0;i<cantidad;i++){
        user[i].isEmpty=1;
    }
    for (i=0;i<cantJuego;i++){
        game[i].isEmpty=1;
    }
    for (i=0;i<cantidad*cantJuego;i++){
        alquiler[i].isEmpty=1;
    }
}
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta
* \param eCliente user Lista , estructra del sistema de clientes
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
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \return Retorna la posicion en la que hay espacio libres
*/
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
/**
* \brief Obtiene el espacio libre en la que la bandera isEmplty esta
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \return Retorna la posicion en la que hay espacio libres
*/
int obtenerEspacioLibreAlquiler(eAlquileres* rent , int cantidad,int cantiGame){
    int i, retorno=-1;
    for (i=0;i<cantidad*cantiGame;i++){
        if(rent[i].isEmpty==1){
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
    printf("2- Modificacion y Baja de clientes\n");
    printf("3- Listado de clientes\n");
    printf("4- Alta de juegos\n");
    printf("5- Modificacion y Baja de juegos\n");
    printf("6- Listado de juegos\n");
    printf("7- Alquiler\n");
    printf("8- Salir\n");
    utn_getEntero(&opcion,"\nIngrese opcion: ","\nERROR Ingrese opcion valida: ",1,8);
    return opcion;
}
/**
* \brief agrega a la lista declientes eClientes los datos coloca la bandera IsEmpty en 0
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
int addUser(eCliente* user,int cantidad)
{
    int index,valDom,retorno=-1,valTel,valNom,valApe,i;
    char nombreAux[51],apellidoAux[51],telAux[21],domAux[51];
    char salida;
    index=obtenerEspacioLibre(user,cantidad);
    if(index!=-1)
    {
        do{
            system("cls");
            printf("***ALTA***\n\n");
            user[index].idCliente=index+1;
            printf("Codigo de cliente: %d\n",user[index].idCliente);
            valApe=getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            valNom=getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            valTel=getStringTelefono("Ingrese telefo: ","ERROR reingrese telefo: ",telAux);
            valDom=getStringAlfaNumerico("Ingrese Domicilio: ","ERROR Rengrese Domicilio: ",domAux);
            for(i=0;i<51;i++){
                nombreAux[i]=toupper(nombreAux[i]);
                apellidoAux[i]=toupper(apellidoAux[i]);
            }
                strcpy(user[index].nombre,nombreAux);
                strcpy(user[index].apellido,apellidoAux);
                strcpy(user[index].telefono,telAux);
                strcpy(user[index].domicilio,domAux);
            if(valApe==0&&valTel==0&&valDom==0&&valNom==0){
                system("cls");
                printUser(user,index);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            }
        }while(salida!='s');
        user[index].isEmpty=0;
        retorno=0;
    }

    return retorno;

}
void printUser(eCliente* user,int i)
{
    printf("\nCodigo de cliente: %d",user[i].idCliente);
    printf("\tNombre:%s, %s",user[i].apellido,user[i].nombre);
    printf("\tDomicilio: %s",user[i].domicilio);
    printf("\tTelefono: %s\n",user[i].telefono);
}
/** \brief busca al cliente por el id en la estructura eCliente
* \param eCliente user Lista , estructra del sistema de cliente
* \param cantidad Total de base de datos del sistema
* \param Codigo de cliente Numero del cliente buscado
* \return Retorna -1 si no encontro al cliente su no retorna la posicion del ckiente buscado
*/
void menuDownModific(eCliente* user,int cantidad){
    int valID,auxId,posicionID,opcion,valOpcion;
    system("cls");
    printf("***MODIFICACIONES y BAJAS DE CLIENTES***\n\n");
    printf("1- Modificaciones.\n");
    printf("2- Bajas.\n\n");
    valOpcion=utn_getEnteroEsc(&opcion,"Seleccione una opcion o 0 para volver al menu: ","ERROR Seleccione una opcion o 0 para volver al menu: ",1,2,0);
    if(valOpcion!=-1){
        switch(opcion){
            case 1:
                valID=utn_getEnteroEsc(&auxId,"Ingrese Codigo del cliente  que desea modificar,o ingrese 0 para volver al menu principal: ","Codigo de cliente incorrecto. Ingrese un Codigo de cliente del 1 al 100 o 0 para salir: ",1,100,0);
                if(valID==0)
                {
                    posicionID=findUserById(user,cantidad,auxId);
                    if(posicionID!=-1){
                        modificationUser(user,posicionID);
                        break;
                    }
                }else
                    break;
            case 2:
                system("cls");
                printf("\t***BAJA***\n\n");
                valID=utn_getEnteroEsc(&auxId,"Ingrese Codigo del cliente que desea remover,o ingrese 0 para volver al menu principal: ","Codigo de cliente incorrecto. Ingrese un Codigo de cliente del 1000 al 10000 o 0 para salir",1,100,0);
                if(valID==0)
                {
                    posicionID=findUserById(user,cantidad,auxId);
                    if(posicionID!=-1){
                        removeUser(user,posicionID);
                        break;
                    }
                }else
                    break;
        }
    }
}
/** \brief Remueve al cliente buscado por el Codigo de cliente pone la bandera isEmpty en 1
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \param posID numero exacto donde se encuantra el dato buscado
* \return no retorna ningun valor
*/
void removeUser(eCliente* user,int posID)
{
    char salida;
    printUser(user, posID);
    utn_getCaracter(&salida,"\n\nDesea eliminar el archivo del cliente S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
    if(salida=='s'){
        system("cls");
        printf("El cliente ha sido eliminado...\n\n");
        system("pause");
        user[posID].idCliente=0;
        user[posID].isEmpty=1;
      }else{
        printf("Volviendo al menu...\n\n");
        system("pause");
    }
}

int findUserById(eCliente* user, int cantidad,int id)
{
    int i;
    for(i=0;i<cantidad;i++){
        if(id==user[i].idCliente && user[i].isEmpty==0)
        {
            printf("\ncliente encontrado... \n\n");
            system("pause");
            return i;

        }
    }
    printf("cliente no encontrado...\n\n");
    system("pause");
    return -1;
}
/** \brief modifica al cliente buscado primero preguntando que datos quiere cambiar o si desea salir
* \param eCliente user Lista , estructra del sistema de clientes
* \param posID Numero del cliente que se desea modificar
* \return np retorno ningun valor
*
*/
void modificationUser(eCliente* user,int index)
{
    char apellidoAux[51],nombreAux[51],telAux[51],domAux[51];
    char salida;
    int i,opcion;
    do{
        system("cls");
        printf("DATOS DEL CLIENTE \n");
        printUser(user, index);
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
                    apellidoAux[i]=toupper(apellidoAux[i]);
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
                    nombreAux[i]=toupper(nombreAux[i]);
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
                getStringAlfaNumerico("Ingrese Domicilio: ","ERROR Rengrese Domicilio: ",domAux);
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
                getStringAlfaNumerico("Ingrese Domicilio: ","ERROR Ringrese Domicilio: ",domAux);
                for(i=0;i<51;i++){
                    nombreAux[i]=toupper(nombreAux[i]);
                    apellidoAux[i]=toupper(apellidoAux[i]);
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
/**
* \brief Acomoda el array de clientes el order indica si de mayor a menor
*         o de menor a mayor
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \param order [1] indica de mayor a menor  - [0] indica de menor a mayor
* \return ino retorna ningun valor
*/

void sortUser(eCliente* user, int cantidad ,int order){
    eCliente userAux;
    int i,j;
    if(order==0){
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if((stricmp(user[i].apellido,user[j].apellido))>0){
                    userAux=user[i];
                    user[i]=user[j];
                    user[j]=userAux;
                }else
                    if((stricmp(user[i].apellido,user[j].apellido))==0){
                        if((stricmp(user[i].nombre,user[j].nombre))>0){
                            userAux=user[i];
                            user[i]=user[j];
                            user[j]=userAux;
                        }
                    }
            }
        }
    }else{
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if((stricmp(user[i].apellido,user[j].apellido))<0){
                    userAux=user[i];
                    user[i]=user[j];
                    user[j]=userAux;
                }else
                    if((stricmp(user[i].apellido,user[j].apellido))==0){
                        if((stricmp(user[i].nombre,user[j].nombre))<0){
                            userAux=user[i];
                            user[i]=user[j];
                            user[j]=userAux;
                        }
                    }
            }
        }
    }
}
void menuDos(eCliente* user,int cantidad){
    int order=0,i;
    system("cls");
    printf("***LISTADO***\n\n");
    printf("INGRESE EL CRITERIO DE ORDENAMIENTO  0(de menor a mayor) o 1 (de mayor a menor)  \n");
    utn_getEntero(&order,"\n\n Seleccione opcion: ","\nOpcion incorrecta es entre 0 y 1: ",0,1);
    system("cls");
    sortUser(user,cantidad,order);
    for(i=0;i<cantidad;i++){
        if(user[i].isEmpty==0){
            printUser(user,i);
        }
    }
    printf("\n"),
    system("pause");
}
/**
* \brief agrega a la lista deJuegos eJuegos los datos coloca la bandera IsEmpty en 0
* \param eJuego game Lista , estructra del sistema de juegos
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/
int addGame(eJuego* game,int cantidad)
{
    int index,valDes,retorno=-1,valImp,i;
    char desAux[51];
    char salida;
    index=obtenerEspacioLibre2(game,cantidad);
    if(index!=-1)
    {
        do{
            system("cls");
            printf("***ALTA***\n\n");
            game[index].idJuego=index+1;
            printf("ID juego: %d\n",game[index].idJuego);
            valDes=getStringAlfaNumerico("Ingrese Descripcion: ","ERROR Rengrese Descripcion: ",desAux);
            valImp=utn_getFloat(&game[index].importe,"Ingrese importe: ","ERROR reingrese importe: ",1);
            for(i=0;i<51;i++){
                desAux[i]=toupper(desAux[i]);
            }
            if(valImp==0&&valDes==0){
                strcpy(game[index].descripcion,desAux);
                system("cls");
                printGame(game,index);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            }
        }while(salida!='s');
        game[index].isEmpty=0;
        retorno=0;
    }

    return retorno;

}
void printGame(eJuego* game,int i)
{
    printf("\nID: %d",game[i].idJuego);
    printf("\tDescripcion: %s",game[i].descripcion);
    printf("\tImporte: $%.2f\n",game[i].importe);
}
/** \brief busca al juego por el id en la estructura eJuego
* \param eJuego game Lista , estructra del sistema de juego
* \param cantidad Total de base de datos del sistema
* \param id Numero del juego buscado
* \return Retorna -1 si no encontro al juego su no retorna la posicion del ckiente buscado
*/
void menuDownModificGame(eJuego* game,int cantidad){
    int valID,auxId,posicionID,opcion,valOpcion;
    system("cls");
    printf("\tMODIFICACIONES y BAJAS DE juegoS\n\n");
    printf("1- Modificaciones.\n");
    printf("2- Bajas.\n\n");
    valOpcion=utn_getEnteroEsc(&opcion,"Seleccione una opcion o 0 para volver al menu: ","ERROR Seleccione una opcion o 0 para volver al menu: ",1,2,0);
    if(valOpcion!=-1){
        switch(opcion){
            case 1:
                valID=utn_getEnteroEsc(&auxId,"Ingrese ID del juego que desea modificar,o ingrese 0 para volver al menu principal: ","ID incorrecto. Ingrese un id del 1 al 20 o 0 para salir: ",1,20,0);
                if(valID==0)
                {
                    posicionID=findGameById(game,cantidad,auxId);
                    if(posicionID!=-1){
                        modificationGame(game,posicionID);
                        break;
                    }
                }else
                    break;
            case 2:
                system("cls");
                printf("***BAJA***\n\n");
                valID=utn_getEnteroEsc(&auxId,"Ingrese ID del juego que desea remover,o ingrese 0 para volver al menu principal: ","ID incorrecto. Ingrese un id del 1 al 20 o 0 para salir",1,20,0);
                if(valID==0)
                {
                    posicionID=findGameById(game,cantidad,auxId);
                    if(posicionID!=-1){
                        removeGame(game,posicionID);
                        break;
                    }
                }else
                    break;
        }
    }
}
/** \brief Remueve al juego buscado por el id pone la bandera isEmpty en 1
* \param eJuego game Lista , estructra del sistema de juegos
* \param cantidad Total de base de datos del sistema
* \param posID numero exacto donde se encuantra el dato buscado
* \return no retorna ningun valor
*/
void removeGame(eJuego* game,int posID)
{
    char salida;
    printGame(game, posID);
    utn_getCaracter(&salida,"\n\nDesea eliminar el archivo del juego S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
    if(salida=='s'){
        system("cls");
        printf("El juego ha sido eliminado...\n\n");
        system("pause");
        game[posID].idJuego=0;
        game[posID].isEmpty=1;
      }else{
        printf("Volviendo al menu...\n\n");
        system("pause");
    }
}

int findGameById(eJuego* game, int cantidad,int id)
{
    int i;
    for(i=0;i<cantidad;i++){
        if(id==game[i].idJuego && game[i].isEmpty==0)
        {
            printf("\nJuego encontrado... \n\n");
            system("pause");
            return i;

        }
    }
    printf("Juego no encontrado...\n\n");
    system("pause");
    return -1;
}
/** \brief modifica al juego buscado primero preguntando que datos quiere cambiar o si desea salir
* \param eJuego game Lista , estructra del sistema de juegos
* \param posID Numero del juego que se desea modificar
* \return np retorno ningun valor
*
*/
void modificationGame(eJuego* game,int index)
{
    char desAux[51];
    float impAux;
    char salida;
    int i,opcion;
    do{
        system("cls");
        printf("DATOS DEL juego \n");
        printGame(game, index);
        printf("\nQUE DESEA MODIFICAR\n\n");
        printf("1. Importe\n");
        printf("2. Descripcion\n");
        printf("3. Todas las opciones\n");
        printf("4. Salir");
        utn_getEntero(&opcion,"\n\nSeleccione una opcion: ","\nERROR Seleccione una opcion valida: ",1,4);
        switch(opcion){
            case 1:
                utn_getFloat(&impAux,"Ingrese importe: ","ERROR reingrese importe : ",1);
                utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
                if(salida=='s'){
                    game[index].importe=impAux;
                    system("cls");
                    printf("Archivo modificado...\n\n");
                    system("pause");
                    break;
                }
                break;
            case 2:
                getStringAlfaNumerico("Ingrese Descripcion: ","ERROR Rengrese Descripcion: ",desAux);
                utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
                if(salida=='s'){
                    system("cls");
                    printf("Archivo modificado...\n\n");
                    system("pause");
                    strcpy(game[index].descripcion,desAux);
                    break;
                }
                break;
            case 3:
                utn_getFloat(&impAux,"Ingrese importe: ","ERROR reingrese importe: ",1);
                getStringAlfaNumerico("Ingrese Descripcion: ","ERROR Rengrese Descripcion: ",desAux);
                for(i=0;i<51;i++){
                    desAux[i]=toupper(desAux[i]);
                }
                utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
                if(salida=='s'){
                    strcpy(game[index].descripcion,desAux);
                    game[index].importe=impAux;
                    system("cls");
                    printf("Archivo modificado...\n\n");
                    system("pause");
                    break;
                }
                break;
            case 4:
                system("cls");
                printf("Volviendo al menu principal...\n");
                system("pause");
                break;
            default:
                break;
        }
    }while(opcion !=4 );
}
/**
* \brief Acomoda el array de juegos el order indica si de mayor a menor
*         o de menor a mayor
* \param eJuego game Lista , estructra del sistema de juegos
* \param cantidad Total de base de datos del sistema
* \param order [1] indica de mayor a menor  - [0] indica de menor a mayor
* \return ino retorna ningun valor
*/
void sortGame(eJuego* game, int cantidad ,int order){
    eJuego gameAux;
    int i,j;
    if(order==0){
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if(game[i].importe>game[j].importe){
                    gameAux=game[i];
                    game[i]=game[j];
                    game[j]=gameAux;
                }else
                    if(game[i].importe==game[j].importe){
                        if((stricmp(game[i].descripcion,game[j].descripcion))>0){
                            gameAux=game[i];
                            game[i]=game[j];
                            game[j]=gameAux;
                        }
                    }
            }
        }
    }else{
        for(i=0;i<cantidad-1;i++){
            for(j=i+1;j<cantidad;j++){
                if(game[i].importe<game[j].importe){
                    gameAux=game[i];
                    game[i]=game[j];
                    game[j]=gameAux;
                }else
                    if(game[i].importe==game[j].importe){
                        if((stricmp(game[i].descripcion,game[j].descripcion))<0){
                            gameAux=game[i];
                            game[i]=game[j];
                            game[j]=gameAux;
                        }
                    }
            }
        }
    }
}
void menuDosGame(eJuego* game,int cantidad){
    int order=0,i;
    system("cls");
    printf("***LISTADO***\n\n");
    printf("INGRESE EL CRITERIO DE ORDENAMIENTO  0(de menor a mayor) o 1 (de mayor a menor)  \n");
    utn_getEntero(&order,"\n\n Seleccione opcion: ","\nOpcion incorrecta es entre 0 y 1: ",0,1);
    system("cls");
    sortGame(game,cantidad,order);
    for(i=0;i<cantidad;i++){
        if(game[i].isEmpty==0){
            printGame(game,i);
        }
    }
    printf("\n"),
    system("pause");
}
/**
* \brief agrega a la lista declientes eClientes los datos coloca la bandera IsEmpty en 0
* \param eCliente user Lista , estructra del sistema de clientes
* \param cantidad Total de base de datos del sistema
* \return Retorna (-1) si es error o 0 si fue correcta la carga
*/

void addRent(eAlquileres* rent,int cantidad,int cantiGame,eCliente* user,eJuego* game)
{
    int index;
    char salida;
    index=obtenerEspacioLibreAlquiler(rent,cantidad,cantiGame);
    if(index!=-1)
    {
        do{
            system("cls");
            printf("***Alquileres***\n\n");
            rent[index].idAlquier=index+1;
            printf("Codigo de alquier: %d\n",rent[index].idAlquier);
            rent[index].idCliente=selecUser(user,cantidad);
            rent[index].idJuego=selecGame(game,cantiGame);
            printf("Fecha\n");
            GetDay(rent,index);
            system("cls");
            printRent(rent[index],game,user,cantidad,cantiGame);
            utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
        }while(salida!='s');
        rent[index].isEmpty=0;
    }
}
void printRent(eAlquileres rent,eJuego* game,eCliente* user,int cantidad,int cantiGame)
{
    char descripcion[51],nombre[102];
    cargarNombre(user,cantidad,rent.idCliente,nombre);
    cargarDescripcion(game,cantiGame,rent.idJuego,descripcion);
    printf("\nID alquiler: %d",rent.idAlquier);
    printf("\tCliente: %s",nombre);
    printf("\tJuegos: %s",descripcion);
    printf("\tFecha: %d/%d/%d\n",rent.fecha.dia,rent.fecha.mes,rent.fecha.anio);
}
void sortGameRent(eJuego* game, int cantidad){
    eJuego gameAux;
    int i,j;
    for(i=0;i<cantidad-1;i++){
        for(j=i+1;j<cantidad;j++){
            if(game[i].idJuego>game[j].idJuego){
                gameAux=game[i];
                game[i]=game[j];
                game[j]=gameAux;
            }
        }
    }
}
void sortUserRent(eCliente* user, int cantidad ){
    eCliente userAux;
    int i,j;
    for(i=0;i<cantidad-1;i++){
        for(j=i+1;j<cantidad;j++){
            if(user[i].idCliente>user[j].idCliente){
                userAux=user[i];
                user[i]=user[j];
                user[j]=userAux;
            }
        }
    }
}

int selecUser(eCliente* user, int cantidad)
{
    int idUser;
    int i;
    sortUserRent(user,cantidad);
    printf("\nClientes\n\n");
    for(i=0; i < cantidad; i++)
    {
        if(user[i].isEmpty==0)
        printf("%d %s %s\n", user[i].idCliente, user[i].nombre,user[i].apellido);
    }
    utn_getEntero(&idUser,"\nSeleccione id del cliente: ","ERROR seleccione id valido: ",1,cantidad);
    for(i=0;i<cantidad;i++){
        if(idUser==user[i].idCliente && user[i].isEmpty==0)
        {
            break;
        }
        if(i==cantidad-1){
            printf("\nEl cliente no existe...");
            utn_getEntero(&idUser,"\nSeleccione id del cliente: ","ERROR seleccione id valido: ",1,cantidad);
            i=0;
        }
    }
    return idUser;

}
void GetDay(eAlquileres* rent, int cantidad)
{

    utn_getEntero(&rent[cantidad].fecha.mes,"Mes del 1 al 12: ","ERROR Mes del 1 al 12: ",1,12);
    switch(rent[cantidad].fecha.mes){
        case 2:
            utn_getEntero(&rent[cantidad].fecha.dia,"Dia del 1 al 28: ","ERROR Dia del 1 al 28: ",1,28);
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            utn_getEntero(&rent[cantidad].fecha.dia,"Dia del 1 al 30: ","ERROR Dia del 1 al 30: ",1,30);
            break;
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            utn_getEntero(&rent[cantidad].fecha.dia,"Dia del 1 al 31: ","ERROR Dia del 1 al 31: ",1,31);
            break;
    }
    utn_getEntero(&rent[cantidad].fecha.anio,"Anio del 2018 al 2030: ","ERROR Anio del 2018 al 2030: ",2018,2030);
}
int selecGame(eJuego* game, int cantidad)
{
    int idGame;
    int i;
    sortGameRent(game,cantidad);
    printf("\nJuegos\n\n");
    for(i=0; i < cantidad; i++)
    {
        if(game[i].isEmpty==0)
        printf("%d %s \n", game[i].idJuego, game[i].descripcion);
    }
    utn_getEntero(&idGame,"\nSeleccione ID de juego: ","ERROR seleccione ID valido: ",1,cantidad);
    for(i=0;i<cantidad;i++){
        if(idGame==game[i].idJuego && game[i].isEmpty==0)
        {
            break;
        }
        if(i==cantidad-1){
            printf("\nEl juego no existe...");
            utn_getEntero(&idGame,"\nSeleccione ID de juego: ","ERROR seleccione ID valido: ",1,cantidad);
            i=0;
        }
    }
    return idGame;
}
void cargarNombre(eCliente user[], int cantidad, int idCliente, char cadena[])
{
    int i;

    for(i=0; i < cantidad; i++)
    {
        if( user[i].idCliente == idCliente)
        {
            strcpy(cadena, user[i].nombre);
            strcat(cadena," ");
            strcat(cadena,user[i].apellido);
            break;
        }
    }
}
void cargarDescripcion(eJuego game[], int cantidad, int idJuego, char cadena[])
{
    int i;
    for(i=0; i < cantidad; i++)
    {
        if( game[i].idJuego == idJuego)
        {
            strcpy(cadena, game[i].descripcion);
            break;
        }
    }
}
