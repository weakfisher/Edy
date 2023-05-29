#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#include "cola.h"
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

/*  utilice  el  recorrido primero  por  extensi ́on
 */
  void btree_recorrer_bfs(BTree raiz){
    Cola cola = cola_crear();
  }

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);


/* EJERCICIO 2
  A) 
  printf("La altura del arbol es %i \n", btree_altura(raiz));
  B)
  printf("La suma total del arbol es %i \n", suma_tree(raiz));
  C)
  printf("La cantidad de nodos del arbol es %i \n", suma_nodos(raiz));
 */


  // EJERCICIO 3
  //btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero);
  puts("");
  btree_destruir(raiz);
  return 0;
}
