/*	PILA DINAMICA CON TODAS LAS OPERACIONES
--------------------------------------
PUSH
Inserta un elemento
--------------------------------------
POP
Elimina un elemento
--------------------------------------
TOP / PEEK
Devuelve el elemento en la cima de la pila sin eliminarlo
--------------------------------------
EMPTY
Verifica si la pila esta vacia
--------------------------------------
FULL
Verifica si la pila esta llena
--------------------------------------

*/

#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf


// funciones

struct nodo {  
    int dato;  
    struct nodo *siguiente;  
};  

struct pila {  
    struct nodo *tope;  
};  

void crearPila(struct pila *);
void verPila(struct pila *);  
int push(struct pila *, int);  
int pop(struct pila *);   
int top(struct pila *);
int empty(struct pila *);


// operaciones

void crearPila(struct pila *pilaNueva) {  
    pilaNueva->tope = NULL;  
    pf("Pila creada\n");  
}  


void verPila(struct pila *verPila) {  
    pf("Datos en la pila:\n");  
    struct nodo *verNodo = verPila->tope;  
    while (verNodo != NULL) {  
        pf("%d\n", verNodo->dato);
        verNodo = verNodo->siguiente;
    }  
}  


int push(struct pila *pilaPush, int nuevoDato) {  
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL) {  
        pf("No se pudo asignar la memoria\n");  
        return -1;  
    }  

    nuevoNodo->dato = nuevoDato;  
    nuevoNodo->siguiente = pilaPush->tope; 
    pilaPush->tope = nuevoNodo; 

    return 0;  
}  


int pop(struct pila *pilaPop) {   
    if (pilaPop->tope == NULL) {  
        pf("Pila vacia\n");  
        return -1;  
    }  
    
    struct nodo *nodoEliminar = pilaPop->tope;  
    pilaPop->tope = nodoEliminar->siguiente;
    free(nodoEliminar);
    return 0;  
}  


int top(struct pila *pilaTop) {  
    if (pilaTop->tope == NULL) {  
        pf("Pila vacia, no hay elemento en la cima\n");  
        return -1;  
    } else {  
        return pilaTop->tope->dato; 
    }  
}  


int empty(struct pila *pilaChecar) {  
    return pilaChecar->tope == NULL;
}



// main

int main() {  
    struct pila miPila;  
    crearPila(&miPila);  

    pop(&miPila);
    push(&miPila, 10);  
    push(&miPila, 8);  
    push(&miPila, 666);  

    pf("Elemento en la cima: %d\n", top(&miPila));  
    pf("¿Pila vacia? %s\n", empty(&miPila) ? "Sí" : "No");  
    
    verPila(&miPila);  

    // Liberar memoria  
    while (!empty(&miPila)) {  
        pop(&miPila);  
    }  

    return 0;  
}
