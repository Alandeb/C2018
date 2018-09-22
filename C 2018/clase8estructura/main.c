#include <stdio_ext.h>
#include <stdlib.h>
struct eEmpleado{
    int legajo;
    float salario;
    char nombre[31];// el nombre del array es la direccion de memoria del comienzo del array no necesita & para declarar un scan ya es como puntero
    int isEmpty;
};

int main()
{
    struct eEmpleado emple[2];// se declara la variable entonces esto guarda el dato si lo declaro como un
    //array de estructura voy variando entre cada uno con un for para guardar cosas diferente
    // esto es mejor para guardar muchos datos ya que no conviene ponerle a cada tipo de variable un array ej legajo[5]
    // lo mejor es poner struct eEmpleado emple[5];
    int i;
    for(i=0;i<2;i++){
    printf("Legajo: \n");
    scanf("%d",&emple[i].legajo);
    printf("Nombre: \n");
    __fpurge(stdin);
    scanf("%s",emple[i].nombre);// no necesito & al ser array ,usar fgets
    printf("Salario: \n");
    scanf("%f",&emple[i].salario);
    emple[i].isEmpty=0;
    }
    system("clear");//como system cls pero en linux
    for(i=0;i<2;i++){
    printf("Legajo: %d\t\tNombre: %s\t\tSalario: %.2f\n",emple[i].legajo,emple[i].nombre,emple[i].salario);
    }


    return 0;
}
