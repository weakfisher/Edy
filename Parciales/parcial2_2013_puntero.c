#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _SNode {
  int dato;
  struct _SNode *next;
} SNode;

typedef SNode *SOlist;

SOlist crearSoList(){
    return NULL;
}

SOlist agregar_lista(SOlist lista,int dato){
    SNode *nuevoNodo = malloc(sizeof(SNode));
    nuevoNodo->dato = dato;
    if(lista==NULL || dato < lista->dato ){
        nuevoNodo->next = lista;
        lista = nuevoNodo;
        return lista;
    }
    SNode * temp = lista;
    for(;temp->next != NULL && dato> temp->next->dato;temp = temp->next);
    nuevoNodo->next = temp->next;
    temp->next = nuevoNodo;
    return lista;
}


void so_recorrer(SOlist lista){
    for(SNode *temp = lista; temp !=NULL; temp = temp->next){
        printf("%i ",temp->dato);
    }
}

void so_destruir(SOlist lista){
    SNode * nodoEliminar ;
    while(lista != NULL){
        nodoEliminar = lista;
        lista = lista->next;
        free(nodoEliminar);
    }
}
void print_arr(int *arr, int longi){
    
    SOlist lista =crearSoList();
    for(int i= 0; i<longi;i++){
        lista =agregar_lista(lista,arr[i]);
    }
    so_recorrer(lista);
    so_destruir(lista);
}



int main(){
    SOlist lista = crearSoList();
    lista = agregar_lista(lista, 4);
        lista = agregar_lista(lista, 6);
    lista = agregar_lista(lista, 10);
        lista = agregar_lista(lista, 4);



    so_recorrer(lista);
    so_destruir(lista);
    int arr[]= {1,6,2,98,2,87,21,8,8};
    int longitud = sizeof(arr)/sizeof(int);
    print_arr(arr,longitud);
    return 0;
}