/*	COLA ESTATICA CON TODAS LAS OPERACIONES
--------------------------------------
ENCOLAR
Inserta un elemento
--------------------------------------
DESENCOLAR
Elimina un elemento
--------------------------------------
FRONT
Devuelve el elemento head de la cola sin eliminarlo
--------------------------------------
EMPTY
Verifica si la cola esta vacia
--------------------------------------
FULL
Verifica si la cola esta llena
--------------------------------------
SIZE COLA ( SizeC )
Da el tamaño de la cola en ese momento

*/


#include <stdio.h>
#define pf printf 

// funciones

struct cola {  
    int elementos[10];  
    int head;  
    int tail;  
    int size;  
};  


void crearCola(struct cola *);  
int encolar(struct cola *, int);  
int desencolar(struct cola *);  
int front(struct cola *);  
int empty(struct cola *);  
int full(struct cola *);  
int sizeC(struct cola *);  


// operacionesCola

void crearCola(struct cola *colaNueva) {  
    colaNueva->head = 0;  
    colaNueva->tail = -1;  
    colaNueva->size = 0;  
    pf("Cola creada\n");  
}  



int encolar(struct cola *colaEncolar, int nuevoDato) {  
    if (colaEncolar->size == 10) {  
        pf("Cola llena\n");  
        return -1;  
    } else {  
        colaEncolar->tail++;  
        colaEncolar->size++;  
        colaEncolar->elementos[colaEncolar->tail] = nuevoDato;  
        pf("Elemento agregado: %d\n", nuevoDato);  
        return 0;  
    }  
}  



int desencolar(struct cola *colaDesencolar) {  
    if (colaDesencolar->size == 0) {  
        pf("Cola vacia\n");  
        return -1;  
    } else {  
        pf("Elemento eliminado: %d\n", colaDesencolar->elementos[colaDesencolar->head]);  
        colaDesencolar->head++;  
        colaDesencolar->size--;  
        return 0;  
    }  
}  



int front(struct cola *colaFront) {  
    if (colaFront->size == 0) {  
        pf("Cola vacia, no hay elemento en la parte delantera\n");  
        return -1; // O puedes manejarlo de otra forma  
    } else {  
        return colaFront->elementos[colaFront->head];  
    }  
}  



int empty(struct cola *colaChecar) {  
    return colaChecar->size == 0; // Devuelve 1 si est� vac�a, 0 si no  
}  



int full(struct cola *colaChecar) {  
    return colaChecar->size == 10; // Devuelve 1 si est� llena, 0 si no  
}  



int sizeC(struct cola *colaSize) {  
    return colaSize->size; // Devuelve el tama�o actual de la cola  
}  



//	Main

int main() {  
    struct cola miCola;  

    crearCola(&miCola);  
    desencolar(&miCola);  
    encolar(&miCola, 7);  
    encolar(&miCola, 21);  
    encolar(&miCola, 3);  
    
    pf("Elemento en la parte delantera: %d\n", front(&miCola));  

    desencolar(&miCola);  
    pf("¿Cola vacia? %s\n", empty(&miCola) ? "Si" : "No");  
    pf("Tamaño de la cola: %d\n", sizeC(&miCola));  

    desencolar(&miCola);  
    pf("¿Cola vacia? %s\n", empty(&miCola) ? "Si" : "No");  

    return 0;  
} 