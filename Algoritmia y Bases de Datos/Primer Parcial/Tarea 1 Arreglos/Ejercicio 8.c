//Ejercicio 8
#include<stdlib.h>
#include<stdio.h>
#define N 5
int main(){
	int maiz[N][N];
	int i,j;
	int cantidad = 1;
	for(i=0;i<N;i++)
	    for(j=0;j<N;j++){
	        maiz[i][j] = cantidad;
	        cantidad *= 2;
        }
	for(i=0;i<N;i++){
	    for(j=0;j<N;j++)
	        printf("%10d ",maiz[i][j]);
	printf("\n");    
    }
	return 1 ;
}
