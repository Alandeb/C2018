#include <stdio.h>
#include <stdlib.h>

#define CANT 3

struct eEmpleado{
    int legajo;
    int isEmpty;
    char nombre[31];
    float salario;
};

int main(){
    struct eEmpleado emple[CANT];
    int i;

    for(i=0; i<CANT; i++){
        printf("Legajo:\n");
        scanf("%d", &emple[i].legajo);

        printf("Nombre:\n");
        fflush(stdin);
        scanf("%s", emple[i].nombre);

        printf("Salario:\n");
        scanf("%f", &emple[i].salario);

        emple[i].isEmpty = 0;
    }


    system("cls");
    for(i=0; i<CANT; i++){
        printf("%d\t%s\t\t%.2f\n", emple[i].legajo, emple[i].nombre, emple[i].salario);
    }


    return 0;
}
