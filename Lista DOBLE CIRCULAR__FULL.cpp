#include<stdio.h>
#include<stdlib.h> 
#define pf printf
#define sf scanf


// funciones

struct nodo{ 
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
}; 
struct lista{
    struct nodo *head;
    struct nodo *tail;
    int size;
};

void crearLista(struct lista *);
void verLista(struct lista *);
void verListaPosiciones(struct lista *);
void liberarLista(struct lista *);
int insertar(struct lista *,int);
int insertarCualquierPosicion(struct lista *, int, int);
int insertarFinal(struct lista *, int);
int buscar(struct lista *,int);
struct nodo * buscarNodo(struct lista *,int);
int borrar(struct lista *, int);
int borrarIndice(struct lista *,int);
int sizeLista(struct lista *);


// operaciones

void crearLista(struct lista *nuevaLista){
    nuevaLista->head = NULL;
    nuevaLista->tail = NULL;
    nuevaLista->size = 0;
    pf("Lista creada\n");
}



void verLista(struct lista *verLista){
    if(verLista->head == NULL){
        pf("Lista vacia\n");
    } else{   	
        struct nodo *verNodo = verLista->head;
        pf("Datos de la lista:\n");
        do {
            pf("%d\n", verNodo->dato);
            verNodo = verNodo->siguiente;
        } while(verNodo != verLista->head);
    }
}



void verListaPosiciones(struct lista *verPosicionLista){
    if(verPosicionLista->head == NULL){
        pf("Lista vacia\n");
    } else{
        struct nodo *verNodo = verPosicionLista->head;
        int indice = 0;
        pf("Datos de la lista:\n");
        do {
            pf("Posicion:%d Dato:%d\n", indice, verNodo->dato);
            verNodo = verNodo->siguiente;
            indice++;
        } while(verNodo != verPosicionLista->head);
    }
    pf("\n");
}



void liberarLista(struct lista *liberarLista) {   
    if(liberarLista->head == NULL) {   
        pf("Lista vacia\n");   
        return;  
    }   
  
    struct nodo *nodoActual = liberarLista->head;   
    struct nodo *nodoLiberar;  

    do {  
        nodoLiberar = nodoActual;  // Guarda el nodo actual que se va a liberar  
        nodoActual = nodoActual->siguiente;  // Apunta al siguiente nodo  
        free(nodoLiberar);  // Libera el nodo que se acaba de guardar  
    } while(nodoActual != liberarLista->head); // Continúa hasta volver al nodo inicial 

    liberarLista->head = NULL;  
    liberarLista->tail = NULL;   
    liberarLista->size = 0;
    pf("Memoria liberada\n");   
}  



int insertar(struct lista *insertarLista, int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }

    nuevoNodo->dato = nuevoDato;
    
    if(insertarLista->head == NULL){
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        insertarLista->head = nuevoNodo;
        insertarLista->tail = nuevoNodo;
    } else {
        nuevoNodo->siguiente = insertarLista->head;
        nuevoNodo->anterior = insertarLista->tail;
        
        insertarLista->head->anterior = nuevoNodo;
        insertarLista->tail->siguiente = nuevoNodo;
        
        insertarLista->head = nuevoNodo;
    }
    insertarLista->size++;
    return 0;
}



int insertarFinal(struct lista *insertarFinalLista, int nuevoDato){  
    struct nodo *nuevoNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }

    nuevoNodo->dato = nuevoDato;  
    
    if(insertarFinalLista->head == NULL){  
        nuevoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = nuevoNodo;
        insertarFinalLista->head = nuevoNodo;  
        insertarFinalLista->tail = nuevoNodo;  
    } else{
        nuevoNodo->siguiente = insertarFinalLista->head;  
        nuevoNodo->anterior = insertarFinalLista->tail;  
        
        insertarFinalLista->tail->siguiente = nuevoNodo;  
        insertarFinalLista->head->anterior = nuevoNodo;  
        
        insertarFinalLista->tail = nuevoNodo;  
    }  
    insertarFinalLista->size++;  
    return 0;  
}  



int insertarCualquierPosicion(struct lista *insertarCualquierPosicion, int nuevoDato, int posicion){
    if(posicion < 0 || posicion > insertarCualquierPosicion->size){
        pf("Posicion no valida\n");
     return -1;
    }
    
    if(posicion == 0) return insertar(insertarCualquierPosicion, nuevoDato);
    if(posicion == insertarCualquierPosicion->size) return insertarFinal(insertarCualquierPosicion, nuevoDato);
    
    struct nodo *nuevoNodo=(struct nodo*)malloc(sizeof(struct nodo));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }  
    
    nuevoNodo->dato = nuevoDato;  
    struct nodo *nodoActual = insertarCualquierPosicion->head;
    for(int i = 0; i < posicion; i++) nodoActual = nodoActual->siguiente;
    
    nuevoNodo->siguiente = nodoActual;
    nuevoNodo->anterior = nodoActual->anterior;
    
    nodoActual->anterior->siguiente = nuevoNodo;
    nodoActual->anterior = nuevoNodo;
    
    insertarCualquierPosicion->size++;
    return 0;
}  



