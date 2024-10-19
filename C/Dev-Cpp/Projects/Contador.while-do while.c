#include<stdio.h>
int main(){
	int n1,n2;
	printf("Informe 2 numeros distintos");
	scanf("%d %d",&n1,&n2);
	if(n1>n2){
		while(n1>n2){
			printf("%d\n",n1);
			n1--;
		}
	}else if(n1<n2){
		do{
			printf("%d\n",n1);
			n1++;
			}while(n1<n2);
	}else{
			printf("Os numeros so iguais");
	}
	return 0;
}
