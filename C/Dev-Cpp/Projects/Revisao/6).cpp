#include<stdio.h>
int main(){
	
	float salario, comissao, salario_t, vendas;
	
	printf(" Informe o salario: R$");
	scanf("%f",&salario);
	
	printf(" Informe o total em vendas: R$");
	scanf("%f",&vendas);
	
	comissao = vendas * 0.04;
	
	salario_t= salario + comissao;
	
	printf(" O valor do produto com desconto e:R$%.2f", salario_t);
	
	return 0;
}
