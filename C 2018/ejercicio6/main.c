#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero,contadornegativo=0,contadorpositivo=0;
   for(int rept=0;rept<10;rept++){
        printf(" ingrese un numero ");
        scanf("%d",&numero);
        if(numero>=0){
            contadorpositivo++;
        }else{
            contadornegativo++;
        }
   }
   printf("los positivos son: %d",contadorpositivo);
   printf(" y los negativos son: %d",contadornegativo);
   return 0;
}
