#include <stdio.h>
#include <stdlib.h>

int main()
{
   int numero,contadornegativo=0,contadorpositivo=0;
   int rept;

   for(rept=0; rept<10; rept++){
        printf(" ingrese un numero ");
        scanf("%d",&numero);
        if(numero>=0){
            contadorpositivo++;
        }else{
            contadornegativo++;d

        }
   }
   printf("los positivos son: %d\ny los negativos son: ",contadorpositivo, contadornegativo);

   /*
   printf("los positivos son: %d",contadorpositivo);
   printf(" y los negativos son: %d",contadornegativo);
   */
   return 0;
}
