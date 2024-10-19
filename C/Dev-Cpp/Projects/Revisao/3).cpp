#include<stdio.h>
#include<stdlib.h>
int main(){
	float num1, num2, div;
	
	printf(" Informe um numero: ");
	scanf("%f",&num1);
	
	printf(" Informe outro numero diferente de zero: ");
	scanf("%f",&num2);
	
	div = num1 / num2;
	
	printf(" O resultado da diuvisao do primeiro numero pelo segundo e: %.2f", div);
	
}
