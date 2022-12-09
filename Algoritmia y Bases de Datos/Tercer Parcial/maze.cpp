#include<iostream>
#include<stdlib.h>
using namespace std;
#define m 20
#define p 20
int maze[m + 2][p + 2];
int mark[m + 2][p + 2];
void setMaze () {// Establece la forma y la salida del laberinto
	fill(maze[0], maze[0] + (m + 2)*(p + 2), 1);
	fill(mark[0], mark[0] + (m + 2)*(p + 2), 0);
	maze[0][0] = 0;
	int i, j;
	for (j = 1; j < 13; j++)maze[1][j] = 0;
	for (i = 1; i < 10; i++)maze[i][13] = 0;
	for (j = 7; j < p + 2; j++)maze[10][j] = 0;
	for (j = 0; j < p + 2; j++) {
		for (i = 0; i < m + 2; i++)cout << maze[i][j] << " ";
		cout << endl;
	}
}

 compensaciones de estructura {// coordenadas
	int a, b;
};
enum directions { N, NE, E, SE, S, SW, W, NW };
 struct Items {// El tipo de pila
	int x, y, dir;
	Items(int a = 0, int b = 0, int c = 0) {
		x = a; y = b; dir = c;
	}
	void Print() {
		cout << "(" << x << "," << y << ")" << ends;
	}
};
template<class T>
class Stack
{
private:
	int top, capacity;
public:
	 T * stack; // Matriz de elementos de pila almacenados
	Stack(int stackCapacity = m*p);
	bool IsEmpty();
	 T & Top (); // Devuelve el elemento superior de la pila
	 void Push (const T & item); // Poner en la pila
	 void Pop (); // Eliminar el elemento superior de la pila
	void Delete();
};
template<class T>
 Pila <T> :: Pila (int stackCpacity) // Constructor
{
	capacity = stackCpacity;
	if (capacity < 1) throw"stack capackty must be > 0";
	stack = new T[capacity];
	top = -1;
}
template<class T>
inline bool Stack<T>::IsEmpty()
{
	return top == -1;
}
template<class T>
inline T& Stack<T>::Top()
{
	if (IsEmpty())throw"Stack is empty";
	return stack[top];
}
template<class T>
void Stack<T>::Push(const T&x)
{
	stack[++top] = x;
}
template<class T>
void Stack<T>::Pop()
{
	if (IsEmpty())throw"Stack is empty. Cannot delete.";
	stack[top--] = 0;
}
template<class T>
void Stack<T>::Delete() {
	if (stack)
		delete[]stack;
}
 Elementos t (1, 1, N); // Posición inicial y orientación
Stack<Items> stack;
void path(Items temp) {
	static offsets move[8] = { -1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1 };
	int i = temp.x; int j = temp.y; int d = temp.dir;
	 if (d> NW) {// El callejón sin salida actual
		stack.Pop();
		if (!stack.IsEmpty()) {
			temp = stack.Top();
			temp.dir++;
			path(temp);
		}
		else cout << "not find";
	}
	int g = i + move[d].a; int h = j + move[d].b;
	 if ((g == m + 1) || (h == p + 1)) {// Encuentra la salida
		cout << "find" << endl;
		stack.Push(temp);
		while (!stack.IsEmpty()) {
			stack.Top().Print();
			stack.Pop();
		}
	}
	 de lo contrario, si ((! laberinto [g] [h]) && (! marca [g] [h])) {// no es actualmente una salida y aún puede continuar
		 stack.Push (temp); // La ruta se coloca en la pila
		mark[g][h] = 1;
		temp.x = g; temp.y = h; temp.dir = N;
		 ruta (temp); // siguiente cuadrícula recursiva
	}
	 sino /// necesita cambiar de dirección
	{
		temp.dir++;
		 ruta (temp); // siguiente cuadrícula recursiva
	}
}
int main() {
	setMaze();
	path(t);
}
