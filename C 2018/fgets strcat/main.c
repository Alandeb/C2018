#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nombre[31];
    char apellido[31];
    char apenom[62];
    int cantidad,i;
    printf("nombre: ");
    fgets(nombre,sizeof(nombre)-2,stdin);
    cantidad = strlen(nombre);
    nombre[cantidad-1] = '\0';
    printf("apellido: ");
    fgets(apellido,sizeof(apellido)-2,stdin);
    cantidad = strlen(apellido);
    apellido[cantidad-1] = '\0';
    //strlwr(apellido);
    //apellido[0]=toupper(apellido[0]);
    //strlwr(nombre);
    //nombre[0]=toupper(nombre[0]);
    strlwr(nombre);
    nombre[0]=toupper(nombre[0]);
    for(i=0;i<cantidad;i++){
        if(nombre[i]==" "&&nombre[i+1]!='\0'){
            nombre [i+1]=toupper(nombre[i+1]);
        }
    }
    strcpy(apenom,apellido);
    strcat(apenom," ");
    strcat(apenom,nombre);
    //apenom[0]='\0';
    //strcat(apenom,apellido);de ambas forma funciona pone primero el apellido despues el nombre son 2 maneras de hacerlo
    //strcat(apenom," ");yo para poder sacar la basura tengo que igualar apenom a algo por ejemplo strcpyy que quiero qwue se le copie
    //strcat(apenom,nombre);y borre la basura , depues con strcat concateno las variables en el orden que lo quiera mostrar
    printf("%s",apenom);

    return 0;
}
