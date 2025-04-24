
struct nodoCC {  
    int dato;  
    struct nodoCC *siguiente;  
};  


struct colaC {  
    struct nodoCC *head;  
    struct nodoCC *tail;  
};  

void crearColaC(struct colaC *);
void verColaC(struct colaC *);
void liberarColaC(struct colaC *);    
int encolarC(struct colaC *, int);  
int desencolarC(struct colaC *);  
int frontC(struct colaC *);
