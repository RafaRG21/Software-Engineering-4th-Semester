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
    int tam = 0,opc = 0;
    char letra;
    cout<<"Ingrese el numero de letras a introducir"<<endl;
    cin>>tam;
    for(int i=0;i<tam;i++){
    	cout<<"Inserte una letra"<<endl;
    	cin>>letra;
    	insertarNodo(&lista,letra);
	}
	mostrarLista(lista);
	do{
	cout<<"\n1.-Buscar Nodo en lista"<<endl;	
	cout<<"\n2.-Mostrar lista"<<endl;
	cout<<"\n3.-Borrar Nodo en lista"<<endl;
	cout<<"\n4.-Borrar Lista"<<endl;
	cout<<"\n5.-Salir"<<endl;	
	cout<<"\nElegir opcion:";
	cin>>opc;	
	//NODO
	switch(opc){
		case 1:
			cout<<"\nNodo a buscar:";
			cin>>letra;
			buscarNodo(lista,letra);
			break;
		case 2:
		    cout<<"\nLista:";
		    mostrarLista(lista);
		    break;
		case 3:
		    cout<<"\nNodo a eliminar:";
			cin>>letra;	
			borrarNodo(&lista,letra);
			break;
		case 4:
			cout<<"\nEliminando Lista...";
			borrarLista(&lista);
			cout<<"Lista borrada\n";
			break;
		case 5: break;
		default:
		cout<<"\nOpcion no valida\n"; 
	}			
	
	}while(opc!=5);
	return 0;
}
void insertarNodo(ListaCirc *lista,char n){
	pNodo nuevo = new Nodo();
	nuevo->dato = n;
	if(!*lista){ 
		*lista = nuevo; 
		(*lista)->siguiente = nuevo; 
		ultimo = nuevo; 
	}
	
	else{ 
		ultimo->siguiente = nuevo; 
		nuevo->siguiente = *lista; 
		ultimo = nuevo; 
	}
}
void mostrarLista(ListaCirc lista){
	pNodo actual;
	actual = lista;
	if(lista){ 
	do{
		cout<<actual->dato<<"->"; 
		actual = actual->siguiente; 
	}while(lista!=actual); 
	cout<<endl;
   }else cout<<"\nLa lista esta vacia"<<endl;
}
void buscarNodo(ListaCirc lista,char n){
	pNodo actual = lista;
	bool encontrado = false;
	if(lista){
		do{
			if(actual->dato==n){ 
				cout<<"\nDato "<<actual->dato<<" encontrado"<<endl;
				encontrado = true; 
			}
			actual = actual->siguiente;  
		}while(lista!=actual&&encontrado!=true); 
		
	}if(!encontrado) cout<<"\nDato "<<n<<" no encontrado"<<endl; 
}

void borrarNodo(ListaCirc *lista,char v){
		pNodo nodo= *lista;
	 do{

	 	if((*lista)->siguiente->dato!=v)
	 	
		 *lista=(*lista)->siguiente;
		 
	 }while((*lista)->siguiente->dato!=v && *lista != nodo);
	 
	 if((*lista)->siguiente->dato==v){
	 	if(*lista == (*lista)->siguiente){

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
	
	while((*lista)->siguiente!=*lista) { 

		nodo=(*lista)->siguiente;
		(*lista)->siguiente=nodo->siguiente;
		delete nodo;
	}
	
	delete *lista;;
	*lista=NULL;
}
