#include "matriz.h"
#include <stdio.h>
/*
** Implementacion utilizando un arreglo bidimensional (arreglo de punteros a arreglo)
*/

typedef struct Matriz_ {
  double ** data;
  size_t filas;
  size_t columnas;
  /*Defina la estructura aqui*/

}Matriz;


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz * matriz = malloc(sizeof(Matriz));
    matriz->data = malloc(sizeof(double*)*numFilas);
  for(int i =0; i<numFilas;i++){
    matriz->data[i] = (double*)malloc(sizeof(double)*numColumnas);
  }
  for(int i = 0;i<numFilas;i++){
    for(int j = 0;j<numColumnas;j++){
      matriz->data[i][j] = 1;
    }
  }
  matriz->columnas = numColumnas;
  matriz->filas = numFilas;
  return matriz;
}
void matriz_destruir(Matriz* matriz) {
  for(int i =0 ; i<matriz->filas;i++){
  
    free(matriz->data[i]);
    
  }
  free(matriz->data);
  free(matriz);
}


void matriz_leer(Matriz* matriz, size_t fil, size_t col) {
  for(int i = 0;i<fil;i++){
    for(int j= 0;j<col;j++){
      printf("%i",(int)matriz->data[i][j]);
    }
    printf("\n");
  }
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  matriz->data[fil][col] = val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->filas;
}

size_t matriz_num_columnas(Matriz* matriz) {
  return matriz->columnas;
}

// intercambio la fila1 con la fila 2
void matriz_intercambiar_filas(Matriz * matriz,int fila1,int fila2){
  double * temp;
  temp = matriz->data[fila1];
  matriz->data[fila1] = matriz->data[fila2];
  matriz->data[fila2] = temp;
 
}
void agregar_fila(Matriz*matriz, int pos){
  matriz->filas++;
  matriz->data = realloc(matriz->data,sizeof(double*)*matriz->filas) ;
  for (int i = matriz->filas-1; i>pos;i--){
    matriz->data[i] = matriz->data[i-1];
  }
  matriz->data[pos] = malloc(sizeof(double)*matriz->columnas);
  for(int i =0 ; i <matriz->columnas;i++){
    matriz->data[pos][i]=0;
  }
}

int main(){
  Matriz *matriz =matriz_crear(5,5);

  matriz_escribir(matriz,3,2,4);
  matriz_intercambiar_filas(matriz,3,2);
  agregar_fila(matriz,3);
  matriz_leer(matriz,matriz->filas,matriz->columnas);
  size_t numF = matriz_num_filas(matriz);
  size_t numC = matriz_num_columnas(matriz);
  printf(" El num de filas son %li y de columnas  %li",numF,numC);
  matriz_destruir(matriz);
  return 0;
}
