#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "utn_abm.h"
void init(Employee perso[],int cantidad){
    int i;
    for (i=0;i<cantidad;i++){
        perso[i].isEmpty=1;
    }
}
int menu(){
    int opcion,flag=0;
    do{
        if(flag==1)
        {
            system("cls");
            fflush(stdin);
            printf("ERROR reingrese numero");
            getch();
        }
        flag=1;
        system("cls");
        printf("MENU");
        printf("\n\n1. Alta de personal ");
        printf("\n2. Baja de personal ");
        printf("\n3. Modificacion");
        printf("\n4. Listado de personal ");
        printf("\n5. Salir");
        printf("\n\n Seleccione opcion: ");
        scanf("%d",&opcion);

    }while(opcion<1 || opcion>5);
    return opcion;
}
void altaPersonal(Employee empleado[],int cantidad)
{
    int index,valSalario;
    index=obtenerEspacioLibre(empleado,cantidad);
    if(index!=-1)
    {
        valSalario=utn_getFloat(&empleado[index].salary,"\nIngrese D.N.I: ","\nERROR!!, Reingrese el D.N.I: ",1,99999999);
        system("cls");
        printf("Coloque sector: ");
        scanf("%d",&empleado[index].sector);
        printf("%d",empleado[index].sector);
        getch();
    }
}
int obtenerEspacioLibre(Employee perso[] , int cantidad){
    int i, retorno;
    for (i=0;i<cantidad;i++){
        if(perso[i].isEmpty==1){
            retorno=i;
            break;
        }
        else{
            system("cls");
            retorno=-1;
            printf("Limite de registro alcanzado ");
            getch();
            break;
        }
    }
    return retorno;
}
static int getInt(int* pBuffer)
{
    return scanf("%d",pBuffer);
}
static float getFloat(float* pBuffer)
{
    return scanf("%f",pBuffer);
}
static char getCaracter(char* pBuffer)
{
    return scanf("%c",pBuffer);
}
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,
                    int min, int max ,int reintentos )
{

    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getFloat(&bufferFloat) == 1) &&
                (bufferFloat >= min && bufferFloat <= max))
            {
                *pFlotante = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}


int utn_getEntero(  int* pEntero, char* msg,
                    char* msgErr,int min, int max,
                    int reintentos)

{
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) &&
                (bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);//limpia en linux como fflush
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}

int utn_getCaracter(  char* pCaracter, char* msg,
                    char* msgErr,char letraUno,char letraDos,
                    int reintentos)

{
    int retorno=-1;
    char bufferChar;
    if( msg != NULL && msgErr != NULL
        && (letraUno>=0||letraUno<=255)&& (letraDos>=0||letraDos<=255) && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            fflush(stdin);
            if( (getCaracter(&bufferChar) == 1) &&
                (bufferChar >= letraUno && bufferChar <= letraDos))
            {

                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);//limpia en linux como fflush
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}
