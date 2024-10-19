#include<stdio.h>
int main(){
	char nome[50];
	int cont=0;
	for(cont=3){
		printf("Informe um nome: \n");
		scanf("%s[49]",nome);
	}
	return 0;
}
