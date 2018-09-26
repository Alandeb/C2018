#ifndef UTN_ABM_H_INCLUDE
#define UTN_ABM_H_INCLUDE

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;
void init(Employee perso[],int cantidad);
int addEmployee(Employee empleado[],int cantidad);
int getNumeroAleatorio(int desde , int hasta);
int obtenerEspacioLibre(Employee perso[] , int cantidad);
int esSoloLetras(char str[]);
int getStringLetras(char* msg,char* msgErr,char* pBuffer);
int utn_getFloat(float *pFlotante, char* msg ,char* msgErr,int min);
int utn_getEntero(  int* pEntero, char* msg,char* msgErr,int min, int max);
int utn_getCaracter(  char* pCaracter, char* msg,char* msgErr,char letraUno,char letraDos);
int menu();
#endif // UTN_ABM_H_INCLUDE
