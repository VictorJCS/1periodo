#include<stdio.h>

int main(void){

	int vetor[7] = { 55, 81, 96, 107, 115, 124, 130};
	int escolha;
	
	printf(" Escolha um numero dos que estao disponiveis ");
	scanf("%d", &escolha);

	for(int i=0; i<7; i++){
		
		if(vetor[i]==escolha){	
			printf(" A posicao e: %d ", i);
			break;
		}
	}
	return 0;
}
