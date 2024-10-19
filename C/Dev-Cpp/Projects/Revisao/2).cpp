#include<stdio.h>

int main(){
	
	float num1, num2, num3, mult;
	
	printf(" Informe um numero: ");
	scanf("%f",&num1);
	
	printf(" Informe outro numero: ");
	scanf("%f",&num2);
	
	printf(" Informe o ultimo numero: ");
	scanf("%f",&num3);
	
	mult = num1 * num2 * num3;
	
	printf(" O resultado da multiplicacao dos 3 numeros e: %.2f",mult);
	
}
