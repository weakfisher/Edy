#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*FuncionVisitante) (int dato);

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}




typedef struct _DNodo {
int dato;
struct _DNodo* sig;
struct _DNodo* ant;
} DNodo;
typedef struct {
DNodo* primero;
DNodo* ultimo;
} DList;

void slist_recorrer(DList* lista, FuncionVisitante visit) {
  for (DNodo *nodo = lista->primero; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}


DList * crearDList(){
    DList * dobleLista = malloc(sizeof(DList));
    dobleLista->primero = NULL;
    dobleLista->ultimo = NULL;
    return dobleLista;
}

DList * agregar_inicio(DList* lista,int dato){
    DNodo* nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = dato;
    if (lista==NULL){
        lista = crearDList();
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
    if (lista->primero == NULL ){
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
    }
    else{
        nuevoNodo->sig = lista->primero;
        lista->primero->ant = nuevoNodo;
        lista->primero = nuevoNodo;
    }



}

int main(){
    DList* lista = crearDList();
    return 0;
}