#include "btree.h"
#include <stdlib.h>

BTree btree_crear() {
  return NULL;
}

void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

int btree_empty(BTree nodo) {
  return nodo == NULL;
}

BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(BTNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}
void pre_order(BTree raiz, FuncionVisitante visit){
  if (btree_empty(raiz)){
    return;
  }
  visit(raiz->dato);
  BTree left = raiz->left;
  pre_order(left,visit);
  BTree right = raiz->right;
  pre_order(right,visit);
}

void in_order(BTree raiz, FuncionVisitante visit){
  if (btree_empty(raiz)){
    return;
  }
  BTree left = raiz->left;
  in_order(left,visit);
  visit(raiz->dato);
  BTree right = raiz->right;
  in_order(right,visit);
}
void post_order(BTree raiz, FuncionVisitante visit){
  if (btree_empty(raiz)){
    return;
  }
  BTree left = raiz->left;
  post_order(left,visit);
  BTree right = raiz->right;
  post_order(right,visit);  
  visit(raiz->dato);


}
void btree_recorrer(BTree raiz, BTreeOrdenDeRecorrido orden, FuncionVisitante visit){

  switch (orden)
  {
    \
  case 0:
   in_order(raiz,(FuncionVisitante)visit);
   break;
  case 1:
   pre_order( raiz, (FuncionVisitante) visit);
    break;
  
  case 2:
    post_order(raiz,(FuncionVisitante )visit);
    break;


  default:
    break;
  }

  
}
