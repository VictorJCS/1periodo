#include<stdio.h>

int main(){
	
	float base_ma, base_me, altura, area;
	
	printf(" Informe a base maior: ");
	scanf("%f",&base_ma);
	
	printf(" Informe a base menor: ");
	scanf("%f",&base_me);
	
	printf(" Informe a altura: ");
	scanf("%f",&altura);
	
	area = ((base_ma + base_me) * altura) / 2;
	
	printf(" A area do trapezio e: %.2f", area);
}
