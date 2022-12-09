#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	
	int valor;
	struct nodo *siguiente;
		
}tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

//declaracion de las funciones a utilzar

void Insertar (Lista *L,int v);
void Borrar (Lista *L,int v);
void BorrarLista(Lista *);
void MostrarLista(Lista L);

int main(int argc, char *argv[]) {
	
	Lista lista=NULL;
	pNodo p;
	
	Insertar (&lista,20);
	Insertar (&lista,40);
	Insertar (&lista,400);
	
	MostrarLista(lista);
	
	Borrar (&lista,40);
	
	MostrarLista(lista);
	
	BorrarLista(&lista);
		
	return 0;
}


void Insertar (Lista *lista,int v){
	
	pNodo nodo;
	
	nodo=(pNodo)malloc(sizeof(tipoNodo));
	nodo->valor=v;
	
	if(*lista==NULL)*lista=nodo;
	 else
	 nodo->siguiente=(*lista)->siguiente;
	 (*lista)->siguiente=nodo;
	
}

void Borrar (Lista *lista,int v){
	  pNodo nodo;
	   
	   nodo=*lista;
	 
	 do{
	 	//hace si no hay un valor y no hay nodo
	 	if((*lista)->siguiente->valor!=v)*lista=(*lista)->siguiente;
	 }  while((*lista)->siguiente->valor!=v && *lista != nodo);
	 
	 if((*lista)->siguiente->valor==v){
	 	if(*lista == (*lista)->siguiente){
	 		//borra toda la lista
	 		free(*lista);
	 		*lista=NULL;
	 	}
	 	else{
	 		
	 		nodo=(*lista)->siguiente;
	 		(*lista)->siguiente=nodo->siguiente;
	 		free(nodo);
		 }
	 		
		 }
	 	
	 }
	 
void BorrarLista(Lista *lista){
	pNodo nodo;
	
	while((*lista)->siguiente!=*lista) {  //mientras la lista tenga mas de un nodo
		//borrar el nodo siguiente al apuntado por la lista
		nodo=(*lista)->siguiente;
		(*lista)->siguiente=nodo->siguiente;
		free(nodo);
	}
	
	 //borrar ademas el ultimo nodo
	free(*lista);
	*lista=NULL;
	
}

void MostrarLista(Lista lista){
	
	pNodo nodo=lista;
	
	do{
		printf("%d ->",nodo->valor);
		nodo=nodo->siguiente;
		
	}while(nodo !=lista);
	
	printf("\n");
	
	}
