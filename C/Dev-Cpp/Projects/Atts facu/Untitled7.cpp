#include<stdio.h>

int main(){

    float chico,ze;
    int ano;
    
    ano = 0;
    chico = 1.50;
    ze = 1.10;
    
    while( chico >= ze ){
        
        ano++;
        
        chico = chico + 0.02;
        
        ze = ze + 0.03;
    
    }
    
    printf(" Sao necessarios %d anos para que Ze seja mais alto que Chico ", ano);
    
    return 0;
    
}