struct nodo * buscarNodo(struct lista *buscarLista, int datoBuscar){
    if(buscarLista->head == NULL) return NULL;
    
    struct nodo *nodoActual = buscarLista->head;
    do {
        if(nodoActual->dato == datoBuscar) return nodoActual;
        nodoActual = nodoActual->siguiente;
    } while(nodoActual != buscarLista->head);
    
    return NULL;
}

int buscar(struct lista *buscarLista, int datoBuscar){
    struct nodo *nodoAux = buscarNodo(buscarLista, datoBuscar);
    return (nodoAux != NULL) ? nodoAux->dato : -1; //Regresa 0 si se encontro el dato, si no lo encontro regresa -1
}



int borrar(struct lista *borrarLista, int datoBorrar){  
    if(borrarLista->head == NULL){
        pf("Lista vacia\n");
        return -1;
    }  
    
    struct nodo *nodoEliminar = buscarNodo(borrarLista, datoBorrar);  
    if(nodoEliminar == NULL){
        pf("Dato no encontrado\n");
        return -1;
    }  
    
    if(borrarLista->size == 1){  
        borrarLista->head = NULL;  
        borrarLista->tail = NULL;  
    } else {  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior;  
        
        if(nodoEliminar == borrarLista->head) borrarLista->head = nodoEliminar->siguiente;  
        if(nodoEliminar == borrarLista->tail) borrarLista->tail = nodoEliminar->anterior;  
    }  
    
    free(nodoEliminar);  
    borrarLista->size--;  
    return 0;  
}



int borrarIndice(struct lista *borrarIndiceLista, int indiceBorrar){  
    if(indiceBorrar < 0 || indiceBorrar >= borrarIndiceLista->size){
        pf("Lista vacia\n");
        return -1;
    }  
    
    struct nodo *nodoEliminar = borrarIndiceLista->head;  
    for(int i = 0; i < indiceBorrar; i++) nodoEliminar = nodoEliminar->siguiente;  
    
    if(borrarIndiceLista->size == 1){  
        borrarIndiceLista->head = NULL;  
        borrarIndiceLista->tail = NULL;  
    } else {  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente;  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior;  
        
        if(nodoEliminar == borrarIndiceLista->head) borrarIndiceLista->head = nodoEliminar->siguiente;  
        if(nodoEliminar == borrarIndiceLista->tail) borrarIndiceLista->tail = nodoEliminar->anterior;  
    }  
    
    free(nodoEliminar);  
    borrarIndiceLista->size--;  
    return 0;  
}



int sizeLista(struct lista *sizeLista){  
    return sizeLista->size;  
}



// main EJEMPLO

int main(){
    struct lista miLista;
    crearLista(&miLista);

    pf("\n-----Insertar elementos-----\n\n");
    insertar(&miLista, 1);
    insertar(&miLista, 2);
    insertarFinal(&miLista, 3);
    insertarCualquierPosicion(&miLista, 4, 1);
    verLista(&miLista);
    verListaPosiciones(&miLista);

    pf("\n-----Buscar elementos----\n\n");
    pf("Buscando el 2... %s\n", buscar(&miLista, 2) != -1 ? "Dato encontrado" : "Dato No encontrado");
    pf("Buscando el 5... %s\n", buscar(&miLista, 5) != -1 ? "Dato encontrado" : "Dato No encontrado");

    pf("\n-----Buscar el primer nodo----\n\n");
    struct nodo *nodoBuscado = buscarNodo(&miLista, 1);
    if(nodoBuscado != NULL){
        pf("Nodo encontrado: %d\n", nodoBuscado->dato);
        pf("Nodo: Anterior(%d) - Actual(%d) - Siguiente(%d)\n", 
           nodoBuscado->anterior->dato, 
           nodoBuscado->dato, 
           nodoBuscado->siguiente->dato);
    }

    pf("\n-----Borrar por elementos----\n\n");
    borrar(&miLista, 2);
    verLista(&miLista);
    pf("\n-----Borrar por indice----\n\n");
    borrarIndice(&miLista, 1);
    verLista(&miLista);

    pf("\nTamaño de la lista: %d\n", sizeLista(&miLista));

    // Liberar memoria
    liberarLista(&miLista);
    return 0;
}