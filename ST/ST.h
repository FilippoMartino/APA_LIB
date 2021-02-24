#ifndef ST_h
#define ST_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NODE_NULL_VAL -1

/* Le Tabelle di simboli di questa libreira sono implementate pensando all'utlizzo con i grafi */


typedef struct symboltable* ST;

/* Inizializzazione e cancellazione tabella */
ST STinit(int maxN);
void STfree(ST st);

/* Conteggio numero elementi nella tabella */
int STcount(ST st);

/* Inserimento */
void STinsert(ST st, char key);

/* Ricerca dell'indice di una data chiave */
int STserach(ST st, char key);

/* Ritorna il valore della tabella ad un dato indice */
char STserachByIndex(ST st, int index);

/* Cancellazione */
void STdelete(ST st, char key);

/* Stampa */
void STdisplay(ST st);


#endif /* ST_h */
