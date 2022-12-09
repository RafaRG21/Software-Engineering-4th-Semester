#include <stdio.h>
#include <stdlib.h>

int main() {
	const int tamarr = 5;
	int cali [] = {98,5,7,23,5};
    int i, *pcali;
	pcali = cali;
	for(i=0; i<tamarr; i++)
		printf("la calificacion %d es %d\n", i+1, *(pcali+i));
}
