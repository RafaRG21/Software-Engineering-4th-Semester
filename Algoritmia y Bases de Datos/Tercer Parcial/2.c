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
void Buscar(struct Nodo* a, int dat);
void Borrar(struct Nodo* arbol, int dat);
int Vacio(struct Nodo* r);
int EsHoja(struct Nodo* r);
//Funciones para el Metodo BFS
void nivelActual(struct Nodo* raiz, int nivel);
int altura(struct Nodo* nodo);
void nivelOrden(struct Nodo* raiz);


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
    //Uso del metodo de busqueda en anchura
    printf("\n\nMetodo BFS\n");
    nivelOrden(raiz);
    printf("\nAltura del arbol: %d\n", altura(raiz));
    printf("Nivel actual 3: ");
    nivelActual(raiz,3);
    printf("\n");
    Borrar(raiz,11);
    Borrar(raiz,96);
    printf("\n Postorden\n");
    postorden(raiz);
    Buscar(raiz,30);
    Buscar(raiz,96);	
    printf("\nMetodo BFS\n");
    nivelOrden(raiz);
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
void Borrar(struct Nodo *arbol, int dat) {
	
   struct Nodo* padre = NULL; /* (1) */
   struct Nodo* actual;
   struct Nodo* nodo;
   int aux;

   actual = arbol;
   while(!Vacio(actual)) { /* Búsqueda else implícito */
      if(dat == actual->dato) { 
         if(EsHoja(actual)) { 
            if(padre)
               if(padre->der == actual) padre->der = NULL;  
               else if(padre->izq == actual) padre->izq = NULL; 
            free(actual); 
            actual = NULL;
            printf("\nNodo %d eliminado\n",dat);
            return;
         }
         else { 
            /* Buscar nodo */
            padre = actual; 
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
            aux = actual->dato; 
            actual->dato = nodo->dato;
            nodo->dato = aux;
            actual = nodo;
         }
      }
      else {
         padre = actual;
         if(dat > actual->dato) actual = actual->der; 
         else if(dat < actual->dato) actual = actual->izq; 
      }
   }
   
}	
void Buscar(struct Nodo* a, int dat) {
   struct Nodo* actual = a;
   while(!Vacio(actual)) {
      if(dat == actual->dato){ 
	  printf("\nNumero %d encontrado\n",dat); 
	  return; /* dato encontrado  */
      }else if(dat < actual->dato) actual = actual->izq;  
      else if(dat > actual->dato) actual = actual->der;
   }
   printf("\nNumero %d no encontrado\n",dat); /* No está en árbol*/
}
int Vacio(struct Nodo* r) {
   return r==NULL;
}
int EsHoja(struct Nodo* r) {
   return !r->der && !r->izq;
}
void nivelActual(struct Nodo* raiz, int nivel){
		if (!raiz)
		return;
	if (nivel == 1)
		printf("%d ", raiz->dato);
	else if (nivel > 1) {
		nivelActual(raiz->izq, nivel - 1);
		nivelActual(raiz->der, nivel - 1);
	}
}
int altura(struct Nodo* nodo){
		if (!nodo)
		return 0;
	else {
		/*Se calcula la altura de cada subarbol*/
		int izqAltura = altura(nodo->izq);
		int derAltura = altura(nodo->der);

		/*Se utiliza el mas largo */
		if (izqAltura > derAltura)
			return (izqAltura + 1);
		else
			return (derAltura + 1);
	}
}
void nivelOrden(struct Nodo* raiz){
	int al = altura(raiz);
	int i;
	for (i = 1; i <= al; i++)
		nivelActual(raiz, i);
}
