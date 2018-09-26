#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int getNumeroAleatorio(int desde , int hasta);
int main()
{
    int i;
    srand(time(NULL));
    for(i=0;i<20;i++){
    printf("%d\n",getNumeroAleatorio(1000,10000));
    printf("%d\n",getNumeroAleatorio(1000,10000));
    printf("%d\n",getNumeroAleatorio(1000,10000));
    printf("%d\n",getNumeroAleatorio(1000,10000));
    }
    return 0;
}
int getNumeroAleatorio(int desde , int hasta)
{
    //srand(time(NULL));
    int diferencia=hasta - desde;
    return desde + (rand() % diferencia);
}
