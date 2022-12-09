#include<stdlib.h>
#include<stdio.h>
struct Nodo{
	int dato;
	struct Nodo  *izq;
	struct Nodo *der;
};

///creacion de Nodo
///size_t es un tipo de dato sin signo, que es mayor a cero
struct Nodo* nuevonodo(int dato){
	//se pide el espacio en memoria para el nuevo nodo
	size_t tamaNodo=sizeof(struct Nodo);
	struct Nodo *nodo=(struct Nodo *)malloc(tamaNodo);
	//asignar el dato a inicar
	nodo->dato = dato;
	nodo->izq = nodo->der = NULL;
	return nodo;
}
void insertar(struct Nodo *nodo,int dato){
	// si es mayor va a la derecha
	if(dato>nodo->dato){
		if(nodo->der==NULL){
		
		
		nodo->der = nuevonodo(dato);
	   } else{
		insertar(nodo->der,dato);
	     }
	}else if(nodo->izq==NULL){
		
		
		nodo->izq = nuevonodo(dato);
	   } else{
		insertar(nodo->izq,dato);
	     }
		
	
}
void preorden(struct Nodo *nodo);
void inorden(struct Nodo *nodo);
void postorden(struct Nodo *nodo);
int eliminar(struct Nodo* nodo,int n);
int main(){
	struct Nodo *raiz= nuevonodo(28);
	insertar(raiz,11);
	insertar(raiz,96);
	insertar(raiz,21);
	insertar(raiz,6);
	insertar(raiz,97);
	insertar(raiz,1);
	insertar(raiz,30);
	insertar(raiz,10);
	insertar(raiz,2);
	printf("Preorden\n");
	preorden(raiz);
	printf("\nPostorden\n");	
    postorden(raiz);
	printf("\nInorden\n"); 
	inorden(raiz);   

 
    eliminar(raiz,11);
	printf("\nPostorden\n");	
    postorden(raiz);
    return 0;

}
void preorden(struct Nodo *nodo){
	if(nodo!=NULL){
		
		printf("%d, ",nodo->dato);
		preorden(nodo->izq);
		preorden(nodo->der);
	}
}
void inorden(struct Nodo *nodo){
	if(nodo!=NULL){
		preorden(nodo->izq);
		printf("%d, ",nodo->dato);
		preorden(nodo->der);
	}
}
void postorden(struct Nodo *nodo){
	if(nodo!=NULL){
		postorden(nodo->izq);
		postorden(nodo->der);
		printf("%d, ",nodo->dato);

	}
}
int eliminar(struct Nodo* nodo,int n){
	if(!nodo) return nodo;
	if(n<nodo->dato)
	nodo->izq=eliminar(nodo->izq,n);
	else if(n>nodo->dato)
	nodo->der=eliminar(nodo->der,n);
	else{
		if(!nodo->izq){
			struct Nodo* aux=nodo->der;
			free(nodo);
			printf("\nNodo %d eliminado",n);
			return aux;
		}
		else if(nodo->der){
			struct Nodo* aux=nodo->izq;
			free(nodo);
			printf("\nNodo %d eliminado",n);
			return aux;
		}
	}
	
	
}
