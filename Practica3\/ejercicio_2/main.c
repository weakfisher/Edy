#include <stdio.h>
#include "contacto.h"
#include "glist.h"
#include <assert.h>
#include <stdlib.h>
typedef GList Pila;


Pila pila_crear();
int pila_es_vacia(Pila pila);
void pila_destruir(Pila *pila, FuncionDestructora destroy);
void* pila_tope(Pila pila);
void pila_apilar(Pila *pila, void *dato, FuncionCopia copia);
void pila_desapilar(Pila* pila);
void pila_imprimir(Pila pila,FuncionVisitante visit);

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

// preguntar memory leak


int main(){
    Pila nuevaPila = pila_crear();
    Contacto *contactos[6];
    int longitud =  sizeof(contactos)/(sizeof(Contacto*));
    contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
    contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
    contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
    contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
    contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
    contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);
    for(int i = 0; i<longitud;i++){
        
        pila_apilar(&nuevaPila,contactos[i],(FuncionCopia)contacto_copia);
        contacto_destruir(contactos[i]);
    }
    // uso de la funcion tope
    // contacto_imprimir(pila_tope(nuevaPila));
    
    pila_imprimir(nuevaPila,(FuncionVisitante)contacto_imprimir);
    
    pila_desapilar(&nuevaPila);
    
    pila_destruir(&nuevaPila,(FuncionDestructora)contacto_destruir);
    

    printf("la lista esta %i",pila_es_vacia(nuevaPila));
        


    return 0;
    }
