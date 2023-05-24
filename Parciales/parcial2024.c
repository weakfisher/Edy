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



void merge_sort(GList lista){
    
}

int main(){



    return 0;
}