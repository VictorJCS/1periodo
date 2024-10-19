#include<stdio.h>
int main(){
	
	float produto, produto_r;
	
	printf(" Informe o valor do produto: ");
	scanf("%f",&produto);
	
	produto_r = produto - (produto * 0.10);
	
	printf(" O valor do produto com desconto e:R$%.2f", produto_r);
	
	return 0;
}
