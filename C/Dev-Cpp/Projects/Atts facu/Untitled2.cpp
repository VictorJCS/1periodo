#include<stdio.h>
int main(){
float salario,novo_salario;
printf("Informe o salario do funcionario: ");
scanf("%f",&salario);
novo_salario = salario*(25.0/100.0);
printf("O salario com ajustes e: %f",novo_salario);
return 0;

}
