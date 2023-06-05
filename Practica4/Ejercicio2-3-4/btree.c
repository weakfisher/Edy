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

int btree_buscar(BTree raiz, int num){
  if (!raiz ){
    return 0;
  }
  if (raiz->dato == num){
    return 1;
  }

  int izq = btree_buscar(raiz->left , num);
  int der =btree_buscar(raiz->right , num);
  if (izq == 1 || der == 1){
    return 1;
  }
  return 0;
}



BTree btree_copiar(BTree raiz){
  if (raiz == NULL){
    return NULL;
  }
  BTree copia =  btree_crear();
  BTree arbolIzq = btree_crear();
  BTree arbolDer = btree_crear();

  if (!btree_empty( raiz->left)){

  arbolIzq =  btree_copiar(raiz->left);
  }
  if (!btree_empty( raiz->right)){

  arbolDer = btree_copiar(raiz->right);
  }
  copia = btree_unir(raiz->dato,arbolIzq,arbolDer );
  

  return copia;
}
int btree_nnodos_profundidad(BTree raiz, int profundidadBuscada,int profundidadActual){
  if (btree_empty(raiz)){
    return 0;
  }
  int cantNodos =0;
  if (profundidadActual == profundidadBuscada){
    return 1;
  }
  cantNodos += btree_nnodos_profundidad(raiz->left,profundidadBuscada,profundidadActual+1);
  cantNodos += btree_nnodos_profundidad(raiz->right,profundidadBuscada,profundidadActual+1);
  return cantNodos;
  
}

int btree_profundiad_aux(BTree raiz,int objetivo,int profundidad){
  if (btree_empty(raiz)){
    return -1;
  }
  if (raiz->dato == objetivo){
    return profundidad;
  }

  int profundidadIzquierda = btree_profundiad_aux(raiz->left, objetivo, profundidad + 1);
  if (profundidadIzquierda != -1) {
    return profundidadIzquierda;
  }
  int profundidadDerecha = btree_profundiad_aux(raiz->right, objetivo, profundidad + 1);
  return profundidadDerecha;
}


int btree_profundiad(BTree raiz,int objetivo){

  int profundidad = 0;
  
  profundidad = btree_profundiad_aux(raiz,objetivo,profundidad);
  return profundidad;
}







/////////////////////////
// EJERCICIO 4


void pre_orderExtra(BTree raiz, FuncionVisitanteExtra visit, void* dato){
  if (btree_empty(raiz)){
    return;
  }
  visit(raiz->dato,dato);
  BTree left = raiz->left;
  pre_orderExtra(left,visit,dato);
  BTree right = raiz->right;
  pre_orderExtra(right,visit,dato);
}

void in_orderExtra(BTree raiz, FuncionVisitanteExtra visit, void* dato){
  if (btree_empty(raiz)){
    return;
  }
  BTree left = raiz->left;
  in_orderExtra(left,visit,dato);
  visit(raiz->dato, dato);
  BTree right = raiz->right;
  in_orderExtra(right,visit,dato);
}
void post_orderExtra(BTree raiz, FuncionVisitanteExtra visit, void* dato){
  if (btree_empty(raiz)){
    return;
  }

  BTree left = raiz->left;
  post_orderExtra(left,visit,dato);
  BTree right = raiz->right;
  post_orderExtra(right,visit,dato);  
  visit(raiz->dato,dato);


}









void btree_recorrer_extra(BTree raiz, BTreeOrdenDeRecorrido orden, FuncionVisitanteExtra visit, void *extra){
  
    switch (orden)
  {
    
  case 0:
   in_orderExtra(raiz,(FuncionVisitanteExtra)visit,extra);
   break;
  case 1:
   pre_orderExtra( raiz, (FuncionVisitanteExtra) visit,extra);
    break;
  
  case 2:
    post_orderExtra(raiz,(FuncionVisitanteExtra )visit,extra);
    break;


  default:
    break;
  }


}

