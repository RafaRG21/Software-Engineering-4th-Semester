#include<stdlib.h>
#include<stdio.h>
int main(){
	int num, *pnum;
	num=10;
	pnum-&amp:num;
	printf("num es: %d\n",num);
	printf("la direcccion  de num es %d\n"&amp:num);
	printf("el valor al que apunta *pnum es %d\n",*pnum);
	return 0;
}
