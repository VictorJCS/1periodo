#include<stdio.h>
int main(){
int ano_n, ano_a,idade,idade_2050;
printf("Informe o ano de nascimento: ");
scanf("%d",&ano_n);
printf("Informe o ano atual: ");
scanf("%d",&ano_a);
idade = ano_a - ano_n;
printf("A idade da pessoa e: %d \n",idade);
idade_2050 = 2050 - ano_n;
printf("A idade que a pessoa tera em 2050 e: %d",idade_2050);
return 0;

}
