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
    fgets(pBuffer, 51 , stdin);
    pBuffer[strcspn(pBuffer, "\n")] = 0;
    //gets(pBuffer);//lo intente con fgets pero no podia tomar el dato lo siento
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
    int index,valSal,retorno=-1,valSec,valNom,valApe,i;
    char nombreAux[51],apellidoAux[51];
    char salida;
    index=obtenerEspacioLibre(empleado,cantidad);
    srand(time(NULL));
    if(index!=-1)
    {
        do{
            system("cls");
            printf("\tALTA\n\n");
            empleado[index].id=validRamdonNumber(empleado,cantidad);
            printf("ID aleatoria: %d\n",empleado[index].id);
            valApe=getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
            valNom=getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
            valSec=utn_getEntero(&empleado[index].sector,"Ingrese sector (1 a 25): ","ERROR!!, Reingrese el sector: ",1,25);
            valSal=utn_getFloat(&empleado[index].salary,"Ingrese salario: ","ERROR!!, Reingrese el salario: ",1);
            for(i=0;i<51;i++){
                nombreAux[i]=tolower(nombreAux[i]);
                apellidoAux[i]=tolower(apellidoAux[i]);
            }
            strcpy(empleado[index].name,nombreAux);
            strcpy(empleado[index].lastName,apellidoAux);
            if(valApe==0&&valSec==0&&valSal==0&&valNom==0){
                system("cls");
                printEmployee(empleado,index);
                utn_getCaracter(&salida,"\n\nSi los datos son correctos preciones 'S' o 'N' para re ingresarlos: ","ERROR tecla incorrecta precione S o N: ",'s','n');
            }
        }while(salida!='s');
        empleado[index].isEmpty=0;
        retorno=0;
    }

    return retorno;
}
void printEmployee(Employee* empleado,int i)
{
    printf("\nID: %d",empleado[i].id);
    printf("\tSector: S0%d",empleado[i].sector);
    printf("\tNombre: %s, %s",empleado[i].lastName,empleado[i].name);
    printf("\tSalario: %.2f$",empleado[i].salary);
}
int findEmployeeById(Employee* empleado, int cantidad,int id)
{
    int i;
    for(i=0;i<cantidad;i++){
        if(id==empleado[i].id && empleado[i].isEmpty==0)
        {
            printf("\nEmpleado encontrado... \n\n");
            printEmployee(empleado, i);
            return i;
        }
    }
    printf("Empleado no encontrado...\n\n ");
    return -1;
}
void modificationEmployee(Employee* empleado,int posID)
{
    char apellidoAux[51],nombreAux[51];
    char salida;
    int i;
    printf("ID : %d\n",empleado[posID].id);
    getStringLetras("Ingrese el apellido: ","ERROR solo debe poseer letras!! reingrese apellido: ",apellidoAux);
    getStringLetras("Ingrese el nombre: ","ERROR solo debe poseer letras!! reingrese nombre: ",nombreAux);
    utn_getEntero(&empleado[posID].sector,"Ingrese sector (1 a 25): ","ERROR!!, Reingrese el sector: ",1,25);
    utn_getFloat(&empleado[posID].salary,"Ingrese salario: ","ERROR!!, Reingrese el salario: ",1);
    for(i=0;i<51;i++){
        nombreAux[i]=tolower(nombreAux[i]);
        apellidoAux[i]=tolower(apellidoAux[i]);
    }
    strcpy(empleado[posID].name,nombreAux);
    strcpy(empleado[posID].lastName,apellidoAux);
    utn_getCaracter(&salida,"\n\nDesea realizar estas modificaciones S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
    if(salida=='s'){
        system("cls");
        printf("Archivo modificado...\n\n");
        system("pause");
    }else{
        printf("Volviendo al menu...\n\n");
        system("pause");
    }
}
void removeEmployee(Employee* empleado,int posID)
{
    char salida;
    utn_getCaracter(&salida,"\n\nDesea eliminar el archivo del empleado S/N: ","ERROR tecla incorrecta precione S o N: ",'s','n');
    if(salida=='s'){
        system("cls");
        printf("El empleado ha sido eliminado...\n\n");
        system("pause");
        empleado[posID].id=0;
        empleado[posID].isEmpty=1;
      }else{
        printf("Volviendo al menu...\n\n");
        system("pause");
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
int validRamdonNumber(Employee empleado[],int cantidad)
{
    int i,idAux;
     do{
            idAux=getNumeroAleatorio(1000,10000);
            for (i=0;i<cantidad;i++){
                if(empleado[i].id==idAux)
                  return -1;

                }
        }while(i!=cantidad);
    return idAux;
}
int getNumeroAleatorio(int desde , int hasta)
{
    //srand(time(NULL));
    return desde + (rand() % (hasta +1-desde));
}

