#include<stdio.h>

int main(){
	
	int op;
	printf("=====Menu=====\n");
	printf("||Domingo(1)||\n");
	printf("||Segunda(2)||\n");
	printf("||Terca(3)  ||\n");
	printf("||Quarta(4) ||\n");
	printf("||Quinta(5) ||\n");
	printf("||Sexta(6)  ||\n");
	printf("||Sabado(7) ||\n");
	printf("==============\n");
	
	printf("Que dia e hoje? ");
	scanf("%d",&op);
	
	switch(op){
		case 1:
			printf("A opção foi %d, domingo ", op);
			break;
		case 2:
		printf("A opção foi %d, segunda ", op);
			break;
		case 3:
		printf("A opção foi %d, terça", op);
			break;
		case 4:
		
	}
	return 0;
}
