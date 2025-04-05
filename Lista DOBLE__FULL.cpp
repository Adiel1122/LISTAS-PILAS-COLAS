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
int borrar(struct lista *, int);
struct nodo * buscarNodo(struct lista *,int);
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
    }else{   	
        struct nodo *verNodo = verLista->head;
		    
        pf("Datos de la lista:\n");
        while(verNodo != NULL){
            pf("%d\n",verNodo->dato);
            verNodo = verNodo->siguiente;
        }   
    }
    pf("\n");
}



void verListaPosiciones(struct lista *verPosicionLista){
    if(verPosicionLista->head == NULL){
        pf("Lista vacia\n");
    }else{   	
        struct nodo *verNodo = verPosicionLista->head;
		int indice = 0;
		
        pf("Datos de la lista \n");
        while(verNodo != NULL){
            pf("Posicion:%d Dato:%d\n", indice, verNodo->dato);
            verNodo = verNodo->siguiente;
            indice++;
        }
    }
    pf("\n");
}

struct nodo *buscarNodo(struct lista *buscarLista, int datoBuscar){
    if(buscarLista->head==NULL){
        pf("La lista esta vacia\n");
        return NULL;
    }
    struct nodo *nodoAux = buscarLista->head;
    while(nodoAux != NULL){
        if(nodoAux->dato == datoBuscar){
            pf("Dato Encontrado\n");
            return nodoAux;
        }
        nodoAux=nodoAux->siguiente;
    }
    pf("Dato no encontrado\n");
    return NULL;
}



void liberarLista(struct lista *liberarLista){  
    struct nodo *nodoActual = liberarLista->head;  
    struct nodo *nodoSiguiente;  

    while (nodoActual != NULL){  
        nodoSiguiente = nodoActual->siguiente; 
        free(nodoActual);                     
        nodoActual = nodoSiguiente;               
    }  
    liberarLista->head = NULL;            
    liberarLista->size = 0;             
    pf("Memoria liberada\n");  
}



int insertar(struct lista *insertarLista, int nuevoDato){
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }
    // Si si se creo el nodo 
    nuevoNodo->dato = nuevoDato;
    // Checar si es el primer elemento
    nuevoNodo->siguiente = insertarLista->head;
    if(insertarLista->head != NULL){
        insertarLista->head->anterior = nuevoNodo; // El nuevo nodo NO es el primer elemento
    }else{
    	insertarLista->tail = nuevoNodo; // El nuevo nodo SI es el primer elemento entonces se actualiza TAIL
	}
	
    insertarLista->head = nuevoNodo;
    nuevoNodo->anterior = NULL;
    insertarLista->size++;
    return 0;
}



int insertarCualquierPosicion(struct lista *insertarCualquierPosicion, int nuevoDato, int posicion){  
    if(posicion < 0 || posicion > insertarCualquierPosicion->size){  
        pf("Posicion no valida\n"); // Checa que la posicion que dio el usuario sea valida  
        return -1;   
    }  
    
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));  
    if(nuevoNodo == NULL){  
        pf("No se asigno memoria\n");  
        return -1;  
    }
	  
    nuevoNodo->dato = nuevoDato;  
    if(posicion == 0){  
        // Insertar AL PRINCIPIO  
        nuevoNodo->siguiente = insertarCualquierPosicion->head;  
        nuevoNodo->anterior = NULL;  
        
        if(insertarCualquierPosicion->head != NULL){  
        	insertarCualquierPosicion->head->anterior = nuevoNodo; // Si la lista NO ESTABA VACIA, actualizamos la variable anterior del nodo al que apunta HEAD  
        }else{  
            // Si la lista SI ESTABA VACIA, el nuevo nodo tambien sera el TAIL 
            insertarCualquierPosicion->tail = nuevoNodo;  
        }
		  
        insertarCualquierPosicion->head = nuevoNodo;
		  
    }else if(posicion == insertarCualquierPosicion->size){  
        // Si se debe insertar AL FINAL, llamamos a insertarFinal jeje  
        return insertarFinal(insertarCualquierPosicion, nuevoDato);
		  
    }else{  
        // Insertar EN MEDIO de dos nodos  
        struct nodo *nodoActual = insertarCualquierPosicion->head;  
        for(int i = 0; i < posicion; i++){  
            nodoActual = nodoActual->siguiente; // Se va moviendo de nodo en nodo hasta que llegue a la posicion que dijo el usuario
				if (nodoActual == NULL) {  
            		pf("Posicion no valida al intentar insertar en medio\n");  
            	return -1; // Maneja el caso donde el indice es incorrecto  
        }  
    }           

        nuevoNodo->siguiente = nodoActual; // El nuevo nodo apunta al nodo actual  
        nuevoNodo->anterior = nodoActual->anterior; // El nuevo nodo apunta al nodo anterior del nodo actual  
        
        if(nodoActual->anterior != NULL){ // Si el nodo actual en su variable anterior NO apunta a NULL
            nodoActual->anterior->siguiente = nuevoNodo; // Conecta el nodo anterior en su variable siguiente con el nuevo nodo  
        } else {  
        // Si nodoActual->anterior es NULL, entonces el nuevo nodo es el nuevo head  
        insertarCualquierPosicion->head = nuevoNodo;   
    }  
        nodoActual->anterior = nuevoNodo; // Ahora el nodo actual en su variable anterior apunta al nuevo nodo  
    }  

    insertarCualquierPosicion->size++; // Incrementa el tama�o porque se inserta un dato  
    return 0; 
}  



