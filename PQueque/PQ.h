#ifndef PQ_h
#define PQ_h

#include "heap.h"

typedef struct pqueque* PQ;

/**
 Inizializzazione di una coda a priorità

 @param max_n numero massimo di elementi
 */
PQ PQ_init(int max_n);

/**
 Cancellazione di una coda a priorità

 @param pq coda da cancellare
 */
void PQ_free(PQ pq);

/**
 Controlla se la coda è vuota
 @param pq la coda da controllare
 */
int PQ_empty(PQ pq);

/**
 Inserimento di un elemento (ordinatamente) nella coda a priorità

 @param pq coda in cui inserire l'elemento
 @param item elemento da inserire
 */
void PQ_insert(PQ pq, int item);

/**
 Estrazione elemento a priorità massima

 @param pq coda dalla quale estrarre elemento massimo
 */
int PQ_exctract_max(PQ pq);

/**
 Permette di ricevere l'elemento a priorità massima, senza che questo venga rimosso dalla lista
 @param pq coda in questione
 */
int PQ_show_max(PQ pq);

/**
 Stampa una coda
 @param pq coda da stampare
 */
void PQ_display(PQ pq);

/**
 Restituisce il numero di elementi in coda
 @param pq coda della quale si vuole conoscere la dimensione
 */
int PQ_size(PQ pq);

/**
 Variazione priorità di un elemento con conseguente riordinamento

 @param pq coda sulla quale operare
 @param pos posizione all'interno della coda dell'elemento da variare
 @param item nuova prorità
 */
void PQ_change(PQ pq, int pos, int item);

#endif /* PQ_h */
