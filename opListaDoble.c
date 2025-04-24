#include <stdio.h>
#include <stdlib.h>
#define pf printf
#define sf scanf

#include "funcionesListaDoble.c"

void crearListaD(struct listaD *lista){
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    pf("Lista creada\n");
}



void verListaD(struct listaD *lista){
    if(lista->head == NULL){
        pf("Lista vacia\n");
    } else{   	
        struct nodoLD *nodoActual = lista->head;
		    
        pf("Datos de la lista:\n");
        while(nodoActual != NULL){
            pf("%d\n",nodoActual->dato);
            nodoActual = nodoActual->siguiente;
        }   
    }
    pf("\n");
}



void verListaPosicionesD(struct listaD *lista){
    if(lista->head == NULL){
        pf("Lista vacia\n");
    }else{   	
        struct nodoLD *nodoActual = lista->head;
		int indice = 0;
		
        pf("Datos de la lista \n");
        while(nodoActual != NULL){
            pf("Posicion:%d Dato:%d\n", indice, nodoActual->dato);
            nodoActual = nodoActual->siguiente;
            indice++;
        }
    }
    pf("\n");
}


void liberarListaD(struct listaD *lista){  
    struct nodoLD *nodoActual = lista->head;  
    struct nodoLD *nodoSiguiente;  

    while (nodoActual != NULL){  
        nodoSiguiente = nodoActual->siguiente; 
        free(nodoActual);                     
        nodoActual = nodoSiguiente;               
    }  
    lista->head = NULL;            
    lista->size = 0;             
    pf("Memoria liberada\n");  
}



int insertarD(struct listaD *lista, int nuevoDato){
    struct nodoLD *nuevoNodo=(struct nodoLD *)malloc(sizeof(struct nodoLD));
    if(nuevoNodo == NULL){
        pf("No se asigno memoria\n");
        return -1;
    }
    // Si si se creo el nodo 
    nuevoNodo->dato = nuevoDato;
    // Checar si es el primer elemento
    nuevoNodo->siguiente = lista->head;
    if(lista->head != NULL){
        lista->head->anterior = nuevoNodo; // El nuevo nodo NO es el primer elemento
    } else{
    	lista->tail = nuevoNodo; // El nuevo nodo SI es el primer elemento entonces se actualiza TAIL
	}
	
    lista->head = nuevoNodo;
    nuevoNodo->anterior = NULL;
    lista->size++;
    return 0;
}



int insertarCualquierPosicionD(struct listaD *lista, int nuevoDato, int posicion){  
    if(posicion < 0 || posicion > lista->size){  
        pf("Posicion no valida\n"); // Checa que la posicion que dio el usuario sea valida  
        return -1;   
    }  
    
    struct nodoLD *nuevoNodo=(struct nodoLD *)malloc(sizeof(struct nodoLD));  
    if(nuevoNodo == NULL){  
        pf("No se asigno memoria\n");  
        return -1;  
    }
	  
    nuevoNodo->dato = nuevoDato;  
    if(posicion == 0){  
        // Insertar AL PRINCIPIO  
        nuevoNodo->siguiente = lista->head;  
        nuevoNodo->anterior = NULL;  
        
        if(lista->head != NULL){  
        	lista->head->anterior = nuevoNodo; // Si la lista NO ESTABA VACIA, actualizamos la variable anterior del nodo al que apunta HEAD  
        }else{  
            // Si la lista SI ESTABA VACIA, el nuevo nodo tambien sera el TAIL 
            lista->tail = nuevoNodo;  
        }
		  
        lista->head = nuevoNodo;
		  
    }else if(posicion == lista->size){  
        // Si se debe insertar AL FINAL, llamamos a insertarFinal jeje  
        return insertarFinalD(lista, nuevoDato);
		  
    }else{  
        // Insertar EN MEDIO de dos nodos  
        struct nodoLD *nodoActual = lista->head;  
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
        lista->head = nuevoNodo;   
    }  
        nodoActual->anterior = nuevoNodo; // Ahora el nodo actual en su variable anterior apunta al nuevo nodo  
    }  

    lista->size++; // Incrementa el tamaño porque se inserta un dato  
    return 0; 
}  



int insertarFinalD(struct listaD *lista, int nuevoDato){  
    struct nodoLD *nuevoNodo=(struct nodoLD *)malloc(sizeof(struct nodoLD));  
    if (nuevoNodo == NULL){  
        pf("No se asigno memoria\n");  
        return -1;  
    }  
    nuevoNodo->dato = nuevoDato;  
    nuevoNodo->siguiente = NULL;  // Como este nodo sera el ultimo, su variable siguiente debe apuntar a NULL  

    if (lista->head == NULL){  
        // Si la lista esta vacia, el nuevo nodo es ahora el HEAD y el TAIL  
        lista->head = nuevoNodo;  
        nuevoNodo->anterior = NULL; // Lo de arriba, No hay nodo anterior  
        lista->tail = nuevoNodo; // El nuevo nodo es tambien el tail  
    }else{  
        // Conecta el nuevo nodo al final de la lista  
        lista->tail->siguiente = nuevoNodo;   
        nuevoNodo->anterior = lista->tail; // El nodo anterior del nuevo nodo es el TAIL actual  
        lista->tail = nuevoNodo; // Actualiza el TAIL al nuevo nodo  
    }  

    lista->size++; // Incrementa el tamaño de la lista porque se inserta un dato 
    return 0; 
}  



