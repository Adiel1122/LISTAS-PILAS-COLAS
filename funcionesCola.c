
struct nodoC {  
    int dato;  
    struct nodoC *siguiente;  
};  


struct cola {  
    struct nodoC *head;  
    struct nodoC *tail;  
};  

void crearCola(struct cola *);
void verCola(struct cola *);    
int encolar(struct cola *, int);  
int desencolar(struct cola *);  
int front(struct cola *);
int empty(struct cola *);
