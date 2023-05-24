#include "dglist.h"
#include "contacto.h"

#include <stdio.h>

typedef SGList Cola;


    Cola * cola_crear(){
        Cola* nq =sglist_crear();
        return nq;
    }

int main(){
    Cola * queue = cola_crear();
    return 0;
}