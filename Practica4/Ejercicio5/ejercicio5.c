#include <stdio.h>
#include <stdlib.h>
#include "dglist.h"
#include "cola.h"
typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
} BTNodo;

typedef BTNodo *BTree;


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






static void imprimir_entero(int data) {
  printf("%d ", data);
}

BTNodo* copiarNodo(BTNodo* nodo) {
    if (nodo == NULL) {
        return NULL;
    }
    
    BTNodo* copia = malloc(sizeof(BTNodo));
    copia->dato = nodo->dato;
    copia->left = copiarNodo(nodo->left);
    copia->right = copiarNodo(nodo->right);
    
    return copia;
}
void destroy(void* dato){
    free(dato) ;
}

void btree_busqueda_extension_iterativa(BTree arbol, FuncionVisitante visit){
    if( btree_empty(arbol)) return;
    Cola cola = cola_crear();
    cola_encolar(cola,arbol,(FuncionCopia) copiarNodo);
    while(!btree_empty(arbol)){
        arbol= (BTree)cola_inicio(cola);
        visit(arbol->dato);
        cola_desencolar(cola,(FuncionDestructora) destroy);
        if(!btree_empty(arbol->left)){
            cola_encolar(cola,arbol->left,(FuncionCopia )copiarNodo);
        }
        if(!btree_empty(arbol->right)){
            cola_encolar(cola,arbol->right,(FuncionCopia)copiarNodo);
        }
    }
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

int main(){

  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);
  btree_busqueda_extension_iterativa(raiz,(FuncionVisitante)imprimir_entero);
  //re_order(raiz,(FuncionVisitante)imprimir_entero);
    return 0 ;
}