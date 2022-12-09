#include <iostream>

using namespace std;

class nodo{
	public:
		nodo(int v, nodo *sig = NULL){
			valor=v;
			siguiente=sig;
		}
		
	private:
		int valor;
		nodo *siguiente;
		
		friend class lista;
};

typedef nodo *pNodo;

class lista{
	public:
		lista(){
			actual = NULL;
		}
		~lista();
		//Declaracion de funciones 
		void Insertar(int v);
		void Borrar(int v);
		bool ListaVacia(){ return actual=NULL;}
		void Mostrar();
		void Siguiente();
		bool Actual(){ return actual!=NULL;}
		int ValorActual(){return actual->valor;}
	private:
		pNodo actual;
};

lista::~lista(){
	pNodo nodo;
	//Mientras la lista tenga mas de un nodo
	while(actual->siguiente != actual){
		nodo = actual->siguiente;
		actual->siguiente = nodo->siguiente;
		delete nodo;
	}
	//Borrar el ultimo nodo
	delete actual;
	actual=NULL;
}

void lista::Insertar(int v){
	pNodo Nodo;
	//Crear un Nodo
	Nodo = new nodo(v);
	//si la lista esta vacia, la lista sera el nuevo nodo
	if(actual==NULL)actual=Nodo;
	//en caso contrario se inserta el nuevo nodo en el siguiente elemento de la lista
	else Nodo->siguiente = actual->siguiente;
	//Cerrar lista circular
	actual->siguiente=Nodo;
}

void lista::Borrar(int v){
	pNodo nodo;
	nodo = actual;
	//Hacer que la lista apunte al nodo anterior al valor v
	do{
		if(actual->siguiente->valor != v){
			actual=actual->siguiente;
		}
	}while(actual->siguiente->valor != v && actual != nodo);
	//Si existe un nodo con el valor v
	if(actual->siguiente->valor == v){
		//Si la lista solo tiene un nodo
		if(actual==actual->siguiente){
			delete actual;
			actual = NULL;
		}else{
			//Si la lista tiene mas de un nodo borrar el nodo del valor v
			nodo = actual->siguiente;
			actual->siguiente = nodo->siguiente;
			delete nodo;
		}
	}
}

void lista::Mostrar(){
	pNodo nodo;
	nodo = actual;
	do{
		cout<<nodo->valor<<" -> ";
		nodo=nodo->siguiente;
	}while(nodo != actual);
	cout<<endl;
}

void lista::Siguiente(){
	if(actual)actual=actual->siguiente;
}

int main(int argc, char** argv) {
	lista Lista;
	Lista.Insertar(1);
	Lista.Insertar(2);
	Lista.Insertar(3);
	Lista.Insertar(4);
	Lista.Insertar(5);
	Lista.Mostrar();
	Lista.Borrar(3);
	Lista.Mostrar();
	return 0;
}
