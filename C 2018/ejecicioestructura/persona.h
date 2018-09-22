#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

typedef struct {//anidamiento se usa para declarar una estructura es como struct pero se va a llamar solo por el nombre final
// por ejemplo este es eFecha
    int dia,mes,anio;

}eFecha;

typedef struct{
    char apellido[31];
    char nombre[31];
    float DNI;
    eFecha fechaNac;
    int isEmpty;

}ePersona;

void init(ePersona[],int);
void persona_baja(ePersona [], int cantidad);
void persona_alta(ePersona [], int cantidad);
int obtenerEspacioLibre(ePersona[] , int cantidad);
void ordenamiento(ePersona perso[], int cantidad );

#endif
