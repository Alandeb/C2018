#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "negocio.h"
#include "validaciones.h"
#define cantUser 100
#define cantGame 20

int main()
{
    eJuego game[cantGame];
    eCliente users[cantUser];
    eAlquileres alquiler[cantUser*cantGame];
    int opcion,flagUno=0,alta,altaDos,flagDos=0;
    init(users,cantUser,game,cantGame,alquiler);
    do
    {
        opcion=menu();
        switch(opcion)
        {
            case 1:
                alta=addUser(users,cantUser);
                if(alta==0&&flagUno==0)
                    flagUno=1;
                break;
            case 2:
                if(flagUno==1){
                    menuDownModific(users,cantUser);
                }else{
                    system("cls");
                    printf("Aun no ingreso ningun cliente\n");
                    system("pause");
                }
                break;
            case 3:
                if(flagUno==1){
                    menuDos(users,cantUser);
                    break;
                }else{
                    system("cls");
                    printf("Aun no ingreso ningun cliente\n");
                    system("pause");
                }
                break;
            case 4:
                altaDos=addGame(game,cantGame);
                if(altaDos==0&&flagDos==0)
                    flagDos=1;
                break;
            case 5:
                if(flagUno==1){
                    menuDownModificGame(game,cantGame);
                }else{
                    system("cls");
                    printf("Aun no ingreso ningun juego\n");
                    system("pause");
                }
                break;
            case 6:
                if(flagUno==1){
                    menuDosGame(game,cantGame);
                }else{
                    system("cls");
                    printf("Aun no ingreso ningun juego\n");
                    system("pause");
                }
                break;
            case 7:
                if(flagUno==1&&flagDos==1)
                {
                    addRent(alquiler,cantUser,cantGame,users,game);
                }
                else{
                    system("cls");
                    printf("Faltan datos que ingresar\n");
                    system("pause");
                }
                break;
            case 8:
                printf("HASTA LUEGO...\n");
                break;
        }
    }while(opcion!= 8);
    return 0;
}
