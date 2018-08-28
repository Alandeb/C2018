#include <stdio.h>
#include <stdlib.h>

int main()
{
    float radio,longitud,area;
    printf("ingrese el radio del circulo ");
    scanf("%f",&radio);
    longitud=2*3.1415*radio;
    area=3.1415*radio*radio;
    printf("la longitud del circulo es %.2f y el area es %.2f",longitud,area);



    return 0;
}
