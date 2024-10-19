#include <stdio.h>

int main(){
    int vet[3], i, j, k, primos, ehPrimos, cont = 0;

    for(i = 0; i < 2; i++){
        printf("Informe o valor do vetor ");
        scanf("%d", &vet[i]);
    }

    for(j = 0; j < 2; j++){
        int ehPrimo = 1; // Inicialmente assumimos que o número é primo
        if (vet[j] <= 1) {
            ehPrimo = 0; // Números menores ou iguais a 1 não são primos
        } else {
            for(int k = 2; k <= vet[j] / 2; k++){
                if(vet[j] % k == 0){
                    ehPrimo = 0;
                    break;
                }
            }
        }

        if(ehPrimo){
           int primos;
            primos = vet[j];
            printf("O valor %d esta no indice %d\n", primos, j + 1);
        }
    }
    
    return 0;
}