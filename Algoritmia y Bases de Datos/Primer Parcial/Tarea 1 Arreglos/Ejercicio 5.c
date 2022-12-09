// Ejercicio 5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>>

int main(){
	int i;
	char palabra1[32], palabra2[32];
	printf("Escribe dos palabras: ");
	scanf("%s",palabra1);
	scanf("%s",palabra2);
	
	printf("%s vs %s\n",palabra1,palabra2);
	printf("Iguales? %s\n",(strcmp(palabra1,palabra2)==0?"Si":"No"));
	printf("Largos: %d y %d\n",strlen(palabra1),strlen(palabra2));
	printf("Concatenacion: %s\n",strcat(palabra1,palabra2));
	return 1;
}
