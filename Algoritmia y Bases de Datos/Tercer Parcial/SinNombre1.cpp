#include <stdio.h>
#include <stdlib.h>

struct Nodo{
	
	    int dato;
	    struct Nodo *izq;
	    struct Nodo *der;
};

///////////////////////creacion de un nodo/////////////////
//      size_t  es un tipo de dato sin signo , que es nmayor a 0

struct Nodo *nuevonodo(int dato);
void insertar(struct Nodo *nodo,int dato);
void preorden(struct Nodo *nodo);
void inorden(struct Nodo *nodo);
void postorden(struct Nodo *nodo);
int Buscar(Nodo* a, int dat);
void Borrar(Nodo* arbol, int dat);
int Vacio(Nodo* r);
int EsHoja(Nodo* r);
	


int main(int argc, char *argv[]) {
	
	struct Nodo *raiz=nuevonodo(28);
	insertar(raiz, 11);
	insertar(raiz, 96);
	insertar(raiz, 21);
	insertar(raiz, 6);
	insertar(raiz, 97);
	insertar(raiz, 1);
	insertar(raiz, 30);
    insertar(raiz, 10);
    insertar(raiz, 2);
    
    printf("\n Preorden\n");
    preorden(raiz);
    
    printf("\n Inorden\n");
    inorden(raiz);
    
    printf("\n Postorden\n");
    postorden(raiz);
    Borrar(raiz,30);
    printf("\n Postorden eliminado\n");
    postorden(raiz);
    if(Buscar(raiz,15)){
    printf("\nNumero encontrado\n");
    }else     printf("\nNumero no encontrado\n");
	return 0;
}
struct Nodo *nuevonodo(int dato){
	  //se pide el espacio en memoria para el nuevo nodo
	size_t tamaNodo=sizeof(struct Nodo);
	struct Nodo *nodo=(struct Nodo *)malloc(tamaNodo);
		// Asignar el dato al iniciar
	nodo->dato=dato;
	nodo->izq=nodo->der=NULL;
	
	return nodo;
	
}

void insertar(struct Nodo *nodo,int dato){
	
	//si es mayor va a la derecha
	if(dato>nodo->dato){
		if(nodo->der==NULL){
			nodo->der=nuevonodo(dato);
		}
		               
					   		
		else{
			insertar(nodo->der,dato);
		}
	}	else{
			// sino a la izquiera
			if(nodo->izq==NULL){
				
				nodo->izq=nuevonodo(dato);
			}else{
				insertar(nodo->izq,dato);
			}
		}
		
	}
	
void preorden(struct Nodo *nodo){
	if(nodo!=NULL){
		printf("%d ",nodo->dato);
		preorden(nodo->izq);
		preorden(nodo->der);
		}
			
}
		
void inorden(struct Nodo *nodo){
	if(nodo!=NULL){	
	   inorden(nodo->izq);
	   printf("%d ",nodo->dato);
	   inorden(nodo->der);
		}
			
}
		
void postorden(struct Nodo *nodo){
	if(nodo!=NULL){	
		postorden(nodo->izq);
		postorden(nodo->der);
	    printf("%d ",nodo->dato);
}
			
}
void Borrar(Nodo *arbol, int dat) {
	
   struct Nodo* padre = NULL; /* (1) */
   struct Nodo* actual;
   struct Nodo* nodo;
   int aux;

   actual = arbol;
   while(!Vacio(actual)) { /* Búsqueda (2) else implícito */
      if(dat == actual->dato) { /* (3) */
         if(EsHoja(actual)) { /* (3-a) */
            if(padre)/* (3-a-i caso else implícito) */
               if(padre->der == actual) padre->der = NULL;  /* (3-a-ii) */
               else if(padre->izq == actual) padre->izq = NULL; /* (3-a-iii) */
            free(actual); /* (3-a-iv) */
            actual = NULL;
            return;
         }
         else { /* (3-b) */
            /* Buscar nodo */
            padre = actual; /* (3-b-i) */
            if(actual->der) {
               nodo = actual->der;
               while(nodo->izq) {
                  padre = nodo;
                  nodo = nodo->izq;
               }
            }
            else {
               nodo = actual->izq;
               while(nodo->der) {
                  padre = nodo;
                  nodo = nodo->der;
               }
            }
            /* Intercambio */
            aux = actual->dato; /* (3-b-ii) */
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else {
         padre = actual;
         if(dat > actual->dato) actual = actual->der; /* (4) */
         else if(dat < actual->dato) actual = actual->izq; /* (5) */
      }
   }
}	
int Buscar(Nodo* a, int dat) {
   Nodo* actual = a;
   while(!Vacio(actual)) {
      if(dat == actual->dato) return 1; /* dato encontrado  (2) */
      else if(dat < actual->dato) actual = actual->izq;  /* (3) */
      else if(dat > actual->dato) actual = actual->der; /* (4) */
   }
   return 0; /* No está en árbol (1) */
}
int Vacio(Nodo* r) {
   return r==NULL;
}
int EsHoja(Nodo* r) {
   return !r->der && !r->izq;
}
