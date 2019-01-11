/*******************************************/
/* 		    minimaxAlum.h                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/

tNodo *jugadaAdversario(tNodo *t);
tNodo *PSEUDOminimax(tNodo *Nodo);
tNodo *minimax(tNodo *nodo,int jugador);
tNodo *poda_ab(tNodo *nodo,int jugador);
int valorMax_ab(tNodo* nodo,int jugador,int prof,int alfa,int beta);
int valorMin_ab(tNodo* nodo,int jugador,int prof,int alfa,int beta);
int maximo(int a,int b);
int minimo(int a,int b);
