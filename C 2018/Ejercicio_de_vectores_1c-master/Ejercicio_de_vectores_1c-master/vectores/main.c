#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define T 2

void cargarAlumnos(int[], char[][21], int[], float[], int);
void mostrarAlumnos(int[], char[][21], int[], float[], int);

-ordenar nombre
-muestre los alumnos aprobados (nota>6)
-muestre los alumnos que se llaman Juan
-muestre los alumnos cuyo nombre comienzan con P
-El alumno con mas nota (sabiendo que puede ser mas que uno)
-"EL mas mediocre legajo=100 nota=5 se llame pepe medir 1.75"
-Ingresar un legajo y permitir la modificacion de la nota

(transformar la carga de datos en una carga aleatoria)

int main()
{
    int legajos[T];
    char nombres[T][21];
    int notas[T];
    float alturas[T];
    char mail[T][50];
    int i;

    cargarAlumnos(legajos, nombres, notas, alturas, T);
    mostrarAlumnos(legajos, nombres, notas, alturas, T);


}

void cargarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &legajos[i]);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombres[i]);
        printf("Ingrese nota: ");
        scanf("%d", &notas[i]);
        printf("Ingrese altura: ");
        scanf("%f", &alturas[i]);

    }
}

void mostrarAlumnos(int legajos[], char nombres[][21], int notas[], float alturas[], int tam)
{
    int i;
     printf("%4s %20s %2s %5s\n","Legajo","Nombre","Nota","Altura");
    for(i=0; i<tam; i++)
    {
        printf("%4d %20s %2d %5f\n", legajos[i], nombres[i], notas[i], alturas[i] );

    }
}


