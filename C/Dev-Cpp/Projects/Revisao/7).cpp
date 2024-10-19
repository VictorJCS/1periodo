#include<stdio.h>
int main(){
	
	float peso, peso_ema, peso_eng;
	
	printf(" Informe o peso: ");
	scanf("%f",&peso);
	
	peso_eng = peso + (peso * 0.20);
	
	peso_ema = peso - (peso * 0.15);
		
	printf(" O peso se o paciente engodar 20 porcento e: %.2f kg", peso_eng);
	printf(" O peso se o paciente emagrecer porcento e: %.2f kg", peso_ema);
	
	return 0;
}
