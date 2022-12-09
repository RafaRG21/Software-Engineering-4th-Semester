#include<iostream>
using namespace std;
//ESTRUCTURA ARBOL
struct Arbol{
	string dato;
	Arbol *der;
	Arbol *izq;
};
//ESTRUCTURA PILA
typedef struct Nodo{
	string dato;
	Nodo *siguiente;
	
}tipoNodo;
typedef tipoNodo *pNodo;
typedef tipoNodo *Pila;

//FUNCIONES
//ARBOL
void insertarLaberinto(Arbol* nodo);
Arbol *nuevonodo(string dato);
bool crearCamino(Arbol *laberinto, string dato);
void mostrarCamino(Pila* pila);
void mostrarLaber();
//PILA
  void Push(Pila *L, string v);
  string Pop(Pila *L);
  Pila pila=NULL;
  int main(){
  	string dat;
  	int opc=0;
  	Arbol* raiz = nuevonodo("D1");
  	insertarLaberinto(raiz);
  	mostrarLaber();
  	cout<<endl;
	cout<<"Ingresa el dato a buscar: ";
	cin>>dat;
	if(crearCamino(raiz,dat))
  	mostrarCamino(&pila);
  	else cout<<"No hay camino";
  	return 0;
  }
  //FUNCIONES ARBOL
  Arbol *nuevonodo(string dato){
    Arbol* nodo = new Arbol();
    nodo->dato=dato;
    nodo->izq=nodo->der=NULL;
    return nodo;
} //Algoritmo para buscar el nodo seleccionado basado en la busqueda en profundidad preorden
bool crearCamino(Arbol *laberinto, string dato){
	if(laberinto==NULL) //Se verifica si el nodo esta vacio
	return false;
	// se agrega el dato del nodo actual a la pila
	Push(&pila,laberinto->dato);
	//se verifica si es igual el dato actual al dato buscado
	if(laberinto->dato == dato)
	return true;
	// Se llama de nuevo la funcion para verificar si se encuentra en la rama izquierda el dato
	if(crearCamino(laberinto->izq, dato))
	return true;
	//sino se encuentra se busca por la rama derecha
	else if(crearCamino(laberinto->der, dato))
	return true;
	//si no se encuentra en ninguna de las dos ramas se elimina el nodo con la funcion Pop()
	Pop(&pila);
	return false;
}
void mostrarCamino(Pila* pila){
	pNodo nodo = new Nodo();  // se crea un nodo para guardar la pila
	nodo = *pila;
	string array[64]; //se crea un arreglo para guardar los datos de la pila
	int cont=0; 
	while(nodo){ // mientras el nodo no sea nulo el arreglo recibe los datos que arroja pop
		array[cont] = Pop(&nodo);
		cont++;
		
	}
	for(int i=cont-1; i>=0;i--){ //Imprime el arreglo de manera inversa
		cout<<array[i];
		if(i!=0) cout<<"->";
	}
}

