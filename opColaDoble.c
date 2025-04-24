#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesColaDoble.c"


void crearColaD(struct colaD *cola){
    cola->head = NULL;
    cola->tail = NULL;
    pf("Cola creada\n");
}


void verCola(struct colaD *cola){
    struct nodoCD *nodoActual = cola->head;
    pf("Datos en la cola\n");
    while(nodoActual != NULL){
        pf("%d\n",nodoActual->dato);
        nodoActual = nodoActual->siguiente;
    }
    pf("\n");
}


int encolarHead(struct colaD *cola, int nuevoDato){
    struct nodoCD *nuevoNodo=(struct nodoCD *)malloc(sizeof(struct nodoCD));
    if(nuevoNodo==NULL){
        pf("No se asigno memoria");
        return -1;
    }

    nuevoNodo->dato = nuevoDato;
    nuevoNodo->anterior = NULL;
    
    nuevoNodo->siguiente = cola->head;
    
    if(cola->head==NULL){
        cola->head = nuevoNodo;
        cola->tail = nuevoNodo;
    } else{
        cola->head->anterior=nuevoNodo;
        cola->head=nuevoNodo;
    }
    return 0;
}


int encolarTail(struct colaD *cola, int nuevoDato){
    struct nodoCD *nuevoNodo=(struct nodoCD *)malloc(sizeof(struct nodoCD));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria");
        return -1;
    }
    
    nuevoNodo->dato = nuevoDato;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = cola->tail;
    
    if(cola->head==NULL){
        cola->head = nuevoNodo;
        cola->tail = nuevoNodo;
    } else{
        cola->tail->siguiente = nuevoNodo;
        cola->tail = nuevoNodo;
    }
    return 0;
}


int desencolarHead(struct colaD *cola){
    if(cola->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    
    struct nodoCD *nodoEliminar = cola->head;
    
    if(cola->head == cola->tail){
        pf("Cola vacia\n");
        cola->head = NULL;
        cola->tail = NULL;
    } else{
        cola->head = nodoEliminar->siguiente;
        cola->head->anterior = NULL;
    }
    free(nodoEliminar);
    return 0;
}


int desencolarTail(struct colaD *cola){
    if(cola->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    
    struct nodoCD *nodoEliminar=cola->tail;
    
    if(cola->head == cola->tail){
        pf("Cola vacia\n");
        cola->head = NULL;
        cola->tail = NULL;
    } else{
        cola->tail = nodoEliminar->anterior;
        cola->tail->siguiente = NULL;
    }
    free(nodoEliminar);
    return 0;
}


int front(struct colaD *cola){
    if(cola->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    return cola->head->dato;
}


int back(struct colaD *cola){
    if(cola->tail==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    return cola->tail->dato;
}


/*
    while(miCola.head!=NULL){
        desencolarHead(&miCola);
    }

*/
