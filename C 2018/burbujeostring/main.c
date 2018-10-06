#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 5

typedef struct{
    char name[51];
}Employees;
void Sorted_Data(Employees people[], int i);

int main()
{
    Employees per[LEN];
    for(int i=0;i<LEN;i++){
        printf("nombre: \n");
        fflush(stdin);
        fgets(per[i].name, 51 , stdin);
        per[i].name[strcspn(per[i].name, "\n")] = 0;
    }
    Sorted_Data(per,0);
    for(int i=0;i<LEN;i++){
        printf("%s\n",per[i].name);
    }
    return 0;
}
void Sorted_Data(Employees people[], int i)
{
    Employees aux;

    for(i=0 ; i<LEN; i++)
    {
        for(int j=0 ; j<LEN-1 ; j++)
        {
            if(stricmp(people[j].name,people[i].name)>0)
            {
                aux = people[i];
                people[i] = people[j];
                people[j] = aux;
            }
        }
    }
}
