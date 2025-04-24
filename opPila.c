#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesPila.c"


void crearPila(struct pila *pila) {  
    pila->tope = NULL;  
    pf("Pila creada\n");  
}  


void verPila(struct pila *pila) {  
    pf("Datos en la pila:\n");  
    struct nodoP *nodoActual = pila->tope;  
    while (nodoActual != NULL) {  
        pf("%d\n", nodoActual->dato);
        nodoActual = nodoActual->siguiente;
    }  
}  


int push(struct pila *pila, int nuevoDato) {  
    struct nodoP *nuevoNodo = (struct nodoP *)malloc(sizeof(struct nodoP));  
    if (nuevoNodo == NULL) {  
        pf("No se pudo asignar la memoria\n");  
        return -1;  
    }  

    nuevoNodo->dato = nuevoDato;  
    nuevoNodo->siguiente = pila->tope; 
    pila->tope = nuevoNodo; 

    return 0;  
}  


int pop(struct pila *pila) {   
    if (pila->tope == NULL) {  
        pf("Pila vacia\n");  
        return -1;  
    }  
    
    struct nodoP *nodoEliminar = pila->tope;  
    pila->tope = nodoEliminar->siguiente;
    free(nodoEliminar);
    return 0;  
}  


int top(struct pila *pila) {  
    if (pila->tope == NULL) {  
        pf("Pila vacia\n");  
        return -1;  
    } else {  
        return pila->tope->dato; 
    }  
}  


int empty(struct pila *pila) {  
    if(pila->tope != NULL){
        pf("Pila con elementos");
        return -1;
    }
    pf("Pila vacia");
    return 0;
}


/* 
	while(miPila.tope != NULL){
		pop(&miPila)
	}
	
*/
