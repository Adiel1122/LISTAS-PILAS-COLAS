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
    int datos[10];  
    int head;  
    int tail;  
    int size;  
};  


void crearCola(struct cola *);
void verCola(struct cola *);  
int encolar(struct cola *, int);  
int desencolar(struct cola *);  
int front(struct cola *);  
int emptyC(struct cola *);  
int fullC(struct cola *);  
int sizeC(struct cola *);  


// operacionesCola

void crearCola(struct cola *colaNueva) {  
    colaNueva->head = 0;  
    colaNueva->tail = -1;  
    colaNueva->size = 0;  
    pf("Cola creada\n");  
}  


void verCola(struct cola *cola){
    if(cola->size == 0){
        pf("Cola vacia\n");
        return;
    }
    pf("Datos de la cola:\n");
    for(int i = cola->head; i <= cola->tail; i--){
        pf("%d\n", cola->datos[i]);
    }
}


int encolar(struct cola *cola, int nuevoDato) {  
    if (cola->size == 10) {  
        pf("Cola llena\n");  
        return -1;  
    }  
    cola->tail++;  
    cola->size++;  
    cola->datos[cola->tail] = nuevoDato;  
    pf("Elemento agregado: %d\n", nuevoDato);  
    return 0;    
}  


int desencolar(struct cola *cola) {  
    if (cola->size == 0) {  
        pf("Cola vacia\n");  
        return -1;  
    }  
    pf("Elemento eliminado: %d\n", cola->datos[cola->head]);  
    cola->head++;  
    cola->size--;  
    return 0;    
}  


int front(struct cola *cola) {  
    if (cola->size == 0) {  
        pf("Cola vacia\n");  
        return -1;
    }  
    return cola->datos[cola->head];  
}  



int emptyC(struct cola *cola) {  
    return cola->size == 0; // Devuelve 1 si esta vacia, 0 si no  
}  



int fullC(struct cola *cola) {  
    return cola->size == 10; // Devuelve 1 si esta llena, 0 si no  
}  



int sizeC(struct cola *cola) {  
    return cola->size; 
}  



//	main

int main() {  
    struct cola miCola;
    crearCola(&miCola);  
    verCola(&miCola);

    pf("¿Cola vacia? %s\n", emptyC(&miCola) ? "Si" : "No");
    pf("¿Cola llena? %s\n", fullC(&miCola) ? "Si" : "No");  
    pf("Tamaño de la cola: %d\n", sizeC(&miCola)); 

    encolar(&miCola, 1);  
    encolar(&miCola, 2);  
    encolar(&miCola, 3);
    encolar(&miCola, 4);
    encolar(&miCola, 5);
    encolar(&miCola, 6);  
    encolar(&miCola, 7);  
    encolar(&miCola, 8);  
    encolar(&miCola, 9);  
    encolar(&miCola, 10);  

    pf("¿Cola vacia? %s\n", emptyC(&miCola) ? "Si" : "No");
    pf("¿Cola llena? %s\n", fullC(&miCola) ? "Si" : "No");  
    pf("Tamaño de la cola: %d\n", sizeC(&miCola)); 
  
  
    desencolar(&miCola); 
    desencolar(&miCola);
    desencolar(&miCola);    
    verCola(&miCola);

    return 0;  
} 