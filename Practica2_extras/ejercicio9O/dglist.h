
#ifndef __DGLIST_H__
#define __DGLIST_H__
#include <stdbool.h>
typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef bool (*FuncionComparadora)(void *, void*);

#include <stdlib.h>
typedef struct _DNodo {
void * dato;
struct _DNodo* sig;
struct _DNodo* ant;
} DNodo;
typedef struct {
DNodo* primero;
DNodo* ultimo;
} GList;
/**
 * Devuelve una lista vacía.
 */
GList * glist_crear();

GList * agregar_inicio(GList* lista,void* dato, FuncionCopia copy);
 
 
 int dglist_longtiud(GList * lista);
 
void glist_recorrer(GList* lista, FuncionVisitante visit) ;
#endif /* __DGLIST_H__ */
