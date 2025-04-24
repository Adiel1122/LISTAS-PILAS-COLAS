#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesCola.c"


void crearCola(struct cola *cola) {  
    cola->head = NULL;
    cola->tail = NULL;  
    pf("Cola creada\n"); 
}  


void verCola(struct cola *cola) {  
    struct nodoC *nodoActual = cola->head;
    pf("Datos en la cola:\n");  
    while (nodoActual != NULL) {
        pf("%d\n", nodoActual->dato);
        nodoActual = nodoActual->siguiente;
    }  
    pf("\n");  
}  


int encolar(struct cola *cola, int nuevoDato) {  
    struct nodoC *nuevoNodo = (struct nodoC*)malloc(sizeof(struct nodoC));  
    if (nuevoNodo == NULL) {  
        pf("No se pudo asignar memoria\n");  
        return -1;  
    }  

    nuevoNodo->dato = nuevoDato;  
    nuevoNodo->siguiente = NULL;

    if (cola->head == NULL) { 
        cola->head = nuevoNodo; 
    } else {  
        cola->tail->siguiente = nuevoNodo; 
    }  

    cola->tail = nuevoNodo;

    return 0;  
}  


int desencolar(struct cola *cola) {  
    if (cola->head == NULL) {  
        pf("Cola vacia\n");  
        return -1;  
    }  

    struct nodoC *nodoEliminar = cola->head; 
    cola->head = nodoEliminar->siguiente; 

  
    if (cola->head == NULL) {  
        cola->tail = NULL;  
    }  

    free(nodoEliminar);
    return 0;  
}  



int front(struct cola *cola) {
    if (cola->head == NULL) {  
        pf("Cola vacia\n");  
        return -1; 
    }  
    return cola->head->dato;
}  


int empty(struct cola *cola) {
    if (cola->head != NULL) { 
        pf("Cola con elementos\n");  
        return -1;
    }  
    pf("Cola vacia");    
    return 0;
}   

/* 
	while(miCola.head != NULL){
		desencolar(&miCola);
	}
	
*/
