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
}





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







tNodo *minimax(tNodo *nodo,int jugador){

  int max,max_actual,jugada,mejorJugada,profundidad=0;
  tNodo* intento = malloc(sizeof(tNodo));
  max= -10000;
  printf("\n Mi turno: \n");


  for(jugada=0; jugada<N ;jugada++ ){

    if(esValida(nodo,jugada)){
      intento = aplicaJugada(nodo,jugador,jugada);
      max_actual=valorMin(intento,profundidad);
      if( max_actual> max){
        max = max_actual;
        mejorJugada=jugada;
      }
    }
  }
  nodo= aplicaJugada(nodo,jugador,mejorJugada);

  return nodo;
}







int valorMin(tNodo *nodo, int profundidad) {
    int valor_min, jugada, jugador = -1;
     if(profundidad == LIMITE) {
        if( terminal(nodo,jugador)==0 && nodo->vacias != 0) {
            valor_min = heuristica(nodo);
        } else {
            valor_min = 100000;
            for (jugada = 0; jugada < N; jugada++) {
                if(esValida(nodo, jugada)) {
                    valor_min = minimo(valor_min, valorMax(aplicaJugada(nodo, jugador, jugada), ++profundidad));
                }
            }
        }
    }
    return valor_min; 
}





int valorMax(tNodo *nodo, int profundidad) {
    int valor_max, jugada, jugador = 1;
    if(profundidad == LIMITE) {
        if( terminal(nodo,jugador)==0 && nodo->vacias != 0) {
            valor_max = heuristica(nodo);
        } else {
            valor_max = -100000;
            for (jugada = 0; jugada < N; jugada++) {
                if(esValida(nodo, jugada)) {
                    valor_max = maximo(valor_max, valorMin(aplicaJugada(nodo, jugador, jugada), ++profundidad));
                }
            }
        }
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