#include <stdio.h>
#include "pila.h"
#include "glist.h"
#include <assert.h>
#include <stdlib.h>


Pila pila_crear( ){
    return glist_crear();
}

void pila_destruir(Pila* pila, FuncionDestructora destroy){
 GNode *nodeToDelete;
  while (*pila != NULL) {
    nodeToDelete = *pila;
    *pila = (*pila)->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}
int pila_es_vacia(Pila pila){
    if (pila == NULL){
        return 1;
    }
    return 0;

}

void * pila_tope(Pila pila){
    if ((pila_es_vacia(pila))){
        return 0;

    }
    else
    {
    return pila->data;    
    }
}

void pila_apilar(Pila *pila, void *dato,FuncionCopia copia){
 
    GList newNode = malloc(sizeof(GNode));
    assert(newNode != NULL);

    newNode->data = copia(dato);
    newNode->next = *pila;
    
    *pila = newNode;
}


void pila_imprimir(Pila pila,FuncionVisitante visit){
    if (!pila_es_vacia(pila) ){
     glist_recorrer(pila,visit);
    }
}

void pila_desapilar(Pila* pila){
    if( !pila_es_vacia(*pila)){
   GNode* temp=*pila;
    *pila= (*pila)->next;
   free(temp);
   
    }
}