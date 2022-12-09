// Ejercicio 3
#include<stdlib.h>
#include<stdio.h>
int main(){
	int i;
	char palabra[32];
	
	for(i=0;i<5;i++)
	    palabra[i] = 65 + i;
	    
	palabra[4] = 0;
	
	for(i=0;i<5;i++)
	    printf("%c",palabra[i]);
	    
	printf("\n");
	
	printf("%s\n",palabra);
	return 1;
}
