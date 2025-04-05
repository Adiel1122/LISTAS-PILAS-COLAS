// LISTA CIRCULAR

#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

// funciones

struct nodo {  
    int dato;  
    struct nodo *siguiente;  
};  

struct lista {  
    struct nodo *head;  
};  
  
void crearLista(struct lista *);
void verLista(struct lista *);  
void liberarLista(struct lista *);  
int insertar(struct lista *, int);  
int buscar(struct lista *, int);  
int borrar(struct lista *, int);  


// operaciones

void crearLista(struct lista *nuevaLista) {  
    nuevaLista->head = NULL;  
    pf("Lista creada\n");  
}  


void verLista(struct lista *verLista) {  
    if (verLista->head == NULL) {  
        pf("Lista Vacia\n");  
        return;  
    }  

    struct nodo *nodoActual = verLista->head->siguiente;  
    pf("Datos de la lista:\n");  

    do {  
        pf("%d\n", nodoActual->dato);  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != verLista->head->siguiente);  
    pf("\n");  
}  


void liberarLista(struct lista *liberarLista) {  
    if (liberarLista->head == NULL) {  
        pf("La lista ya está vacía\n");  
        return;  
    }  

    struct nodo *listaTail = liberarLista->head;
    while(listaTail->siguiente != liberarLista->head) {  
         listaTail = listaTail->siguiente;  
    }  
    listaTail->siguiente = NULL;

    struct nodo *nodoActual = liberarLista->head;  
    struct nodo *nodoSiguiente;  

    while (nodoActual != NULL) {  
        nodoSiguiente = nodoActual->siguiente;  
        free(nodoActual);  
        nodoActual = nodoSiguiente;  
    }  
    liberarLista->head = NULL;  
    pf("Memoria de la lista liberada correctamente\n");  
}


int insertar(struct lista *insertarLista, int nuevoDato) {  
    struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  

    if (insertarLista->head == NULL) {

        nuevoNodo->siguiente = nuevoNodo;  
        insertarLista->head = nuevoNodo;  
    } else {  
        nuevoNodo->siguiente = insertarLista->head->siguiente;  
        insertarLista->head->siguiente = nuevoNodo;  
        
    }  
    return 0;  
}  


int buscar(struct lista *buscarLista, int datoBuscar) {  
    if (buscarLista->head == NULL) {  
        pf("Lista vacia\n");  
        return -1;  
    }  
    struct nodo *nodoActual = buscarLista->head;  
    do {  
        if (nodoActual->dato == datoBuscar) {  
            pf("Dato encontrado\n");  
            return nodoActual->dato;  
        }  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != buscarLista->head);

    pf("Dato no encontrado\n");  
    return -1;  
}  


int borrar(struct lista *borrarLista, int datoBorrar) {  
    if (borrarLista->head == NULL) {  
        pf("Lista vacia\n");  
        return -1;  
    }  

    struct nodo *nodoActual = borrarLista->head;  
    struct nodo *nodoPrevio = NULL;  

    do {  
        if (nodoActual->dato == datoBorrar) {  
            break;  
        }  
        nodoPrevio = nodoActual;  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != borrarLista->head);

    if (nodoActual->dato != datoBorrar) {  
        
        pf("No esta el elemento\n");  
        return -1;  
    }  
   
    if (nodoActual->siguiente == nodoActual) {  
        borrarLista->head = NULL;  
    } else {  
        if (nodoPrevio == NULL) {  
            nodoPrevio = borrarLista->head;
            while(nodoPrevio->siguiente != borrarLista->head) {  
                nodoPrevio = nodoPrevio->siguiente;  
            }  
            nodoPrevio->siguiente = nodoActual->siguiente;  
            borrarLista->head = nodoPrevio; 
        } else {  
            nodoPrevio->siguiente = nodoActual->siguiente;  
        }  
    }  

    free(nodoActual);
    return 0;  
}  


// main

int main() {  
    struct lista miLista;  
    crearLista(&miLista);  

    insertar(&miLista, 1);  
    insertar(&miLista, 2);  
    insertar(&miLista, 3);  
    insertar(&miLista, 4);  
    insertar(&miLista, 5);  
    verLista(&miLista);  

    buscar(&miLista, 4);  
    buscar(&miLista, 9);  

    borrar(&miLista, 1);  
    borrar(&miLista, 5);    
    verLista(&miLista);  

    // Liberar memoria  
    liberarLista(&miLista);  
    return 0;  
}
