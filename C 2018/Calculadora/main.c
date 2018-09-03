#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27

int MENU();
float ingresenumero(float);
float suma();
float resta();
float producto();
float dividir();
int factorial(int);
int MENUdos();
char seguir;
float numerouno,numerodos;
int main()
{

    int opcion,banderauno=0,banderados=0,opcioncalcular;
    float ressuma,resresta,resproducto,resdividir,resfactorialA,resfactorialB;

    do{
        system("cls");
        opcion=MENU();
        switch(opcion){
            case 1:
                numerouno=ingresenumero(numerouno);
                if(seguir!=ESC){
                    banderauno=1;
                    break;
                }else{
                    seguir=0;
                    break;
                }
            case 2:
                numerodos=ingresenumero(numerodos);
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
                    printf("bandera %d y %d",banderauno,banderados);
                    printf("Le falta algun numero ");
                    getch();
                    break;
                }
                switch(opcioncalcular){
                            case 1:
                                ressuma=suma();
                                break;
                            case 2:
                                resresta=resta();
                                break;
                            case 3:
                                resproducto=producto();
                                break;
                            case 4:
                                if(numerodos!=0){
                                    resdividir=dividir();
                                    break;
                                }else{
                                    system("cls");
                                    printf("MATH ERROR");
                                    printf("\nNo es posible dividir por cero volver a intentar ");
                                    getch();
                                    break;
                                }
                            case 5:
                                if(numerouno>=1){
                                    resfactorialA=factorial(numerouno);
                                    break;
                                }else{
                                    system("cls");
                                    printf("No es posible hacer el factorial de cero o un numero negativo");
                                    getch();
                                    break;
                                }
                            case 6:
                                if(numerodos>=1){
                                    resfactorialB=factorial(numerodos);
                                    break;
                                }else{
                                    system("cls");
                                    printf("No es posible hacer el factorial de cero o un numero negativo");
                                    getch();
                                    break;
                                }
                            case 7:
                                ressuma=suma();
                                resresta=resta();
                                resproducto=producto();
                                if(numerodos!=0){
                                    resdividir=dividir();
                                }
                                if(numerouno>=1){
                                    resfactorialA=factorial(numerouno);
                                }
                                if(numerodos>=1){
                                    resfactorialB=factorial(numerodos);
                                }
                                system("cls");
                                printf("Operaciones hechas vaya a la opcion 4 para los resultados ");
                                getch();
                                break;
                            default:
                                break;
                        }
                   break;
            case 4:
                system("cls");
                numerouno=0;
                numerodos=0;
                banderauno=0;
                banderados=0;
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
float ingresenumero(float operando){
          system("cls");
          printf("Coloque un numero o 'esc' para cancelar ");
          seguir=getch();
          if(seguir!=ESC){//operador imbecil hecho por si entro por equivocacion
                scanf("%f",&operando);
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
int MENUdos(){
        int opciondos;
        printf("Calculos");
        printf("\n\n1. Suma de %.2f+%.2f",numerouno,numerodos);
        printf("\n2. Resta de %.2f-%.2f",numerouno,numerodos);
        printf("\n3. Producto de %.2f*%.2f",numerouno,numerodos);
        printf("\n4. division de %.2f/%.2f",numerouno,numerodos);
        printf("\n5. Factorial de %.0f!",numerouno);
        printf("\n6. Factorial de %.0f!",numerodos);
        printf("\n7. Hacer todos los calculos");
        printf("\n8. Cancelar");
        printf("\n\n Seleccione opcion: ");
        scanf("%d",&opciondos);
        return opciondos;
}
float suma(){
    float resultado;
    resultado=numerouno+numerodos;
    return resultado;
}
float resta(){
    float resultado;
    resultado=numerouno-numerodos;
    return resultado;
}
float producto(){
    float resultado;
    resultado=numerouno*numerodos;
    return resultado;
}
float dividir(){
    float resultado;
    resultado=numerouno/numerodos;
    return resultado;
}
int factorial(int numero){
      int b ,  fact = 1;
      for (b = numero; b > 1; b--){
            fact = fact * b;
       }
       return fact;
}
