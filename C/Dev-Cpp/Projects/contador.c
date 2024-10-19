#include<stdio.h>
int main(){
	int n1,n2,i;
	printf("Informe dois numeros");
	scanf("%d %d",&n1,&n2);
	if (n1>n2){
		for( i=n1;i>=n2;i--){
			printf("%d\n",i);
		}
	}else if(n1<n2){
		for(i=n1;i<=n2;i++){
			printf("%d\n",i);
		}
	}else{
			printf("Os numeros sao iguais");
	}
	return 0;
}
