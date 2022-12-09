// Ejercicio 1
#include<stdlib.h>
#include<stdio.h>

int main(){
	int numeros[10];
	int i;
	int *p;
	printf("Ingresa 10 numeros: \n");
	for(p=numeros;p<(numeros+10);p++)
	    scanf("%d",p);
	
	for(i=0;i<10;i++)
     	printf("%d\n",numeros[i]);

	return 1;
}
