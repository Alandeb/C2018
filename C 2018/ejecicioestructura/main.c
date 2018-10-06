#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "persona.h"
//#include "get.h"
#define cant 200
/*
1) Realizar una agenda para guardar los datos de hasta 200 personas de las cuales se toman los siguientes datos:

Apellido
Nombre
DNI (NO SE PUEDE REPETIR)
fechaNac
isEmpty
a- Realizar un programa con un menú de opciones para hacer altas, bajas y modificaciones (ABM) de una agenda.
b- Mostrar un listado ordenado por Apellido
*/

int main()
{
    int opcion;
    ePersona per[cant];
    init (per, cant);
    do{

            case 1:
                persona_alta(per,cant);
                break;
            case 2:
                //persona_baja(per,cant);
                break;
            default:
                break;
        }

    }while(opcion!=5);

    return 0;
}


