#include <stdio.h>
#include "contacto.h"
#include "pila.h"



// preguntar donde hay memory leak
void invertir_pila(Pila* pila,FuncionCopia copia){
    Pila invertida = pila_crear();

    while(!pila_es_vacia(*pila)){
        void * dato =pila_tope(*pila);
        pila_desapilar(pila);
        pila_apilar(&invertida,dato,(FuncionCopia )copia);
    }
    pila_destruir(pila,(FuncionDestructora) contacto_destruir);   
    printf("%i", pila_es_vacia(*pila));
    *pila = invertida;
}
 

int main(){
    Pila pila = pila_crear();
    Contacto *contactos[6];
      contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
    contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
    contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
    contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
    contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
    contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);
    for(int i = 0; i<6;i++){
        
        pila_apilar(&pila,contactos[i],(FuncionCopia)contacto_copia);
        contacto_destruir(contactos[i]);
    }
    printf("La lista sin invertir es \n");
    pila_imprimir(pila,(FuncionVisitante)contacto_imprimir);
    invertir_pila(&pila,(FuncionCopia )contacto_copia);
    printf("La lista  invertida es \n");
    pila_imprimir(pila,(FuncionVisitante)contacto_imprimir);
    
   
    pila_destruir(&pila,(FuncionDestructora)contacto_destruir);
    return 0;
}