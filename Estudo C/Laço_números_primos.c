#include <stdio.h>
#include <math.h>
int main(){
    int vet[3], i, j, k, primo;
    
    for(i=0;i<2;i++){
        
        printf("Informe o valor do vetor ");
        scanf("%d", &vet[i]);
        
    }
    for(j=0; j<2; j++){
        
        primo=1;
        
        if(vet[j]<=1){
            
            primo=0;
         
            
        }else{
            for(int k=2; k<=sqrt(vet[j]);k++){
                if(vet[j]%k==0){
                    primo=0;
                    break;
                }
            }
        }
        if(primo){
            printf("O valor %d esta no indice %d\n",vet[j],j+1);
        }
    }
    
    return 0;
}