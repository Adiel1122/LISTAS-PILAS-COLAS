//	COLA DOBLE

/*-----------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf


// funciones

struct nodo {
    int dato; 
    struct nodo *siguiente;
    struct nodo *anterior;
};

struct cola{
    struct nodo *head;
    struct nodo *tail;
};

void crearCola(struct cola *);
void verCola(struct cola *);
int encolarHead(struct cola *, int);
int encolarTail(struct cola *, int);
int desencolarHead(struct cola *);
int desencolarTail(struct cola *);
int front(struct cola *);
int back(struct cola *);


// operaciones

void crearCola(struct cola *nuevaCola){
    nuevaCola->head=NULL;
    nuevaCola->tail=NULL;
    pf("Cola creada\n");
}


void verCola(struct cola *verCola){
    struct nodo *verNodo = verCola->head;
    pf("Datos en la cola\n");
    while(verNodo!=NULL){
        pf("%d\n",verNodo->dato);
        verNodo=verNodo->siguiente;
    }
    pf("\n");
}


int encolarHead(struct cola *encolarColaHead, int nuevoDato){
   
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        pf("No se asigno memoria");
        return -1;
    }

    nuevoNodo->dato=nuevoDato;
    nuevoNodo->anterior=NULL;
    
    nuevoNodo->siguiente=encolarColaHead->head;
    
    if(encolarColaHead->head==NULL){
        encolarColaHead->head=nuevoNodo;
        encolarColaHead->tail=nuevoNodo;
    }else{
        encolarColaHead->head->anterior=nuevoNodo;
        encolarColaHead->head=nuevoNodo;
    }
    return 0;
}


int encolarTail(struct cola *encolarColaTail, int nuevoDato){
    
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        pf("No se asigno memoria");
        return -1;
    }
    
    nuevoNodo->dato=nuevoDato;
    nuevoNodo->siguiente=NULL;
    
    nuevoNodo->anterior=encolarColaTail->tail;
    
    if(encolarColaTail->head==NULL){
        encolarColaTail->head=nuevoNodo;
        encolarColaTail->tail=nuevoNodo;
    }else{
        encolarColaTail->tail->siguiente=nuevoNodo;
        encolarColaTail->tail=nuevoNodo;
    }
    return 0;
}


int desencolarHead(struct cola *desencolarColaHead){
    if(desencolarColaHead->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    
    struct nodo *nodoEliminar=desencolarColaHead->head;
    
    if(desencolarColaHead->head==desencolarColaHead->tail){
        pf("Cola vacia\n");
        desencolarColaHead->head=NULL;
        desencolarColaHead->tail=NULL;
    }else{
        desencolarColaHead->head=nodoEliminar->siguiente;
        desencolarColaHead->head->anterior=NULL;
    }
    free(nodoEliminar);
    return 0;
}


int desencolarTail(struct cola *desencolarColaTail){
    if(desencolarColaTail->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    
    struct nodo *nodoEliminar=desencolarColaTail->tail;
    
    if(desencolarColaTail->head==desencolarColaTail->tail){
        pf("Cola vacia\n");
        desencolarColaTail->head=NULL;
        desencolarColaTail->tail=NULL;
    }else{
        desencolarColaTail->tail=nodoEliminar->anterior;
        desencolarColaTail->tail->siguiente=NULL;
    }
    free(nodoEliminar);
    return 0;
}


int front(struct cola *colaFront){
    if(colaFront->head==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    return colaFront->head->dato;
}


int back(struct cola *colaBack){
    if(colaBack->tail==NULL){
        pf("Cola vacia\n");
        return -1;
    }
    return colaBack->tail->dato;
}


// main

int main(){
    struct cola miCola;
    crearCola(&miCola);
    desencolarHead(&miCola);
    desencolarTail(&miCola);

    encolarHead(&miCola,1);
    encolarHead(&miCola,2);
    encolarTail(&miCola,3);
    verCola(&miCola);

    desencolarHead(&miCola);
    verCola(&miCola);

    desencolarTail(&miCola);
    verCola(&miCola);

    // Liberar memoria
    while(miCola.head!=NULL){
        desencolarHead(&miCola);
    }
    
    return 0;
}
