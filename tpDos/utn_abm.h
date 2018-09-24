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
void altaPersonal(Employee empleado[],int cantidad);
int obtenerEspacioLibre(Employee perso[] , int cantidad);
int menu();
#endif // UTN_ABM_H_INCLUDE
