#ifndef PQ_h
#define PQ_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pqueue *PQ;

/* Inizializzazione e cancellazione */
PQ      PQinit(int maxN);
void    PQfree(PQ pq);

/* Booleana di servizio */
int     PQempty(PQ pq);

/* Inserimento */
void    PQinsert(PQ pq, int *mindist, int node);

/* Estrazione del minimo */
int     PQextractMin(PQ pq, int *mindist);

/* Cambio priorità */
void    PQchange(PQ pq, int *mindist, int k);

#endif /* PQ_h */
