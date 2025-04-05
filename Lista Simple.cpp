//		LISTA SIMPLE
 
#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf


// funciones

struct nodo{
    int dato;
    struct nodo *siguiente;
};

struct lista{
    struct nodo *head;
};


void crearLista(struct lista *);
void verLista(struct lista *);
void liberarLista(struct lista *);
int insertar(struct lista *,int);
int buscar(struct lista *,int);
int borrar(struct lista *,int);


// operacionesLista

void crearLista(struct lista *nuevaLista){
    nuevaLista->head=NULL;
    pf("Lista creada\n");
}


void verLista(struct lista *verLista){
    if(verLista->head==NULL){
        pf("Lista Vacia\n");
    }else{
        struct nodo *verNodo=verLista->head;
        pf("Datos de la lista\n");
        while(verNodo != NULL){
            pf("%d\n",verNodo->dato);
            verNodo=verNodo->siguiente;
        }
    }
    pf("\n");
    
}


void liberarLista(struct lista *liberarLista) {  
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


int insertar(struct lista *insertarLista,int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        pf("No se asigno memoria\n");
        return -1;
    }
    nuevoNodo->dato=nuevoDato;
    nuevoNodo->siguiente=insertarLista->head;
    insertarLista->head=nuevoNodo;
    return 0;
}



int buscar(struct lista *buscarLista,int datoBuscar){
    if(buscarLista->head==NULL){
        pf("Lista vacia\n");
        return -1;
    }
    struct nodo *nodoAux = buscarLista->head;
    while(nodoAux!=NULL){
        if(nodoAux->dato==datoBuscar){
            pf("Dato encontrado\n");
            return nodoAux->dato;
        }
        nodoAux=nodoAux->siguiente;
    }
    pf("Dato no encontrado\n");
    return -1;
}



int borrar(struct lista *borrarLista,int datoBorrar){
    
    if(borrarLista->head==NULL){
        pf("Lista vacia\n");
        return -1;
    }
    
    struct nodo *nodoEliminar=borrarLista->head;
    struct nodo *nodoPrevio=NULL;
    
   
    while(nodoEliminar != NULL && nodoEliminar->dato != datoBorrar){
        nodoPrevio=nodoEliminar;
        nodoEliminar=nodoEliminar->siguiente;
    }
    
    if(nodoEliminar==NULL){
        pf("No esta el elemento\n");
        return -1;
    }
    
    if(nodoEliminar == borrarLista->head){
        borrarLista->head=nodoEliminar->siguiente;
    }else{
        nodoPrevio->siguiente=nodoEliminar->siguiente;
    }
    free(nodoEliminar);
    return 0;
}


// main

int main() {  
    struct lista miLista;  
    crearLista(&miLista);
  
    insertar(&miLista, 8);  
    insertar(&miLista, 3);  
    insertar(&miLista, 7);  
    insertar(&miLista, 10);  
    insertar(&miLista, 9);  
    verLista(&miLista);
  
    buscar(&miLista, 8);  
    buscar(&miLista, 15);
  
    borrar(&miLista, 8);  
    borrar(&miLista, 15);  
    borrar(&miLista, 7);
  
    verLista(&miLista);  

    // Liberar memoria 
    liberarLista(&miLista);  
    return 0;  
}

