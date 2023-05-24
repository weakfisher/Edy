#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef void* (*FuncionTransformar)(void *dato);
typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef struct{
    GNode * primero;
    GNode * ultimo;
}GList;

/**
 * Devuelve una lista vacía.
 */
GList glist_crear() {
    GList lista;
    lista.primero = NULL;
        lista.ultimo = NULL;

  }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void glist_destruir(GList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
  for(GNode * nodo = list.primero;nodo !=NULL;){
    nodeToDelete = nodo;
    nodo = nodo->next;
    destroy(nodeToDelete->data);
    free(nodeToDelete);
  }
}


GList glist_agregar_final(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  newNode->data = copy(data);
  newNode->next = NULL;
  if ( list.primero== NULL){
    list.primero = newNode;
  }
  else{
    list.ultimo->next = newNode;
  }
  list.ultimo=newNode;
  return list;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNode *node = list.primero; node != NULL; node = node->next)
    visit(node->data);
}

GList glist_map(GList lista,FuncionTransformar f,FuncionCopia c){
    if (lista.primero == NULL){
        return lista;
    }
    GList nuevaLista = glist_crear();
    for(GNode * temp = lista.primero;temp!=NULL; temp = temp->next){
        void *dato = f(temp->data);
        nuevaLista = glist_agregar_final(nuevaLista,dato,c);
    }
    return nuevaLista;
}

void* copia_string(void* dato){
    char* str = (char*) dato;
    char* nuevo = malloc(sizeof(char)*(strlen(str)+1));
    strcpy(nuevo,str);
    return nuevo;
}

void mostrar(void* dato){
    char* str = (char*)dato;
    char* nuevo = malloc(sizeof(char)*(strlen(str)+1));
    strcpy(nuevo,str);
        printf("%s ", nuevo);
  
      
}

void * stringMayus(void* dato){
    int i = 0;
    char* str= (char*) dato;
    char* mayusculas = malloc(sizeof(char)*(strlen(str)+1));
    while(str[i]!='\0'){
        mayusculas[i]=toupper(str[i]);
        i++;
    }
    mayusculas[i]='\0';
    return mayusculas;
}

int main(){
    GList lista = glist_crear();
    char *str = "Licenciatura";
    lista = glist_agregar_final(lista,str,copia_string);
    char* str2 = "en";
    lista = glist_agregar_final(lista,str2,copia_string);
    str = " Ciencias";
    lista = glist_agregar_final(lista,str,copia_string);
    str= " de la";
    lista = glist_agregar_final(lista,str,copia_string);
    //glist_recorrer(lista,mostrar);
    GList listamayus = glist_crear();
    listamayus = glist_map(lista,stringMayus,copia_string);
    glist_recorrer(listamayus,mostrar);
    return 0;
}