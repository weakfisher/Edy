#include "arreglosenteros.h"
#include <stdio.h>

struct _Pila {
ArregloEnteros *arr;
int ultimo;
};
typedef struct _Pila *Pila;


Pila pila_crear(int capacidad){
    Pila nuevaPila = malloc(sizeof(Pila));

    nuevaPila->arr = arreglo_enteros_crear(capacidad);
    nuevaPila->ultimo = 0;
    return nuevaPila;
    

}

void pila_destruir(Pila pila){
    
    arreglo_enteros_destruir(pila->arr);
    free(pila);
}

int pilas_es_vacia(Pila pila){
    if (pila== NULL || esArregloVacio(pila->arr)){
        return 1;
    }
    else{
        return 0;
    }
}

void pila_apilar(Pila pila, int dato){
    if (pila->ultimo > pila->arr->capacidad){
        
        arreglo_enteros_ajustar(pila->arr,(pila->arr->capacidad)*2);
    }
    
        arreglo_enteros_escribir(pila->arr,pila->ultimo,dato);
        pila->ultimo += 1;
    
}

int pila_tope(Pila pila){
    if( pilas_es_vacia(pila)!= 1){
        return arreglo_enteros_leer(pila->arr,pila->ultimo);
    }
    return -1;
}


// consultar ayuda no acepta pilas <= 2 tam

void pila_desapilar(Pila pila){
    arreglo_enteros_eliminar(pila->arr,pila_tope(pila));
    pila->ultimo -= 1;

}
void pila_imprimir(Pila pila){
    for(int i =pila->ultimo-1; i>=0 ; i--){
        printf("elemento  %i \n",pila->arr->direccion[i]);
    }
}

int main(){
    Pila pila = pila_crear(2);
    printf("la pila es %i \n",pilas_es_vacia(pila));

    pila_apilar(pila,3);
    pila_apilar(pila,4);
    pila_apilar(pila,5);
   pila_apilar(pila,6);
/*     pila_desapilar(pila);
    pila_desapilar(pila); */

    printf("pila ultimo %i \n",pila->ultimo);
    pila_imprimir(pila);
            printf("la pila elemento tope es %i",pila_tope(pila));
    pila_destruir(pila);
    return 0 ;
}