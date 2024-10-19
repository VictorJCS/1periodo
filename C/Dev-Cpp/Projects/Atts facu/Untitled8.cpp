#include<stdio.h>
int main(){
    float altura, peso;
    printf("Informe a peso: ");
    scanf("%f",&peso);
    if(peso<=60.0){
       printf("Informe a altura: ");
       scanf("%f",&altura);
       if(altura<1.20){
       printf("A sua classificacao e: A");
       }if(altura>=1.20 && altura<=1.70){
       printf("A sua classificacao e: B");
       }if(altura>1.70){
       printf("A sua classificacao e: C");
        }
        }
    if(peso>60.0 && peso<90){
        printf("Informe a altura: ");
        scanf("%f",&altura);
        printf("Informe a altura: ");
        scanf("%f",&altura);
       if(altura<1.20){
       printf("A sua classificacao e: D");
       }if(altura>=1.20 && altura<=1.70){
       printf("A sua classificacao e: E");
       }if(altura>1.70){
       printf("A sua classificacao e: F");
        }
        }
    if(peso>90){
       printf("Informe a altura: ");
       scanf("%f",&altura);
       if(altura<1.20){
       printf("A sua classificacao e: G");
       }if(altura>=1.20 && altura<=1.70){
       printf("A sua classificacao e: H");
       }if(altura>1.70){
       printf("A sua classificacao e: I");
        }
        }   
    return 0;
}
