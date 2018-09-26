#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "utn_abm.h"
#define personal 1000

int main()
{
    Employee empleado[personal];
    int opcion,alta;
    init(empleado,personal);
    do
    {
        opcion=menu();
        switch(opcion)
        {
            case 1:
                alta=addEmployee(empleado,personal);
                break;
            case 2:
                if(alta==0){

                }
                break;
            case 3:
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
