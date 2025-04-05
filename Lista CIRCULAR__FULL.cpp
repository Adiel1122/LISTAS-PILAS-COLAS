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
int insertarFinal(struct lista *, int);  
int insertarCualquierPosicion(struct lista *, int, int);  
int buscar(struct lista *, int);  
int borrar(struct lista *, int);  
int borrarIndice(struct lista *, int);  
int size(struct lista *);  


// operaciones

void crearLista(struct lista *nuevaLista) {  
    nuevaLista->head = NULL;  
    pf("Lista creada\n");  
}  



void verLista(struct lista *verLista) {  
    if (verLista->head == NULL) {  
        pf("Lista vacia\n");  
        return;  
    }  

    struct nodo *nodoActual = verLista->head;  
    pf("Datos de la lista:\n");  
    do {  
        pf("%d\n", nodoActual->dato);  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != verLista->head);  
    pf("\n");  
}  



void liberarLista(struct lista *liberarLista) {  
    if (liberarLista->head == NULL) {  
        pf("La lista esta vacia\n");  
        return;  
    }  

    struct nodo *nodoActual = liberarLista->head;  
    struct nodo *nodoSiguiente;  
    do {  
        nodoSiguiente = nodoActual->siguiente;  
        free(nodoActual);  
        nodoActual = nodoSiguiente;  
    } while (nodoActual != liberarLista->head);  
    liberarLista->head = NULL;  
    pf("Memoria liberada\n");  
}  



int insertar(struct lista *insertarLista, int nuevoDato) {  
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  

    if (insertarLista->head == NULL) {  
        nuevoNodo->siguiente = nuevoNodo;  
        insertarLista->head = nuevoNodo;  
    } else {  
        struct nodo *ultimoNodo = insertarLista->head;  
        while (ultimoNodo->siguiente != insertarLista->head) {  
            ultimoNodo = ultimoNodo->siguiente;  
        }  
        nuevoNodo->siguiente = insertarLista->head;  
        ultimoNodo->siguiente = nuevoNodo;  
        insertarLista->head = nuevoNodo;  
    }  
    return 0;  
}  



int insertarFinal(struct lista *insertarLista, int nuevoDato) {  
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  

    if (insertarLista->head == NULL) {  
        nuevoNodo->siguiente = nuevoNodo;  
        insertarLista->head = nuevoNodo;  
    } else {  
        struct nodo *ultimoNodo = insertarLista->head; 
        while (ultimoNodo->siguiente != insertarLista->head) {  // modificacion necesaria para que las otras funciones funcionen x.x 
            ultimoNodo = ultimoNodo->siguiente;  
        }  
        ultimoNodo->siguiente = nuevoNodo;  
        nuevoNodo->siguiente = insertarLista->head;  
    }  
    return 0;  
}  



