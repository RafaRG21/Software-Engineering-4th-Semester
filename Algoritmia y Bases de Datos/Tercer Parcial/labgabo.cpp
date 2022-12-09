#include <stdio.h>
#include <stdlib.h>

// variables globales
int inc = 0, aum = 0, plus = 0, numero;

// Estructuras de nodos
struct Nodo
{
	int dato;
	struct Nodo *izq;
	struct Nodo *der;
};

struct NodoList
{

	int dato;
	struct NodoList *next;
};

// Funciones de lista
struct NodoList *insertarList(struct NodoList *lista, int data);
void printList(struct NodoList *list);
char findway(struct NodoList *lista, int data);

void imprimirLaberintoNumeros();

// Funciones de arbol
void crearArbol(struct Nodo *nodo);
struct Nodo *nuevonodo(int dato);

// crear todos los caminos posibles
struct NodoList *buscarNumero(struct Nodo *a, int num, struct NodoList *lista);
struct NodoList *buscarNumerob(struct Nodo *a, int num, struct NodoList *lista);
struct NodoList *buscarNumeroc(struct Nodo *c, int num, struct NodoList *lista);
struct NodoList *buscarNumerod(struct Nodo *d, int num, struct NodoList *lista);
struct NodoList *buscarNumeroe(struct Nodo *e, int num, struct NodoList *lista);

int main()
{

	struct NodoList *lista1 = NULL;
	struct NodoList *lista2 = NULL;
	struct NodoList *lista3 = NULL;
	struct NodoList *lista4 = NULL;
	struct NodoList *lista5 = NULL;

	imprimirLaberintoNumeros();

	struct Nodo *nodo = nuevonodo(49);
	crearArbol(nodo);
	


	printf("Digite el numero al que quieres llegar: ");
	scanf("%d", &numero);

	lista1 = buscarNumero(nodo, numero, lista1);

	if (findway(lista1, numero) == 't')
	{
		return 0;
	}
	lista2 = buscarNumeroc(nodo, numero, lista2);
	if (findway(lista2, numero) == 't')
	{
		return 0;
	}
	lista3 = buscarNumerod(nodo, numero, lista3);
	if (findway(lista3, numero) == 't')
	{
		return 0;
	}
	lista4 = buscarNumeroe(nodo, numero, lista4);
	if (findway(lista4, numero) == 't')
	{
		return 0;
	}
	
	lista5 = buscarNumerob(nodo, numero, lista5);
	
	if (findway(lista5, numero) == 't')
	{
		return 0;
	}
	printf("El numero no se encuentra en el laberinto \n");

	return 0;
}

struct NodoList *buscarNumero(struct Nodo *a, int num, struct NodoList *lista)
{

	if (a != NULL)
	{
		if (a->dato != num)
		{
			lista = insertarList(lista, a->dato);

			//buscarNumero(a->izq, num);
			if (a->izq != NULL)
				lista = buscarNumero(a->izq, num, lista);
			else
				lista = buscarNumero(a->der, num, lista);
		}
		else
		{
			lista = insertarList(lista, a->dato);
		}
	}
	return lista;
}

struct NodoList *buscarNumeroc(struct Nodo *c, int num, struct NodoList *lista)
{

	if (c != NULL)
	{
		if (c->dato != num)
		{
			lista = insertarList(lista, c->dato);

			//buscarNumero(a->izq, num);
			if (c->izq != NULL && inc == 0)
			{
				inc++;
				lista = buscarNumeroc(c->izq, num, lista);
			}
			else
				lista = buscarNumeroc(c->der, num, lista);
		}
		else
		{
			lista = insertarList(lista, c->dato);
		}
	}
	return lista;
}

struct NodoList *buscarNumerod(struct Nodo *d, int num, struct NodoList *lista)
{

	if (d != NULL)
	{
		if (d->dato != num)
		{
			lista = insertarList(lista, d->dato);

			//buscarNumero(a->izq, num);
			if (d->izq != NULL)
			{
				aum++;
				if (aum <= 2)
					lista = buscarNumerod(d->izq, num, lista);
				else
					lista = buscarNumerod(d->der, num, lista);
			}
			else
				lista = buscarNumerod(d->der, num, lista);
		}
		else
		{
			lista = insertarList(lista, d->dato);
		}
	}
	return lista;
}

struct NodoList *buscarNumerob(struct Nodo *b, int num, struct NodoList *lista)
{
	if(!b){
		return lista;
	}

	if (b->dato != num)
	{
		lista = insertarList(lista, b->dato);

		lista = buscarNumerob(b->der, num, lista);
	}
	else
	{
		lista = insertarList(lista, b->dato);
	}
	return lista;
}

struct NodoList *buscarNumeroe(struct Nodo *e, int num, struct NodoList *lista)
{

	if (e != NULL)
	{
		if (e->dato != num)
		{
			lista = insertarList(lista, e->dato);

			//buscarNumero(a->izq, num);
			if (e->izq != NULL)
			{
				plus++;

				if (plus > 1)
					lista = buscarNumeroe(e->izq, num, lista);
				else
					lista = buscarNumeroe(e->der, num, lista);
			}
			else
				lista = buscarNumeroe(e->der, num, lista);
		}
		else
		{
			lista = insertarList(lista, e->dato);
		}
	}
	return lista;
}

