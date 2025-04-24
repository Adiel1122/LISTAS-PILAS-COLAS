
struct nodoLD { 
    int dato;
    struct nodoLD *siguiente;
    struct nodoLD *anterior;
}; 

struct listaD {
    struct nodoLD *head;
    struct nodoLD *tail;
    int size;
};


void crearListaD(struct listaD *);			// BASICA
void verListaD(struct listaD *);				// BASICA
void verListaPosicionesD(struct listaD *);	// BASICA
void liberarListaD(struct listaD *);			// Recomendada
int insertarD(struct listaD *,int);			// BASICA
int insertarCualquierPosicionD(struct listaD *, int, int);
int insertarFinalD(struct listaD *, int);
int buscarD(struct listaD *,int);				// BASICA
int borrarD(struct listaD *, int);			// BASICA
int borrarIndiceD(struct listaD *,int);		// BASICA
int sizeListaD(struct listaD *);				// Recomendada

struct nodoLD * buscarNodoD(struct listaD *,int);	// BASICA
