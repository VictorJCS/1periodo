#include<stdio.h>
int main(){
	
	float nota1, nota2, media;
	
	printf(" Informe a nota 1: ");
	scanf("%f",&nota1);
	
	printf(" Informe a nota 2: ");
	scanf("%f",&nota2);
	
	media = ( ( nota1 * 0.2 ) + ( nota2 * 0.3 ) ) / ( 0.2 + 0.3 );
	
	printf(" O resultado da media ponderada e: %.2f", media);
	
	return 0;
}
