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
int size(struct lista *);
int insertarFinal(struct lista *, int);
int insertarCualquierPosicion(struct lista *, int, int);
int borrarIndice(struct lista *, int);


// operaciones

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


   while(nodoActual!= NULL) {
       nodoSiguiente = nodoActual->siguiente;
       free(nodoActual);
       nodoActual = nodoSiguiente;
   }
   liberarLista->head = NULL;
   pf("Memoria liberada\n");
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
   struct nodo *nodoBuscar = buscarLista->head;
   while(nodoBuscar!=NULL){
       if(nodoBuscar->dato==datoBuscar){
           pf("Dato encontrado\n");
           return nodoBuscar->dato;
       }
       nodoBuscar=nodoBuscar->siguiente;
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
   pf("Elemento eliminado. El indice se recorrio\n");
   return 0;
}


int size(struct lista *sizeLista) {
   int tamano = 0;
   struct nodo *nodoActual = sizeLista->head;
  
   while(nodoActual != NULL) {
       tamano++;
       nodoActual = nodoActual->siguiente;
   }
  
   return tamano;
}


int insertarFinal(struct lista *insertarFinalLista, int nuevoDato) {
   struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
   if(nuevoNodo == NULL) {
       pf("No se asigno memoria\n");
       return -1;
   }
  
   nuevoNodo->dato = nuevoDato;
   nuevoNodo->siguiente = NULL;
  
   if(insertarFinalLista->head == NULL) {
       insertarFinalLista->head = nuevoNodo;
   } else {
       struct nodo *nodoActual = insertarFinalLista->head;
       while(nodoActual->siguiente != NULL) {
           nodoActual = nodoActual->siguiente;
       }
       nodoActual->siguiente = nuevoNodo;
   }
  
   return 0;
}


int insertarCualquierPosicion(struct lista *insertarPosicionLista, int nuevoDato, int posicion) {
   if(posicion < 1) {
       pf("Posicion no valida\n");
       return -1;
   }
  
   if(posicion == 1) {
       return insertar(insertarPosicionLista, nuevoDato);
   }
  
   struct nodo *nuevoNodo = (struct nodo *)malloc(sizeof(struct nodo));
   if(nuevoNodo == NULL) {
       pf("No se asigno memoria\n");
       return -1;
   }
   nuevoNodo->dato = nuevoDato;
  
   struct nodo *nodoActual = insertarPosicionLista ->head;
   struct nodo *nodoAnterior = NULL;
   int indice = 1;
  
   while(nodoActual != NULL && indice < posicion) {
       nodoAnterior = nodoActual;
       nodoActual = nodoActual->siguiente;
       indice++;
   }
  
   if(indice != posicion) {
       pf("Posicion fuera de la lista\n");
       free(nuevoNodo);
       return -1;
   }
  
   nodoAnterior->siguiente = nuevoNodo;
   nuevoNodo->siguiente = nodoActual;
  
   return 0;
}


int borrarIndice(struct lista *borrarIndiceLista, int posicion) {
   if(borrarIndiceLista ->head == NULL) {
       pf("Lista vacia\n");
       return -1;
   }
  
   if(posicion < 1) {
       pf("Posicion no valida\n");
       return -1;
   }
  
   if(posicion == 1) {
       struct nodo *nodoEliminar = borrarIndiceLista ->head;
       borrarIndiceLista ->head = borrarIndiceLista ->head->siguiente;
       free(nodoEliminar);
       pf("Elemento eliminado. El indice se recorrio\n");
       return 0;
   }
  
   struct nodo *nodoActual = borrarIndiceLista ->head;
   struct nodo *nodoAnterior = NULL;
   int indice = 1;
  
   while(nodoActual != NULL && indice < posicion) {
       nodoAnterior = nodoActual;
       nodoActual = nodoActual->siguiente;
       indice++;
   }
  
   if(nodoActual == NULL) {
       pf("Posicion fuera de la lista\n");
       return -1;
   }
  
   nodoAnterior->siguiente = nodoActual->siguiente;
   free(nodoActual);
   pf("Elemento eliminado. El indice se recorrio\n");
   return 0;
}


// main

int main() {  
    struct lista miLista;  
    crearLista(&miLista);  
    
    insertar(&miLista, 3);  
    insertar(&miLista, 2);  
    insertar(&miLista, 1);  
    verLista(&miLista);  
    
    insertarFinal(&miLista, 10);  
    insertarFinal(&miLista, 20);  
    verLista(&miLista);  
    
    insertarCualquierPosicion(&miLista, 30, 1);
	insertarCualquierPosicion(&miLista, 40, 2);  
    verLista(&miLista);  
    
    buscar(&miLista, 2);  
    buscar(&miLista, 9); 
    
    pf("Tamaño de la lista: %d\n", size(&miLista));  
    
    borrar(&miLista, 40);  
    verLista(&miLista);  
    
    borrarIndice(&miLista, 1);
    verLista(&miLista); 
    borrarIndice(&miLista, 1);
    verLista(&miLista);  
    
    liberarLista(&miLista);  
    
    return 0;  
}  
