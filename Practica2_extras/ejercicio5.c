

#include <stdio.h>
#include <stdlib.h>
/* 
Dada una lista enlazada de n ́umeros enteros, eliminar todas las sub secuencias que sumen cero y
retornar la lista resultante. En los casos que se puedan elegir una subsecuencia que est ́e contenida en
otra, elegir la m ́as grande
 */
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

 SList lista_suma_cero(SList lista){

    for(SNodo* temp1 = lista; temp1!= NULL && temp1->sig != NULL ; temp1 = temp1->sig ){

        int carry = temp1->dato;
        int sc = 0;
        SNodo* temp2 = temp1->sig;
        for(;temp2->sig != NULL; temp2 = temp2->sig){
            sc += temp2->dato;
            if ((carry + sc )== 0){
                
                if (temp1->ant != NULL){
                    temp1->ant->sig = temp2->sig;
                    temp2->sig->ant = temp1->ant;
                }
                else {
                    lista = temp2->sig;
                    temp2->sig->ant = NULL;
                }
                temp1 = temp2->sig;
            }
        }
         if (temp2 != NULL && carry + temp2->dato == 0) {
            temp1->ant->sig = NULL;
        }

    }  
    return lista; 

} 




void slist_recorrer(SList lista){
    for(SNodo *temp =lista; temp!= NULL; temp = temp->sig){
        printf(" -> %i ",temp->dato);
    }
    puts("");
}

int main(){
    SList lista = slist_crear();
    lista = slist_agregar_inicio(lista,-8);
    lista = slist_agregar_inicio(lista,8);
    lista = slist_agregar_inicio(lista,9);
    lista = slist_agregar_inicio(lista,-12);
    lista = slist_agregar_inicio(lista,4);
    lista = slist_agregar_inicio(lista,8);
    lista = slist_agregar_inicio(lista,-6);   
    lista = slist_agregar_inicio(lista,6);

    slist_recorrer(lista);
    lista = lista_suma_cero(lista);
    slist_recorrer(lista);
 
    SList lista2= slist_crear();
     lista2 = slist_agregar_inicio(lista2,25);
    lista2 = slist_agregar_inicio(lista2,20);
    lista2 = slist_agregar_inicio(lista2,-18);
    lista2 = slist_agregar_inicio(lista2,10);
    lista2 = slist_agregar_inicio(lista2,-19);
    lista2 = slist_agregar_inicio(lista2,10);
    lista2 = slist_agregar_inicio(lista2,9);   
    lista2 = slist_agregar_inicio(lista2,8);
   
    lista2 = slist_agregar_inicio(lista2,-10);
    lista2 = slist_agregar_inicio(lista2,6);
    lista2 = slist_agregar_inicio(lista2,4);
        slist_recorrer(lista2);

    lista2 = lista_suma_cero(lista2);
    slist_recorrer(lista2);
    return 0 ;
}