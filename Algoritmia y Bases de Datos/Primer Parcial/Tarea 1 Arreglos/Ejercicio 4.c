// Ejercicio 4
#include<stdio.h>
#include<stdlib.h>

int main(){
	int i;
	char palabra[32];
	
	for(i=0;i<10;i++)
	    palabra[i] = 65+i;

    palabra[i]=0; 
	printf("%s\n",palabra);
	palabra[4] = 0;
	printf("%s\n",palabra);

	return 1;
}
