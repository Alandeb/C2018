#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn_abm.h"
#define personal 1000

int main()
{
    Employee empleado[personal];
    int opcion;
    init(empleado,personal);
    do
    {
        opcion=menu();
        switch(opcion)
        {
            case 1:
                altaPersonal(empleado,personal);
                break;
            case 2:
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
                //system("cls");
                //printf("Opcion equivocada intente de nuevo ");
                //getch();
                break;
        }
    }while(opcion!=5);
    return 0;
}
