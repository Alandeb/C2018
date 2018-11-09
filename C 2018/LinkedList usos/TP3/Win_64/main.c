/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


typedef struct
{

    char nombre[20];
    int edad;

} ePersona;

ePersona* newPersona();
ePersona* newPersonaParam(char* nombre, int edad);
void mostrarPersona ( ePersona* unaPersona);
void mostrarPersonas ( LinkedList* lista);

int main()
{
    LinkedList* lista;
      LinkedList* lista2;

    ePersona* p1, *p2, *p3, *p4, *p5, *p6, *auxPersona;

    p1 = newPersonaParam("Juan", 25);
    p2 = newPersonaParam("Martin", 18);
    p3 = newPersonaParam("Ana", 23);
    p4 = newPersonaParam("Julia", 37);
    p5 = newPersonaParam("Maria", 28);
    p6 = newPersonaParam("Marcos", 31);




    lista = ll_newLinkedList();

    if(lista == NULL)
    {
        exit(1);
    }

    printf("Cantidad: %d\n", ll_len(lista));

    ll_add(lista, p1);
    ll_add(lista, p2);
    ll_add(lista, p3);
    ll_add(lista, p4);


    printf("Cantidad: %d\n", ll_len(lista));

  //  auxPersona = (ePersona*) ll_get(lista, 2);

  //  mostrarPersona(auxPersona);

  mostrarPersonas(lista);
    printf("\n\n");

  ll_push(lista, 2, p5);

printf("Cantidad: %d\n", ll_len(lista));
   mostrarPersonas(lista);

   printf("\n\n");

    ll_set(lista, 3, p6);// set solo sirve para pisar el push lo colaca al final si lo pongo en el orden correcto
     mostrarPersonas(lista);

   printf("\n\n");
   //printf("Cantidad: %d\n", ll_len(lista));

   ll_remove(lista, 0);

    mostrarPersonas(lista);

   printf("\n\n");

   //ll_clear(lista);

   // printf("Cantidad: %d\n", ll_len(lista));


    int posicion;

    posicion = ll_indexOf(lista, p6);

     printf("pos: %d\n", posicion);

   lista2 = ll_subList(lista, 1, 4);


   mostrarPersonas(lista2);

    printf("\n\n");


    lista2 = ll_clone(lista);


     mostrarPersonas(lista2);

    printf("\n\n");


   // ll_sort();












    return 0;
}


ePersona* newPersona()
{

    ePersona* persona;

    persona = (ePersona*) malloc(sizeof(ePersona));

    if(persona != NULL)
    {
        strcpy(persona->nombre, "");
        persona->edad = 0;
    }

    return persona;
}


ePersona* newPersonaParam(char* nombre, int edad)
{

    ePersona* persona;

    persona = newPersona();

    if(persona != NULL)
    {
        strcpy(persona->nombre, nombre);
        persona->edad = edad;
    }

    return persona;
}

void mostrarPersona ( ePersona* unaPersona)
{

    if(unaPersona != NULL)
    {
        printf("%10s  %2d\n", unaPersona->nombre, unaPersona->edad);
    }
}

void mostrarPersonas ( LinkedList* lista){

    ePersona* p;

    for(int i=0; i < ll_len(lista); i++){
            p = (ePersona*)ll_get(lista, i);
        mostrarPersona(p);
    }
}*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