int insertarFinal(struct lista *insertarFinalLista, int nuevoDato){  
    struct nodo *nuevoNodo=(struct nodo *)malloc(sizeof(struct nodo));  
    if (nuevoNodo == NULL){  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  
    nuevoNodo->siguiente = NULL;  // Como este nodo sera el �ltimo, su variable siguiente debe apuntar a NULL  

    if (insertarFinalLista->head == NULL){  
        // Si la lista esta vacia, el nuevo nodo es ahora el HEAD y el TAIL  
        insertarFinalLista->head = nuevoNodo;  
        nuevoNodo->anterior = NULL; // Lo de arriba, No hay nodo anterior  
        insertarFinalLista->tail = nuevoNodo; // El nuevo nodo es tambien el tail  
    }else{  
        // Conecta el nuevo nodo al final de la lista  
        insertarFinalLista->tail->siguiente = nuevoNodo;   
        nuevoNodo->anterior = insertarFinalLista->tail; // El nodo anterior del nuevo nodo es el TAIL actual  
        insertarFinalLista->tail = nuevoNodo; // Actualiza el TAIL al nuevo nodo  
    }  

    insertarFinalLista->size++; // Incrementa el tamaño de la lista porque se inserta un dato 
    return 0; 
}  



int buscar(struct lista *buscarLista, int datoBuscar){
    if(buscarLista->head == NULL){
        pf("Lista vacia\n");
        return -1;
    }
    
    struct nodo *nodoAux = buscarLista->head;
    while(nodoAux != NULL){ // Mientras el nodo no llegue al final de la lista 
        if(nodoAux->dato == datoBuscar){ // Si encuentra el dato
            pf("Dato Encontrado\n");
            return nodoAux->dato;
        }
        nodoAux=nodoAux->siguiente; // Se va moviendo al siguiente nodo
    }
    pf("Dato no encontrado\n"); // Si ya llego al NULL
    return -1;
}



int borrar(struct lista *borrarLista, int datoBorrar){  
    if(borrarLista->head == NULL){  
        pf("Lista vacia\n");  
        return -1;
    }  
    
    struct nodo *nodoEliminar = borrarLista->head; // Inicializa el nodo a eliminar desde el HEAD de la lista      
    // Busca el elemento que se desea borrar en la lista  
    while (nodoEliminar != NULL && nodoEliminar->dato != datoBorrar){  
        nodoEliminar = nodoEliminar->siguiente; // Mueve al siguiente nodo en la lista  
    }  
    
    // Si alcanza el final de la lista sin encontrar el dato  
    if(nodoEliminar == NULL){  
        pf("Dato no encontrado\n");  
        return -1; 
    }  
    
    // Caso 1: El nodo que se desea eliminar es el UNICO NODO en la lista 
    if(nodoEliminar->siguiente == NULL && nodoEliminar->anterior == NULL){  
        // Actualiza el HEAD de la lista a NULL, ya que la lista quedaria vacia  
        borrarLista->head = NULL;  
    }   
    // Caso 2: El nodo que se quiere eliminar es el ULTIMO NODO en la lista  
    else if (nodoEliminar->siguiente == NULL){  
        nodoEliminar->anterior->siguiente = NULL; // Cambias a donde apunta el nodo anterior en su variable siguiente (apuntaria a NULL)   
    }   
    // Caso 3: El nodo que se quiere eliminar es el PRIMER NODO en la lista  
    else if (nodoEliminar == borrarLista->head) {  
        borrarLista->head = nodoEliminar->siguiente; // Actualiza el HEAD de la lista al siguiente nodo  
        borrarLista->head->anterior = NULL; // Haces que la variable anterior del nuevo HEAD apunte a NULL, ya que es el primer nodo  
    }   
    // Caso 4: El nodo a eliminar esta EN MEDIO de la lista  
    else {  
        // Conecta al nodo anterior y el nodo que le sigue para eliminar el nodo actual de la lista  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente; // Conecta el nodo anterior con el siguente de nodoEliminar  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior; // Conecta el nodo siguiente con el anterior de nodoEliminar  
    }  
    
    // Actualiza el tamaño de la lista despues de eliminar el nodo  
    borrarLista->size--;   
    free(nodoEliminar); // El todopoderoso free para matar al nodito  
    return 0;  
}  



int borrarIndice(struct lista *borrarIndiceLista, int indiceBorrar) {  
    if (borrarIndiceLista->head == NULL) {  
        pf("Lista vacia\n");  
        return -1;  
    }  
    
    // Checa si el indice que metio el usuario es valido  
    if (indiceBorrar > borrarIndiceLista->size || indiceBorrar < 0) {  
        pf("Indice no valido\n");  
        return -1;  
    }  
    
    struct nodo *nodoEliminar = borrarIndiceLista->head; // Inicializa el nodo a eliminar desde el HEAD de la lista  
    int indiceAux = 0; // Inicializa en cero pq estamos empezando desde el primer nodo de la lista, que tiene un indice de 0 

    // Recorre la lista hasta llegar al indice que metio el usuario  
    while (indiceAux != indiceBorrar) {  
        nodoEliminar = nodoEliminar->siguiente; // Mueve al siguiente nodo en la lista  
        indiceAux++; // Incrementa el indice auxiliar  
    }  
    
    /* Aqui ya nodoEliminar no deberia ser NULL porque el indice es valido  
	Se checa para asegurar que no lleguaremos a un nodo NULL */ 
    
    // Caso 1: El nodo a eliminar es el UNICO NODO en la lista  
    if (nodoEliminar->siguiente == NULL && nodoEliminar->anterior == NULL) {  
        // Actualiza el HEAD de la lista a NULL, ya que la lista quedaria vacia  
        borrarIndiceLista->head = NULL;  
    }   
    // Caso 2: El nodo a eliminar es el ULTIMO NODO en la lista  
    else if (nodoEliminar->siguiente == NULL) {  
        nodoEliminar->anterior->siguiente = NULL; // Cambias a donde apunta el nodo anterior en su variable siguiente (apuntaria a NULL)    
    }   
    // Caso 3: El nodo a eliminar es el PRIMER NODO en la lista  
    else if (nodoEliminar == borrarIndiceLista->head) {  
        borrarIndiceLista->head = nodoEliminar->siguiente; // Actualiza el head de la lista al siguiente nodo.  
        borrarIndiceLista->head->anterior = NULL; // Haces que la variable anterior del nuevo HEAD apunte NULL  
    }   
    // Caso 4: El nodo a eliminar esta EN MEDIO de la lista  
    else {  
        // Conecta al nodo anterior y el nodo que le sigue para eliminar el nodo actual de la lista  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente; // Conecta el nodo anterior con el siguente de nodoEliminar  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior; // Conecta el nodo siguiente con el anterior de nodoEliminar  
    }  
    
    // Actualiza el tama�o de la lista despues de eliminar el nodo  
    borrarIndiceLista->size--;   
    free(nodoEliminar); // De nuevo dejamos a free chambear  
    
    return 0;  
}  


int sizeLista(struct lista *sizeLista){
    return sizeLista->size;
}



// main

int main() {  
    struct lista miLista;  
    crearLista(&miLista);  

    insertar(&miLista, 1);  
    insertar(&miLista, 2);  
    insertarFinal(&miLista, 3);  
    insertarCualquierPosicion(&miLista, 4, 1); // Inserta el 4 en la posicion 1  

    // Ver la lista  
    verLista(&miLista);  
    verListaPosiciones(&miLista);  

    // Buscar elementos  
    buscar(&miLista, 2);  
    buscar(&miLista, 5);  

    // Borrar elementos  
    borrar(&miLista, 1); // Borra el nodo que contiene el dato 1  
    verLista(&miLista); 

    // Borrando por indice  
    borrarIndice(&miLista, 1); // Borra el nodo en la posicion 1  
    verLista(&miLista);  

    // Mostrar el tamaño de la lista  
    int tamanio = sizeLista(&miLista);  
    pf("El tamaño de la lista es %d\n", tamanio);  

    // Liberar la memoria de la lista  
    liberarLista(&miLista);  
    return 0;  
} 
