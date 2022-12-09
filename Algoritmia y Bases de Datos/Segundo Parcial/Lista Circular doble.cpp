#include<iostream>
using namespace std;

typedef struct Nodo{
	int dato;
	struct Nodo *siguiente;
	struct Nodo *anterior;
}tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *ListaCirDoble;

pNodo ultimo  = NULL;
ListaCirDoble lista = NULL;

void insertarNodo(ListaCirDoble *lista,int n);
void mostrarListaPU(ListaCirDoble lista);
void mostrarListaUP(ListaCirDoble lista);
void buscarNodo(ListaCirDoble lista,int n);
void modificarNodo(ListaCirDoble *lista, int n,int v);

int main(){
	insertarNodo(&lista,1);
	insertarNodo(&lista,2);
	insertarNodo(&lista,3);
	insertarNodo(&lista,4);
	insertarNodo(&lista,5);
	insertarNodo(&lista,6);
	insertarNodo(&lista,7);
	insertarNodo(&lista,8);
	mostrarListaPU(lista);
	mostrarListaUP(lista);
	buscarNodo(lista,5);
	buscarNodo(lista,9);
	modificarNodo(&lista,3,9);
	mostrarListaPU(lista);
	return 0;
}
void insertarNodo(ListaCirDoble *lista,int n){
	pNodo nuevo = new Nodo();
	nuevo->dato = n;
	if(*lista==NULL){
		*lista = nuevo; // el primero es igual al nuevo dato
		ultimo = nuevo; // el ultimo es igual al nuevo dato
		(*lista)->siguiente = *lista; //lista ->siguiente apunta a si misma
		(*lista)->anterior = ultimo; //lista ->anterior apunta a si misma
	}else{
		ultimo->siguiente = nuevo;
		nuevo->anterior = ultimo;
		nuevo->siguiente = *lista;
		ultimo = nuevo;
		(*lista)->anterior = ultimo;
	}
	cout<<"\nNodo "<<n<<" ingresado"<<endl;
}
void mostrarListaPU(ListaCirDoble lista){
	pNodo actual = lista;
	cout<<"\nLista del primero al ultimo:"<<endl;	
	if(lista!=NULL){
		do{
			cout<<"<-"<<actual->dato<<"->";
			actual = actual->siguiente;
		}while(actual!=lista);
		cout<<endl;
	}else cout<<"\nLista Vacia"<<endl;
}
void mostrarListaUP(ListaCirDoble lista){
	pNodo actual = ultimo;
	cout<<"\nLista del ultimo al primero:"<<endl;
	if(lista!=NULL){
		do{
			cout<<"<-"<<actual->dato<<"->";
			actual = actual->anterior;
		}while(actual!=ultimo);
		cout<<endl;
	}else cout<<"\nLista Vacia"<<endl;	
}
void buscarNodo(ListaCirDoble lista,int n){
	pNodo actual = lista;
	bool encontrado = false;
	if(lista){
		do{
			if(actual->dato==n){ // si actual->dato es igual al dato buscado
				cout<<"\nDato "<<actual->dato<<" encontrado"<<endl;
				encontrado = true; // encontrado es igual a true
			}
			actual = actual->siguiente;   // actual se sigue desplazando
		}while(lista!=actual&&encontrado!=true); 
		
	}if(!encontrado) cout<<"\nDato "<<n<<" no encontrado"<<endl; 
}
void modificarNodo(ListaCirDoble *lista, int n,int v){
    pNodo actual = new Nodo();
    actual = *lista;
	bool encontrado = false;
	if(*lista){
		do{
			if(actual->dato==n){ // si actual->dato es igual al dato buscado
				cout<<"\nDato "<<actual->dato<<" encontrado"<<endl;
				actual->dato = v;
				encontrado = true; // encontrado es igual a true
				cout<<"\nDato "<<n<<" modificado por "<<actual->dato<<endl;
				
			}
			actual = actual->siguiente;   // actual se sigue desplazando
		}while(*lista!=actual&&encontrado!=true); 
		
	}if(!encontrado) cout<<"\nDato "<<n<<" no encontrado"<<endl; 	
}
