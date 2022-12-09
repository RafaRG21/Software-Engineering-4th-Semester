#include<iostream>
#include<string>
using namespace std;
class Nodo {
   public: //Creacion de la clase Nodo
   	int dato;
   	Nodo *siguiente;
};
class Lista {
	private:
		Nodo *lista; // declaracion de la lista de tipo Nodo
   public:
    Lista();//Constructor
    ~Lista();//Destructor
    void InsertarNodo(int n){
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
    void BorrarNodo(int);
    void BorrarLista();
    void MostrarLista(){
    	Nodo *actual = new Nodo;
	actual = lista;
	while(actual!=NULL){
		cout<<actual->dato<<"->";
		actual = actual->siguiente;
	}if(actual==NULL) cout<<"NULL";
	cout<<endl;
	}    
};
Lista::Lista(){

	lista = NULL;
}
Lista::~Lista(){
	
};

void Lista::BorrarNodo(int n){
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
		cout<<"\nElmento "<<n<<" eliminado"<<endl;
	} 
	else{
		anterior->siguiente = aux_borrar->siguiente;
		delete aux_borrar;
		cout<<"\nElmento "<<n<<" eliminado"<<endl;		
	}
	
}
}
void Lista::BorrarLista(){
	cout<<"\nBorrando lista..."<<endl;
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
int main(){
	Lista lis;
	lis.InsertarNodo(1);
	lis.InsertarNodo(5);
	lis.InsertarNodo(8);
	lis.InsertarNodo(2);
	lis.InsertarNodo(7);
	lis.InsertarNodo(4);
	lis.InsertarNodo(10);
	lis.InsertarNodo(3);
	lis.InsertarNodo(6);
	lis.InsertarNodo(9);
    lis.MostrarLista();
	lis.BorrarNodo(5);
	lis.BorrarNodo(10);
	lis.BorrarNodo(2);
	lis.MostrarLista();
	lis.BorrarLista();
	lis.MostrarLista();	
	return 0;
}
