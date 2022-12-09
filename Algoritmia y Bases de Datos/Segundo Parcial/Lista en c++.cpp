#include<iostream>
using namespace std;

typedef struct Nodo{
	int dato;
	struct Nodo *siguiente;
}tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *Lista;
 void insertarNodo(Lista *lista,int n);
 void mostrarLista(Lista lista);
 void buscarNodo(Lista lista,int n);
 void borrarNodo(Lista *lista,int n);
 void borrarLista(Lista *lista);
bool ListaVacia(Lista lista);
 
 int main(){
 	Lista lista = NULL;
    insertarNodo(&lista,8);
    insertarNodo(&lista,3);
    insertarNodo(&lista,9);
    insertarNodo(&lista,1);
    insertarNodo(&lista,6);
    insertarNodo(&lista,5);
    insertarNodo(&lista,2);					    
 	mostrarLista(lista);
 	buscarNodo(lista,10);
 	borrarNodo(&lista,8);
 	borrarNodo(&lista,10);
 	mostrarLista(lista);
 	borrarLista(&lista);
 	mostrarLista(lista);
 	return 0;
 }
 
void insertarNodo(Lista *lista,int n){
	pNodo nuevo = new Nodo();
	pNodo anterior = new Nodo();
	nuevo->dato = n;
	if(ListaVacia(*lista)||(*lista)->dato>=n){
    nuevo->siguiente = *lista;
    *lista = nuevo;
	}else{
	anterior = *lista;
	while(anterior->siguiente && anterior->siguiente->dato<=n){
		anterior = anterior->siguiente;
	}
	nuevo->siguiente = anterior->siguiente;
	anterior->siguiente = nuevo;
		
	}
	
}
void mostrarLista(Lista lista){
	pNodo actual = lista;
	if(ListaVacia(lista)) 	
	cout<<"Lista vacia"<<endl;
	else{
	while(actual){
		cout<<actual->dato<<"->";
		actual = actual->siguiente;
	}cout<<"NULL"<<endl;
}

}
 void buscarNodo(Lista lista,int n){
 	pNodo actual=lista;
 	bool encontrado = false;
	 while(actual&&actual->dato<=n){
	 	if(actual->dato==n) encontrado = true;
	 	actual = actual->siguiente;
	 } 
	 if(encontrado)
	   cout<<"Dato "<<n<<" encontrado"<<endl;
	   else 	   
	   cout<<"Dato "<<n<<" no encontrado"<<endl;
 }
 void borrarNodo(Lista *lista,int n){
 	pNodo anterior, actual = *lista;
 	anterior = NULL;
 	while(actual&&actual->dato<n){
 		anterior = actual;
 		actual = actual->siguiente;
	 }
 	if(!actual||actual->dato!=n){
 		cout<<"No se encontro "<<n<<" , no se pudo eliminar"<<endl;
 		return;
	 }
	 else{
	 	if(!anterior) *lista = actual->siguiente;
	 	else{
	 		anterior->siguiente = actual->siguiente;
	 		delete actual;
		 }
	 }
	 cout<<"Nodo "<<n<<" eliminado"<<endl;
 }
  void borrarLista(Lista *lista){
  	pNodo actual;
  	while(*lista){
  		actual = *lista;
  		*lista = actual->siguiente;
  		delete actual;
	  }
  }
bool ListaVacia(Lista lista){
  	return (lista==NULL);
  }
