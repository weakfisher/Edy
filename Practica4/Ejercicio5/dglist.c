#include "dglist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


SGList* sglist_crear(){
    SGList * nuevaLista = malloc(sizeof(SGList));
    nuevaLista->primero =NULL;
    nuevaLista->ultimo=NULL;
    return nuevaLista;
}

void sglist_destruir(SGList *lista, FuncionDestructora destroy){

    if (lista->primero !=NULL){
    GNode* temp = lista->primero;

    while(temp !=NULL ){
        destroy(temp->data);
        GNode * siguiente = temp->next;
        free(temp);
        temp = siguiente;
    }}
    free(lista);

}

int sglist_vacia(SGList* lista){
    if (lista == NULL){
        return 1;
    }
    if (lista->primero == NULL){
        return 1;
    }
    return 0;
}

void sglist_recorrer(SGList* lista, FuncionVisitante visitante){
     if (lista->primero !=NULL){
    GNode* temp = lista->primero;

    while(temp !=NULL ){
        visitante(temp->data);
        
        temp = temp->next;
    }}
} 


SGList * sglist_agregar_inicio(SGList * lista,FuncionCopia copia,void *data){
    GNode * nuevoNodo =malloc(sizeof(GNode));
    nuevoNodo->data = copia(data);
    nuevoNodo->next = lista->primero;
    if (lista->ultimo ==NULL){
        lista->ultimo =nuevoNodo;
    }
    lista->primero= nuevoNodo;
    return lista;
}

SGList *sglist_insertar(SGList* lista, void *data, FuncionCopia copia, FuncionComparadora compara){

    if (lista->primero==NULL){
        lista =sglist_agregar_inicio(lista,copia,data); 
        return lista;
    }
    GNode *temp = lista->primero;
    if( compara(data,temp->data)<0){
        lista =  sglist_agregar_inicio(lista,copia,data);
        return lista;
    }
    GNode* nuevoNodo = malloc(sizeof(GNode));
    nuevoNodo->data= copia(data);
    for(;temp!= NULL && compara(data,temp->next->data)>0; temp = temp->next   );
   
    nuevoNodo->next  =temp->next; 
    temp->next= nuevoNodo;

    return lista;   
}







int sglist_buscar(SGList *lista, void *data , FuncionComparadora buscar){
    GNode * temp = lista->primero;
    int res = 1;
    while(temp!=NULL){
        res = buscar(data,temp->data);
        //printf("res = %d, data = %s, temp->data = %s\n", res, ((Contacto*)data)->nombre, ((Contacto*)temp->data)->nombre);
        if(res <= 0) temp = NULL;
        else temp = temp->next;
    }
    return res == 0;
}

SGList* sglist_arr(void ** arr, int longi, FuncionCopia copia, FuncionComparadora compara){
    SGList *nuevaLista = sglist_crear();
    for (int i = 0 ; i< longi;i++){
        void * dato = copia(arr[i]);
        nuevaLista =sglist_insertar(nuevaLista,dato,copia,compara);
    }
    return nuevaLista;
}
