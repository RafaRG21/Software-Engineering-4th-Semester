#include <stdio.h>

#define ASCENDENTE 1
#define DESCENDENTE 0

typedef struct _nodo {
   int valor;
   struct _nodo *siguiente;
   struct _nodo *anterior;
} tipoNodo;

typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

/* Funciones con listas: */
void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
void Buscar(Lista l, int v);
void BorrarLista(Lista *);
void MostrarLista(Lista l, int orden);

int main() {
   Lista lista = NULL;
   pNodo p;

   Insertar(&lista, 7);
   Insertar(&lista, 4);
   Insertar(&lista, 8);
   Insertar(&lista, 1);
   Insertar(&lista, 9);
   Insertar(&lista, 6);

   MostrarLista(lista, ASCENDENTE);
   MostrarLista(lista, DESCENDENTE);

   Borrar(&lista, 8);
   Borrar(&lista, 1);
   Borrar(&lista, 3);
   Borrar(&lista, 6);

   MostrarLista(lista, ASCENDENTE);
   MostrarLista(lista, DESCENDENTE);
   Buscar(lista,7);
   Buscar(lista,8);
   BorrarLista(&lista);
   MostrarLista(lista,ASCENDENTE);

   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nuevo, actual;
   printf("\nInsercion de %d",v);
   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   nuevo->valor = v;

   /* Colocamos actual en la primera posición de la lista */
   actual = *lista;
   if(actual) while(actual->anterior) actual = actual->anterior;
   /* Si la lista está vacía o el primer miembro es mayor que el nuevo */
   if(!actual || actual->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = actual;
      nuevo->anterior = NULL;
      if(actual) actual->anterior = nuevo;
      if(!*lista) *lista = nuevo;
   }
   else {
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(actual->siguiente &&actual->siguiente->valor <= v)
         actual = actual->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = actual->siguiente;
      actual->siguiente = nuevo;
      nuevo->anterior = actual;
      if(nuevo->siguiente) nuevo->siguiente->anterior = nuevo;
   }
}
void Buscar(Lista lista,int v){
	printf("\nBusqueda");
	pNodo nodo = lista;
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v){
    printf("\nNodo %d no encontrado, no se pudo eliminar",v);
   }else printf("\nNodo %d encontrado",v);
}
void Borrar(Lista *lista, int v) {
   pNodo nodo;
   printf("\nEliminacion de Nodo");
   /* Buscar el nodo de valor v */
   nodo = *lista;
   if(nodo){
   while(nodo && nodo->valor < v) nodo = nodo->siguiente;
   while(nodo && nodo->valor > v) nodo = nodo->anterior;

   /* El valor v no está en la lista */
   if(!nodo || nodo->valor != v){
    printf("\nNodo %d no encontrado, no se pudo eliminar",v);
	return;
   }

   /* Borrar el nodo */
   /* Si lista apunta al nodo que queremos borrar, apuntar a otro */
   if(nodo == *lista)
     if(nodo->anterior) *lista = nodo->anterior;
     else *lista = nodo->siguiente; // si nodo es igual al primer elemento de la lista

   if(nodo->anterior) /* no es el primer elemento */
      nodo->anterior->siguiente = nodo->siguiente;
   if(nodo->siguiente) /* no es el último nodo */
      nodo->siguiente->anterior = nodo->anterior;
   free(nodo);
   printf("\nNodo %d eliminado",v);
   } else printf("\nLista vacia ");
}

void BorrarLista(Lista *lista) {
   pNodo nodo, actual;
   printf("\nEliminacion de Lista");
   actual = *lista;
   while(actual->anterior) actual = actual->anterior;

   while(actual) {
      nodo = actual;
      actual = actual->siguiente;
      free(nodo);
   }
   *lista = NULL;
   printf("\nLista borrada\n");
}

void MostrarLista(Lista lista, int orden) {
   pNodo nodo = lista;
    printf("\nLista:\n");
   if(!lista) printf("\nLista vacia");

   nodo = lista;
   if(orden == ASCENDENTE) {
      while(nodo->anterior) nodo = nodo->anterior;
      printf("\nOrden ascendente: ");
      while(nodo) {
         printf("%d -> ", nodo->valor);
         nodo = nodo->siguiente;
      }
   }
   else {
      while(nodo->siguiente) nodo = nodo->siguiente;
      printf("\nOrden descendente: ");
      while(nodo) {
         printf("%d -> ", nodo->valor);
         nodo = nodo->anterior;
      }
   }

   printf("\n");
}
