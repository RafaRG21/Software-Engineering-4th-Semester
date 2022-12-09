#include <stdio.h>
#include <stdlib.h>
struct Nodo{
 int dato;
 struct Nodo *izq;
 struct Nodo *der;
};
///////////////////////creacion de un nodo/////////////////
// size_t es un tipo de dato sin signo , que es nmayor a 0
struct Nodo *nuevonodo(int dato){
 //se pide el espacio en memoria para el nuevo nodo
size_t tamaNodo=sizeof(struct Nodo);
struct Nodo *nodo=(struct Nodo *)malloc(tamaNodo);
// Asignar el dato al iniciar
nodo->dato=dato;
nodo->izq=nodo->der=NULL;
return nodo;
}
void insertar(struct Nodo *nodo,int dato);
void preorden(struct Nodo *nodo);
void inorden(struct Nodo *nodo);
void postorden(struct Nodo *nodo);
void Borrar(struct Nodo *nodo, int dato);
int Vacio(struct Nodo* r);
int EsHoja(struct Nodo* r);
int Buscar(struct Nodo *nodo, int dato);

int main(int argc, char *argv[]) {
	
struct Nodo *raiz=nuevonodo(28);
raiz->der=nuevonodo(2);
raiz->der->der=nuevonodo(15);
raiz->der->der->der=nuevonodo(12);
raiz->der->der->der



 printf(" Preorden\n");
 preorden(raiz);
 
 printf("\n Inorden\n");
 inorden(raiz);

 printf("\n Postorden\n");
 postorden(raiz);

 printf("\n Metodo BFS (Busqueda en anchura) \n");
 cicloBFS(raiz);

printf("\n\n");
 Borrar(raiz, 6);
 printf("Borrar 6: ");
 postorden(raiz);

 printf("\n");
 Borrar(raiz, 11);
 printf("Borrar 11: ");
 postorden(raiz);



 printf("\n\n");
 printf("Buscar 15: ");
 if(Buscar(raiz,15)) printf("Se encontro el numero\n");
 else printf("No se encontro el numero\n");

 printf("Buscar 2: ");
 if(Buscar(raiz,2)) printf("Se encontro el numero\n");
 else printf("No se encontro el numero\n");



return 0;
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
} else{
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
void Borrar(struct Nodo *a, int dato) {
 struct Nodo *padre = NULL;
 struct Nodo *actual;
 struct Nodo *nodo;
 int aux;
 actual = a;
 while(!Vacio(actual)) {
 if(dato == actual->dato) {
 if(EsHoja(actual)) {
 if(padre)
 if(padre->der == actual) padre->der = NULL;
 else if(padre->izq == actual) padre->izq = NULL;
 free(actual);
 actual = NULL;
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
 if(dato > actual->dato) actual = actual->der;
 else if(dato < actual->dato) actual = actual->izq;
 }
 }
}
int Vacio(struct Nodo* r) {
 return r==NULL;
}
int EsHoja(struct Nodo* r) {
 return !r->der && !r->izq;
}
int Buscar(struct Nodo *a, int dat) {
 struct Nodo *actual = a;
 while(!Vacio(actual)) {
 if(dat == actual->dato) return 1; /* dato encontrado (2) */
 else if(dat < actual->dato) actual = actual->izq; /* (3) */
 else if(dat > actual->dato) actual = actual->der; /* (4) */
 }
 return 0; /* No está en árbol (1) */
}
void cicloBFS(struct Nodo* a)
{
 int h = altura(a);
 int i;
 for (i = 1; i <= h; i++)
 printBFS(a, i);
}
/* Imprime los nodos del mismo nivel */
void printBFS(struct Nodo* a, int nivel)
{
 if (a == NULL)
 return;
 if (nivel == 1)
 printf("%d ", a->dato);
 else if (nivel > 1) {
 // printf("%d, %d \n", a->dato, nivel);
 printBFS(a->izq, nivel - 1);
 printBFS(a->der, nivel - 1);
 }
}
int altura(struct Nodo* a)
{
 if (a == NULL)
 return 0;
 else {

 int ialtura = altura(a->izq);
 int daltura = altura(a->der);
 if (ialtura > daltura)
 return (ialtura + 1);
 else
 return (daltura + 1);
 }
}

