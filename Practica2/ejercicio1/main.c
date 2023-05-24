#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef void (*FuncionVisitante) (int dato);

typedef struct nodo {
    int dato ;
    struct nodo *sig;
}Nodo;

Nodo * slit_agregar_final(Nodo * lista , int dato){
    if (lista == NULL){
        lista = malloc(sizeof(Nodo));
        lista->dato = dato;
        lista->sig = NULL;

    }
    else{
        lista->sig = slit_agregar_final(lista->sig,dato);
    }
    return lista;

}


int slist_longitud(Nodo *lista){
    if (lista == NULL){
        return 0;
    }
    int contador = 1;
    for(Nodo* actual = lista; actual->sig!= NULL;actual = actual->sig ){
        contador++;

    }
    return contador;
}

 Nodo * slist_concatenar(Nodo * lista1, Nodo* lista2){
    if (lista1 == NULL){
        return lista2;
    }
    else if (lista2 == NULL){
        return lista1;
    }
    Nodo* actual = lista1;
    while (actual->sig != NULL) {
        actual = actual->sig;

    }
    actual->sig = lista2;



    return lista1;
 }

Nodo * slist_insertar(Nodo * lista,int pos,int dato){
    Nodo * nuevoNodo= malloc(sizeof(Nodo));
    nuevoNodo->sig = NULL;
    nuevoNodo->dato = dato;
    if(lista == NULL || pos == 1){
        
        nuevoNodo->sig = lista;
        lista= nuevoNodo;
        return lista;
    }
    Nodo *temp = lista;
    int i = 1;
    while(temp->sig != NULL && i<pos-1){
        temp = temp->sig;
        i++;
    }

    if (i == pos-1){
        nuevoNodo->sig = temp->sig;
        temp->sig = nuevoNodo;
    }
    

    return lista;


}

void slist_eliminar(Nodo * lista,int pos){
    Nodo *temp = lista;
   
    if (pos == 1){
        lista = lista->sig;
    }
   
   
    int i = 1;
    while(temp->sig != NULL && i<pos-1){
        temp = temp->sig;
        i++;
    }

    if (i == pos-1){
        temp->sig= temp->sig->sig;
    }
    

}

