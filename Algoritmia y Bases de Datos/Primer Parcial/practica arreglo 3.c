#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define N 4
int main(){
	int numeros[N];
	int i;
	double sum;
	for(i=0;i<N;i++)
		scanf("%d",&numeros[i]);
	sum=0;
	for(i=0;i<N;i++){
	sum = sum + numeros[i];		
	}
	printf("%f",sum);
	
	return 1;
}
