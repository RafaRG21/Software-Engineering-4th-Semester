#include<stdlib.h>
#include<stdio.h>
int main(){
	static int a[]={2,5,7,4,5,1};
	int *px, *py;
	px =&a[0];
	py=&a[2];
	printf("los valores de %d x %d es %d\n",*px,*py,*px**py);
	printf("el res es %d",(*px+3));
	
}
