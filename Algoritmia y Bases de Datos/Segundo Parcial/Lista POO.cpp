#include<iostream>
using namespace std;

class Nodo{
	private:
		int dato;
		Nodo *siguiente;
		friend class Lista;
	public:
		//Constructor
		Nodo(int n, Nodo *sig=NULL){
			dato = n;
			siguiente  = sig;
		}
};
typedef Nodo *pNodo;
class Lista{
	private:
		pNodo actual;
	public:
		//Constructor
		Lista(){
			actual = NULL;
		}
		//Destructor
		~Lista();
		//Funciones
		void insertarNodo(int n);
        void mostrarLista();
        void buscarNodo(int n);
        void borrarNodo(int n);
        void borrarLista();
        bool ListaVacia(){
        	return actual == NULL;
		}
};
Lista::~Lista(){
	pNodo nodo;
	while(actual->siguiente!=actual){
		nodo = actual->siguiente;
		actual->siguiente = nodo->siguiente;
		delete nodo;
	}
	//Se borra el ultimo nodo
	delete actual;
	actual = NULL;
}
void Lista::insertarNodo(int n){
	pNodo nuevo = new Nodo(n); //se inicializan con el constructor y el dato
	pNodo anterior = new Nodo(n);

	if(ListaVacia()||actual->dato>=n){ // Si lista esta vacia o el dato de actual es mayor o igual a n
    nuevo->siguiente = actual;
    actual = nuevo;
	}else{
	anterior = actual;
	while(anterior->siguiente && anterior->siguiente->dato<=n){
		anterior = anterior->siguiente;
	}
	nuevo->siguiente = anterior->siguiente;
	anterior->siguiente = nuevo;
}}
void Lista::buscarNodo(int n){
	pNodo nodo=actual;
 	bool encontrado = false;
	 while(nodo&&nodo->dato<=n){
	 	if(nodo->dato==n) encontrado = true;
	 	nodo = nodo->siguiente;
	 } 
	 if(encontrado)
	   cout<<"Dato "<<n<<" encontrado"<<endl;
	   else 	   
	   cout<<"Dato "<<n<<" no encontrado"<<endl;
}
void Lista::mostrarLista(){
	pNodo nodo = actual;
	if(ListaVacia()) 	
	cout<<"Lista vacia"<<endl;
	else{
	while(nodo){
		cout<<nodo->dato<<"->";
		nodo = nodo->siguiente;
	}cout<<"NULL"<<endl;
}
}
void Lista::borrarNodo(int n){
	pNodo anterior, nodo = actual;
 	anterior = NULL;
 	while(nodo&&nodo->dato<n){
 		anterior = nodo;
 		nodo = nodo->siguiente;
	 }
 	if(!nodo||nodo->dato!=n){
 		cout<<"No se encontro "<<n<<" , no se pudo eliminar"<<endl;
 		return;
	 }
	 else{
	 	if(!anterior) actual = nodo->siguiente;
	 	else{
	 		anterior->siguiente = nodo->siguiente;
	 		delete nodo;
		 }
	 }
	 cout<<"Nodo "<<n<<" eliminado"<<endl;
}
void Lista::borrarLista(){
	pNodo nodo;
  	while(actual){
  		nodo = actual;
  		actual = nodo->siguiente;
  		delete nodo;
	  }
}
int main(){
	Lista lista;
	int dato , opc; 
	do{
    cout<<"Listas simplemente enlazadas"<<endl;
    cout<<"1.- Ingresar nodo"<<endl;
    cout<<"2.- Mostrar Lista"<<endl;
    cout<<"3.- Buscar nodo"<<endl;
    cout<<"4.- Borrar nodo"<<endl;
    cout<<"5.- Borrar Lista"<<endl;
    cout<<"6.- Salir"<<endl;
    cout<<"Opcion a elegir: ";
    cin>>opc;
    switch(opc){
    	case 1:
    		cout<<"Ingresa un numero: ";
    		cin>>dato;
    		lista.insertarNodo(dato);
    		cout<<endl;
    		break;
    	case 2: 
    	    cout<<"Lista:"<<endl;
    	    lista.mostrarLista();
    	    cout<<endl;
    	    break;
    	case 3:
		    cout<<"Nodo a buscar: ";
    	    cin>>dato;
    	    lista.buscarNodo(dato);
    	    cout<<endl;
    	    break;
    	case 4:
		    cout<<"Nodo a borrar: ";
			cin>>dato;
			lista.borrarNodo(dato);
			cout<<endl;
			break;
		case 5: 
		    lista.borrarLista();
			cout<<"Lista eliminada"<<endl;
			break;	    
		case 6: 
		    break;
		default: 
		    cout<<"Opcion no válida"<<endl;
		    break;	
    	
	}
	system("pause");
	system("cls");
	}while(opc!=6);
		
	return 0;
}
