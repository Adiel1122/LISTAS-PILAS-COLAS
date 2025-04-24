#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesListaDobleCircular.c"

void crearListaDC(struct listaDC *lista){
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    pf("Lista creada\n");
}



void verListaDC(struct listaDC *lista){
    if(lista->head == NULL){
        pf("Lista vacia\n");
    } else{   	
        struct nodoLDC *nodoActual = lista->head;
        pf("Datos de la lista:\n");
        do {
            pf("%d\n", nodoActual->dato);
            nodoActual = nodoActual->siguiente;
        } while(nodoActual != lista->head);
    }
}



void verListaPosicionesDC(struct listaDC *lista){
    if(lista->head == NULL){
        pf("Lista vacia\n");
    } else{
        struct nodoLDC *nodoActual = lista->head;
        int indice = 0;
        pf("Datos de la lista:\n");
        do {
            pf("Posicion:%d Dato:%d\n", indice, nodoActual->dato);
            nodoActual = nodoActual->siguiente;
            indice++;
        } while(nodoActual != lista->head);
    }
    pf("\n");
}



void liberarListaDC(struct listaDC *lista) {   
    if(lista->head == NULL) {   
        pf("Lista vacia\n");   
        return;  
    }   
  
    struct nodoLDC *nodoActual = lista->head;   
    struct nodoLDC *nodoLiberar;  

    do {  
        nodoLiberar = nodoActual;  // Guarda el nodo actual que se va a liberar  
        nodoActual = nodoActual->siguiente;  // Apunta al siguiente nodo  
        free(nodoLiberar);  // Libera el nodo que se acaba de guardar  
    } while(nodoActual != lista->head); // Contin�a hasta volver al nodo inicial 

    lista->head = NULL;  
    lista->tail = NULL;   
    lista->size = 0;
    pf("Memoria liberada\n");   
}  



int insertarDC(struct listaDC *lista, int nuevoDato){
    struct nodoLDC *nuevoNodo=(struct nodoLDC*)malloc(sizeof(struct nodoLDC));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }

    nuevoNodo->dato = nuevoDato;
    
    if(lista->head == NULL){
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        lista->head = nuevoNodo;
        lista->tail = nuevoNodo;
    } else {
        nuevoNodo->siguiente = lista->head;
        nuevoNodo->anterior = lista->tail;
        
        lista->head->anterior = nuevoNodo;
        lista->tail->siguiente = nuevoNodo;
        
        lista->head = nuevoNodo;
    }
    lista->size++;
    return 0;
}



int insertarFinalDC(struct listaDC *lista, int nuevoDato){  
    struct nodoLDC *nuevoNodo=(struct nodoLDC*)malloc(sizeof(struct nodoLDC));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }

    nuevoNodo->dato = nuevoDato;  
    
    if(lista->head == NULL){  
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        lista->head = nuevoNodo;  
        lista->tail = nuevoNodo;  
    } else{
        nuevoNodo->siguiente = lista->head;  
        nuevoNodo->anterior = lista->tail;  
        
        lista->tail->siguiente = nuevoNodo;  
        lista->head->anterior = nuevoNodo;  
        
        lista->tail = nuevoNodo;  
    }  
    lista->size++;  
    return 0;  
}  



int insertarCualquierPosicionDC(struct listaDC *lista, int nuevoDato, int posicion){
    if(posicion < 0 || posicion > lista->size){
        pf("Posicion no valida\n");
     return -1;
    }
    
    if(posicion == 0) return insertarDC(lista, nuevoDato);
    if(posicion == lista->size) return insertarFinalDC(lista, nuevoDato);
    
    struct nodoLDC *nuevoNodo=(struct nodoLDC*)malloc(sizeof(struct nodoLDC));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }  
    
    nuevoNodo->dato = nuevoDato;  
    struct nodoLDC *nodoActual = lista->head;
    for(int i = 0; i < posicion; i++) nodoActual = nodoActual->siguiente;
    
    nuevoNodo->siguiente = nodoActual;
    nuevoNodo->anterior = nodoActual->anterior;
    
    nodoActual->anterior->siguiente = nuevoNodo;
    nodoActual->anterior = nuevoNodo;
    
    lista->size++;
    return 0;
}  



struct nodoLDC * buscarNodoDC(struct listaDC *lista, int datoBuscar){
    if(lista->head == NULL) return NULL;
    
    struct nodoLDC *nodoActual = lista->head;
    do {
        if(nodoActual->dato == datoBuscar) return nodoActual;
        nodoActual = nodoActual->siguiente;
    } while(nodoActual != lista->head);
    
    return NULL;
}

int buscarDC(struct listaDC *lista, int datoBuscar){
    struct nodoLDC *nodoBuscar = buscarNodoDC(lista, datoBuscar);
    return (nodoBuscar != NULL) ? nodoBuscar->dato : -1; //Regresa 0 si se encontro el dato, si no lo encontro regresa -1
}



int borrarDC(struct listaDC *lista, int datoBorrar){  
    if(lista->head == NULL){
        pf("Lista vacia\n");
        return -1;
    }  
    
    struct nodoLDC *nodoEliminar = buscarNodoDC(lista, datoBorrar);  
    if(nodoEliminar == NULL){
        pf("Dato no encontrado\n");
        return -1;
    }  
    
    if(lista->size == 1){  
        lista->head = NULL;  
        lista->tail = NULL;  
    } else {  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior;  
        
        if(nodoEliminar == lista->head) lista->head = nodoEliminar->siguiente;  
        if(nodoEliminar == lista->tail) lista->tail = nodoEliminar->anterior;  
    }  
    
    free(nodoEliminar);  
    lista->size--;  
    return 0;  
}



int borrarIndiceDC(struct listaDC *lista, int posicion){  
    if(posicion < 0 || posicion >= lista->size){
        pf("Posicion no valida\n");
        return -1;
    }  
    
    struct nodoLDC *nodoEliminar = lista->head;  
    for(int i = 0; i < posicion; i++) nodoEliminar = nodoEliminar->siguiente;  
    
    if(lista->size == 1){  
        lista->head = NULL;  
        lista->tail = NULL;  
    } else {  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior;  
        
        if(nodoEliminar == lista->head) lista->head = nodoEliminar->siguiente;  
        if(nodoEliminar == lista->tail) lista->tail = nodoEliminar->anterior;  
    }  
    
    free(nodoEliminar);  
    lista->size--;  
    return 0;  
}



int sizeListaDC(struct listaDC *lista){  
    return lista->size;  
}

