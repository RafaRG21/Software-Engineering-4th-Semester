#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 4
int main(){
	int numeros[N];
	int i;
	int maximo, minimo;
	minimo = 1000;
	maximo = 0;
	for(i=0;i<N;i++){
		if(numeros[i]<minimo)
		   minimo = numeros[i];
		if(numeros[i]>maximo);
		maximo = numeros[i];   
	}	
    printf("Maximo %d",maximo); 
	return 1;
}
