#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int num1,num2,resta;
    do{
    printf("ingrese numero 1: ");
    scanf("%d",&num1);
    }while(num1==0);
    do{
    printf("ingrese numero 2: ");
    scanf("%d",&num2);
    }while(num2==0);
    resta=num1-num2;
    if(resta>0){
        printf("el resultado es positivo %d",resta);
    }else{
        printf("el resultado es negativo %d",resta);
    }
    return 0;
}
