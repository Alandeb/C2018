#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


#define CANTIDAD_EMPLEADOS 6

int main()
{
    int edades[CANTIDAD_EMPLEADOS] ;
    float salario[CANTIDAD_EMPLEADOS];
    char caracter[CANTIDAD_EMPLEADOS];

    int i;
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        //if(utn_getEntero(&edades[i],"\nEdad?","\nEdad fuera de rango",0,200,2)==-1)
        //{
         //   edades[i] = -1;
        //}
        //utn_getFloat(&salario[i],"\nSalario?","\nSalario incorrecto",0,100578,2);
        utn_getCaracter(&caracter[i],"\nletra?","\nletra incorrecta",'f','n',2);
    }
    for(i=0;i<CANTIDAD_EMPLEADOS;i++)
    {
        //printf("\nSalario es: %.2f",salario[i]);
        printf("\n%c",caracter[i]);
    }


    return 0;
}






