/*	PILA ESTATICA CON TODAS LAS OPERACIONES
--------------------------------------
PUSH
Inserta un elemento
--------------------------------------
POP
Elimina un elemento
--------------------------------------
TOP / PEEK
Devuelve el elemento en la cima de la pila sin eliminarlo
--------------------------------------
EMPTY
Verifica si la pila esta vacia
--------------------------------------
FULL
Verifica si la pila esta llena
--------------------------------------
SIZE
Da el tamaño de la pila en ese momento

*/



#include <stdio.h>
#define pf printf

// funciones
  
struct pila{  
    int elementos[10];  
    int tope;  
};  

void crearPila(struct pila *);  
int pop(struct pila *);  
int push(struct pila *, int);  
int top(struct pila *);  
int empty(struct pila *);  
int full(struct pila *);  
int size(struct pila *);  
  

// operacionesPila

void crearPila(struct pila *pilaNueva) {  
    pilaNueva->tope = -1;  
    pf("Pila creada\n");  
}
  


int pop(struct pila *pilaPop) {  
    if (pilaPop->tope == -1) {  
        pf("Pila vacia\n");  
        return -1;  
    } else {  
        pf("Elemento eliminado: %d\n", pilaPop->elementos[pilaPop->tope]);  
        pilaPop->tope--;  
        return 0;  
    }  
}  



int push(struct pila *pilaPush, int nuevoDato) {  
    if (pilaPush->tope == 9) {  
        pf("Pila llena\n");  
        return -1;  
    } else {  
        pilaPush->tope++;  
        pilaPush->elementos[pilaPush->tope] = nuevoDato;  
        pf("Dato ingresado correctamente: %d\n", nuevoDato);  
        return 0;  
    }  
}  



int top(struct pila *pilaTop) {  
    if (pilaTop->tope == -1) {  
        pf("Pila vacia, no hay elemento en la cima\n");  
        return -1;  
    } else {  
        return pilaTop->elementos[pilaTop->tope];  
    }  
}  



int empty(struct pila *pilaChecar) {  
    return pilaChecar->tope == -1;  
}  



int full(struct pila *pilaChecar) {  
    return pilaChecar->tope == 9;  
}  



int size(struct pila *pilaSize) {  
    return pilaSize->tope + 1; // +1 porque tope comienza en -1  
}  



// Main

int main() {  
    struct pila miPila;  
    crearPila(&miPila);  
    
    push(&miPila, 100);  
    push(&miPila, 50);  
    
    pf("Elemento en la cima: %d\n", top(&miPila));  

    pop(&miPila);  
    pf("¿Pila vacia? %s\n", empty(&miPila) ? "Si" : "No");  
    pf("Tamaño de la pila: %d\n", size(&miPila));  
    
    pop(&miPila);  
    pf("¿Pila vacia? %s\n", empty(&miPila) ? "Si" : "No");  

    return 0;  
}