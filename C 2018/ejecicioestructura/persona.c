#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "persona.h"
#include "get.h"

void init(ePersona perso[],int cantidad){
    int i;
    for (i=0;i<cantidad;i++){
        perso[i].isEmpty=1;
    }
}
void persona_alta(ePersona perso[], int cantidad){
    int index;
    index=obtenerEspacioLibre(perso ,cantidad);
    if(index!=-1){
        //utn_getFloat(&perso[index].DNI,"\nIngrese D.N.I: ","\nERROR!!, Reingrese el D.N.I: ",1,99999999);

        printf("ingrese nombre: ");
        fgets(perso[index].nombre,sizeof(perso[index].nombre)-2,stdin);
       // getString(&perso[index].nombre);

        //fflush(stdin);
        //gets(perso[index].nombre);
        //printf("%s",perso[index].nombre);
        //getch();


    }
}
/*void persona_baja(ePersona perso[], int cantidad){
    int i ;
    long int dniaux;
}*/
int obtenerEspacioLibre(ePersona perso[] , int cantidad){
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
/*void ordenamiento(ePersona perso[], int cantidad ){
    ePersona persoaux;
    int i,j;
    for(i=0;i<cantidad-1;i++){
        for(j=i+1;j<cantidad;j++){
            if((stricmp(perso[i].apellido,perso[j].apellido))>0){
                persoaux=perso[i];
                perso[i]=perso[j];
                perso[j]=persoaux;
            }
            else{
                if((stricmp(perso[i].apellido,perso[j].apellido))==0){
                    if((stricmp(perso[i].nombre,perso[j].nombre))>0){
                    persoaux=perso[i];
                    perso[i]=perso[j];
                    perso[j]=persoaux;
                    }
                }
            }
        }
    }
}

*/
