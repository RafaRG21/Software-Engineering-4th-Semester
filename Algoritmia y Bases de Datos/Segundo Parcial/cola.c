#include <stdio.h>
#include <stdlib.h>

// TDA Cola

typedef struct nodo{
	int valor;
	struct nodo *siguiente;
}tipoNodo;

typedef tipoNodo *pNodo;

// declarar las funciones a usar

void Anadir(pNodo *primero, pNodo *ultimo, int v);
int Leer(pNodo *primero, pNodo *ultimo);

int main(int argc, char *argv[]) {
	
	pNodo  primero=NULL, ultimo=NULL;
	
	Anadir(&primero,&ultimo,40);
	printf("<-(40)");
	
	Anadir(&primero,&ultimo,20);
	printf("<-(20)");
	
	Anadir(&primero,&ultimo,10);
	printf("<-(10)");
	
	printf("\nLeer: %d\n",Leer(&primero,&ultimo));
	printf("\nLeer: %d\n",Leer(&primero,&ultimo));
	printf("\nLeer: %d\n",Leer(&primero,&ultimo));
	
	
	
	
		
	return 0;
}


//creacion de las funciones
void Anadir(pNodo *primero, pNodo *ultimo, int v){
	
	pNodo nuevo;
	nuevo =(pNodo)malloc(sizeof(tipoNodo));
	nuevo->valor=v;
	nuevo->siguiente=NULL;
	
		if(*ultimo) (*ultimo)->siguiente=nuevo;
		*ultimo=nuevo;
		if(!*primero) *primero=nuevo;
	
	}
	void mostrar(Pila *pila){
	pNodo nodo; 
	nodo=(pNodo)malloc(sizeof(tipoNodo));
	nodo = *pila;
	printf("Datos pila: ");
	while(nodo!=NULL){
		printf("%d ",nodo->dato);
		nodo= nodo->siguiente;
	}
	printf("\n");
}
int Leer(pNodo *primero, pNodo *ultimo){
	
	pNodo nodo;
	int v;
	
	nodo=*primero;
	
	if (!nodo) return 0;
	*primero=nodo->siguiente;
	v=nodo->valor;
	free(nodo);
	
	if(!*primero) *ultimo =NULL;
		return v;
	
}

