// Ejercicio 2
#include<stdlib.h>
#include<stdio.h>

int main (){
	int numeros[10];
	int i;
	int *p;
	numeros[0] = 0;
	for(i=1;i<10;i++)
		numeros[i] = numeros[i-1] + 1;
		
	for(p=numeros;p<(numeros+10);p++)
	    printf("%d\n",*p);

	return 1;	
	
}
