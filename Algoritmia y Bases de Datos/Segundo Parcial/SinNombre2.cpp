#include<iostream>
#include<string>
using namespace std;

struct Nodo{
	int dato;
	struct Nodo *siguiente;
};
Nodo *lista = NULL;

void insertarlista(Nodo *&,int);
void mostrarlista(Nodo *);
void buscarnodo(Nodo *,int);
void eliminarnodo(Nodo *&,int);
void borrarlista(Nodo *&);
void menu();
int main(){
    menu();
    return 0;	
}
void menu(){
	int opc=0,n;
	do{
		n=0;
		cout<<"\n\t|Listas|"<<endl;
		cout<<"1.- Agregar elemento a la lista."<<endl;
		cout<<"2.- Mostrar elementos de la lista."<<endl;
		cout<<"3.- Buscar elemento en la lista."<<endl;
		cout<<"4.- Borrar elemento de la lista."<<endl;
		cout<<"5.- Vaciar lista."<<endl;
		cout<<"6.- Salir."<<endl;
		cout<<"Elige una opcion: "; cin>>opc;
		switch(opc){
			case 1:
				cout<<"\nElemento a agregar: ";
				cin>>n;
				insertarlista(lista,n);
				break;
			case 2:
				cout<<"\nElementos de la lista: "<<endl;
				mostrarlista(lista);
				system("pause");
				break;
			case 3:
				cout<<"\nIngresar elemento a buscar: ";
				cin>>n;
				buscarnodo(lista,n);
				system("pause");
				break;
			case 4:
				if(lista==NULL) cout<<"\nLista vacia"<<endl;
				else{
				cout<<"\nIngresar elemento a borrar: ";
				cin>>n;
				eliminarnodo(lista,n);
			    }
			    system("pause");
				break;
			case 5: 
			    if(lista==NULL) cout<<"Lista vaciada"<<endl;
			    else{
			    borrarlista(lista);}
				system("pause");	
			default:
				break;
		}

		system("cls");
	}while(opc!=6);
}
void insertarlista(Nodo *&lista,int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	Nodo *aux1 = lista;
	Nodo *aux2;
	while(aux1!=NULL&&aux1->dato<n){
		aux2 = aux1;
		aux1 = aux1->siguiente;
	}
	if(lista==aux1)
	lista = nuevo_nodo;
	else
	aux2->siguiente = nuevo_nodo; 
	nuevo_nodo->siguiente = aux1;
	
}
void mostrarlista(Nodo *lista){
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual!=NULL){
		cout<<actual->dato<<"->";
		actual = actual->siguiente;
	}if(actual==NULL) cout<<"NULL";
	cout<<endl;
}
void buscarnodo(Nodo *lista,int n){
	bool band = false;
	Nodo *actual = new Nodo();
	actual = lista;
	while(actual!=NULL&&actual->dato<=n){
		if(actual->dato==n)
		band = true;
		actual = actual->siguiente;
	}
	if(band) cout<<"\nElemento "<<n<<" encontrado en la lista"<<endl;
	else cout<<"\nElemento "<<n<<" no encontrado en la lista"<<endl;
}
void eliminarnodo(Nodo *&lista,int n){
	if(lista!=NULL){
	Nodo *aux_borrar;
	Nodo *anterior=NULL;
	
	aux_borrar = lista;		
	while(aux_borrar!=NULL&&aux_borrar->dato!=n){
		anterior = aux_borrar;
		aux_borrar = aux_borrar->siguiente;
	}
	if(aux_borrar==NULL) cout<<"Elemento NO encontrado"<<endl;
	else if(anterior==NULL){
		lista = lista->siguiente;
		delete aux_borrar;
		cout<<"\nElmento eliminado"<<endl;
	} 
	else{
		anterior->siguiente = aux_borrar->siguiente;
		delete aux_borrar;
		cout<<"\nElmento eliminado"<<endl;		
	}
	
}}
void borrarlista(Nodo *&lista){
	int n;
	Nodo *aux = new Nodo();
	while(lista!=NULL){
	aux = lista;
	n = aux->dato;
	lista = lista->siguiente;
	cout<<n<<"->";
	delete aux;
}cout<<"NULL"<<endl;
cout<<"\nLista borrada"<<endl;
}
