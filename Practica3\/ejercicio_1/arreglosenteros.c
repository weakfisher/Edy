#include "arreglosenteros.h"

#include <stdio.h>
#include <stdlib.h>

/* Crear un arreglo dinamico
 */ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros * arreglo = malloc(sizeof(ArregloEnteros));  
    arreglo->direccion = malloc(sizeof(int)*capacidad);
    arreglo->capacidad = capacidad;
    return arreglo;
}

/* destruye un arreglo dinamico */

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
    free(arreglo->direccion);
    free(arreglo);
}

/* lee un arreglo dinamico */

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    if (pos > arreglo->capacidad){
        return -1;
    }
    else{
        
        return arreglo->direccion[pos-1];
    }
}

/*  escribe un entero en un arreglo
 */
void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){

    arreglo->direccion[pos] = dato;
}

/* devuevle un entero siendo el int la cap del arreglo
 */
int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    int num  = arreglo->capacidad;
    return num;
}

/* imprime el arreglo
 */
void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for(int i = 0;i<arreglo->capacidad;i++){
        printf("El elemetno %i es %i \n",i+1,arreglo->direccion[i]);
    }
}


/*  ajusta la capacida del arreglo 
 */
void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad){
    arreglo->capacidad = capacidad;
    arreglo = realloc(arreglo,capacidad);
}

void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato){
    int nueva_capacidad = (arreglo->capacidad)+1;
    arreglo->direccion = realloc(arreglo->direccion,nueva_capacidad*sizeof(int));
    for(int i = nueva_capacidad; i >=pos-1;i--){
        arreglo->direccion[i+1]= arreglo->direccion[i];
    }
    arreglo->direccion[pos-1] = dato;
    arreglo->capacidad = nueva_capacidad;
}

/* elimina un elemento que se encuentra en una pos
 */
void arreglo_enteros_eliminar(ArregloEnteros* arreglo,int pos){
    int nueva_capacidad = (arreglo->capacidad)-1;
    for(int i =pos-1;i< nueva_capacidad;i++){
        arreglo->direccion[i] = arreglo->direccion[i+1];
    }
    arreglo->direccion = realloc(arreglo->direccion,(nueva_capacidad+1)*sizeof(int));
    arreglo->capacidad = nueva_capacidad;
}


int esArregloVacio(ArregloEnteros* arr) {
    if (arr->direccion == NULL || arr->capacidad == 0) {
        return 1;
    } else {
        return 0;
    }
}
