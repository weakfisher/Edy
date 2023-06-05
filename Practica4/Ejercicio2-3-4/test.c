#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
static void imprimir_entero(int data) {
  printf("%d ", data);
}

/* Calcule la suma de los elementos de un  ́arbol de enteros. */
int suma_tree(BTree raiz){
  if(  btree_empty(raiz)  ){
    return 0;
  }
  int contador = raiz->dato;
  contador+=suma_tree(raiz->left);
  contador += suma_tree(raiz->right); 
  return contador;
}
/* Cuente la cantidad de nodos de un  ́arbol de enteros.
 */int suma_nodos(BTree raiz){
  if (btree_empty(raiz)){
    return 0;
  }
  int contador = 1;
  contador+=suma_nodos(raiz->left);
  contador += suma_nodos(raiz->right); 
  return contador;
}
/* Calcule la altura de un  ́arbol de enteros.
 */
int btree_altura(BTree raiz){
  if (btree_empty(raiz)){
    return -1;
  }
  int altD = btree_altura(raiz->right);
  int altI = btree_altura(raiz->left);
  if (altD >altI){
    return altD+1;
  }else{
  return altI+1;}
}




int main() {

  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);


/* EJERCICIO 2
  d) 
  printf("La altura del arbol es %i \n", btree_altura(raiz));

  g)
  printf("La suma total del arbol es %i \n", suma_tree(raiz));

  a)
  printf("La cantidad de nodos del arbol es %i \n", suma_nodos(raiz));
 */

  // b)
  //int num =btree_buscar(raiz,1); 
  //printf("retorne 1 si el n ́umero dado se encuentra en el  ́arbol, y 0 en caso contrario %i \n",num );


  // c)
  //BTree copiaarbol = btree_crear();
  //copiaarbol = btree_copiar(raiz);


  //e)
  //printf("ddd %i",btree_nnodos_profundidad(raiz,1,0));

  // f)
  //printf("%i",btree_profundiad(raiz,2));

  //btree_recorrer(copiaarbol, BTREE_RECORRIDO_PRE, imprimir_entero);



  // EJERCICIO 3
  //puts("");
  //btree_destruir(raiz);
  return 0;
}
