
struct nodoP {  
    int dato;  
    struct nodoP *siguiente;  
};  

struct pila {  
    struct nodoP *tope;  
};  

void crearPila(struct pila *);
void verPila(struct pila *);  
int push(struct pila *, int);  
int pop(struct pila *);   
int top(struct pila *);
int empty(struct pila *);