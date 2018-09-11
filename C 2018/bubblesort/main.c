#include <stdio.h>
#include <stdlib.h>
#define SIZE 8

void mostrar(char vec[], int size );
void bubbleSort (char vec[], int size, int criterio);

int main()
{

char letras[]={'a','b','c','d','c','p','O','R'};
int criterio;

printf("INGRESE EL CRITERIO DE ORDENAMIENTO:  0(de mayor a menor) o 1 (de menor a mayor)  \n");
scanf("%d",&criterio);

mostrar(letras,SIZE);
bubbleSort(letras,SIZE,criterio);
mostrar(letras,SIZE);

    return 0;
}


void mostrar(char vec[], int size)
{
    for( int i=0;i<size;i++)
    {
        printf("\n %c",vec[i]);

    }

    printf("\n\n");
}
//pasarle un criterio para que sea asc o desc
void bubbleSort (char vec[], int size, int criterio)
{
    int j;
    int aux;
    int i;

    if(criterio==0)
    {

    for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(vec[i]<vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }

    }

    }

    else
    {

     for(i=0;i<size-1;i++)
    {
        for(j=i+1;j<size;j++)
        {
            if(vec[i]>vec[j])
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
        }

    }


    }


}
