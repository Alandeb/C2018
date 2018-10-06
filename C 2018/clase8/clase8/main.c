#include <stdio.h>
#include <stdlib.h>

struct eEmpleado{
    int legajo;
    int isEmpty;
    char nombre[31];
    float salario;
};

int main(){
    struct eEmpleado emple;
    printf("Legajo:\n");
    scanf("%d", &emple.legajo);

    printf("Nombre:\n");
    fflush(stdin);
    scanf("%s", emple.nombre);

    printf("Salario:\n");
    scanf("%f", &emple.salario);

    emple.isEmpty = 0;

    system("cls");

    printf("%d\t%s\t\t%.2f", emple.legajo, emple.nombre, emple.salario);

    return 0;
}
