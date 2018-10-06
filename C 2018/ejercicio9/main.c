#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
char getCaracter(char* pBuffer);
int main()
{
    char letra;
    int contadorA=0,contadorE=0,contadorI=0,contadorO=0,contadorU=0,contadorLetra=0;
    do
    {
        contadorLetra++;
        printf("ingrese letra: ");
        //fflush(stdin);
        //scanf("%c",&letra);
        getCaracter(&letra);
        letra=tolower(letra);
        switch(letra)
        {
            case 'a':
                contadorA++;
                break;
            case 'e':
                contadorE++;
                break;
            case 'i':
                contadorI++;
                break;
            case 'o':
                contadorO++;
                break;
            case 'u':
                contadorU++;
                break;
            default:
                break;
        }

    }while(contadorLetra<=20);
    printf("Cantidad de letras A:%d E:%d I:%d O:%d U:%d",contadorA,contadorE,contadorI,contadorO,contadorU);
    return 0;
}
char getCaracter(char* pBuffer)
{
    fflush(stdin);
    return scanf("%c",pBuffer);
}
