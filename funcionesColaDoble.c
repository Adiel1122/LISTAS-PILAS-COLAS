
struct nodoCD {
    int dato; 
    struct nodoCD *siguiente;
    struct nodoCD *anterior;
};

struct colaD {
    struct nodoCD *head;
    struct nodoCD *tail;
};

void crearColaD(struct colaD *);
void verColaD(struct colaD *);
int encolarHead(struct colaD *, int);
int encolarTail(struct colaD *, int);
int desencolarHead(struct colaD *);
int desencolarTail(struct colaD *);
int frontCD(struct colaD *);
int backCD(struct colaD *);