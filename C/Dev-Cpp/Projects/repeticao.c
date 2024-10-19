#include<stdio.h>
int main(){
	char nome[50];
	int cont=0;
	for(cont=0; cont<3; cont++){
		printf("Informe um nome: ");
		scanf("%49s", &nome);
	}
	return 0;
}
