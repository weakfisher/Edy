#include "contacto.h"
#include <stdio.h>
#include <stdlib.h>
typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*Predicado)(void *dato);
typedef int (*FuncionComparadora)(void *, void*);

typedef struct _GNode{
    void *data;
    struct _GNode *next;
}GNode;

typedef struct _SGList{
    GNode* primero;
    GNode* ultimo;
}SGList;


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


SGList * slist_agregar_inicio(SGList * lista,FuncionCopia copia,void *data){
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
        lista =slist_agregar_inicio(lista,copia,data); 
        return lista;
    }
    GNode *temp = lista->primero;
    if( compara(data,temp->data)<0){
        lista =  slist_agregar_inicio(lista,copia,data);
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
        printf("res = %d, data = %s, temp->data = %s\n", res, ((Contacto*)data)->nombre, ((Contacto*)temp->data)->nombre);
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


int main(){
    SGList *lista = sglist_crear();
    Contacto *contactos[6];
  contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
  contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);
    printf(" la lista es %i \n",sglist_vacia(lista));
      for (int i = 0; i < 6; ++i) {
    lista = sglist_insertar(lista, contactos[i],(FuncionCopia)contacto_copia, (FuncionComparadora)contacto_comparar);
  }    
    sglist_recorrer(lista, (FuncionVisitante)contacto_imprimir);
    printf("Res %s = %d", contacto_crear("Fardo Fuseneco", "3416894526", 64)->nombre, 
        sglist_buscar(lista, (Contacto*)contacto_crear("Fardo Fuseneco", "3416894526", 64), (FuncionComparadora)contacto_comparar));
    sglist_destruir(lista, (FuncionDestructora)contacto_destruir);
    for(int i=0; i<5;i++){
        free(contactos[i]->nombre);
        free(contactos[i]->tel);
        free(contactos[i]);
    }
    

    return 0;

}