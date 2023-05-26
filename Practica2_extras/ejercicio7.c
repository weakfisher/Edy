#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct SNodo {
int dato;
struct SNodo* ant;
struct SNodo* sig;
} SNodo;
typedef struct SNodo * SList;

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  nuevoNodo->ant = NULL;
  if (lista != NULL){
    lista->ant = nuevoNodo;
  }
  return nuevoNodo;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */
  nuevoNodo->ant = nodo;
  nodo->sig = nuevoNodo;
  return lista;
}
SList slist_crear(){
    return NULL;
}
void slist_recorrer(SList lista){
    for(SNodo *temp =lista; temp!= NULL; temp = temp->sig){
        printf(" -> %i ",temp->dato);
    }
    puts("");
}
/* 
Se pide entonces, dadas dos listas enlazadas, encontrar la intersecci ́on de las mismas, es decir, el nodo a
partir del cual las dos listas siguen igual (o la direcci ́on nula en caso de no tener nodos en com ́un). Para
el ejemplo anterior, se deber ́ıa retornar la direcci ́on del nodo 7
 */

SList interseccion_listas(SList lista1, SList lista2){
    
    
    SNodo *nodoI= NULL;
    bool aparecioIgual = false;
    for(SNodo *temp1 = lista1;temp1 != NULL ;temp1 =temp1->sig){
        bool iguales =false;

        for(SNodo *temp2 = lista2; temp2!= NULL && !iguales ;temp2 =temp2->sig){
                   

            if (temp1->dato == temp2->dato && !aparecioIgual){
                aparecioIgual = true;
                iguales = true;
                nodoI = temp2;
            }
            if(aparecioIgual && temp1->dato == temp2->dato){
                iguales = true;

            }
        }
        if (!iguales && aparecioIgual) {
            aparecioIgual = false;
            nodoI = NULL;
        }
         
    }
    return nodoI;

}


int main(){
    SList lista1 = slist_crear();
    SList lista2 = slist_crear();

    lista1= slist_agregar_inicio(lista1,9);
        lista1= slist_agregar_inicio(lista1,8);
    lista1= slist_agregar_inicio(lista1,7);
    lista1= slist_agregar_inicio(lista1,3);
    lista1= slist_agregar_inicio(lista1,2);
    lista1= slist_agregar_inicio(lista1,1);

    lista2= slist_agregar_inicio(lista2,9);
    lista2= slist_agregar_inicio(lista2,8);
    lista2= slist_agregar_inicio(lista2,7);
    lista2= slist_agregar_inicio(lista2,6);
    lista2= slist_agregar_inicio(lista2,5);
        slist_recorrer(lista1);
    slist_recorrer(lista2);



    SList lista4 = slist_crear();
    lista4 = slist_agregar_inicio(lista4,3);    
    lista4 = slist_agregar_inicio(lista4,1);    


    SList lista3 = slist_crear();
     lista3 = interseccion_listas(lista1,lista2);
    slist_recorrer(lista3);



    return 0;
}