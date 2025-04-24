
struct nodoLDC { 
    int dato;
    struct nodoLDC *siguiente;
    struct nodoLDC *anterior;
}; 

struct listaDC {
    struct nodoLDC *head;
    struct nodoLDC *tail;
    int size;
};


void crearListaDC(struct listaDC *);			    // BASICA
void verListaDC(struct listaDC *);				// BASICA
void verListaPosicionesDC(struct listaDC *);	    // BASICA
void liberarListaDC(struct listaDC *);			// Recomendada
int insertarDC(struct listaDC *,int);			    // BASICA
int insertarCualquierPosicionDC(struct listaDC *, int, int);
int insertarFinalDC(struct listaDC *, int);
int buscarDC(struct listaDC *,int);				// BASICA
int borrarDC(struct listaDC *, int);			    // BASICA
struct nodoLDC * buscarNodoDC(struct listaDC *,int);	// BASICA
int borrarIndiceDC(struct listaDC *,int);		    // BASICA
int sizeListaDC(struct listaDC *);				// Recomendada
