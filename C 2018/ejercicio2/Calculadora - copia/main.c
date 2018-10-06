#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define ESC 27

int menu(float,float);
float ingreseNumero(float);
float suma(float , float);
float resta(float , float);
float producto(float , float);
float dividir(float, float);
unsigned long factorial(long);
char menuDos(float,float);

int main()
{
    int opcion,banderaUno=0,banderaDos=0,banderaTres=0;
    char opcionCalcular;
    float numeroUno=0,numeroDos=0,resSuma,resResta,resProducto,resDividir;
    unsigned long resFactorialA,resFactorialB;
    do{
        system("cls");
        opcion=menu(numeroUno,numeroDos);
        switch(opcion){
            case 1:
                numeroUno=ingreseNumero(numeroUno);
                    banderaUno=1;
                    break;
            case 2:
                    numeroDos=ingreseNumero(numeroDos);
                    banderaDos=1;
                    break;
            case 3:
                system("cls");
                if(banderaUno==1&&banderaDos==1){
                        system("cls");
                        opcionCalcular=menuDos(numeroUno,numeroDos);
                }else{
                    system("cls");
                    printf("Le falta algun numero ");
                    getch();
                    break;
                }
                switch(opcionCalcular){
                            case 'a':
                                resSuma=suma(numeroUno,numeroDos);
                                break;
                            case 'b':
                                resResta=resta(numeroUno,numeroDos);
                                break;
                            case 'c':
                                resProducto=producto(numeroUno,numeroDos);
                                break;
                            case 'd':
                                if(numeroDos!=0){
                                    resDividir=dividir(numeroUno,numeroDos);
                                    break;
                                }else{
                                    break;
                                }
                            case 'e':
                                if(numeroUno>=1){
                                    resFactorialA=factorial(numeroUno);
                                    break;
                                }
                                break;
                            case 'f':
                                if(numeroDos>=1){
                                    resFactorialB=factorial(numeroDos);
                                    break;
                                }
                                break;
                            case 'g':
                                resSuma=suma(numeroUno,numeroDos);
                                resResta=resta(numeroUno,numeroDos);
                                resProducto=producto(numeroUno,numeroDos);
                                if(numeroDos!=0){
                                    resDividir=dividir(numeroUno,numeroDos);
                                }
                                if(numeroUno>=1){
                                    resFactorialA=factorial(numeroUno);
                                }
                                if(numeroDos>=1){
                                    resFactorialB=factorial(numeroDos);
                                }
                                system("cls");
                                printf("Operaciones hechas vaya a la opcion 4 para los resultados ");
                                getch();
                                break;
                            default:
                                break;
                        }
                        banderaTres=1;
                        break;
            case 4:
                system("cls");
                if(banderaTres==1){
                switch(opcionCalcular){
                    case 'a':
                        printf("La suma de %.2f y %.2f es igual a %.2f",numeroUno,numeroDos,resSuma);
                        getch();
                        break;
                    case 'b':
                        printf("La resta de %.2f y %.2f es igual a %.2f",numeroUno,numeroDos,resResta);
                        getch();
                        break;
                    case 'c':
                        printf("El producto de %.2f y %.2f es igual a  %.2f",numeroUno,numeroDos,resProducto);
                        getch();
                        break;
                    case 'd':
                        if(numeroDos!=0){
                            printf("La division de %.2f y %.2f es igua a %.2f",numeroUno,numeroDos,resDividir);
                            getch();
                            break;
                        }else{
                            printf("MATH ERROR");
                            printf("\nNo es posible dividir por cero volver a intentar ");
                            getch();
                            break;
                         }
                    case 'e':
                         if(numeroUno>=1){
                                printf("El numero factorial de %.0f es %li",numeroUno,resFactorialA);
                                getch();
                                break;
                            }else{
                                printf("No es posible hacer el factorial de cero o un numero negativo");
                                getch();
                                break;
                            }
                    case 'f':
                        if(numeroDos>=1){
                                printf("El numero factorial de %.0f es %li",numeroDos,resFactorialB);
                                getch();
                                break;
                            }else{
                                printf("No es posible hacer el factorial de cero o un numero negativo");
                                getch();
                                break;
                            }
                    case 'g':
                        printf("La suma de %.2f y %.2f es igual a %.2f",numeroUno,numeroDos,resSuma);
                        printf("\nLa resta de %.2f y %.2f es igual a %.2f",numeroUno,numeroDos,resResta);
                        printf("\nEl producto de %.2f y %.2f es igual a  %.2f",numeroUno,numeroDos,resProducto);
                        if(numeroDos!=0){
                            printf("\nLa division de %.2f y %.2f es igua a %.2f",numeroUno,numeroDos,resDividir);
                        }else{
                            printf("\nNo es posible dividir por cero ");
                        }
                        if(numeroUno>=1){
                                printf("\nEl numero factorial de %.0f es %li",numeroUno,resFactorialA);
                        }else{
                                printf("\nNo es posible hacer el factorial de cero o un numero negativo");
                        }
                        if(numeroDos>=1){
                                printf("\nEl numero factorial de %.0f es %li",numeroDos,resFactorialB);
                        }else{
                                printf("\nNo es posible hacer el factorial de cero o un numero negativo");
                        }
                        getch();
                        break;
                    default:
                        break;
                }
                numeroUno=0;
                numeroDos=0;
                banderaUno=0;
                banderaDos=0;
                banderaTres=0;
                }

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
float ingreseNumero(float operando){
          system("cls");
          printf("Coloque un numero o 'esc' para cancelar ");
          scanf("%f",&operando);
          return operando;
}




int menu(float numeroUno,float numeroDos){
        int opcion;
        printf("MENU");
        printf("\n\n1. Ingresar 1er operando(A=%.2f)",numeroUno);
        printf("\n2. Ingresar 2do operando(B=%.2f)",numeroDos);
        printf("\n3. Calcular las operaciones");
        printf("\n4. Informar resultados");
        printf("\n5. Salir");
        printf("\n\n Seleccione opcion: ");
        scanf("%d",&opcion);
        return opcion;

}
char menuDos(float numeroUno,float numeroDos){
        char opcion;
        system("cls");
        printf("Calculos");
        printf("\n\nA) Suma de %.2f+%.2f",numeroUno,numeroDos);
        printf("\nB) Resta de %.2f-%.2f",numeroUno,numeroDos);
        printf("\nC) Producto de %.2f*%.2f",numeroUno,numeroDos);
        printf("\nD) division de %.2f/%.2f",numeroUno,numeroDos);
        printf("\nE) Factorial de %.0f!",numeroUno);
        printf("\nF) Factorial de %.0f!",numeroDos);
        printf("\nG) Hacer todos los calculos");
        printf("\n\n Seleccione opcion: ");
        scanf("%s",&opcion);
        return opcion;
}
float suma(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno+numeroDos;
    return resultado;
}
float resta(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno-numeroDos;
    return resultado;
}
float producto(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno*numeroDos;
    return resultado;
}
float dividir(float numeroUno, float numeroDos){
    float resultado;
    resultado=numeroUno/numeroDos;
    return resultado;
}
unsigned long factorial(long numero){
      unsigned long numeFact ,fact = 1;
      for (numeFact = numero; numeFact > 1; numeFact--){
            fact *=  numeFact;
       }
       return fact;
}
