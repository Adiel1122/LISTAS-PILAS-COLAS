//	COLA CIRCULAR

/*-----------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf


// funciones

struct nodo {
    int dato; 
    struct nodo *siguiente;
};

struct cola{
    struct nodo *head;
    struct nodo *tail;
};

void crearCola(struct cola *);
void verCola(struct cola *);
int encolar(struct cola *, int);
int desencolar(struct cola *);
int front(struct cola *);


// operaciones

void crearCola(struct cola *nuevaCola){
    nuevaCola->head=NULL;
    nuevaCola->tail=NULL;
    pf("Cola creada\n");
}


void verCola(struct cola *verCola){
    struct nodo *verNodo=verCola->head;
    pf("Datos de la cola:\n");
   do{
        pf("%d\n",verNodo->dato);
        verNodo=verNodo->siguiente;
    }while(verNodo!=verCola->head);
    pf("\n");
}


int encolar(struct cola *colaEncolar,int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo==NULL){
        pf("No se asigno memoria al nodo\n");
        return -1;
    }
    
    nuevoNodo->dato=nuevoDato;
    nuevoNodo->siguiente=NULL;

    if(colaEncolar->head==NULL){
       
        colaEncolar->head=nuevoNodo;
        
    }else{
        colaEncolar->tail->siguiente=nuevoNodo;
    }
    colaEncolar->tail=nuevoNodo;
    nuevoNodo->siguiente=colaEncolar->head;
    return 0;   
}


int desencolar(struct cola *colaDesencolar){
    if(colaDesencolar->tail == NULL){
        pf("Cola vacia\n");
        return -1;
    }

    struct nodo *nodoEliminar=colaDesencolar->head;

    if(colaDesencolar->head==colaDesencolar->tail){
        pf("Cola vacia\n");
        colaDesencolar->tail=NULL;
        colaDesencolar->head=NULL;
    }else{
      colaDesencolar->head=nodoEliminar->siguiente;
        colaDesencolar->tail->siguiente=colaDesencolar->head;
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



// main

int main(){
    struct cola miCola;
    crearCola(&miCola);
    desencolar(&miCola);
    
    encolar(&miCola,10);
    encolar(&miCola,9);
    encolar(&miCola,11);
    verCola(&miCola);
    
    int dato1=front(&miCola);
    pf("El valor del head es: %d\n",dato1);
    desencolar(&miCola);
    verCola(&miCola);
    
    dato1=front(&miCola);
    pf("El valor del head es: %d\n",dato1);
    
    // Liberar memoria
    while(miCola.head!=NULL){
        desencolar(&miCola);
    }

    return 0;
}
