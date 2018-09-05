
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
        //fflush(stdin);
        //scanf("%c",&opcion);
        opcion = getche();
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
