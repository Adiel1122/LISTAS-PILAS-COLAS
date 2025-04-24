#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesLista.c"


void crearLista(struct lista *lista){
    lista->head=NULL;
   pf("Lista creada\n");
}


void verLista(struct lista *lista){
   if(lista->head==NULL){
       pf("Lista Vacia\n");
   } else{
       struct nodoL *nodoActual = lista->head;
       pf("Datos de la lista\n");
       while(nodoActual != NULL){
           pf("%d\n",nodoActual->dato);
           nodoActual = nodoActual->siguiente;
       }
   }
   pf("\n");
}


void liberarLista(struct lista *lista) {
   struct nodoL *nodoActual = lista->head;
   struct nodoL *nodoSiguiente;

   while(nodoActual != NULL) {
       nodoSiguiente = nodoActual->siguiente;
       free(nodoActual);
       nodoActual = nodoSiguiente;
   }
   lista->head = NULL;
   pf("Memoria liberada\n");
}


int insertar(struct lista *lista,int nuevoDato){
   struct nodoL *nuevoNodo=(struct nodoL *)malloc(sizeof(struct nodoL));
   if(nuevoNodo==NULL){
       pf("No se asigno memoria\n");
       return -1;
   }
   nuevoNodo->dato = nuevoDato;
   nuevoNodo->siguiente = lista->head;
   lista->head=nuevoNodo;
   return 0;
}


int buscar(struct lista *lista,int datoBuscar){
   if(lista->head==NULL){
       pf("Lista vacia\n");
       return -1;
   }
   struct nodoL *nodoBuscar = lista->head;
   while(nodoBuscar != NULL){
       if(nodoBuscar->dato == datoBuscar){
           pf("Dato encontrado\n");
           return nodoBuscar->dato;
       }
       nodoBuscar = nodoBuscar->siguiente;
   }
   pf("Dato no encontrado\n");
   return -1;
}


int borrar(struct lista *lista,int datoBorrar){
   if(lista->head==NULL){
       pf("Lista vacia\n");
       return -1;
   }
  
   struct nodoL *nodoEliminar = lista->head;
   struct nodoL *nodoAnterior = NULL;
  
   while(nodoEliminar != NULL && nodoEliminar->dato != datoBorrar){
       nodoAnterior = nodoEliminar;
       nodoEliminar = nodoEliminar->siguiente;
   }
  
   if(nodoEliminar==NULL){
       pf("No esta el elemento\n");
       return -1;
   }
  
   if(nodoEliminar == lista->head){
       lista->head = nodoEliminar->siguiente;
   } else{
       nodoAnterior->siguiente = nodoEliminar->siguiente;
   }
   free(nodoEliminar);
   pf("Elemento eliminado. El indice se recorrio\n");
   return 0;
}


int size(struct lista *lista) {
   int tamano = 0;
   struct nodoL *nodoActual = lista->head;
  
   while(nodoActual != NULL) {
       tamano++;
       nodoActual = nodoActual->siguiente;
   }
   return tamano;
}


int insertarFinal(struct lista *lista, int nuevoDato) {
   struct nodoL *nuevoNodo=(struct nodoL *)malloc(sizeof(struct nodoL));
   if(nuevoNodo==NULL) {
       pf("No se asigno memoria\n");
       return -1;
   }
  
   nuevoNodo->dato = nuevoDato;
   nuevoNodo->siguiente = NULL;
  
   if(lista->head==NULL) {
       lista->head = nuevoNodo;
   } else{
       struct nodoL *nodoActual = lista->head;
       while(nodoActual->siguiente != NULL) {
           nodoActual = nodoActual->siguiente;
       }
       nodoActual->siguiente = nuevoNodo;
   }  
   return 0;
}


int insertarCualquierPosicion(struct lista *lista, int nuevoDato, int posicion) {
    int tamano = size(lista);
    
    if(posicion < 1 || posicion > tamano + 1) {
        pf("Posicion inválida. Rango permitido: 1 - %d\n", tamano + 1);
        return -1;
    }

    if(posicion == 1) return insertar(lista, nuevoDato);
    if(posicion == tamano + 1) return insertarFinal(lista, nuevoDato);

    struct nodoL *nuevoNodo=(struct nodoL *)malloc(sizeof(struct nodoL));
    if(nuevoNodo == NULL) {
        pf("No se asigno memoria\n");
        return -1;
    }

    nuevoNodo->dato = nuevoDato;
    struct nodoL *nodoActual = lista->head;

    for(int i = 1; i < posicion - 1; i++) {  
        nodoActual = nodoActual->siguiente;
    }

    nuevoNodo->siguiente = nodoActual->siguiente;
    nodoActual->siguiente = nuevoNodo;

    return 0;
}


int borrarIndice(struct lista *lista, int posicion) {
    if(lista->head == NULL) {
        pf("Lista vacia\n");
        return -1;
    }

    int tamano = size(lista);
    
    if(posicion < 1 || posicion > tamano) {
        pf("Posición invalida. Rango permitido: 1 - %d\n", tamano);
        return -1;
    }

    struct nodoL *nodoEliminar;

    if(posicion == 1) {
        nodoEliminar = lista->head;
        lista->head = lista->head->siguiente;
    } else{
        struct nodoL *nodoActual = lista->head;
        for(int i = 1; i < posicion - 1; i++) {  
            nodoActual = nodoActual->siguiente;
        }
        nodoEliminar = nodoActual->siguiente;
        nodoActual->siguiente = nodoEliminar->siguiente;
    }

    free(nodoEliminar);
    pf("Elemento en posición %d eliminado\n", posicion);
    return 0;
}
