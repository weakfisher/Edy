

#ifndef __SGLIST_H__
#define __SGLIST_H__

typedef void (*FuncionDestructora)(void* dato);
typedef void* (*FuncionCopia)(void* dato);
typedef void (*FuncionVisitante)(void* dato);
typedef int (*FuncionComparadora)(void* dato1, void* dato2);

typedef struct _GNode {
    void* data;
    struct _GNode* next;
} GNode;

typedef struct {
    GNode* primero;
    GNode* ultimo;
} SGList;


SGList* sglist_crear();

void sglist_destruir(SGList* lista, FuncionDestructora destroy);

int sglist_vacia(SGList* lista);

void sglist_recorrer(SGList* lista, FuncionVisitante visitante);

SGList* sglist_agregar_inicio(SGList* lista, FuncionCopia copia, void* data);

SGList* sglist_insertar(SGList* lista, void* data, FuncionCopia copia, FuncionComparadora compara);

int sglist_buscar(SGList* lista, void* data, FuncionComparadora buscar);

SGList* sglist_arr(void** arr, int longi, FuncionCopia copia, FuncionComparadora compara);




#endif /* __SGLIST_H__ */