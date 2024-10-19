#include<stdio.h>
int main(){
	char nome[50];
	int cont;
	for(cont=0; cont>=3; cont++){
		printf("Informe um nome: \n");
		scanf("%s[49]",nome);
	}
	return 0;
}
