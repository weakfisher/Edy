#include <stdio.h>
#include <stdlib.h>
#include "dglist.h"
#include <stdbool.h>

/* Implementar una funci ́on que determine si una lista enlazada es pal ́ındrome, esta aplicada en listas generales doblemente
 enlazadas por lo tanto se puede usar para verificar que cualquier tipo de dato es palindrome.
  En este caso muestro si es palindrome para listas que guarda numeros enteros
 */
void* copiar(void* data){
    int *num =malloc(sizeof(int));
    *num = *(int*)data;
    return num;
}

void imprimir_int(void* n){
    int *num = (int*) n ;
    printf( "-> %i ",*num);
}


bool verificar_igualdad(void* dato1,void * dato2){
    int *num1 = (int*)dato1;
    int *num2 = (int*)dato2;
    if ((*num2==*num1)){
        return true;
    }
    return false;
}

bool es_palindrome(GList *lista,FuncionComparadora compara){
    DNodo * inicio = lista->primero;
    DNodo * final = lista->ultimo;
        if (inicio == NULL || inicio == final) {
        return true;
    }
    bool iguales = true;
      while (inicio != final && inicio->ant != final && iguales ) {
        if (!compara(inicio->dato, final->dato)) {
            iguales= false;
        }
        inicio = inicio->sig;
        final = final->ant;
    } 
   return iguales;
}




int main(){
    GList *lista = glist_crear();
    for(int i = 0; i<5;i++){
       int  num = i;
        lista = agregar_inicio(lista,&num,(FuncionCopia)copiar);
    }
    GList *lista2 = glist_crear();

        
    int num1 = 1;
    lista2 = agregar_inicio(lista2, &num1, (FuncionCopia)copiar);
    int num2 = 2;
    lista2 = agregar_inicio(lista2, &num2, (FuncionCopia)copiar);
    int num3 = 3;
    lista2 = agregar_inicio(lista2, &num3, (FuncionCopia)copiar);
    int num4 = 2;
    lista2 = agregar_inicio(lista2, &num4, (FuncionCopia)copiar);
    int num5 = 1;
    lista2 = agregar_inicio(lista2, &num5, (FuncionCopia)copiar);



    glist_recorrer(lista2,(FuncionVisitante)imprimir_int);
    bool palindrome =es_palindrome(lista2,verificar_igualdad);
    printf("si son iguales es 1 contrario 0, valor= %i \n", palindrome);
    return 0;
}