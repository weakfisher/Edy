
#ifndef __MATRIZ_H__
#define __MATRIZ_H__

#include <stdlib.h>



typedef struct {
int* direccion;
int capacidad;
} ArregloEnteros;
/* Crear un arreglo dinámico */
ArregloEnteros* arreglo_enteros_crear(int capacidad);

int esArregloVacio(ArregloEnteros *arr);

/* Destruye un arreglo dinámico */
void arreglo_enteros_destruir(ArregloEnteros* arreglo);

/* Lee un elemento de un arreglo en una posición específica */
int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos);

/* Escribe un entero en un arreglo en una posición específica */
void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato);

/* Devuelve la capacidad del arreglo */
int arreglo_enteros_capacidad(ArregloEnteros* arreglo);

/* Imprime los elementos del arreglo */
void arreglo_enteros_imprimir(ArregloEnteros* arreglo);

/* Ajusta la capacidad del arreglo */
void arreglo_enteros_ajustar(ArregloEnteros* arreglo, int capacidad);

/* Inserta un elemento en una posición específica del arreglo */
void arreglo_enteros_insertar(ArregloEnteros* arreglo, int pos, int dato);

/* Elimina un elemento en una posición específica del arreglo */
void arreglo_enteros_eliminar(ArregloEnteros* arreglo, int pos);

#endif /* __MATRIZ_H__ */