int slist_contiene(Nodo * lista, int dato){
    int not_encontrado = 0;
    Nodo * temp=lista;
    while(temp!= NULL && not_encontrado == 0){
        if(temp->dato == dato){
            not_encontrado = 1;
        }
        temp = temp->sig;
    }
    return not_encontrado;
}
void slist_recorrer(Nodo* lista, FuncionVisitante visit) {
  for (Nodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}
static void imprimir_entero(int dato) {
  printf("%d ", dato);
}
int slist_indice(Nodo * lista,int dato){
    int not_encontrado = 0;
    int contador = 1;
    Nodo * temp=lista;
    while(temp->sig != NULL && not_encontrado == 0){
        if(temp->dato == dato){
            not_encontrado = 1;
            
        }
        else{
        temp = temp->sig;
        contador++;}
    }
    if (not_encontrado==0){return -1;}
    else{return contador;}
    
}

Nodo * slist_intersecar(Nodo* lista1 , Nodo * lista2){
    Nodo * nuevaLista= NULL;
    Nodo * ultimo = NULL;

    for(Nodo * temp=lista1;temp!= NULL;){
        if(slist_contiene(lista2,temp->dato) && lista2->sig != NULL){
            Nodo * nuevoNodo= malloc(sizeof(Nodo));
            nuevoNodo->dato = temp->dato;
            nuevoNodo->sig = NULL;
        
        if (nuevaLista == NULL){
            nuevaLista = nuevoNodo;
            ultimo = nuevoNodo;
            }
        else{
            ultimo->sig =nuevoNodo;
            ultimo = nuevoNodo;
            }
        }
        temp = temp->sig;
    }
    return nuevaLista;

}
int compararEnteros(int n,int m){
    if (n>m){
        return 0;
    }
    return -1;
}
Nodo * slist_ordenar(Nodo * lista1,int(*func)(int,int)){
    Nodo * inicio = lista1;
    Nodo* temp = inicio;
    Nodo* temp2 = NULL;
    int numb;
    while(temp !=NULL){
        temp2 = temp->sig;
        while(temp2 !=NULL){
            if(func(temp->dato,temp2->dato)==0){
                numb = temp->dato;
                temp->dato = temp2->dato;
                temp2->dato = numb;

            }
            temp2 = temp2->sig;
        }
        temp = temp->sig;
    }
    return inicio;


}
Nodo * slist_reverso(Nodo* lista){
    
    Nodo * actual = lista;
    Nodo * anterior= NULL;
    Nodo * siguiente =NULL;
    while(actual!= NULL){
    siguiente = actual->sig;    
    actual->sig = anterior;
    anterior  = actual;
    actual = siguiente;
    }
    lista= anterior;
    return lista;
}

Nodo* slist_intercalar(Nodo* lista1,Nodo* lista2){
    Nodo * temp = lista1;
    Nodo* nuevaLista =NULL;
    while(lista1!=NULL && lista2 != NULL){
        if(nuevaLista == NULL){
            nuevaLista=lista1;
            temp = nuevaLista;
        }
        else{
            temp->sig =lista1;
            temp =temp->sig;
        }
        lista1 =lista1->sig;

        temp->sig =lista2;
        temp =temp->sig;
        lista2=lista2->sig;
    }
      if (lista1 != NULL) {
        if (nuevaLista == NULL) {
            nuevaLista = lista1;
        } else {
            temp->sig = lista1;
        }
    } else if (lista2 != NULL) {
        if (nuevaLista == NULL) {
            nuevaLista = lista2;
        } else {
            temp->sig = lista2;
        }
    }
    return nuevaLista;
}

Nodo* slist_partir(Nodo* lista){
    int longitud = slist_longitud(lista);
    Nodo * temp = lista;
    if(longitud%2 == 0){
        for(int contador= 0 ;contador<longitud/2;contador++){
            temp = temp->sig;
        }
    }
    else{
        for(int contador= 0 ;contador<(longitud/2)+1;contador++){
            temp = temp->sig;
        }
    }
    return temp;
}



int main(){
    Nodo* inicioL = NULL;
    Nodo * nodo2 = NULL;
    inicioL = slit_agregar_final(inicioL,1);
    inicioL = slit_agregar_final(inicioL,2);
    inicioL = slit_agregar_final(inicioL,3);

    inicioL = slist_insertar(inicioL,4,4);
    //slist_eliminar(inicioL,1);
    nodo2 = slit_agregar_final(nodo2,4);
    nodo2 = slit_agregar_final( nodo2,5);
    nodo2 = slit_agregar_final( nodo2,6);
    nodo2 = slit_agregar_final( nodo2,6);
    nodo2 = slit_agregar_final( nodo2,6);
    nodo2 = slit_agregar_final( nodo2,6);


    //inicioL = slist_concatenar(inicioL,nodo2);
    //printf("El elemento %i \n",slist_contiene(inicioL,20));
    //printf("El elemento esta en %i \n",slist_indice(inicioL,4));
    
    // Nodo* nodo3 = slist_intersecar(inicioL,nodo2);
    // slist_recorrer(nodo3, imprimir_entero);

   // Nodo* lista_ascendente = slist_ordenar(inicioL,compararEnteros);
    //slist_recorrer(lista_ascendente, imprimir_entero);

    // Nodo * reverso = slist_reverso(inicioL);
    // slist_recorrer(reverso, imprimir_entero);

    // Nodo * listaIntercalada = slist_intercalar(inicioL,nodo2);
    // slist_recorrer(listaIntercalada, imprimir_entero);

    Nodo * listaPartida = slist_partir(inicioL);
    slist_recorrer(listaPartida, imprimir_entero);
    printf("la longitud es %i",slist_longitud(inicioL));
    return 0;
}
