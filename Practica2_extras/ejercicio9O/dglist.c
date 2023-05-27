
#include "dglist.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * Devuelve una lista vacía.
 */
GList * glist_crear(){
  GList* lista = malloc(sizeof(GList));
  lista->primero = NULL;
  lista->ultimo = NULL ;
  return lista;
} 

GList * agregar_inicio(GList* lista,void* dato, FuncionCopia copy){
    DNodo* nuevoNodo = malloc(sizeof(DNodo));
    nuevoNodo->dato = copy(dato);
    
    if (lista->primero == NULL ){
        lista->primero = nuevoNodo;
        lista->ultimo = nuevoNodo;
        nuevoNodo->sig =NULL;
    }
    else{
        nuevoNodo->sig = lista->primero;
        lista->primero->ant = nuevoNodo;
        lista->primero = nuevoNodo;
    }

  return lista;

}

void glist_recorrer(GList* lista, FuncionVisitante visit) {
  for (DNodo *node = lista->primero; node != NULL; node = node->sig)
    visit(node->dato);
}

 int dglist_longtiud(GList * lista){
    if (lista->primero == NULL){
        return 0;
    }
    int longitud = 0;
    for(DNodo *temp= lista->primero;temp != NULL;temp = temp->sig){
        longitud++;
    }
    return longitud;
 }
