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
#define sf scanf


// funciones

struct pila{
    int datos[10];
    int tope;
};

void crearPila(struct pila*);
void verPila(struct pila*);
int pop(struct pila*);
int push(struct pila*, int);
int top(struct pila*);
int empty(struct pila*);
int full(struct pila*);
int size(struct pila*);


//  Operaciones

void crearPila(struct pila*pila){
    pila->tope = -1;
    pf("Pila creada\n");
}


void verPila(struct pila*pila){
    if(pila->tope==-1){
        pf("Pila vacia\n");
        return;
    }
    pf("Datos de la pila\n");
    for(int i=top(pila)-1; i>=0; i--){
        pf("%d\n",pila->datos[i]);
    }
}


int push(struct pila*pila, int nuevoDato){
    if(pila->tope==9){
        pf("Pila llena\n");
        return -1;
    } else{
        pila->tope++;
        pila->datos[pila->tope] = nuevoDato;
        pf("Dato ingresado: %d\n", nuevoDato);
        return 0;
    }
}


int pop(struct pila*pila){
    if(pila->tope==-1){
        pf("Pila vacia\n");
        return -1;
    } else{
        pf("Elemento eliminado: %d\n",pila->datos[pila->tope]);
        pila->tope--;
        return 0;
    }
}


int top(struct pila*pila){
    if(pila->tope==-1){
        pf("Pila vacia\n");
        return -1;
    }
    return pila->datos[pila->tope];
}


int empty(struct pila*pila){
    if(pila->tope!=-1){
        pf("Pila con elementos\n");
        return -1;
    }
    pf("Pila vacia\n");
    return 0;
}


int full(struct pila* pila){
    if(pila->tope!=9){
        pf("Pila no llena\n");
        return -1;
    }
    pf("Pila llena\n");
    return 0;
}


int size(struct pila* pila){
    return pila->tope+1;
}


// main

int main(){
    struct pila miPila;
    crearPila(&miPila);

    push(&miPila, 1);
    push(&miPila, 2);
    push(&miPila, 3);
    push(&miPila, 4);
    verPila(&miPila);

    pop(&miPila);
    pop(&miPila);

    verPila(&miPila);

    empty(&miPila);
    full(&miPila);
    pf("Tamaño de la pila: %d\n",size(&miPila));

    return 0;
}
