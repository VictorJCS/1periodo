#include<stdio.h>
#include<stdlib.h>
int main(){
	float num1, num2, sub;
	
	printf(" Informe um numero: ");
	scanf("%f",&num1);
	
	printf(" Informe outro numero: ");
	scanf("%f",&num2);
	
	sub = num1 - num2;
	
	printf(" O resultado da subtracao do primeiro numero pelo segundo e: %.2f", sub);
	
}
