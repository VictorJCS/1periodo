#include<stdio.h>
#include<locale.h>
int main(){
	setlocale(LC_ALL,"portuguese");
	
	int sistema,sist_produto;
	float produto,total_compra;
	char codigo,nome;
	
	total_compra == 0;
	
	printf("Deseja iniciar o sistema? \n Sim[1] Não[2] \n");
	scanf("%d",&sistema);
	
	while(sistema==1){
	
		printf("Deseja efetuar uma compra? \n Sim[1] Não[2] \n");
		scanf("%d",&sist_produto);
			
			while(sist_produto==1){
			
				printf("Quanto custa o produto? \n");
				scanf("%f",&produto);
			
				printf("Deseja adicionar outro produto? \n Sim[1] Não[2] \n");
				scanf("%d",&sist_produto);
				
				total_compra = total_compra + produto;		
				
			
			
				printf("O total da compra foi: %.2f",total_compra);
				
			}
		
		printf("\nDeseja encerrar o sistema? \n Sim[2] Não[1] \n");
		scanf("%d",&sistema);
	}
	
	printf("Sistema encerrado.\n");
	
	printf("\n O somatório de vendas do dia foi: %.2f",total_compra);
	
	return 0;
}
