#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char nombre[31];
    printf("nombre: ");
    fflush(stdin);
    gets(nombre);
    //scanf("%[^\n]",nombre);
    //strcpy(nombre,"alan damian debonis");
    printf("%s",nombre);
    return 0;
}
