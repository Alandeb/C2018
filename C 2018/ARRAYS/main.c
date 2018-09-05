#include <stdio.h>
#include <stdlib.h>
#define cantidad 5

int main()
{
    int  edad[cantidad],i;
    float salario[cantidad];
    for(i=0;i<cantidad;i++){
        printf("Ingrese edad: ");
        scanf("%d",&edad[i]);
        printf("Ingrese salario: ");
        scanf("%f",&salario[i]);
    }
     for(i=0;i<cantidad;i++){
        printf("edad: %d\n",edad[i]);
        printf("salario: %.2f\n",salario[i]);
     }

    return 0;
}
