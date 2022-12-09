#include <stdio.h>
#include <stdlib.h>

//programa de las acciones de una TDA's pila
//definiremos la estructura del nodo

typedef struct nodo{
	int dato;
	struct nodo *siguiente;
	
}tipoNodo;

// declarar dos punteros  a Nodo y otro a pila

typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

//declaracion de funciones Push & POP

  void Push(Pila *L, int v);
  int Pop(Pila *L);
  void mostrar(Pila *pila);
    void invertirpila(Pila *pila);
    int array[100];
    int num=0;
int main(int argc, char *argv[]) {
	Pila pila=NULL;
	Push(&pila,60);
	Push(&pila,50);
	Push(&pila,40);
	Push(&pila,30);
	Push(&pila,20);
	Push(&pila,10);
	Pila pilon = pila;
	printf("Datos pila: ");
	
	printf("%d ,",Pop(&pila));

    printf("Pila inversa: ");
    Pop(&pila);
    mostrar(&pila);
    printf("\n");
    for(int i=num-1;i>=0;i--){
    	printf("%d ",array[i]);
	}
	printf("%d",array[num]);
	return 0;
}
void mostrar(Pila *pila){
	pNodo nodo; 
	nodo=(pNodo)malloc(sizeof(tipoNodo));
	nodo = *pila;
	printf("Datos pila: ");
	while(nodo!=NULL){
		printf("%d ",nodo->dato);
		array[num]=nodo->dato;
		num++;
		nodo= nodo->siguiente;
	}
	printf("\n");
}

 void Push(Pila *pila, int v){
 	
 	pNodo nuevo;
 	/* Crear un nuevo nodo*/
 	nuevo=(pNodo)malloc(sizeof(tipoNodo));
 	/*se asigna el valor v a nuevo->valor*/
 	nuevo->dato=v;
 	
 	/*Añadimos la pila a continuacion del nuevo nodo*/
 	nuevo->siguiente =*pila;
 	/*ahora el comienzo de nuestra pila es nuevo nodo*/
 	*pila=nuevo;
  }
  
  void invertirpila(Pila *pila){
  	pNodo nodo1, nodo2,nodo3;
  	nodo1=nodo2=nodo3=NULL;
  	nodo1 = *pila;
  	if(pila){
  		while(nodo1!=NULL){
  			Push(&nodo2,nodo1->dato);
  			nodo1 = nodo1->siguiente;
		  }
		while(nodo2!=NULL){
  			Push(&nodo3,nodo2->dato);
  			nodo2 = nodo2->siguiente;
		  }  
		while(nodo3!=NULL){
  			Push(&pila,nodo3->dato);
  			nodo3 = nodo3->siguiente;
		  }    
	  }
	  mostrar(&nodo1);
  }
  
  int Pop(Pila *pila){
  	pNodo nodo;
  	int v;
  	
  	/*Nodo apunta a primer elemento de la pila*/
  	nodo= *pila;
  	
  	if(!nodo) return 0; //si no hay nodos en la lista retornaremos a 0
  	
  	/*Asignamos a pila toda la pila menos el primer elemento */
  	
  	*pila=nodo->siguiente;
  	/*se guarda el valor v*/
  	v=nodo->dato;
  	
  	free(nodo);  //se libera el espacio del nodo utilizado*/
  	
  	return v;
  	
  	}
