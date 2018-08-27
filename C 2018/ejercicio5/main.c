#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,cuadrado;
    printf("ingrese numero 1: ");
    scanf("%d",&num1);
    if(num1>0){
        cuadrado=num1*num1;
        printf("el cuadrado del numero es: %d",cuadrado);
    }else{
        printf("ERROR, el número debe ser mayor que cero");
    }
    return 0;
}
