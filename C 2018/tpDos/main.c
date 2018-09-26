#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "utn_abm.h"
#define personal 1000

int main()
{
    Employee empleado[personal];
    int opcion,alta,flag=0,auxId;
    init(empleado,personal);
    do
    {
        opcion=menu();
        switch(opcion)
        {
            case 1:
                alta=addEmployee(empleado,personal);
                if(alta==0)
                    flag=1;
                break;
            case 2:
                if(flag=1){

                }
                break;
            case 3:
                if(flag=1)
                {
                     printf("\tBAJA\n\n");
                     printf("Coloque el ID que desea aliminar: ");
                     getInt(&auxId);
                     removeEmployee(empleado,personal,auxId);
                }
                break;
            case 4:
                break;
            case 5:
                system("cls");
                printf("HASTA LUEGO");
                break;
            default:
                break;
        }
    }while(opcion!=5);
    return 0;
}
