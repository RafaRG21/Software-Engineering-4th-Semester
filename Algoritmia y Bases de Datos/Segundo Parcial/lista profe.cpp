#include <stdlib.h>
#include <stdio.h>

/* TDA's Lista Enlazada */

typedef struct nodo {
   int valor;
   struct nodo *siguiente;
} tipoNodo;


typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;

////////////////////declarqacion de las funciones utilizadas//////

void Insertar(Lista *l, int v);
void Borrar(Lista *l, int v);
int ListaVacia(Lista l);
void BorrarLista(Lista *);
void MostrarLista(Lista l);

//////////////////////////////////////////////////////////////////////////

int main() {
   Lista lista = NULL;
   pNodo p;

   Insertar(&lista, 4);
   Insertar(&lista, 2);
    Insertar(&lista,1);
    Insertar(&lista,3);
    Insertar(&lista, 5);
   

   MostrarLista(lista);

   Borrar(&lista, 6);
   Borrar(&lista, 2);
  
   MostrarLista(lista);

   BorrarLista(&lista);

   return 0;
}

void Insertar(Lista *lista, int v) {
   pNodo nuevo, anterior;

   /* Crear un nodo nuevo */
   nuevo = (pNodo)malloc(sizeof(tipoNodo));
   // 3 7 4 6 1 5 2 8
// dato = 8
//lista= 1->2->3->4->5->6->7->Null  nuevo = 8  anterior = 7->Null
 // 
   nuevo->valor = v;
   /* Si la lista está vacía */
   if(ListaVacia(*lista) || (*lista)->valor > v) {
      /* Añadimos la lista a continuación del nuevo nodo */
      nuevo->siguiente = *lista;
      /* Ahora, el comienzo de nuestra lista es en nuevo nodo */
      *lista = nuevo;
   } else {
      /* Buscar el nodo de valor menor a v */
      anterior = *lista;
      /* Avanzamos hasta el último elemento o hasta que el siguiente tenga
         un valor mayor que v */
      while(anterior->siguiente && anterior->siguiente->valor <= v) // anterior->siguiente se refiere a que anterior->siguiente no sea null
         anterior = anterior->siguiente;
      /* Insertamos el nuevo nodo después del nodo anterior */
      nuevo->siguiente = anterior->siguiente;
      anterior->siguiente = nuevo;
   }
}

void Borrar(Lista *lista, int v) {
   pNodo anterior, nodo;

   nodo = *lista;
   anterior = NULL;
   while(nodo && nodo->valor < v) {
      anterior = nodo;
      nodo = nodo->siguiente;
   }
   if(!nodo || nodo->valor != v) return;
   else { /* Borrar el nodo */
      if(!anterior) /* Primer elemento */
         *lista = nodo->siguiente;
      else  /* un elemento cualquiera */
         anterior->siguiente = nodo->siguiente;
      free(nodo);
   }
}

int ListaVacia(Lista lista) {
   return (lista == NULL);
}

void BorrarLista(Lista *lista) {
   pNodo nodo;

   while(*lista) {
      nodo = *lista;
      *lista = nodo->siguiente;
      free(nodo);
   }
}

void MostrarLista(Lista lista) {
   pNodo nodo = lista;

   if(ListaVacia(lista)) printf("Lista vacía\n");
   else {
      while(nodo) {
         printf("%d -> ", nodo->valor);
         nodo = nodo->siguiente;
     }
     printf("\n");
   }
}
