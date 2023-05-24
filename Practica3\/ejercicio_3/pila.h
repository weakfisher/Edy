#ifndef __PILA_H__
#define __PILA_H__



#include "glist.h"
#include <stdio.h>
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






#endif /* __PILA_H__ */