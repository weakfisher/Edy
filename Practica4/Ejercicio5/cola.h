#ifndef __COLA__H__
#define __COLA__H__

#include "dglist.h"
typedef SGList* Cola;

Cola  cola_crear();

void cola_destruir(Cola cola,FuncionDestructora destroy);
int cola_es_vacio(Cola cola);

void* cola_inicio(Cola cola);

void cola_encolar(Cola cola, void* dato, FuncionCopia copia);
    
void cola_desencolar(Cola cola, FuncionDestructora destroy);

void cola_imprimir(Cola cola, FuncionVisitante visit);

#endif /* __COLA_H__ */