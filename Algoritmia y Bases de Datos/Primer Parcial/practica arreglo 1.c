#include<stdlib.h>
#include<stdio.h>
int main(){
	int numeros[10];
	int i;
	numeros[0]=0;
	for(i=1;i<10;i++)
	numeros[i]=numeros[i-1]+1;
	for(i=0;i<10;i++)
	printf("%d\n",numeros[i]);
	return i;
}
