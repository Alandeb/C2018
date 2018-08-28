#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27

int main()
{
    char seguir;
    int max,min,numero,bandera;
    bandera=0;
    do
    {
        system("cls");
        printf("ingrese numeros  ");
        scanf("%d",&numero);

        if(bandera==0)
        {
            max=numero;
            min=numero;
            bandera=1;

        }else{
            if(numero>max){
                max=numero;
            }
            if(numero<min){
                min=numero;
            }
        }
        printf("toque escape para terminar o cualquier letra para seguir ");
        seguir=getch();


    }while(seguir!=ESC);
    printf("\nel numero minimo es: %d \nel numero maximo es: %d",min,max);
    return 0;
}
