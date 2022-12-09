#include<iostream>
using namespace std;

typedef struct Nodo{
	char dato;
	struct Nodo *siguiente;
}tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *ListaCirc;
void insertarNodo(ListaCirc *lista,char n);
void mostrarLista(ListaCirc lista);
void buscarNodo(ListaCirc lista,char n);
void borrarNodo(ListaCirc *lista,char v);
void borrarLista(ListaCirc *lista);
ListaCirc lista=NULL;
pNodo primero = lista, ultimo=NULL;
int main(){
    int tam = 0;
    char letra;
    cout<<"Ingrese el numero de letras a introducir"<<endl;
    cin>>tam;
    for(int i=0;i<tam;i++){
    	cout<<"Inserte una letra"<<endl;
    	cin>>letra;
    	insertarNodo(&lista,letra);
	}
	mostrarLista(lista);
	borrarLista(&lista);
	return 0;
}
void insertarNodo(ListaCirc *lista,char n){
	pNodo nuevo = new Nodo();
	nuevo->dato = n;
	if(!*lista){ //si lista es null o esta vacio
		*lista = nuevo; // la lista es igual al nuevo dato
		(*lista)->siguiente = nuevo; //y lista->siguiente apunta a si mismo 
		ultimo = nuevo; // y tambien el ultimo es igual a nuevo 
	}
	//8->7->primero nuevo=5
	else{ // si la lista circular no esta vacia
		ultimo->siguiente = nuevo; // ultimo->siguiente es igual al nuevo nodo
		nuevo->siguiente = *lista; // y nuevo->siguiente es igual a lista para cerrar el circulo
		ultimo = nuevo; //ultimo es el nuevo nodo ingresado
	}
}
void mostrarLista(ListaCirc lista){
	pNodo actual;
	actual = lista;
	if(lista){ // si la lista no es null
	do{
		cout<<actual->dato<<"->"; // se imprime el dato
		actual = actual->siguiente; // se mueve actual al siguiente nodo
	}while(lista!=actual); //para que no entre en un bucle infiinito ya que todo esta enlazado
	cout<<endl;
   }else cout<<"\nLa lista esta vacia"<<endl;
}
void buscarNodo(ListaCirc lista,char n){
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

void borrarNodo(ListaCirc *lista,char v){
		pNodo nodo= *lista;
	 do{
	 	//hace si no hay un valor y no hay nodo
	 	if((*lista)->siguiente->dato!=v)
	 	
		 *lista=(*lista)->siguiente;
		 
	 }while((*lista)->siguiente->dato!=v && *lista != nodo);
	 
	 if((*lista)->siguiente->dato==v){
	 	if(*lista == (*lista)->siguiente){
	 		//borra toda la lista
	 		delete *lista;
	 		*lista=NULL;
	 	}
	 	else{
	 		
	 		nodo=(*lista)->siguiente;
	 		(*lista)->siguiente=nodo->siguiente;
	 		delete nodo;
		 }
	 		
		 }
}
void borrarLista(ListaCirc *lista){
		pNodo nodo;
	
	while((*lista)->siguiente!=*lista) {  //mientras la lista tenga mas de un nodo
		//borrar el nodo siguiente al apuntado por la lista
		nodo=(*lista)->siguiente;
		(*lista)->siguiente=nodo->siguiente;
		delete nodo;
	}
	
	 //borrar ademas el ultimo nodo
	delete *lista;;
	*lista=NULL;
}
