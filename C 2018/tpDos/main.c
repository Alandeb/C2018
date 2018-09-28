#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "utn_abm.h"
#define personal 1000

int main()
{
    Employee empleado[personal];
    int opcion,alta,flag=0,auxId,valID=-1,posicionID=-1;
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
                if(flag==1){
                    printf("\tMODIFICACIONES\n\n");
                    valID=utn_getEntero(&auxId,"Ingrese ID del empleado que desea modificar: ","ERROR el id es numerico entre 1000 a 10000: ",1000,10000);
                    if(valID==0)
                    {
                        posicionID=findEmployeeById(empleado,personal,auxId);
                        if(posicionID!=-1){
                            modificationEmployee(empleado,posicionID);
                            break;
                        }
                    }
                }
                break;
            case 3:
                if(flag==1)
                {
                     system("cls");
                     printf("\tBAJA\n\n");
                     valID=utn_getEntero(&auxId,"Ingrese ID del empleado que desea remover: ","ERROR el id es numerico entre 1000 a 10000: ",1000,10000);
                     if(valID==0)
                     {
                         posicionID=findEmployeeById(empleado,personal,auxId);
                            if(posicionID!=-1){
                                removeEmployee(empleado,posicionID);
                                break;
                            }
                     }
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
