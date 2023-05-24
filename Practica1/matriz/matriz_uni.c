#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

/*
** Implmentacion utilizando un unico arreglo unidimensional
*/

typedef struct Matriz_ {
  double* data;
  int filas;
  int columns;
  /*Defina la estructura aqui*/

}Matriz;


Matriz* matriz_crear(size_t numFilas, size_t numColumnas) {
  Matriz* arreglo = malloc(sizeof(Matriz));
  arreglo->data = malloc(sizeof(double)*numFilas*numColumnas);
  arreglo->filas = numFilas;
  arreglo->columns = numColumnas;
  return arreglo;
}

void matriz_destruir(Matriz* matriz) {
  free(matriz->data);
  free(matriz);
}

void matriz_leer(Matriz* matriz, size_t fil, size_t col) {
 
  for(int i = 0; i<fil;i++){
    for(int j=0;j<col;j++){
      printf("%i ",(int)matriz->data[(i*matriz->columns)+j]);
    }
    printf("\n");
  }
}

void matriz_escribir(Matriz* matriz, size_t fil, size_t col, double val) {
  matriz->data[((fil-1)*matriz->columns)+(col-1)] =val;
}

size_t matriz_num_filas(Matriz* matriz) {
  return matriz->filas;
}

size_t matriz_num_columnas(Matriz* matriz) {

  return matriz->columns;
}

void matriz_agregar_fila(Matriz * matriz,int pos){
  matriz->filas++;
  pos--;
  matriz->data = realloc(matriz->data,sizeof(double)*matriz->filas*matriz->columns);
  for(int i = matriz->filas*matriz->columns-1; i>=(pos+1)*matriz->columns  ;i--){
    matriz->data[i] = matriz->data[i-matriz->columns];
  }
  for(int i=pos*matriz->columns;i< (pos+1)*matriz->columns;i++){
    matriz->data[i] = 0;
  }

}
int main(){
  Matriz* matriz =matriz_crear(5,5);
  size_t fil = matriz->filas;
  size_t col = matriz->columns;
  for(int i = 0; i<matriz->filas;i++){
    for(int j=0;j<matriz->columns;j++){
     matriz->data[(i*matriz->columns)+j] = i;
    }
  }
    matriz_leer(matriz,matriz->filas,matriz->columns);
  printf("\n");
  //matriz_escribir(matriz,fil,col,5);
  matriz_agregar_fila(matriz,3);
  //matriz_leer(matriz,matriz->filas,matriz->columns);
  size_t numC = matriz_num_columnas(matriz);
  size_t numF =matriz_num_filas(matriz);
  printf("la matriz tiene %li columnas y %li filas",numC,numF);
  return 0;
}