typedef struct
{

    char nombre[20];
    int edad;

} ePersona;
void mostrarEmployees(LinkedList* lista);
ePersona* newPersona();
ePersona* newPersonaParam(char* nombre, int edad);
Employee* new_employee();
void mostrarPersona ( ePersona* unaPersona);
void mostrarPersonas ( LinkedList* lista);
void mostrarEmployee(Employee* emp);
int main()
{
    LinkedList* lista;
    ePersona* p1, *p2, *p3, *p4, *p5;
    FILE* f;




    lista = ll_newLinkedList();
 /*   p1 = newPersonaParam("Juan", 25);
    p2 = newPersonaParam("Martin", 18);
    p3 = newPersonaParam("Ana", 23);
    p4 = newPersonaParam("Julia", 37);
    p5 = newPersonaParam("Maria", 28);


    if(lista == NULL)
    {
        exit(1);
    }

    printf("Cantidad: %d\n", ll_len(lista));

    ll_add(lista, p1);
    ll_add(lista, p2);
    ll_add(lista, p3);
    ll_add(lista, p4);
    ll_add(lista, p5);

    f = fopen("personas.bin", "wb");

    ePersona* p;

    for(int i=0; i< ll_len(lista); i++){

    p = (ePersona*)ll_get(lista, i);

    fwrite(p, sizeof(ePersona), 1, f);

    }

    fclose(f);



    ePersona* auxPersona;


    int cant;
    f = fopen("personas.bin", "rb");

    while(!feof(f)){

        auxPersona = newPersona();

        cant = fread(auxPersona, sizeof(ePersona), 1, f);

        if(cant < 1){
            break;
        }

        ll_add(lista, auxPersona);

    }

    fclose(f);

    mostrarPersonas(lista);
*/


//    ePersona* auxPersona;
//    Employee* auxEmployee;
//    char buffer[4][50];
//    int cant;
//
//    f = fopen("data.csv", "r");
//    fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
//   do{
//
//       // auxPersona = newPersona();
//
//        cant =fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
//
//        if(cant == 4){
//            auxEmployee= new_employee();
//            auxEmployee->id=atoi(buffer[0]);
//            strcpy(auxEmployee->nombre,buffer[1]);
//            auxEmployee->horasTrabajadas=atoi(buffer[2]);
//            auxEmployee->sueldo=atoi(buffer[3]);
//           ll_add(lista, auxEmployee);
//
//        }
//
//   } while(!feof(f));
////
////    f = fopen("data.bin", "rb");
////    //fscanf(f,"%[^,],%[^,],%[^,],%[^\n]\n",buffer[0],buffer[1],buffer[2],buffer[3]);
////   do{
////
////         auxEmployee= new_employee();
////
////        cant = fread(auxEmployee, sizeof(Employee), 1, f);
////         printf("%d %15s %d %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
////      //   system("pause");
////        //if(cant == 1){
////
////            ll_add(lista, auxEmployee);
////        //}
////
////
////    } while(!feof(f));
//
//    //fclose(f);
//
//   fclose(f);
////
//   mostrarEmployees(lista);
//
//    f = fopen("data.bin", "wb");
//
//    Employee* p;
//
//    for(int i=0; i< ll_len(lista); i++){
//
//        p = (Employee*)ll_get(lista, i);
//
//        fwrite(p, sizeof(Employee), 1, f);
//
//    }
//
//    fclose(f);

    Employee* auxEmployee=(Employee*) calloc (1,sizeof(Employee)  );

    if(auxEmployee!= NULL)
    {

       // persona->id=0;
       // strcpy(persona->nombre, " ");
        //persona->horasTrabajadas=0;
        //persona->sueldo=0;
        printf("%d %15s %d %d\n",auxEmployee->id,auxEmployee->nombre,auxEmployee->horasTrabajadas,auxEmployee->sueldo);
        system("pause");
    }


    return 0;
}


ePersona* newPersona()
{

    ePersona* persona;

    persona = (ePersona*) malloc(sizeof(ePersona));

    if(persona != NULL)
    {
        strcpy(persona->nombre, "");
        persona->edad = 0;
    }

    return persona;
}


ePersona* newPersonaParam(char* nombre, int edad)
{

    ePersona* persona;

    persona = newPersona();

    if(persona != NULL)
    {
        strcpy(persona->nombre, nombre);
        persona->edad = edad;
    }

    return persona;
}

void mostrarPersona ( ePersona* unaPersona)
{

    if(unaPersona != NULL)
    {
        printf("%10s  %2d\n", unaPersona->nombre, unaPersona->edad);
    }
}



void mostrarPersonas ( LinkedList* lista){

    ePersona* p;

    for(int i=0; i < ll_len(lista); i++){
            p = (ePersona*)ll_get(lista, i);
        mostrarPersona(p);
    }

}

Employee* new_employee(){
    Employee* persona;
        persona = (Employee*) malloc(sizeof(Employee));

    if(persona != NULL)
    {
        persona->id=0;
        strcpy(persona->nombre, " ");
        persona->horasTrabajadas=0;
        persona->sueldo=0;
//        //persona->id = 0;
      // persona->horasTrabajadas=0;
      //persona->sueldo=0;

    }

    return persona;

}





void mostrarEmployee(Employee* emp){
    if(emp!=NULL){
        printf("%d %15s %d %d\n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    }
}
void mostrarEmployees(LinkedList* lista){
       Employee* p;

    for(int i=0; i < ll_len(lista); i++){
            p = (Employee*)ll_get(lista, i);
        mostrarEmployee(p);
    }
}
