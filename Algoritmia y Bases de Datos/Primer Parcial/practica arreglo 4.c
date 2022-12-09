#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 4
int main(){
	int numeros[N];
	int i;
	double sum,parit,pgeom;
	sum=0;
	pgeom=1;
	for(i=0;i<N;i++){
		sum = sum + numeros[i];
	}	
	parit = 1.0 * sum / N;
	pgeom = pow(pgeom,1.0 / N);
	printf("%f",pgeom);
	return 1;
}
