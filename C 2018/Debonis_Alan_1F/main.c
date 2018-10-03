#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "negocio.h"
#include "validaciones.h"
#define cantUser 100
#define cantGame 20

int main()
{
    eJuego game[cantGame];
    eCliente users[cantUser];
    int opcion,flagUno=0,alta,valID,posicionID,auxId;
    init(users,cantUser,game,cantGame);
    do
    {
        opcion=menu();
        switch(opcion)
        {

        case 1:
            alta=addEmployee(users,cantUser);
            system("pause");
            if(alta==0&&flagUno==0)
                flagUno=1;
            break;
       case 2:
                if(flagUno==1){
                    do{
                        system("cls");
                        printf("\tMODIFICACIONES\n\n");
                        valID=utn_getEntero(&auxId,"Ingrese ID del cliente que desea modificar,o ingrese 0 para volver al menu principal: ","ID incorrecto. Ingrese un id del 1 al 100 o 0 para salir: ",1,100);
                        if(valID==0)
                        {
                            posicionID=findEmployeeById(users,cantUser,auxId);
                            if(posicionID!=-1){
                                modificationEmployee(users,posicionID);
                                break;
                            }
                        }else
                            break;
                    }while(posicionID==-1);
                }else{
                    system("cls");
                    printf("aun no ingreso ningun empleado\n");
                    system("pause");
                }
                break;
     /*   case 3:
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
        case 8:
            mostrarAlmuerzos(almuerzos, 21, lista, 10, comidas, 5);
            system("pause");
            break;
        case 9:
            mostrarAlmuerzosEmpleado(almuerzos, 21, lista, 10, comidas, 5, sectores, 5);
            system("pause");
            break;
        case 10:
            break;*/
        }

    }while(opcion!= 10);
    return 0;
}
