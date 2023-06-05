#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitante) (int dato);
typedef void (*FuncionVisitanteExtra) (int dato, void *extra);
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

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,FuncionVisitante visit);

int btree_buscar(BTree raiz, int num);

BTree btree_copiar(BTree raiz);

int btree_nnodos_profundidad(BTree raiz, int profundidadBuscada,int profundidadActual);

int btree_profundiad(BTree raiz,int objetivo);

void in_order(BTree raiz, FuncionVisitante visit);
void post_order(BTree raiz, FuncionVisitante visit);
void pre_order(BTree raiz, FuncionVisitante visit);

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,FuncionVisitanteExtra visit, void *extra);

#endif /* __BTREE_H__ */
