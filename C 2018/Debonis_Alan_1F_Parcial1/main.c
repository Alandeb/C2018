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
    int opcion,flagUno=0,alta;
    init(users,cantUser,game,cantGame);
    do
    {
        opcion=menu();
        switch(opcion)
        {
            case 1:
                alta=addUser(users,cantUser);
                system("pause");
                if(alta==0&&flagUno==0)
                    flagUno=1;
                break;
            case 2:
                if(flagUno==1){

                    menuDownModific(users,cantUser);
                }else{
                    system("cls");
                    printf("aun no ingreso ningun empleado\n");
                    system("pause");
                }
                break;
            case 3:
                if(flagUno==1){
                    menuDos(users,cantUser);
                    break;
                }else{
                    system("cls");
                    printf("aun no ingreso ningun empleado\n");
                    system("pause");
                }
                break;
     /*     case 4:
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
            system("pause");
            break;
        */
        }

    }while(opcion!= 7);
    return 0;
}
