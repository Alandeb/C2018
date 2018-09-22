#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

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
                __fpurge(stdin);//limpia en linux como fflush
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
                __fpurge(stdin);//limpia en linux como fflush
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
            __fpurge(stdin);
            if( (getCaracter(&bufferChar) == 1) &&
                (bufferChar >= letraUno && bufferChar <= letraDos))
            {

                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                __fpurge(stdin);//limpia en linux como fflush
                printf("%s",msgErr);
            }
        }while(reintentos>=0);

    }
    return retorno;
}


















