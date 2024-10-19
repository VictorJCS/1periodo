#include<stdio.h>

int main(){
	
	float base, altura, area;
	
	printf(" Informe a base: ");
	scanf("%f",&base);
	
	printf(" Informe a altura: ");
	scanf("%f",&altura);
	
	area =  base * altura;
	
	printf(" A area do quadrado e: %.2f", area);
}
