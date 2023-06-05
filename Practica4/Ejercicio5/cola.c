#include "cola.h"

#include <stdlib.h>
typedef SGList* Cola;

Cola  cola_crear(){
    Cola nq =sglist_crear();
    return nq;
}

void cola_destruir(Cola cola,FuncionDestructora destroy){
    sglist_destruir(cola,(FuncionDestructora)destroy);
}
int cola_es_vacio(Cola cola){
    return cola->primero == NULL;
}

void* cola_inicio(Cola cola){
    return cola->primero->data;
}
void cola_encolar(Cola cola, void* dato, FuncionCopia copia){
    GNode * nuevoNodo =malloc(sizeof(GNode));
    nuevoNodo->data = copia(dato);
    nuevoNodo->next = NULL;
    if (cola_es_vacio(cola)) {
        cola->primero = nuevoNodo;
        cola->ultimo = nuevoNodo;
    } else {
        cola->ultimo->next = nuevoNodo;
        cola->ultimo = nuevoNodo;
    }
}
    
void cola_desencolar(Cola cola, FuncionDestructora destroy){
    GNode* nodoADestruir = cola->primero;
    cola->primero = cola->primero->next;
    destroy(nodoADestruir->data);
    free(nodoADestruir);
}

void cola_imprimir(Cola cola, FuncionVisitante visit){
    sglist_recorrer(cola, visit);
}