#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1,numero2,numero3,dato;
    printf("Ingrese primer numero: ");
    scanf("%d",&numero1);
    printf("ingrese segundo numero: ");
    scanf("%d",&numero2);
    printf("ingrese tercer numero: ");
    scanf("%d",&numero3);
    if(numero1>numero2 && numero1<numero3)
    {
        dato=numero1;
    }else if(numero2>numero1&&numero2<numero3){
        dato=numero2;
    }else{
        dato=numero3;
    }
    printf("el valor del medio es: %d",dato);
    return 0;
}
