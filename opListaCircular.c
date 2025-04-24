#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesListaCircular.c"


void crearListaC(struct listaC *lista) {  
    lista->head = NULL;  
    pf("Lista creada\n");  
}  


void verListaC(struct listaC *lista) {  
    if (lista->head == NULL) {  
        pf("Lista vacia\n");  
        return;  
    }  

    struct nodoLC *nodoActual = lista->head;  
    pf("Datos de la lista:\n");  
    do {  
        pf("%d\n", nodoActual->dato);  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != lista->head);  
    pf("\n");  
}  



void liberarListaC(struct listaC *lista) {  
    struct nodoLC *nodoActual = lista->head;  
    struct nodoLC *nodoSiguiente;  
    do {  
        nodoSiguiente = nodoActual->siguiente;  
        free(nodoActual);  
        nodoActual = nodoSiguiente;  
    } while (nodoActual != lista->head);  
    lista->head = NULL;  
    pf("Memoria liberada\n");  
}  



int insertarC(struct listaC *lista, int nuevoDato) {  
    struct nodoLC *nuevoNodo=(struct nodoLC *)malloc(sizeof(struct nodoLC));  
    if (nuevoNodo==NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  

    if (lista->head == NULL) {  
        nuevoNodo->siguiente = nuevoNodo;  
        lista->head = nuevoNodo;  
    } else{  
        struct nodoLC *nodoActual = lista->head;  
        while (nodoActual->siguiente != lista->head) {  
            nodoActual = nodoActual->siguiente;  
        }  
        nuevoNodo->siguiente = lista->head;  
        nodoActual->siguiente = nuevoNodo;  
        lista->head = nuevoNodo;  
    }  
    return 0;  
}  



int insertarFinalC(struct listaC *lista, int nuevoDato) {  
    struct nodoLC *nuevoNodo=(struct nodoLC *)malloc(sizeof(struct nodoLC));  
    if (nuevoNodo==NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  

    nuevoNodo->dato = nuevoDato;  
    if (lista->head == NULL) {  
        nuevoNodo->siguiente = nuevoNodo;  
        lista->head = nuevoNodo;  
    } else {  
        struct nodoLC *nodoActual = lista->head; 
        while (nodoActual->siguiente != lista->head) {  // modificacion necesaria para que las otras funciones funcionen x.x 
            nodoActual = nodoActual->siguiente;  
        }  
        nodoActual->siguiente = nuevoNodo;  
        nuevoNodo->siguiente = lista->head;  
    }  
    return 0;  
}  



int insertarCualquierPosicionC(struct listaC *lista, int nuevoDato, int posicion) {  
    if (posicion < 1) {  
        pf("Posicion no valida\n");  
        return -1;  
    }  

    struct nodoLC *nuevoNodo=(struct nodoLC *)malloc(sizeof(struct nodoLC));  
    if (nuevoNodo==NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  

    nuevoNodo->dato = nuevoDato;  
    if (posicion == 1) {  
        if (lista->head == NULL) {  
            nuevoNodo->siguiente = nuevoNodo;  
            lista->head = nuevoNodo;  
        } else {  
            struct nodoLC *nodoActual = lista->head;  
            while (nodoActual->siguiente != lista->head) {  
                nodoActual = nodoActual->siguiente;  
            }  
            nuevoNodo->siguiente = lista->head;  
            nodoActual->siguiente = nuevoNodo;  
            lista->head = nuevoNodo;  
        }  
        return 0;  
    }  

    struct nodoLC *nodoActual = lista->head;  
    struct nodoLC *nodoAnterior = NULL;  
    int indice = 1;  

    while (indice < posicion && nodoActual->siguiente != lista->head) {  
        nodoAnterior = nodoActual;  
        nodoActual = nodoActual->siguiente;  
        indice++;  
    }  

    if (indice != posicion - 1) {   
        free(nuevoNodo);
        return -1;  
    }  

    nuevoNodo->siguiente = nodoActual->siguiente;  
    nodoAnterior->siguiente = nuevoNodo;  
    return 0;  
} 



int buscarC(struct listaC *lista, int datoBuscar) {  
    if (lista->head == NULL) {  
        pf("Lista vacia\n");  
        return -1;  
    }  
    
    struct nodoLC *nodoActual = lista->head;  
    do {  
        if (nodoActual->dato == datoBuscar) {  
            pf("Dato encontrado\n");  
            return nodoActual->dato;  
        }  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != lista->head);  

    pf("Dato no encontrado\n");  
    return -1;  
}  



int borrarC(struct listaC *lista, int datoBorrar) {  
    if (lista->head == NULL) {  
        pf("Lista vacia\n");  
        return -1;  
    }  

    struct nodoLC *nodoActual = lista->head;  
    struct nodoLC *nodoAnterior = NULL;  

    do {  
        if (nodoActual->dato == datoBorrar) {
			//Si se encuentra el nodo  
            break;  
        }  
        nodoAnterior = nodoActual;  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != lista->head);  

    if (nodoActual->dato != datoBorrar) {  
        pf("No esta el elemento en la lista\n");  
        return -1;  
    }  

    if (nodoActual->siguiente == nodoActual) {  
        lista->head = NULL;  
    } else {  
        if (nodoAnterior == NULL) {  
            nodoAnterior = lista->head;  
            while(nodoAnterior->siguiente != lista->head) {  
                nodoAnterior = nodoAnterior->siguiente;  
            }  
            nodoAnterior->siguiente = nodoActual->siguiente;  
            lista->head = nodoAnterior;   
        } else {  
            nodoAnterior->siguiente = nodoActual->siguiente;  
        }  
    }  

    free(nodoActual);
	pf("Elemento eliminado. El indice se recorrio\n");  
    return 0;  
}  



int borrarIndiceC(struct listaC *lista, int posicion) {  
    if (lista->head == NULL || posicion < 1) {  
        pf("Posicion no valida o lista vacia\n");  
        return -1;  
    }  

    struct nodoLC *nodoActual = lista->head;  
    struct nodoLC *nodoAnterior = NULL;  
    int indice = 1;  

    if (posicion == 1) {  
        // Borrar el nodo head  
        if (lista->head->siguiente == lista->head) { // Si solo hay un nodo  
            free(lista->head);  
            lista->head = NULL;
			pf("Elemento eliminado. El indice se recorrio\n");  
            return 0;  
        } else {  
            nodoAnterior= lista->head;  
            while (nodoAnterior->siguiente != lista->head) {  
                nodoAnterior = nodoAnterior->siguiente;  
            }  
            nodoAnterior->siguiente = lista->head->siguiente;
			free(lista->head);  
    		lista->head = nodoAnterior->siguiente;
			pf("Elemento eliminado. El indice se recorrio\n");    
			return 0;
			}   
        }    

    while (indice < posicion && nodoActual->siguiente != lista->head) {  
        nodoAnterior= nodoActual;  
        nodoActual= nodoActual->siguiente;  
        indice++;  
    }  

    if (indice < posicion) { // Si se llega al final y no se encontra la posicion  
        pf("Posicion fuera de la lista\n");  
        return -1;  
    }  
	// Aqui se borra el nodoActual  
    nodoAnterior->siguiente = nodoActual->siguiente;  
    free(nodoActual);
	pf("Elemento eliminado. El indice se recorrio\n");  
    return 0;  
}  



int size(struct listaC *lista) {  
    if (lista->head == NULL) {  
        return 0; // La lista es vacia  
    }  

    int tamano = 0;  
    struct nodoLC *nodoActual= lista->head;  

    do {  
        tamano++;  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != lista->head);  

    return tamano; // Regresa el tamaño de la lista  
}  

