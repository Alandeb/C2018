#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int num1,num2,producto,cuadrado;
    do{
    printf("ingrese numero 1: ");
    scanf("%d",&num1);
    }while(num1==0);
    do{
    printf("ingrese numero 2: ");
    scanf("%d",&num2);
    }while(num2==0);
    producto=num1*num2;
    cuadrado=num1*num1;
    printf("el producto es: %d",producto);
    printf("\ny el cuadrado de primero es: %d",cuadrado);
    return 0;



}
