#include<stdio.h>
int main(){
float nota1, nota2, nota3, media;
printf("Informe a primeira nota: ");
scanf("%f", &nota1);

printf("Informe a segunda nota: ");
scanf("%f", &nota2);

printf("Informe a terceira nota: ");
scanf("%f", &nota3);

media =	(nota1 + nota2 + nota3)/3;

if(media >=7){
	
	printf(" Aprovado com a media de: %.1f", media);
	
}
else{
	
	printf(" Reprovado com a media de: %.1f", media);

}

return 0;

}
