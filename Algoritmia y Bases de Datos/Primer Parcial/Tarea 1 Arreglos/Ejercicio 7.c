//Ejercicio 7
#include<stdlib.h>
#include<stdio.h>
#define N 5
int main(){
	int maiz[N][N], i,j;
	printf("Ingresar datos de la matriz: \n");
	for(i=0;i<N;i++){
	    for(j=0;j<N;j++){
	    	printf("[%d][%d]: ",i,j);
	    	scanf("%d",&maiz[i][j]);
		}
    }
	for(i=0;i<N;i++){
	    for(j=0;j<N;j++){
	        printf("%10d",maiz[i][j]);
	    }	printf("\n");
}
	return 1;
}