void imprimirLaberintoNumeros()
{
	printf("\033[5;34m");
	printf("\t      --- LABERINTO --- \n");
	printf("\033[0m");

	printf("\t  __________________________  \n");
	printf("\t  | 1 %c%c 3  4  5  6  7  8  |  \n", 95, 95);
	printf("\t  | 9 10 11 %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c|  \n", 95, 95, 95, 95,
	 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95);
	printf("\t  |%c%c%c%c%c 19 %c%c%c%c%c%c%c%c%c%c%c 24 |  \n", 95, 95, 95, 95,
	 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95);
	printf("\t  |%c%c%c%c%c 27 %c%c%c%c%c 30 31 32 |  \n", 95, 95, 95, 95, 95,
	 95, 95, 95, 95, 95);
	printf("\t  |%c%c%c%c%c 35 36 37 38 %c%c%c%c%c%c| \n", 95, 95, 95, 95, 95, 
	95, 95, 95, 95, 95, 95);
	printf("\t  |41 42 43 %c%c 45 %c%c%c%c%c%c%c%c%c| \n", 95, 95, 95, 95, 95, 
	95, 95, 95, 95, 95, 95);
	printf("\033[0;31m");

	printf("\t-> 49");
	printf("\033[0m");
	printf(" %c%c%c%c%c%c%c%c 53 54 55 56 | \n", 95, 95, 95, 95, 95, 
	95, 95, 95);

	printf("\t  |%c%c%c%c%c%c%c%c%c%c%c%c%c%c 62 %c%c%c%c%c%c| \n", 95, 
	95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 
	95, 95, 95, 95, 95, 95, 95, 95);
	printf("\t  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c \n",
	 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95,
	  95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95, 95);
}

void crearArbol(struct Nodo *nodo)
{
	nodo->der = nuevonodo(41);
	nodo->der->der = nuevonodo(42);
	nodo->der->der->der = nuevonodo(43);
	nodo->der->der->der->der = nuevonodo(35);

	//Parte de la derecha del 35
	nodo->der->der->der->der->izq = nuevonodo(36);
	nodo->der->der->der->der->izq->der = nuevonodo(37);

	//Parte derecha del 37
	nodo->der->der->der->der->izq->der->der = nuevonodo(38);
	nodo->der->der->der->der->izq->der->der->der = nuevonodo(30);
	nodo->der->der->der->der->izq->der->der->der->der = nuevonodo(31);
	nodo->der->der->der->der->izq->der->der->der->der->der = nuevonodo(32);
	nodo->der->der->der->der->izq->der->der->der->der->der->der = nuevonodo(24);

	//Parte izquierda del 37
	nodo->der->der->der->der->izq->der->izq = nuevonodo(45);
	nodo->der->der->der->der->izq->der->izq->der = nuevonodo(53);
	nodo->der->der->der->der->izq->der->izq->der->der = nuevonodo(54);

	//Parte izquierda del 54
	nodo->der->der->der->der->izq->der->izq->der->der->izq = nuevonodo(62);

	//Parte derecha del 54
	nodo->der->der->der->der->izq->der->izq->der->der->der = nuevonodo(55);
	nodo->der->der->der->der->izq->der->izq->der->der->der->der = nuevonodo(56);

	//La parte de arriba del 35
	nodo->der->der->der->der->der = nuevonodo(27);
	nodo->der->der->der->der->der->der = nuevonodo(19);
	nodo->der->der->der->der->der->der->der = nuevonodo(11);

	//Parte izquierda del 11
	nodo->der->der->der->der->der->der->der->izq = nuevonodo(10);
	nodo->der->der->der->der->der->der->der->izq->der = nuevonodo(9);
	nodo->der->der->der->der->der->der->der->izq->der->der = nuevonodo(1);

	//Parte derecha del 11
	nodo->der->der->der->der->der->der->der->der = nuevonodo(3);
	nodo->der->der->der->der->der->der->der->der->der = nuevonodo(4);
	nodo->der->der->der->der->der->der->der->der->der->der = nuevonodo(5);
	nodo->der->der->der->der->der->der->der->der->der->der->der = nuevonodo(6);
	nodo->der->der->der->der->der->der->der->der->der->der->der->der = nuevonodo(7);
	nodo->der->der->der->der->der->der->der->der->der->der->der->der->der = nuevonodo(8);
}

struct Nodo *nuevonodo(int dato)
{
	//se pide el espacio en memoria para el nuevo nodo
	size_t tamaNodo = sizeof(struct Nodo);
	struct Nodo *nodo = (struct Nodo *)malloc(tamaNodo);
	// Asignar el dato al iniciar
	nodo->dato = dato;
	nodo->izq = nodo->der = NULL;

	return nodo;
}

struct NodoList *insertarList(struct NodoList *lista, int data)
{

	struct NodoList *nodo = (struct NodoList *)malloc(sizeof(struct NodoList));
	nodo->dato = data;
	nodo->next = NULL;

	if (lista == NULL)
	{
		nodo->next = NULL;
		lista = nodo;

		return lista;
	}
	else
	{

		struct NodoList *aux = lista;
		while (aux->next != NULL)
		{

			aux = aux->next;
		}
		nodo->next = NULL;
		aux->next = nodo;

		return lista;
	}
}

char findway(struct NodoList *lista, int data)
{
	if(lista==NULL){
		return 'f';

	}
	struct NodoList *aux = lista;

	while (aux->next != NULL)
	{

		aux = aux->next;
	}

	if (aux->dato == data)
	{
		printList(lista);
		return 't';
	}
	else
	{
		return 'f';
	}
}

void printList(struct NodoList *list)
{

	if (list == NULL)
	{

		return;
	}
	struct NodoList *lista = list;
	while (lista != NULL)
	{

		printf(" %d ->", lista->dato);
		lista = lista->next;
	}
	printf("\n");
}
