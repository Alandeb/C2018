#ifndef GET_H_INCLUDED
#define GET_H_INCLUDED

int utn_getEntero(  int* pEntero, char* msg,char* msgErr);
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min, int max);
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr);


#endif
