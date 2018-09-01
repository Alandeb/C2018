#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27

int MENU();
float ingresenumero();
float numerouno,numerodos;
char seguir;
int main()
{
    int opcion,banderauno=0,banderados=0,opcioncalcular;
    do{
        system("cls");
        opcion=MENU();
        switch(opcion){
            case 1:
                numerouno=ingresenumero();

                if(seguir!=ESC){
                    banderauno=1;
                    break;
                }else{
                    seguir=0;
                    break;
                }
            case 2:
                  numerodos=ingresenumero();

                if(seguir!=ESC){

                    banderados=1;
                    break;
                }else{
                    seguir=0;
                    break;
                }
            case 3:

                if(banderauno==1&&banderados==1){
                        system("cls");
                        opcioncalcular=MENUdos();
                }else{
                    system("cls");
                    printf("Le falta un numero ");
                    getch();
                }
                break;
            case 4:
                system("cls");
                numerouno=0;
                numerodos=0;
                break;
            case 5:
                system("cls");
                printf("Hasta luego");
                break;
            default:
                break;
        }
    }while (opcion!=5);

    return 0;
}
float ingresenumero(){
          float operando;
          system("cls");
          printf("Coloque un numero: ");
          seguir=getch();
          if(seguir!=ESC){//operador imbecil hecho por si entro por equivocacion
            scanf("%f",&operando);

         }else{
            main();
         }

         return operando;

}




int MENU(){
        int opcion;
        printf("MENU");
        printf("\n\n1. Ingresar 1er operando(A=%.2f)",numerouno);
        printf("\n2. Ingresar 2do operando(B=%.2f)",numerodos);
        printf("\n3. Calcular todas las operaciones()si me da el tiempo separarlas");
        printf("\n4. Informar resultados");
        printf("\n5. Salir");
        printf("\n\n Seleccione opcion: ");
        scanf("%d",&opcion);
        return opcion;

}
