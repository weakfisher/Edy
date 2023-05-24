#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char*pais;
    char*ciudad;
    int cantidadHabitantes;
    int importancia;
    }
     Objetivo;

typedef struct nodo{
    Objetivo dato;
    struct nodo*anterior;
    struct nodo*siguiente;
    }
     Nodo;


Nodo* agregaObjetivo(Nodo*inicio, Objetivo o){
    // creamos un objetivo
    Nodo *nuevoNodo = malloc(sizeof(Nodo));
    nuevoNodo->dato = o;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;
    if (inicio == NULL){
        return nuevoNodo; 
    }
    else {
        Nodo * actual = inicio;
        while(actual->siguiente != NULL){
            actual =actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
        nuevoNodo->anterior = actual;
    }
    return inicio;
}


void muestraCantidadHabitantesPorPais(Nodo*inicio, char*pais){
    int contadorHab = 0;
    if (inicio == NULL){
        printf("NO hay objetivos previstos para ese pais");
    }
    else{
        Nodo * actual = inicio;
        while(actual != NULL){
            
                // printf(" las cant %s",);
            
            if (strcasecmp(actual->dato.pais,pais)== 0){
                contadorHab += actual->dato.cantidadHabitantes;
            }
           actual = actual->siguiente;
        }
    printf("la suma total de gente en el pais es de %i",contadorHab);
    }

}

Objetivo *creaObjetivo(){
    Objetivo *o=malloc(sizeof(Objetivo));
    int cantH;
    char buffer[255];
    printf("Ingrese un pais" );
    scanf("%s",buffer);
    o->pais = malloc(sizeof(char)*strlen(buffer)+1);
    strcpy(o->pais,buffer);

    printf("ingrese una ciudad ");
    scanf("%s",buffer);
    o->ciudad = malloc(sizeof(char)*strlen(buffer)+1);
    strcpy(o->ciudad,buffer);

    printf("Ingrese cant hab");
    scanf("%i",&cantH);
    o->cantidadHabitantes=cantH;
     while (getchar() != '\n');
    
    return o;

    
}

int main(){
    // creamos un nodo 
   Objetivo* o;
    o = creaObjetivo();
    Nodo *inicio = NULL;
    Objetivo o2;
    o2.ciudad = "ros";
    o2.pais = "argentina";
    o2.cantidadHabitantes = 1000;
    Objetivo o3;
    o3.ciudad = "ros";
    o3.pais = "argentina";
    o3.cantidadHabitantes = 2000;
    inicio = agregaObjetivo(inicio,*o);
    inicio = agregaObjetivo(inicio,o2);
    inicio = agregaObjetivo(inicio,o3);
    muestraCantidadHabitantesPorPais(inicio,"argentina");


    
    
    return 0;


}