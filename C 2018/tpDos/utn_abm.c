#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "utn_abm.h"
int getInt(int* pBuffer)
{
    fflush(stdin);
    return scanf("%d",pBuffer);
}
int getFloat(float* pBuffer)
{
    fflush(stdin);
    return scanf("%f",pBuffer);
}
void getString(char msg[],char* pBuffer)
{
    printf("%s",msg);
    fflush(stdin);
    gets(pBuffer);//lo intente con fgets pero no podia tomar el dato lo siento
}
int getCaracter(char* pBuffer)
{
    fflush(stdin);
    return scanf("%c",pBuffer);
}

void init(Employee* perso,int cantidad){
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
            printf("ERROR OPCION INCORRECTA");
            getch();
        }else
            flag=1;
        system("cls");
        printf("\tMENU");
        printf("\n\n1. Alta de personal ");
        printf("\n2. Modificacion");
        printf("\n3. Baja de personal ");
        printf("\n4. Informacion del personal ");
        printf("\n5. Salir");
        printf("\n\n Seleccione opcion: ");
        getInt(&opcion);

    }while(opcion<1 || opcion>5);
    return opcion;
}
int addEmployee(Employee empleado[],int cantidad)
{
    int index,valSal,retorno=-1,valSec,valNom,valApe,i,idAux;
    char nombreaux[51],apellidoaux[51];
    char salida;
    index=obtenerEspacioLibre(empleado,cantidad);
    srand(time(NULL));
    if(index!=-1)
    {
        do{
            system("cls");
            printf("\tALTA\n\n");
            do{
                idAux=getNumeroAleatorio(1000,10000);
                for (i=0;i<cantidad;i++){
                    if(empleado[i].id==idAux)
                        break;
                }
            }while(i!=cantidad);
            empleado[index].id=idAux;
            printf("ID aleatoria: %d",empleado[index].id);
            valApe=getStringLetras("Ingrese el apellido: ","ERROR!! reingrese apellido: ",apellidoaux);
            valNom=getStringLetras("Ingrese el nombre: ","ERROR!! reingrese nombre: ",nombreaux);
            valSec=utn_getEntero(&empleado[index].sector,"\nIngrese el sector: ","ERROR!!, Reingrese el sector: ",1,25);
            valSal=utn_getFloat(&empleado[index].salary,"Salario: ","ERROR!!, Reingrese el salario: ",1);
            for(i=0;i<51;i++){
                nombreaux[i]=tolower(nombreaux[i]);
                apellidoaux[i]=tolower(apellidoaux[i]);
            }
            strcpy(empleado[index].name,nombreaux);
            strcpy(empleado[index].lastName,apellidoaux);
            if(valApe==0&&valSec==0&&valSal==0&&valNom==0){
                system("cls");
                printf("\nID: %d",empleado[index].id);
                printf("\tNombre: %s , %s",empleado[index].lastName,empleado[index].name);
                printf("\tSector: S0%d",empleado[index].sector);
                printf("\tSalario: %.2f",empleado[index].salary);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR incorrecto precione S o N ",'s','n');
            }
        }while(salida!='s');
        empleado[index].isEmpty=0;
        retorno=0;
    }

    return retorno;
}
int removeEmployee(Employee* empleado, int cantidad, int id)
{
    int i,retorno;

 return retorno;
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

int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min)
{
    int retorno=-1;
    float bufferFloat;
    if(pFlotante != NULL && msg != NULL && msgErr != NULL&& min >= 1)
    {
        do
        {
            printf("%s",msg);
            if( (getFloat(&bufferFloat) == 1) &&(bufferFloat >= min))
            {
                *pFlotante = bufferFloat;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);
    }
    return retorno;
}


int utn_getEntero(  int* pEntero, char* msg,char* msgErr,int min, int max)
{
    int retorno=-1;
    int bufferInt;
    if(pEntero != NULL && msg != NULL && msgErr != NULL&& min <= max)
    {
        do
        {
            printf("%s",msg);
            if( (getInt(&bufferInt) == 1) &&(bufferInt >= min && bufferInt <= max))
            {
                *pEntero = bufferInt;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);//limpia en linux como fflush
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int getStringLetras(char* msg,char* msgErr,char* pBuffer)
{
    char aux[51];
    int retorno=-1;
    do{
        getString(msg,aux);
        if(esSoloLetras(aux))
        {
            strcpy(pBuffer,aux);
            retorno=0;
            break;
        }
     msg=msgErr;
    }while(retorno!=0);
    return retorno;
}
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr,char letraUno,char letraDos)

{
    int retorno=-1,devuelve;
    char bufferChar;
    if( msg != NULL && msgErr != NULL&& (letraUno>=0||letraUno<=255)&& (letraDos>=0||letraDos<=255) )
    {
        do
        {
            printf("%s",msg);
            fflush(stdin);
            devuelve=getCaracter(&bufferChar);
            bufferChar=tolower(bufferChar);
            if( ( devuelve == 1)&&(bufferChar == letraUno || bufferChar == letraDos))
            {
                *pCaracter = bufferChar;
                retorno = 0;
                break;
            }
            else
            {
                fflush(stdin);
                msg=msgErr;
            }
        }while(retorno!=0);

    }
    return retorno;
}
int getNumeroAleatorio(int desde , int hasta)
{
    //srand(time(NULL));
    return desde + (rand() % (hasta +1-desde));
}
