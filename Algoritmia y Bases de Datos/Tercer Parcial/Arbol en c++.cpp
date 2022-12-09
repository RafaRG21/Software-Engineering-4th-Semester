#include<iostream>
using namespace std;

struct Nodo{
	int dato;
	Nodo* padre;
	Nodo* derecha;
	Nodo* izquierda;
};

Nodo* crearNodo(Nodo*,int);
void insertarNodo(Nodo*&,Nodo*,int n);
void mostrarArbol(Nodo*,int);
bool busqueda(Nodo*,int);
void eliminar(Nodo*,int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void remplazar(Nodo*,Nodo*);
void destruir(Nodo*);
int main(){ 
	Nodo* arbol = NULL;
	int contador=0;
	insertarNodo(arbol,NULL,28);
	insertarNodo(arbol,NULL,11);
	insertarNodo(arbol,NULL,96);
	insertarNodo(arbol,NULL,21);
	insertarNodo(arbol,NULL,6);
	insertarNodo(arbol,NULL,97);
	insertarNodo(arbol,NULL,1);
	insertarNodo(arbol,NULL,30);
	insertarNodo(arbol,NULL,10);
	insertarNodo(arbol,NULL,2);
	mostrarArbol(arbol,contador);
	if(busqueda(arbol,2))
	cout<<"\nNumero 12 encontrado\n";
	else cout<<"\nNumero 12 no encontrado\n";
	if(busqueda(arbol,13))
	cout<<"Numero 13 encontrado\n";
	else cout<<"Numero 13 no encontrado\n";
	eliminar(arbol,2);
	mostrarArbol(arbol,contador);
}
Nodo* crearNodo(Nodo* padre,int n){
	Nodo* nuevoNodo = new Nodo();
	nuevoNodo->dato = n;
	nuevoNodo->derecha = nuevoNodo->izquierda = NULL;
	nuevoNodo->padre=padre;
	return nuevoNodo;
}
void insertarNodo(Nodo*& arbol,Nodo* padre,int n){
	if(!arbol){
		Nodo* nuevoNodo = crearNodo(padre,n);
		arbol = nuevoNodo;
		return;
	}else{
		if(n<arbol->dato)
			insertarNodo(arbol->izquierda,arbol,n);
		else insertarNodo(arbol->derecha,arbol,n);
	}
}
void mostrarArbol(Nodo* arbol,int cont){
	if(!arbol)
	return;
	else{
		mostrarArbol(arbol->derecha,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izquierda,cont+1);
	}
}
bool busqueda(Nodo* arbol,int n){
	if(!arbol) // si arbol esta vacio
	return false;
	if(arbol->dato==n) // si el nodo es igual al dato
	return true;
	if(n<arbol->dato) // si el dato es menor al nodo
	return busqueda(arbol->izquierda,n);// se repite el proceso por la izquierda
	else return busqueda(arbol->derecha,n);// sino se repite por la derecha
}
//Funcion para encontrar el nodo a eliminar
void eliminar(Nodo* arbol,int n){
	if(!arbol) // Si el nodo esta vacio solo retorna;
	return;
	if(n<arbol->dato) // si el dato es menor al nodo
	eliminar(arbol->izquierda,n);//se vuelve a llamar la funcion hacia el lado izq
	else if(n>arbol->dato)// caso contrario se llama hacia la derecha
	eliminar(arbol->derecha,n);
	else
	eliminarNodo(arbol); // Cuando se encuetra el nodo se llama la funcion para borrar
}
//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo* nodo){
	if(nodo->izquierda&&nodo->derecha){ //Si el nodo tiene dos hijos
	    Nodo* min=minimo(nodo); // Se busca el nodo minimo mas izq
	    nodo->dato = min->dato; // el arbol se iguala al nodo min
	    eliminarNodo(min);// se elimina el nodo minimo
	}
	else if(nodo->izquierda){ // si tiene un hijo izq
		remplazar(nodo,nodo->izquierda); // se remplaza con el hijo izq
		destruir(nodo);// se borra el nodo
	} else if(nodo->derecha){// si tiene un hijo der
		remplazar(nodo,nodo->derecha);// se remplaza con el hijo der
		destruir(nodo);// se borra el nodo
	}else{
		remplazar(nodo,NULL);
		destruir(nodo);
	}
}
//Funcion para obtener el nodo mas izq del arbol desde el nodo seleccionado
Nodo* minimo(Nodo* nodo){
	if(!nodo) return NULL; // si el nodo no contiene nada retorna nulo
	if(nodo->izquierda) // si el nodo tiene hijos en la izquierda
	minimo(nodo->izquierda); // se vuelve a llamar a la funcion misma pero en el hijo izquierdo
	else return nodo; // si no hay mas hijos izquierdos se retorna el nodo
}
//Funcion para intercambiar dos nodos
void remplazar(Nodo* arbol,Nodo* nodo){
	if(arbol->padre){
		if(arbol->dato==arbol->padre->izquierda->dato) //si arbol es igual al hijo izq de su padre 
		arbol->padre->izquierda = nodo; // su nuevo hijo es nodo
		else arbol->padre->derecha = nodo;// caso contrario el nuevo nodo va hacia la der
	}
	if(nodo){
		// El nuevo nodo le damos su nuevo padre 
		nodo->padre = arbol->padre;
	}
}
void destruir(Nodo* nodo){
	nodo->derecha=nodo->izquierda=nodo->padre=NULL;// se igualan los hijos y padre a nulo
	delete nodo;// se borra el nodo
}
