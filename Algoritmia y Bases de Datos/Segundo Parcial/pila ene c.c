/*Ejercicio 1: Hacer un programa para agregar números enteros a una pila, 
hasta que el usuario lo decida, después mostrar todos los números 
introducidos en la pila.*/
#include<stdlib.h>
#include<stdio.h>


typedef struct Nodo{
	char dato;
	struct Nodo *siguiente;
}tipoNodo;
typedef tipoNodo *pnodo;
typedef tipoNodo *Pila;
void push(Pila*, char);
int pop(Pila*);
void mostrarpila(Pila);
void borrarpila(Pila *pila);
int main(){
	Pila pila = NULL;
	int cont=0,opc,i;
	char nodo;
	do{
		printf("\n1.-Insertar un caracter a la pila\n");
		printf("2.-Mostrar elementos de la pila\n");
		printf("3.-Salir\n");
		printf("Opcion a elegir: ");
		scanf("%d",&opc);
		while(getchar()!='\n');
		switch(opc){
			case 1:
				printf("Ingresar nodo: ");
		        scanf("%c",&nodo);
	         	push(&pila,nodo);
				break;
			case 2: 
			    while(pila!=NULL){
				   printf("%c",pop(&pila));
			    }
			    break;
			case 3:
			borrarpila(&pila);   
		 
		}	
       

	}while(opc!=3);

	
	return 0;
}
void push(Pila *pila,char n){
	pnodo nuevo = (pnodo)malloc(sizeof(tipoNodo));
	nuevo->dato = n;
	nuevo->siguiente = *pila;
	*pila = nuevo;
	
}
int pop(Pila *pila){
	pnodo nodo;
	int n;
	nodo = *pila;
	if(!nodo) return 0;
	*pila = nodo->siguiente;
	n = nodo->dato;
	free(nodo);
	return n;
}
void mostrarpila(Pila pila){
	pnodo nodo;
	nodo = pila;
	if(!nodo) return 0;
	while(nodo){
		printf("%c ",nodo->dato);
		nodo = nodo->siguiente;
	}printf("\n");
}
void borrarpila(Pila* pila){
	pnodo nodo;
	if(*pila) return;
	while(*pila){
	nodo = *pila;
	*pila = nodo->siguiente;
	free(nodo);
	}
}
