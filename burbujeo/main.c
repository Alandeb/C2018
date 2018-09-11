#include <stdio.h>
#include <stdlib.h>
#define cant 5
int main()
{
    int pts[cant]={1,0,3,3,1};
    int dg[cant]={8,10,5,3,4};
    int auxpts,auxdg,i,j;

    for(i=0;i<cant-1;i++){
        for(j=i+1;j<cant;j++){
            if(pts[i]<pts[j]){
                auxpts=pts[i];
                pts[i]=pts[j];
                pts[j]=auxpts;
                auxdg=dg[i];
                dg[i]=dg[j];
                dg[j]=auxdg;
            }else{
                if(pts[i]==pts[j]){
                    if(dg[i]<dg[j]){
                        auxpts=pts[i];
                        pts[i]=pts[j];
                        pts[j]=auxpts;
                        auxdg=dg[i];
                        dg[i]=dg[j];
                        dg[j]=auxdg;
                    }
                }
            }


        }

    }
     for(i=0;i<cant;i++){
         printf("pts %d , dg %d\n",pts[i],dg[i]);
       }



    return 0;
}
