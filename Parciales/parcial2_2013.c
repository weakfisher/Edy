#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _SNode {
  int dato;
  struct _SNode *next;
} SNode;

typedef SNode *SOlist;

SOlist crear_slist(){
    return NULL;
}
void solistdestroy(SOlist * lista);

void solistadd(int dato, SOlist *lista){
    SNode *nuevoNodo = malloc(sizeof(SNode));
    nuevoNodo->dato = dato;
    nuevoNodo->next = NULL;
    if (*lista == NULL || dato <= (*lista)->dato){
        nuevoNodo->next = *lista;    
        *lista = nuevoNodo;
        
    }else{
    SNode * temp = *lista;
    for(;temp->next!= NULL &&  dato > temp->next->dato; temp = temp->next){
        
    }
    nuevoNodo->next = temp->next;
    temp->next =nuevoNodo;
    }


}

void solista_print(SOlist * lista){
    if (*lista == NULL){ return;}
    for(SNode * temp= *lista; temp !=NULL; temp = temp->next){
        printf("%i ",temp->dato);
    }
}

void print_ordered(int *arr,int longitud ){
    SOlist arrOrde = crear_slist();

    for(int i = 0; i<longitud;i++){
        solistadd(arr[i],&arrOrde);
    }
    solista_print(&arrOrde);
    solistdestroy(&arrOrde);
}

void solistdestroy(SOlist * lista){
     if (*lista == NULL){ return;}
     SNode * nodeBorrar ;
    while (*lista !=NULL)
    {
        nodeBorrar = *lista;
        *lista = (*lista)->next;
        free(nodeBorrar);
    }
    
    
}

int main(){
    SOlist  lista =crear_slist();
    solistadd(2,&lista);
     solistadd(4,&lista);
    solistadd(1,&lista);
     int arrr[] = {1,5,9,2,4,1};
    print_ordered(arrr,sizeof(arrr)/sizeof(int)); 
    solistdestroy(&lista);

    return 0;
}