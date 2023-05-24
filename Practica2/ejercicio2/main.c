#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*FuncionVisitante) (int dato);


typedef struct _SNodo {
int dato;
struct _SNodo *sig;
} SNodo;

typedef struct SList {
SNodo *primero;
SNodo *ultimo;
} Slist;


Slist * slist_crear(){
    Slist * lista = malloc(sizeof(Slist));
    lista->primero = NULL;
    lista->ultimo = NULL;
    return lista;
}

Slist * slist_agregar_inicio(Slist * lista,int dato){
    if (lista->primero == NULL){
        lista->primero = malloc(sizeof(SNodo));
        lista->primero->dato = dato;
        lista->ultimo = lista->primero;
    }
    else{
        SNodo * temp = lista->primero;
        temp = lista->primero;
        lista->primero = malloc(sizeof(SNodo));
        lista->primero->dato = dato;
        lista->primero->sig = temp;
    }
    return lista;
}
void slist_recorrer(Slist* lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista->primero; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}
static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

Slist *slist_agregar_final(Slist* lista, int dato){
    if (lista == NULL){
        SNodo *nuevoNodo=malloc(sizeof(SNodo));
        lista->primero = nuevoNodo;
        nuevoNodo->dato = dato;
        lista->ultimo = nuevoNodo;
    }
    else{
        SNodo* nuevoNodo=malloc(sizeof(SNodo));
        lista->ultimo->sig =nuevoNodo;
        lista->ultimo = nuevoNodo;
        nuevoNodo->dato = dato;
    }
    return lista;
}


int main(){
    Slist* nuevaLista = slist_crear();
    nuevaLista = slist_agregar_inicio(nuevaLista,2);
        nuevaLista = slist_agregar_inicio(nuevaLista,3);

    slist_recorrer(nuevaLista,imprimir_entero);
    return 0;
}