int insertarCualquierPosicion(struct lista *insertarPosicionLista, int nuevoDato, int posicion) {  
    if (posicion < 1) {  
        pf("Posicion no valida\n");  
        return -1;  
    }  

    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL) {  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  

    if (posicion == 1) {  
        if (insertarPosicionLista->head == NULL) {  
            nuevoNodo->siguiente = nuevoNodo;  
            insertarPosicionLista->head = nuevoNodo;  
        } else {  
            struct nodo *ultimoNodo = insertarPosicionLista->head;  
            while (ultimoNodo->siguiente != insertarPosicionLista->head) {  
                ultimoNodo = ultimoNodo->siguiente;  
            }  
            nuevoNodo->siguiente = insertarPosicionLista->head;  
            ultimoNodo->siguiente = nuevoNodo;  
            insertarPosicionLista->head = nuevoNodo;  
        }  
        return 0;  
    }  

    struct nodo *nodoActual = insertarPosicionLista->head;  
    struct nodo *nodoPrevio = NULL;  
    int indice = 1;  

    while (indice < posicion && nodoActual->siguiente != insertarPosicionLista->head) {  
        nodoPrevio = nodoActual;  
        nodoActual = nodoActual->siguiente;  
        indice++;  
    }  

    if (indice != posicion - 1) {   
        free(nuevoNodo);
        return -1;  
    }  

    nuevoNodo->siguiente = nodoActual->siguiente;  
    nodoPrevio->siguiente = nuevoNodo;  
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

    struct nodo *nodoActual= borrarLista->head;  
    struct nodo *nodoPrevio= NULL;  

    do {  
        if (nodoActual->dato == datoBorrar) {
			//Si se encuentra el nodo  
            break;  
        }  
        nodoPrevio= nodoActual;  
        nodoActual= nodoActual->siguiente;  
    } while (nodoActual != borrarLista->head);  

    if (nodoActual->dato != datoBorrar) {  
        pf("No esta el elemento en la lista\n");  
        return -1;  
    }  

    if (nodoActual->siguiente == nodoActual) {  
        borrarLista->head= NULL;  
    } else {  
        if (nodoPrevio == NULL) {  
            nodoPrevio = borrarLista->head;  
            while(nodoPrevio->siguiente != borrarLista->head) {  
                nodoPrevio = nodoPrevio->siguiente;  
            }  
            nodoPrevio->siguiente= nodoActual->siguiente;  
            borrarLista->head= nodoPrevio;   
        } else {  
            nodoPrevio->siguiente= nodoActual->siguiente;  
        }  
    }  

    free(nodoActual);
	pf("Elemento eliminado. El indice se recorrio\n");  
    return 0;  
}  



int borrarIndice(struct lista *borrarIndiceLista, int indice) {  
    if (borrarIndiceLista->head == NULL || indice < 1) {  
        pf("Indice no valido o lista vacia\n");  
        return -1;  
    }  

    struct nodo *nodoActual = borrarIndiceLista->head;  
    struct nodo *nodoPrevio = NULL;  
    int contador = 1;  

    if (indice == 1) {  
        // Borrar el nodo head  
        if (borrarIndiceLista->head->siguiente == borrarIndiceLista->head) { // Si solo hay un nodo  
            free(borrarIndiceLista->head);  
            borrarIndiceLista->head = NULL;
			pf("Elemento eliminado. El indice se recorrio\n");  
            return 0;  
        } else {  
            nodoPrevio= borrarIndiceLista->head;  
            while (nodoPrevio->siguiente != borrarIndiceLista->head) {  
                nodoPrevio= nodoPrevio->siguiente;  
            }  
            nodoPrevio->siguiente= borrarIndiceLista->head->siguiente;
			free(borrarIndiceLista->head);  
    		borrarIndiceLista->head = nodoPrevio->siguiente;
			pf("Elemento eliminado. El indice se recorrio\n");    
			return 0;
			}   
        }    

    while (contador < indice && nodoActual->siguiente != borrarIndiceLista->head) {  
        nodoPrevio= nodoActual;  
        nodoActual= nodoActual->siguiente;  
        contador++;  
    }  

    if (contador < indice) { // Si se llega al final y no se encontra el indice  
        pf("Indice fuera de la lista\n");  
        return -1;  
    }  
	// Aqui se borra el nodoActual  
    nodoPrevio->siguiente = nodoActual->siguiente;  
    free(nodoActual);
	pf("Elemento eliminado. El indice se recorrio\n");  
    return 0;  
}  



int size(struct lista *sizeLista) {  
    if (sizeLista->head == NULL) {  
        return 0; // La lista es vacia  
    }  

    int tamano = 0;  
    struct nodo *nodoActual= sizeLista->head;  

    do {  
        tamano++;  
        nodoActual = nodoActual->siguiente;  
    } while (nodoActual != sizeLista->head);  

    return tamano; // Regresa el tamaño de la lista  
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

    pf("Tamaño de la lista: %d\n", size(&miLista));

    insertarFinal(&miLista, 10);    
    insertarCualquierPosicion(&miLista, 11, 3);  
    verLista(&miLista);
	
	borrar(&miLista, 2);
    borrarIndice(&miLista, 1);
    verLista(&miLista);

	buscar(&miLista, 4);
	buscar(&miLista, 2);

    liberarLista(&miLista);  
    return 0;  
}