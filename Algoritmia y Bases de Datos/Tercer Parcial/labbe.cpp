// Árboles

#include <iostream>

using namespace std;

typedef struct Nodo {
    string dato;
    Nodo* der;
    Nodo* izq;
    Nodo* padre;
}nodo;
typedef nodo* raiz;
Nodo *crearNodo(string);
void mostrarArbol(Nodo*, string);
bool busqueda(Nodo*, string);
void preOrden(Nodo*);
void inOrden(Nodo*);
void postOrden(Nodo*);

struct Nodo* arbol = new Nodo();
arbol = crearNodo("A3");
arbol->der = crearNodo("B3");

int main()
{
	int cont=0;
    
}

//Función para crear un nuevo nodo
Nodo* crearNodo(string n) {
    Nodo* nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

//Función para mostrar el arbol
void mostrarArbol(Nodo* arbol, int cont) {
    if (arbol == NULL) {
        return;
    }
    else {
        mostrarArbol(arbol->der, cont + 1);
        for (int i = 0; i < cont; i++) {
            cout <<"    ";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izq, cont + 1);
    }
}

// Funcion para recorrido en profundidad - PreOrden
void preOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        cout << arbol->dato << " - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}
// Funcion para recorrido en profundidad - InOrden
void inOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        inOrden(arbol->izq);
        cout << arbol->dato << " - ";
        inOrden(arbol->der);
    }
}
// Funcion para recorrido en profundidad - PostOrden
void postOrden(Nodo* arbol) {
    if (arbol == NULL) {
        return;
    }
    else {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->dato << " - ";
    }
}

