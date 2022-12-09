#include<iostream>
using namespace std;

class Nodo{
	private:
		int dato;
		Nodo *siguiente;
		friend class Lista;
	public:
		Nodo(int v, Nodo *sig = NULL){
			dato = v;
			siguiente = sig;
		}
};
typedef Nodo *pNodo;
class Lista{
	private:
		pNodo actual;
		pNodo ultimo;
	public:
		Lista(){
			actual = NULL;
		}
		~Lista();
		void insertarNodo(int n);
        void mostrarLista();
        void buscarNodo(int n);
        void borrarNodo(int n);
       

};
Lista::~Lista(){
	pNodo nodo;
	while(actual->siguiente!=actual) {  //mientras la lista tenga mas de un nodo
		//borrar el nodo siguiente al apuntado por la lista
		nodo=actual->siguiente;
		actual->siguiente=nodo->siguiente;
		delete nodo;
	}
	 //borrar ademas el ultimo nodo
	delete actual;
	actual=NULL;
}
void Lista::insertarNodo(int n){
	pNodo nuevo = new Nodo(n);
	if(!actual){ //si lista es null o esta vacio
		actual = nuevo; // la lista es igual al nuevo dato
		actual->siguiente = nuevo; //y lista->siguiente apunta a si mismo 
		ultimo = nuevo; // y tambien el ultimo es igual a nuevo 
	}
	else{ // si la lista circular no esta vacia
		ultimo->siguiente = nuevo; // ultimo->siguiente es igual al nuevo nodo
		nuevo->siguiente = actual; // y nuevo->siguiente es igual a lista para cerrar el circulo
		ultimo = nuevo; //ultimo es el nuevo nodo ingresado
	}
}
void Lista::mostrarLista(){
	pNodo nodo;
	nodo = actual;
	if(actual){ // si la lista no es null
	do{
		cout<<nodo->dato<<"->"; // se imprime el dato
		nodo = nodo->siguiente; // se mueve actual al siguiente nodo
	}while(actual!=nodo); //para que no entre en un bucle infiinito ya que todo esta enlazado
	cout<<endl;
   }else cout<<"\nLa lista esta vacia"<<endl;
}
void Lista::buscarNodo(int n){
	pNodo nodo = actual;
	bool encontrado = false;
	if(actual){
		do{
			if(nodo->dato==n){ // si actual->dato es igual al dato buscado
				cout<<"\nDato "<<nodo->dato<<" encontrado"<<endl;
				encontrado = true; // encontrado es igual a true
			}
			nodo = nodo->siguiente;   // actual se sigue desplazando
		}while(actual!=nodo&&encontrado!=true); 
		
	if(!encontrado) cout<<"\nDato "<<n<<" no encontrado"<<endl; 
	}else cout<<"\nLa lista esta vacia"<<endl;
}
void Lista::borrarNodo(int n){
	pNodo nodo= actual;
	if(actual){
	 do{
	 	//hace si no hay un valor y no hay nodo
	 	if(actual->siguiente->dato!=n)
	 	
		 actual=actual->siguiente;
		 
	    }while(actual->siguiente->dato!=n && actual != nodo);
	 
	 if(actual->siguiente->dato==n){
	 	if(actual == actual->siguiente){ // cuando es solo un nodo en la lista circular
	 		//borra toda la lista
	 		delete actual;
	 		actual = NULL;
	 	}
	 	else{
	 		nodo=actual->siguiente;
	 		actual->siguiente=nodo->siguiente;
	 		delete nodo;
		    }
	 		
     	}else{
	    	cout<<"\nDato "<<n<<" no encontrado.\nNo se pudo eliminar"<<endl;
    	}
   }else cout<<"\nLista Vacia"<<endl;
}
int main(){
	int opc,valor;
	Lista lista;
	do{
		cout << "\n|      ° LISTA CIRCULAR SIMPLE °      |";
		cout << "\n| 1. Insertar      | 4. Eliminar Dato |";
		cout << "\n| 2. Mostrar       | 5. Eliminar Lista|";   
		cout << "\n| 3. Buscar        | 6. Salir         |";
		cout << "\n Seleccione una Opcion: ";
		cin >> opc;
		switch(opc){
		case 1:
			cout << "INSERTA NODO EN LA LISTA:";
			cin>>valor;
			lista.insertarNodo(valor);
			break;
		case 2:
			cout << "LISTA CIRCULAR:";
			lista.mostrarLista();
			break;
		case 3:
			cout << "Inserta Nodo a buscar:";
			cin>>valor;
			lista.buscarNodo(valor);
			break;
		case 4:
			cout << "Inserta Nodo a eliminar:";
			cin>>valor;
			lista.borrarNodo(valor);
			break;
		case 5: 
			cout << "ELIMINAR LISTA CIRCULAR \n\n";
			lista.~Lista();
			cout<<"\nLISTA BORRADA"<<endl;
			break;
		case 6: break;
		default:
			cout << "Opcion No Valida \n\n";
		}
	} while (opc != 6);

	return 0;
}