int buscarD(struct listaD *lista, int datoBuscar){
    if(lista->head == NULL){
        pf("Lista vacia\n");
        return -1;
    }
    
    struct nodoLD *nodoBuscar = lista->head;
    while(nodoBuscar != NULL){ // Mientras el nodo no llegue al final de la lista 
        if(nodoBuscar->dato == datoBuscar){ // Si encuentra el dato
            pf("Dato Encontrado\n");
            return nodoBuscar->dato;
        }
        nodoBuscar = nodoBuscar->siguiente; // Se va moviendo al siguiente nodo
    }
    pf("Dato no encontrado\n"); // Si ya llego al NULL
    return -1;
}



int borrarD(struct listaD *lista, int datoBorrar){  
    if(lista->head == NULL){  
        pf("Lista vacia\n");  
        return -1;
    }  
    
    struct nodoLD *nodoEliminar = lista->head; // Inicializa el nodo a eliminar desde el HEAD de la lista      
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
        lista->head = NULL;  
    }   
    // Caso 2: El nodo que se quiere eliminar es el ULTIMO NODO en la lista  
    else if (nodoEliminar->siguiente == NULL){  
        nodoEliminar->anterior->siguiente = NULL; // Cambias a donde apunta el nodo anterior en su variable siguiente (apuntaria a NULL)   
    }   
    // Caso 3: El nodo que se quiere eliminar es el PRIMER NODO en la lista  
    else if (nodoEliminar == lista->head) {  
        lista->head = nodoEliminar->siguiente; // Actualiza el HEAD de la lista al siguiente nodo  
        lista->head->anterior = NULL; // Haces que la variable anterior del nuevo HEAD apunte a NULL, ya que es el primer nodo  
    }   
    // Caso 4: El nodo a eliminar esta EN MEDIO de la lista  
    else {  
        // Conecta al nodo anterior y el nodo que le sigue para eliminar el nodo actual de la lista  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente; // Conecta el nodo anterior con el siguente de nodoEliminar  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior; // Conecta el nodo siguiente con el anterior de nodoEliminar  
    }  
    
    // Actualiza el tamaño de la lista despues de eliminar el nodo  
    lista->size--;   
    free(nodoEliminar); // El todopoderoso free para matar al nodito  
    return 0;  
}  



int borrarIndiceD(struct listaD *lista, int posicion) {  
    if (lista->head == NULL) {  
        pf("Lista vacia\n");  
        return -1;  
    }  
    
    // Checa si el indice que metio el usuario es valido  
    if (posicion > lista->size || posicion < 0) {  
        pf("Indice no valido\n");  
        return -1;  
    }  
    
    struct nodoLD *nodoEliminar = lista->head; // Inicializa el nodo a eliminar desde el HEAD de la lista  
    int indice = 0; // Inicializa en cero pq estamos empezando desde el primer nodo de la lista, que tiene un indice de 0 

    // Recorre la lista hasta llegar al indice que metio el usuario  
    while (indice != posicion) {  
        nodoEliminar = nodoEliminar->siguiente; // Mueve al siguiente nodo en la lista  
        indice++; // Incrementa el indice auxiliar  
    }  
    
    /* Aqui ya nodoEliminar no deberia ser NULL porque el indice es valido  
	Se checa para asegurar que no lleguaremos a un nodo NULL */ 
    
    // Caso 1: El nodo a eliminar es el UNICO NODO en la lista  
    if (nodoEliminar->siguiente == NULL && nodoEliminar->anterior == NULL) {  
        // Actualiza el HEAD de la lista a NULL, ya que la lista quedaria vacia  
        lista->head = NULL;  
    }   
    // Caso 2: El nodo a eliminar es el ULTIMO NODO en la lista  
    else if (nodoEliminar->siguiente == NULL) {  
        nodoEliminar->anterior->siguiente = NULL; // Cambias a donde apunta el nodo anterior en su variable siguiente (apuntaria a NULL)    
    }   
    // Caso 3: El nodo a eliminar es el PRIMER NODO en la lista  
    else if (nodoEliminar == lista->head) {  
        lista->head = nodoEliminar->siguiente; // Actualiza el head de la lista al siguiente nodo.  
        lista->head->anterior = NULL; // Haces que la variable anterior del nuevo HEAD apunte NULL  
    }   
    // Caso 4: El nodo a eliminar esta EN MEDIO de la lista  
    else {  
        // Conecta al nodo anterior y el nodo que le sigue para eliminar el nodo actual de la lista  
        nodoEliminar->anterior->siguiente = nodoEliminar->siguiente; // Conecta el nodo anterior con el siguente de nodoEliminar  
        nodoEliminar->siguiente->anterior = nodoEliminar->anterior; // Conecta el nodo siguiente con el anterior de nodoEliminar  
    }  
    
    // Actualiza el tamaño de la lista despues de eliminar el nodo  
    lista->size--;   
    free(nodoEliminar); // De nuevo dejamos a free chambear  
    
    return 0;  
}  


int sizeListaD(struct listaD *lista){
    return lista->size;
}

