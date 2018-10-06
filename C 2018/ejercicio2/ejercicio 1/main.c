#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,num3,num4,num5,media;
    printf("ingrese numero: ");
    scanf("%d",&num1);
    printf("ingrese numero: ");
    scanf("%d",&num2);
    printf("ingrese numero: ");
    scanf("%d",&num3);
    printf("ingrese numero: ");
    scanf("%d",&num4);
    printf("ingrese numero: ");
    scanf("%d",&num5);
    media=(num1+num2+num3+num4+num5)/2;
    printf("la media es %d",media);
    return 0;
}
