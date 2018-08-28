#include <stdio.h>
#include <stdlib.h>

int main()
{
    float base,altura,superficie;
    printf("base del triangulo");
    scanf("%f",&base);
    printf("altura del triangulo");
    scanf("%f",&altura);
    superficie=base*altura*0.5;
    printf("la superficie es %.2f metros",superficie);
    return 0;

}
