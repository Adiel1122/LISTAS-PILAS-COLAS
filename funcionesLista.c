
struct nodoL {
   int dato;
   struct nodoL *siguiente;
};

struct lista {
   struct nodoL *head;
};


void crearLista(struct lista *); 	// BASICA
void verLista(struct lista *);	 	// BASICA
void liberarLista(struct lista *);	// Recomendada
int insertar(struct lista *,int);	// BASICA
int buscar(struct lista *,int);		// BASICA
int borrar(struct lista *,int);		// BASICA
int size(struct lista *);			   // Recomendada
int insertarFinal(struct lista *, int);
int insertarCualquierPosicion(struct lista *, int, int);
int borrarIndice(struct lista *, int);
