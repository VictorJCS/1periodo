#include<stdio.h>
int main(){
	char nome[50];
	float num1, num2, media;
	int cont=1;
	while(cont==1){
		printf("Informe o nome do aluno: ");
		scanf("%s[49]", &nome);
		printf("Informe a primeira nota do aluno: ");
		scanf("%f", &num1);
		printf("Informe a segunda nota do aluno: ");
		scanf("%f", &num2);
		media=(num1+num2)/2;
		if(media>=7){
			printf("O aluno foi aprovado com a media: %.1f\n", media);
		}
		else if(media<7&&media>=5){
			printf("O aluno foi para a recuperacao com a media: %.1f\n", media);
		}
		else{
			printf("O aluno foi reporvado com a media: %.1f\n", media);
		}
		printf(" Deseja registrar outro aluno? sim[1] nao[2]");
		scanf("%d", &cont);
	}
	return 0;
}