void insertarLaberinto(Arbol* nodo){
	//Se inserta el laberinto al arbol
   	Arbol* raiz = nodo;
   	raiz->der=nuevonodo("E1");
   	raiz->der->der=nuevonodo("F1");
   	raiz->der->der->der=nuevonodo("F2");
   	raiz->der->der->der->der=nuevonodo("E2");
   	raiz->der->der->der->der->der=nuevonodo("D2");

   	raiz->der->der->der->der->izq=nuevonodo("E3"); 	//Camino alterno en E2
   	
   	raiz->der->der->der->der->der->der=nuevonodo("C2");
   	raiz->der->der->der->der->der->der->der=nuevonodo("C1");
   	raiz->der->der->der->der->der->der->der->der=nuevonodo("B1");
   	raiz->der->der->der->der->der->der->der->der->der=nuevonodo("B2");
   	//Camino alterno en B1
   	raiz->der->der->der->der->der->der->der->der->izq=nuevonodo("A1");
   	raiz->der->der->der->der->der->der->der->der->izq->der=nuevonodo("A2");
   	raiz->der->der->der->der->der->der->der->der->izq->der->der=nuevonodo("A3");
   	
   	raiz->der->der->der->der->der->der->der->der->der->der=nuevonodo("B3");
   	raiz->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("B4");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("A4");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("A5");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("B5");
   	
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->izq=nuevonodo("A6"); //Camino alterno en A5
   	
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("C5");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("C4");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("C3");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("D3");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("D4");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("D5");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("E5");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("E4");
   	//Camino alterno en E5
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq=nuevonodo("F5"); 
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->der=nuevonodo("G5");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->der->der=nuevonodo("G4");
   	//camino alterno en F5
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->izq=nuevonodo("F6");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->izq->der=nuevonodo("F7");
   	//Camino alterno en F6
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->izq->izq=nuevonodo("E6");
   	
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("F4");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("F3");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("G3");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("G2");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("G1");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("H1");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("H2");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("H3");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("H4");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("H5");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("H6");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("G6");
   	//Camino alterno en H6
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq=nuevonodo("H7");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->der=nuevonodo("H8");
   	
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("G7");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("G8");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("F8");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("E8");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("E7");
   	//Camino alterno en E8
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq=nuevonodo("D8");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->der=nuevonodo("C8");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->der->der=nuevonodo("B8");
   	//Camino alterno en C8
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->izq->der->izq=nuevonodo("C7");
   	
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("D7");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("D6");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("C6");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("B6");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("B7");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("A7");
   	raiz->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der->der=nuevonodo("A8");
   }
  void mostrarLaber(){
  char b= 178;
  	cout<<endl;	
  	//Se imprime el laberinto ilustrativo
	cout<<"   |  "<<"  1   2   3   4   5   6   7   8     |"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"   |           ->S                        |"<<endl;
	cout<<"   |  "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   |"<<endl;
	cout<<"A  |  "<<b<<"A1 "<<" A2 "<<" A3 "<<b<<"A4 "<<" A5 "<<" A6 "<<b<<"A7 "<<" A8"<<" ->S |  A"<<endl;
	cout<<"   |  "<<b<<"   "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<b<<b<<b<<b<<"   |"<<endl;
	cout<<"B  |  "<<b<<"B1 "<<" B2 "<<" B3 "<<" B4 "<<b<<"B5 "<<b<<"B6 "<<" B7 "<<b<<"B8"<<" "<<b<<"   |  B"<<endl;
	cout<<"   |  "<<b<<"   "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<"   |"<<endl;
	cout<<"C  |  "<<b<<"C1 "<<" C2 "<<b<<"C3 "<<" C4 "<<" C5 "<<b<<"C6 "<<b<<"C7 "<<" C8"<<" "<<b<<"   |  C"<<endl;
	cout<<"   |  "<<b<<b<<b<<b<<b<<"   "<<b<<"  "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<"   |"<<endl;
	cout<<"D  |I->"<<"D1 "<<b<<"D2 "<<b<<"D3 "<<" D4 "<<" D5 "<<b<<"D6 "<<" D7 "<<b<<"D8"<<" ->S |  D"<<endl;
	cout<<"   |  "<<b<<"   "<<b<<"   "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<"   "<<b<<"   |"<<endl;
	cout<<"E  |  "<<b<<"E1 "<<b<<"E2 "<<" E3 "<<b<<"E4 "<<" E5 "<<b<<"E6 "<<b<<"E7 "<<" E8"<<" "<<b<<"   |  E"<<endl;
	cout<<"   |  "<<b<<"   "<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<"   "<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<"   |"<<endl;
	cout<<"F  |  "<<b<<"F1 "<<" F2 "<<b<<"F3 "<<" F4 "<<b<<"F5 "<<" F6 "<<" F7 "<<b<<"F8"<<" "<<b<<"   |  F"<<endl;
	cout<<"   |  "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<b<<b<<b<<b<<"   "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<"   |"<<endl;
	cout<<"G  |S->"<<"G1 "<<" G2 "<<" G3 "<<b<<"G4 "<<" G5 "<<b<<"G6 "<<" G7 "<<" G8"<<" "<<b<<"   |  G"<<endl;
	cout<<"   |  "<<b<<"  "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"  "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   |"<<endl;
	cout<<"H  |  "<<b<<"H1 "<<" H2 "<<" H3 "<<" H4 "<<" H5 "<<" H6 "<<" H7 "<<" H8"<<" "<<b<<"   |  H"<<endl;
	cout<<"   |  "<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<b<<"   "<<b<<"   |"<<endl;
	cout<<"   |                              ->S     |"<<endl;
	cout<<"-----------------------------------------------"<<endl;
	cout<<"   |  "<<"  1   2   3   4   5   6   7   8     |"<<endl;
  } 
   

  //FUNCIONES PILA
 void Push(Pila *pila, string v){
 	
 	pNodo nuevo;
 	/* Crear un nuevo nodo*/
 	nuevo = new tipoNodo();
 	/*se asigna el valor v a nuevo->valor*/
 	nuevo->dato=v;
 	
 	/*Añadimos la pila a continuacion del nuevo nodo*/
 	nuevo->siguiente =*pila;
 	/*ahora el comienzo de nuestra pila es nuevo nodo*/
 	*pila=nuevo;
  }
  string Pop(Pila *pila){
  	pNodo nodo;
  	string v;
  	
  	/*Nodo apunta a primer elemento de la pila*/
  	nodo= *pila;
  	
  	if(!nodo) return 0; //si no hay nodos en la lista retornaremos a 0
  	
  	/*Asignamos a pila toda la pila menos el primer elemento */
  	
  	*pila=nodo->siguiente;
  	/*se guarda el valor v*/
  	v=nodo->dato;
  	
  	delete nodo;  //se libera el espacio del nodo utilizado*/
  	
  	return v;
  	
  	}  
