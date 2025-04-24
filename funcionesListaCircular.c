
struct nodoLC {
   int dato;
   struct nodoLC *siguiente;
};

struct listaC {
   struct nodoLC *head;
};


void crearListaC(struct listaC *); 	   // BASICA
void verListaC(struct listaC *);	 	   // BASICA
void liberarListaC(struct listaC *);	// Recomendada
int insertarC(struct listaC *,int);	   // BASICA
int buscarC(struct listaC *,int);		// BASICA
int borrarC(struct listaC *,int);		// BASICA
int sizeC(struct listaC *);			   // Recomendada
int insertarFinalC(struct listaC *, int);
int insertarCualquierPosicionC(struct listaC *, int, int);
int borrarIndiceC(struct listaC *, int);
