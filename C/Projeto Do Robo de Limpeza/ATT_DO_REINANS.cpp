#include<stdio.h>
int main (){
    int G, Gi, Gg, i, Vi, Vg, E;
    Vi=0;
    Vg=0;
    E=0;
        while(1){
            scanf("%d%d", &Gi, &Gg);
            if(Gi>Gg){
                Vi++;
            }else if(Gg>Gi){
                Vg++;
            }else{
                E++;
            }
            i++;
            printf("Novo grenal(1-sim 2-nao):");
            scanf("%d",&G);
            if(G==2){
			break;
			}
        }
        printf("%d grenais\n",i);
        printf("Inter: %d\n",Vi);
        printf("Gremio: %d\n",Vg);
        printf("Empates: %d\n",E);
        if(Vi>Vg){
    		printf("Inter venceu mais");
        }else if(Vg>Vi){
           printf("Gremio venceu mais");
        }else{
           printf("Nao houve vencerdor");
        }
    return 0;
}
