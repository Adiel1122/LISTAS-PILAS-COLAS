#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesColaCircular.c"


void crearColaC(struct colaC *cola){
    cola->head=NULL;
    cola->tail=NULL;
    pf("Cola creada\n");
}


void verColaC(struct colaC *cola){
    struct nodoCC *nodoActual = cola->head;
    pf("Datos de la cola:\n");
   do{
        pf("%d\n",nodoActual->dato);
        nodoActual = nodoActual->siguiente;
    } while(nodoActual != cola->head);
    pf("\n");
}


void liberarColaC(struct colaC *cola) {
    if (cola->head == NULL) return;

    struct nodoCC *nodoActual = cola->head;
    struct nodoCC *nodoLiberar;

    do {
        nodoLiberar = nodoActual;
        nodoActual = nodoActual->siguiente;
        free(nodoLiberar);
    } while(nodoActual != cola->head);

    cola->head = NULL;
    cola->tail = NULL;
}


int encolarC(struct colaC *cola,int nuevoDato){
    struct nodoCC *nuevoNodo=(struct nodoCC *)malloc(sizeof(struct nodoCC));
    if(nuevoNodo==NULL){
        pf("No se asigno memoria\n");
        return -1;
    }
    
    nuevoNodo->dato=nuevoDato;
    nuevoNodo->siguiente=NULL;

    if(cola->head==NULL){   
        cola->head=nuevoNodo;        
    } else{
        cola->tail->siguiente=nuevoNodo;
    }
    cola->tail=nuevoNodo;
    nuevoNodo->siguiente=cola->head;
    return 0;   
}


int desencolarC(struct colaC *cola){
    if(cola->tail == NULL){
        pf("Cola vacia\n");
        return -1;
    }

    struct nodoCC *nodoEliminar=cola->head;

    if(cola->head==cola->tail){
        pf("Cola vacia\n");
        cola->tail=NULL;
        cola->head=NULL;
    } else{
        cola->head=nodoEliminar->siguiente;
        cola->tail->siguiente=cola->head;
    }
    free(nodoEliminar);
    return 0;
}   


int frontC(struct colaC *cola){
    if(cola->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    return cola->head->dato;
}
