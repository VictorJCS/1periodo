#include <stdio.h>

int main(){
	
	float dado;
	
	printf(" Informe o valor do dado: ");
	scanf("%f%*c", &dado);
	
	dado ++; // mais 1 = +1
	dado --; // menos 1 = -1
	dado += 3; // mais 3 = +3
	dado -= 3; // menos 3 = -3
	dado *= 3; // vezes 3 = *3
	dado /= 3; // dividido por 3 = /3
	dado >  0; // maior que zero
	dado >= 0; // maior ou igual a zero
	dado <  0; // menor que zero
	dado <= 0; // menor ou igual a zero
	dado == 0; // igual a zero
	dado != 0; // diferente de zero
	
	printf(" O valor do dado e: %.2f ", dado);
	
	return 0;	
}
