#include<stdio.h>
#include<string.h>

struct Endereco{

	int cep;
	char cidade[100];
	char rua[100];
	char bairro[50];
};

typedef struct Endereco endereco;

struct Horario{
	
	int hora;
	int minutos;
	int segundos;
};

typedef struct Horario horario;

struct Servico{
	
	int ano;
	int mes;
	char dia;
};

typedef struct Servico servico;

struct Cliente{
	
	char nome[200];
	Endereco endereco;
	Horario horario;
	Servico servico;
	char descricao[1000];
};

typedef struct Cliente arrombado;

int codigo;

int main(){

	Cliente arrombado1;
	Cliente arrombado2;

	printf(" Deseja registrar um serviço? sim[1] nao[2] ");
	scanf("%i",&codigo);
	if(codigo==1){
	printf("Informe o nome do cliente:");
	scanf("%s", &arrombado1.nome);
	printf("Informe o endereco.\n");
	printf("Informe o cep:");
	scanf("%i",&arrombado1.endereco.cep);
	printf("Informe a cidade:");
	scanf("%s",&arrombado1.endereco.cidade);
	printf("Informe a bairro:");
	scanf("%s",&arrombado1.endereco.bairro);
	printf("Informe a rua:");
	scanf("%s",&arrombado1.endereco.rua);
}
	Cliente arrombado2={"Rodrigo",{246,"Gaysland","No rego","frango"}};
	
	printf("\n Nome:%s \n cep:%i,\n Cidade:%s,\n Bairro:%s,\n Rua:%s",Cliente.arrombado2.nome,Cliente.arrombado2.cep,Cliente arrombado2.ciedade,Cliente.arrombado2.bairro,Cliente.arrombado2.rua);
	
	
	return 0;
}
