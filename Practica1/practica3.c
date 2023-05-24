#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int* direccion;
int capacidad;
} ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad){
    ArregloEnteros * arreglo = malloc(sizeof(ArregloEnteros));  
    arreglo->direccion = malloc(sizeof(int)*capacidad);
    arreglo->capacidad = capacidad;
    return arreglo;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
    free(arreglo->direccion);
    free(arreglo);
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    if (pos > arreglo->capacidad){
        return -1;
    }
    else{
        printf(" D %i D",arreglo->direccion[pos-1]);
    }
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){

    arreglo->direccion[pos] = dato;
}
int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    int num  = arreglo->capacidad;
    return num;
}

void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for(int i = 0;i<arreglo->capacidad;i++){
        printf("El elemetno %i es %i \n",i+1,arreglo->direccion[i]);
    }
}

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

void arreglo_enteros_eliminar(ArregloEnteros* arreglo,int pos){
    int nueva_capacidad = (arreglo->capacidad)-1;
    for(int i =pos-1;i< nueva_capacidad;i++){
        arreglo->direccion[i] = arreglo->direccion[i+1];
    }
    arreglo->direccion = realloc(arreglo->direccion,nueva_capacidad*sizeof(int));
    arreglo->capacidad = nueva_capacidad;
}


int main(){
    ArregloEnteros* arreglo = arreglo_enteros_crear(4);
    for(int i = 0; i< arreglo->capacidad;i++){
        arreglo->direccion[i] = i+1;
    }
    printf("%i %s" ,arreglo->capacidad,"FD");
    arreglo_enteros_leer(arreglo,5);
    arreglo_enteros_escribir(arreglo,2,3);
    arreglo_enteros_imprimir(arreglo);

    //arreglo_enteros_ajustar(arreglo,1);

    //arreglo_enteros_insertar(arreglo,5,5);

    arreglo_enteros_eliminar(arreglo,2);
    arreglo_enteros_imprimir(arreglo);
    //int capacidad = arreglo_enteros_capacidad(arreglo);
    //printf(" la capaciad es %i",capacidad);
    arreglo_enteros_destruir(arreglo);
    return 0;
}