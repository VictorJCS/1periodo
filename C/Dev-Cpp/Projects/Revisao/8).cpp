#include<stdio.h>

int main(){
	
	float peso_kg, peso_g;
	
	printf(" Informe o peso: ");
	scanf("%f",&peso_kg);
	
	peso_g = peso_kg * 1000;
	
	printf(" O peso em grama e: %.2f gramas",peso_g);
	
	return 0;
}
