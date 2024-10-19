	#include<stdio.h>
	int main(){
		float i, j;
		i=0; j=1;
		while(i<=2.2){
			if((i>0&&i<1)||(i>1&&i<2)||(i>2.1&&i<2.2)){
				printf("I=%.1f J=%.1f \n",i , j+i);
				printf("I=%.1f J=%.1f \n",i , j+i+1);
				printf("I=%.1f J=%.1f \n",i , j+i+2);
				
			}else{
				printf("I=%d J=%d \n",int(i) ,int(j+i));
				printf("I=%d J=%d \n",int(i) ,int(j+i+1));	
				printf("I=%d J=%d \n",int(i) ,int(j+i+2));
				}
			i+=0.2;
		}
		return 0;
	}
