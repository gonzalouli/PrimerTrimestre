/*******************************************/
/* 		    minimaxAlum.c                  */
/*       Estrategia MiniMax                */
/*						                   */
/* Asignatura: Inteligencia Artificial     */
/* Grado en Ingenieria Informatica - UCA   */
/*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tictactoe.h"
#include "minimaxAlum.h"

#define LIMITE 2

/*
tNodo *PSEUDOminimax(tNodo *t) {
 int mejorJugada = -1;
 int puntos = -2;
 int i, temp;
 tNodo *intento=malloc(sizeof(tNodo));
 printf("\n Mi turno: \n");
 for(i = 0; i < 9; ++i){
  if (esValida(t,i)) {
    intento=aplicaJugada(t,1,i); //Intenta jugada
    temp =terminal(intento,-1); // Calcula el valor minimax
    if(temp > puntos) {
      puntos = temp;
      mejorJugada = i;
    }
   }
  }//for
t=aplicaJugada(t,1,mejorJugada);
return t;
}*/

tNodo *jugadaAdversario(tNodo *t) {
     int jugada = 0;
     printf("\nJugada ([0..8])?: ");
     scanf("%d", &jugada);
     while (!esValida(t,jugada))
     {
        printf("\n Intenta otra posicion del tablero \n");
        printf("\n");
        printf("\nJugada ([0..8])?: ");
        scanf("%d", &jugada);
     }
     t=aplicaJugada(t,-1,jugada);
     return t;
}

/*
tNodo *minimax(tNodo *nodo,int jugador){

  int max,max_actual,jugada,mejorJugada;
  tNodo* intento = malloc(sizeof(tNodo));
  max= -10000;
  printf("\n Mi turno: \n");


  for(jugada=0; jugada<N ;jugada++ ){

    if(esValida(nodo,jugada)){
      intento = aplicaJugada(nodo,jugador,jugada);
      max_actual=valorMin(intento);
      if( max_actual> max){
        max = max_actual;
        mejorJugada=jugada;
      }
    }
  }
  nodo= aplicaJugada(nodo,jugador,mejorJugada);
  return nodo;
}
*/



tNodo *poda_ab(tNodo *nodo,int jugador){

  int max,max_actual,jugada,mejorJugada,prof,v;

  int alfa = -100;
  int beta = 100;
  prof = 1;

  tNodo* intento = malloc(sizeof(tNodo));
  jugada = 1;

  printf("\n Mi turno: \n");


  while(jugada<=N){

    if(esValida(nodo,jugada)){
      intento = aplicaJugada(nodo,jugador,jugada);
      v = valorMin_ab(intento, opuesto(jugador),prof+1,alfa,beta);
      if( v > alfa){
        alfa = v;
        mejorJugada=jugada;
      }
    }
    jugada++;
  }

  if(esValida(nodo,mejorJugada))
    nodo= aplicaJugada(nodo,jugador,mejorJugada);
  
  return nodo;

}




int valorMin_ab(tNodo* nodo,int jugador,int prof,int alfa,int beta){

  int valor_min,jugada;
  tNodo* intento = malloc(sizeof(tNodo));

  int ganador = terminal(nodo,jugador);

  if( ganador!=0 || lleno(nodo))
    valor_min = ganador;
  else{
    if(prof == LIMITE)
      valor_min=heuristica(nodo,jugador);
    else
      jugada=1;
      while(jugada<=N && alfa < beta){
        if(esValida(nodo,jugada)){
          intento = aplicaJugada(nodo,jugador,jugada);
          beta = minimo (beta, valorMax_ab(intento,opuesto(jugador),prof+1,alfa,beta));
        }
        jugada++;
      }
      valor_min=beta;
    }
return valor_min;
}


int valorMax_ab(tNodo* nodo,int jugador,int prof,int alfa,int beta){

  int valor_max,jugada;
  tNodo* intento = malloc(sizeof(tNodo));

  if(terminal(nodo,jugador) || lleno(nodo))
    valor_max = terminal(nodo,jugador);
  else{
    if(prof == LIMITE)
      valor_max=heuristica(nodo,jugador);
    else
      jugada=1;
      while(jugada<=N && alfa < beta){
        if(esValida(nodo,jugada)){
          intento = aplicaJugada(nodo,jugador,jugada);
          alfa = maximo(alfa, valorMin_ab(  intento,  opuesto(jugador), prof+1, alfa, beta));
        }
        jugada++;
      }
      valor_max=alfa;
    }
return valor_max;
}




int maximo(int a,int b){
int max;
  if(a>=b)
    max = a;
  else
    max = b;

return max;
}

int minimo(int a,int b){
int min;
  if(a>=b)
    min = b;
  else
    min = a;

return min;
}
