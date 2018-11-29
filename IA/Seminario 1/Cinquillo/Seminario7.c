///estado final

/* 	oros col1		rey	caballo	sota 7 6 5 4 3 2 1	
	bastos col2	 	rey caballo sota  7 6 5 4 3 2 1

Operaciones

void colocarcarta( int carta, int columna)

test objetivo

void testobjetivo(int *col1,int* col2){
	
	if( ordenada(col1) && ordenada(col2) || mano1 == 0 || mano2==0)
		printf("FIN DE JUEGO")
}






*/


#define MESA 0
#define MAX 1
#define MIN -1

struct{
	///baraja -1 min 0 mesa 1 max
	int mesa[2][10];
	
}tnodo

struct{
	int jugador; 
	int palo;
	int carta;
	}tjugada;

void estadoinicial(){
	col1=	
}




void aplicajugada(tnodo* nodo, tjugada* jugada){

	if( esValido(nodo,jugada)==1){

		nodo->mesa[jugada->palo][jugada->carta]=0;

	}

}



int esValido(tnodo* nodo, tjugada* jugada) {
	int valido;
	if(nodo->mesa[jugada->palo][jugada->carta]==jugada->jugador){
		if( nodo->mesa[jugada->palo][jugada->carta-1] ==0 || nodo->mesa[jugada->palo][jugada->carta+1] ==0 ||  nodo->mesa[jugada->palo][jugada->carta+1] ==5 )

			puts("Se puede sealizar ");
			valido=1;
	}
	else{
		puts("ERROR");
		valido = 0;
	}

	return valido;
}























