#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(  int* pEntero, char* msg,
                    char msgErr[],int min, int max,
                    int reintentos);
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,
                    int min, int max ,int reintentos );
int utn_getCaracter(  char* pCaracter, char* msg,
                    char* msgErr,char letraUno,char letraDos,
                    int reintentos);

#endif // UTN_H_INCLUDED
