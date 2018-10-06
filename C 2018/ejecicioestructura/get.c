#include <stdio.h>
#include <stdlib.h>
#include "get.h"

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
/*int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min, int max)
{

    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && msg != NULL && msgErr != NULL && min <= max)
    {
        do
        {
            system("cls");
            fflush(stdin);
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
                //fflush(stdin);//limpia en linux como fflush
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}


int utn_getEntero(  int* pEntero, char* msg,
                    char* msgErr,int min, int max)

{
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL
        && min <= max )
    {
        do
        {
            fflush(stdin);
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
*/
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr)
{
    int retorno=-1;
    char bufferChar;
    if( msg != NULL && msgErr != NULL)
    {
        do
        {

            fflush(stdin);
            printf("%s",msg);
            if( (getCaracter(&bufferChar) == 1) &&
                (bufferChar >= letraUno && bufferChar <= letraDos))
            {

                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
               msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}


