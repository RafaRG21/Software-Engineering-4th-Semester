#include <iostream>
#include <stdio.h>

using namespace std;

class nodo {
   public:
    nodo(char v, nodo *sig = NULL) {//funcion nodo que tiene un cato y un puntero que al inicio apunta a null
       dato = v;   //el valor de retorno se guarda en dato
       siguiente = sig;  // el valor de sig sse guarda en siguiente
    }
   private:
    char dato;         //los protagonista de la clase el dato y el puntero nodo
    nodo *siguiente;  // puntero siguiente  de tipo noto
   friend class pila; // acceso a esta clase desde pila
};
typedef nodo *pnodo;   //se define el typo nodo del puntero

class pila {
   public:
    pila() : ultimo(NULL) {}
    ~pila();

    void Push(char v);
    char Pop();

   private:
    pnodo ultimo;
};

// funcion de caso particular de pila que verifica si la pila esta vacia

pila::~pila() {
   while(ultimo) Pop();
}

//funcion  de inseratar calor
void pila::Push(char v) {
   pnodo nuevo;       // declaracion de nuevo

nuevo = new nodo(v, ultimo);  //crear un nuevo nodo
ultimo = nuevo;         // el comienzo de esta pila es en nuevo nodo
}

char pila::Pop() {
   pnodo nodo;    // variable que manipula ell nodo
   char v;        // variable que retorna

   if(!ultimo) return '0';       //si no hay nodos retorna 0
         nodo = ultimo;         // nodo apunta al primer elemento de la pila
         ultimo = nodo->siguiente;   //asignamos a pila toda la pila menos el primer elemento
          v = nodo->dato;      //guardamos el valor de retorno 
         delete (nodo);          //borrar nodo
   return v;
}


int main(int argc, char** argv) {
	pila Pila;
	
	Pila.Push('a');
	cout<<"Push(a) <-";
	Pila.Push('b');
	cout<<"Push(b) <-";
	Pila.Push('c');
	cout<<"Push(c) <-";
	Pila.Push('d');
	cout<<"Push(d) <-";
	Pila.Push('e');
	cout<<"Push(e) <-"<<endl;
	cout<<"Pop()= "<<Pila.Pop()<<endl;
	cout<<"Pop()= "<<Pila.Pop()<<endl;
	cout<<"Pop()= "<<Pila.Pop()<<endl;
    cout<<"Pop()= "<<Pila.Pop()<<endl;
    cout<<"Pop()= "<<Pila.Pop()<<endl;	
    cout<<"Pop()= "<<Pila.Pop()<<endl;	
	
	
	return 0;
}
