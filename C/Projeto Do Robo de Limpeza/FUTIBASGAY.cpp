#include<stdio.h>
int main (){
    int G, Gi, Gg, i, Vi, Vg, E;
   	printf(" Novo grenal (1-sim 2-nao): ");
     scanf("%d",&G);
        while(G==1){
            i++;
            printf("Quantos gols o Inter fez? ");
            scanf("%d", &Gi);
            printf("Quantos gols o grêmio fez? ");
            scanf("%d", &Gg);
            if(Gi>Gg){
                Vi++;
            }else if(Gg>Gi){
                Vg++;
            }else{
                E++;
            }
        	printf(" Novo grenal (1-sim 2-nao): ");
            scanf("%d",&G);
        }
    	printf("A quantidade de grenais foram: %d \n", i);
    	printf("O numero de vitorias do Inter foram: %d \n", Vi);
		printf("O numero de vitorias do Gremio foram: %d \n", Vg);
		printf("O numero de empates foram: %d \n", E);
		if(Vi>Vg){
			printf("O inter venceu o maior numero de grenais com: %d vitoria(s).", i);
		}else if(Vg>Vi){
			printf("O gremio venceu o maior numero de grenais com: %d vitoria(s).", i);
		}else{
			printf("Nao hove vencedor pois o numero de grenais foram igualmente vencidos: %d vitoria(s) para cada.", i);
		}    
	return 0;
}

