#include<iostream>
#include<cstring>
using namespace std;

struct Nodo{
	string dato;
	struct Nodo *der;
	struct Nodo *izq;
};

