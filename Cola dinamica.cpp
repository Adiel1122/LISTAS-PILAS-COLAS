/*	COLA DINAMICA CON TODAS LAS OPERACIONES
--------------------------------------
ENCOLAR
Inserta un elemento
--------------------------------------
DESENCOLAR
Elimina un elemento
--------------------------------------
FRONT
Devuelve el elemento head de la cola sin eliminarlo
--------------------------------------
EMPTY
Verifica si la cola esta vacia
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


struct cola {  
    struct nodo *head;  
    struct nodo *tail;  
};  

void crearCola(struct cola *);
void verCola(struct cola *);    
int encolar(struct cola *, int);  
int desencolar(struct cola *);  
int front(struct cola *);
int empty(struct cola *); 


// operaciones

void crearCola(struct cola *nuevaCola) {  
    nuevaCola->head = NULL;
    nuevaCola->tail = NULL;  
    pf("Cola creada\n");  
    return; 
}  


void verCola(struct cola *miCola) {  
    struct nodo *nodoAuxiliar = miCola->head;
    pf("Datos en la cola:\n");  
    while (nodoAuxiliar != NULL) {
        pf("%d\n", nodoAuxiliar->dato);
        nodoAuxiliar = nodoAuxiliar->siguiente;
    }  
    pf("\n");  
}  


int encolar(struct cola *encolarCola, int dato) {  
    struct nodo *nuevoNodo = (struct nodo*)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL) {  
        pf("No se pudo asignar la memoria al elemento\n");  
        return -1;  
    }  

    nuevoNodo->dato = dato;  
    nuevoNodo->siguiente = NULL;

    if (encolarCola->head == NULL) { 
        encolarCola->head = nuevoNodo; 
    } else {  
        encolarCola->tail->siguiente = nuevoNodo; 
    }  

    encolarCola->tail = nuevoNodo;

    return 0;  
}  


int desencolar(struct cola *desencolarCola) {  
    if (desencolarCola->head == NULL) {  
        pf("Error: la cola esta vacia\n");  
        return -1;  
    }  

    struct nodo *nodoEliminar = desencolarCola->head; 
    desencolarCola->head = nodoEliminar->siguiente; 

  
    if (desencolarCola->head == NULL) {  
        desencolarCola->tail = NULL;  
    }  

    free(nodoEliminar);
    return 0;  
}  



int front(struct cola *frontCola) {
    if (frontCola->head == NULL) {  
        pf("Error: la cola esta vacia\n");  
        return -1; 
    }  
    return frontCola->head->dato;
}  


int empty(struct cola *checarCola) {
    if (checarCola->head == NULL) { 
        pf("La cola esta vacia\n");  
        return 1;
    } else {  
        return 0;
    }  
}  



// main

int main() {  
    struct cola miCola;  
    crearCola(&miCola);
    empty(&miCola);

    encolar(&miCola, 1);  
    encolar(&miCola, 2);  
    encolar(&miCola, 3);   
    verCola(&miCola);

    encolar(&miCola, 4);
    verCola(&miCola);

    desencolar(&miCola);
    desencolar(&miCola);
    verCola(&miCola);

    int datoHead = front(&miCola);
    pf("Dato del head: %d\n", datoHead);  
    
    desencolar(&miCola);
    int datoHeadDos = front(&miCola);
    pf("Dato del head: %d\n", datoHeadDos);  
    
    // Liberar memoria  
    while (!empty(&miCola)) {  
        desencolar(&miCola);  
    }  

    system("PAUSE");  
    return 0;  
}
  