#include <iostream>
#include <conio.h>
using namespace std;

void menu();

class Nodo {
    public:
    int dato;
    Nodo* siguiente;
};

class List{
    private:
    Nodo* head;
    public:
        List()
        {
            head = NULL;
        }
        void insertarList(int d)
        {
            Nodo* n = new Nodo;
            n->dato = d;
            n->siguiente = NULL;

            if(head == NULL){
                head = n;
            }else{
                Nodo* temp = head;
                while (temp->siguiente != NULL)
                    temp = temp->siguiente;
                    temp->siguiente = n;
            }
        }

        void mostrarList()
        {
            Nodo* temp = head;
            if(temp == NULL) {cout<<"La lista esta vacia"; }
            while (temp != NULL)
            {
                cout<<temp->dato<< " -> ";
                temp = temp->siguiente;
            }
            cout<<endl;
        }

        
    void eliminarNodo(int n){
	    if(head != NULL){
		    Nodo *aux_borrar;
		    Nodo *anterior = NULL;
		
		    aux_borrar = head;
		    while((aux_borrar != NULL) && (aux_borrar->dato !=n)){
			    anterior = aux_borrar;
			    aux_borrar = aux_borrar->siguiente;
		    }
		
		    if(aux_borrar == NULL){
			    cout<<"El elemento no ha sido encontrado";
		    }
		    else if (anterior == NULL){
			    head = head->siguiente;
			    delete aux_borrar;
			    cout<<"El elemento ha sido eliminado";
		    }
		    else{
			    anterior->siguiente = aux_borrar->siguiente;
			    delete aux_borrar;
			    cout<<"El elemento ha sido eliminado";
		    }
	    }else{ cout << "La lista esta vacia"; }
    }

    void eliminarLista(){
        int n;
        while (head != NULL){
	        Nodo *aux = head;
	        n = aux->dato;
            cout<<n<<" -> ";
	        head = aux->siguiente;
	        delete aux;
        }
    }
};

List l;
int dato;


void menu(){
	int opcion;
	do{
		cout<<"\t MENU \n";
		cout << "1. Insertar elementos a la lista \n";
		cout << "2. Mostrar elementos de la lista \n";
		cout << "3. Eliminar un nodo de la lista \n";
		cout << "4. Eliminar Lista \n";
		cout << "5. Salir \n";
		cout << "Digite la opcion: ";
		cin>>opcion;
		
		switch(opcion){
			case 1 : 
						cout<<"\nDigite un numero: ";
						cin>>dato;
						l.insertarList(dato);
						cout<<"\n";
						system("pause");
						break;
			case 2 : 
						l.mostrarList();
						cout<<"\n";
						system("pause");
						break; 
            case 3 : 
						cout<<"\nDigite nodo a eliminar: ";
						cin>>dato;
						l.eliminarNodo(dato);
						cout<<"\n";
						system("pause");
						break;
            case 4:     
						l.eliminarLista();
						cout<<"\n";
						system("pause");
						break;
			
		}
		
		system("cls");
	}while(opcion !=5);
}


int main(){
    menu();

}
