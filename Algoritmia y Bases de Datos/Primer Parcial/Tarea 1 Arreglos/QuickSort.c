#include<stdio.h>
#include<stdlib.h>
void quicksort(int arreglo[], int izquierda, int derecha);
int particion(int arreglo[], int izquierda, int derecha);
void intercambiar(int *a, int *b);
int main(void) {
  // El arreglo
  int arreglo[] = {28, 11, 96, -5, 21, 18, 17, 12, 7, 22, 30, 97, -3, -7, -13};
  int longitud = sizeof arreglo / sizeof arreglo[0];
  printf("Arreglo desordenado:\n");
  for (int x = 0; x < longitud; x++) {
    printf("%d ", arreglo[x]);
  }
  printf("\n");
  //Invocar a quicksort indicando el arreglo, desde la posicion 0 a n-1
  quicksort(arreglo, 0, longitud - 1);
  printf("Arreglo Ordenado:\n");
  for (int x = 0; x < longitud; x++)
    printf("%d ", arreglo[x]);
  return 0;
}
void intercambiar(int *a, int *b) {
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

// Divide y vencerás
void quicksort(int arreglo[], int izquierda, int derecha) {
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha);
    quicksort(arreglo, izquierda, indiceParticion);
    quicksort(arreglo, indiceParticion + 1, derecha);
  }
}
int particion(int arreglo[], int izquierda, int derecha) {
  // Elegimos el pivote, es el primero
  int pivote = arreglo[izquierda];
  // Ciclo infinito
  while (1) {
    // Mientras cada elemento desde la izquierda esté en orden (sea menor que el
    // pivote) continúa avanzando el índice
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    // Mientras cada elemento desde la derecha esté en orden (sea mayor que el
    // pivote) continúa disminuyendo el índice
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    /*Si la izquierda es mayor o igual que la derecha significa que no
    necesitamos hacer ningún intercambio de variables, pues los elementos ya están 
	en orden (al menos en estaiteración)*/
    if (izquierda >= derecha) {
      // Indicar en dónde nos quedamos para poder dividir el arreglo de nuevo y ordenar los demás elementos
      return derecha;
    } else {
      /*Si las variables quedaron "lejos" (es decir, la izquierda no superó ni
      alcanzó a la derecha) significa que se detuvieron porque encontraron un valor que no estaba
      en orden, así que lo intercambiamos */
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      //Despues de intercambiar se continua avanzando los índices
      izquierda++;
      derecha--;
    } // El while se repite hasta que izquierda >= derecha
  }
}
