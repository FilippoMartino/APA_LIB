#ifndef BST_h
#define BST_h

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ATTENZIONE */

/* In questa libreria si suppone l'oggetto 'ITEM', per semplicità, un intero */

typedef struct _bst* BST;

/* Enumerazione per la strategia di visita del BST */
typedef enum {
	INORDER,
	PREORDER,
	POSTORDER,
} Strategy;

/**
 Inizializza un nuovo BST
 */
BST BST_init(void);

/**
 Dealloca un BST
 
 @param bst il BST da deallocare
 */
void BST_free(BST bst);

/**
 Ritorna il numero di elementi presenti nel BST
 
 @param bst bst di cui si vuole conoscere la dimensione
 @return int numero di elementi presenti nel BST
 */
int BST_count(BST bst);

/**
 Controlla se un BST è vuoto
 
 @param bst BST da controllare
 
 @return 1 BST vuoto
 @return 0 BST non vuoto
 */
int BST_empty(BST bst);

/**
 Ricerca e restituisce, se presente, l'elemento item (in questa libreria un intero),
 corrispondente alla chiave di ricerca key
 
 @param bst BST sul quale effettuare la ricerca
 @param key chiave sulla base della quale effettuare la ricera
 
 @return item (int) nel caso sia stata trovata la chiave
 @return -1 (valore di default -> item_set_null) nel caso di elemento non presente nel BST
 */
int BST_search(BST bst, int key);

/**
 Si occupa di inserire l'elemento item in foglia, tale elemento deve quindi essere funzionalmente una
 foglia, per inserimenti all'interno del BST usare inserimento in radice
 
 @param bst BST in cui fare inserimento in foglia
 @param item item da inserire
	
 */
void BST_insert_leaf(BST bst, int item);

/**
 Si occupa dell'inserimento in radice di un elemento item, che può avvenire in qualisiasi
 punto del BST, si applicano le  rotazioni per mantenere la proprietà funzionale
 
 @param bst BST sul quale effettuare l'inserimento
 @param item oggetto da inserire
 */
void BST_insert_root(BST bst, int item);

/**
 Restituisce, nel caso di un BST con almeno un elemento, l'elemento con valore minore
 
 @param bst BST sul quale efettuare la  ricerca
 
 @return int item con valore minore in caso di successo
 @return int item_set_default (nel caso di questa lib = -1) in caso di albero senza elementi
 */
int BST_min(BST bst);

/**
 Restituisce, nel caso di un BST con almeno un elemento, l'elemento con valore maggiore
 
 @param bst BST sul quale efettuare la  ricerca
 
 @return int item con valore maggiore in caso di successo
 @return int item_set_default (nel caso di questa lib = -1) in caso di albero senza elementi
 */
int BST_max(BST bst);

/**
 Stampa il BST passato secondo la strategia specificata
 
 @param bst BST da stampare
 @param strategy una delle 3 strategie disponibili (INORDER, PREORDER, POSTORDER)
 */
void BST_visit(BST bst, Strategy strategy);

/**
 Restituisce il primo successore (chiave minima successiva a quella specificata)
 
 @param bst BST sul quale effettuare la ricerca
 @param key chiave della quale cercare il successore
 */
int BST_succ(BST bst, int key);


/**
 Restituisce il primo predecessore (chiave minima precedente a quella specificata)
 
 @param bst BST sul quale effettuare la ricerca
 @param key chiave della quale cercare il predecessore
 */
int BST_pred(BST bst, int key);

/**
 Selezione dell'item con la r-seima chiave più piccola
 
 @param bst BST sul quale operare
 @param r r-esima chiave
 */
int BST_select(BST bst, int r);

/**
 Cancella dal bst il nodo corrispondente alla chiave specificata
 
 @param bst BST dal quale cancellare
 @param key chiave del nodo da cancellare
 */
void BST_delete(BST bst, int key);

/**
 Permette di bilanciare un BST
 
 @param bst BST da bilanciare
 */
void BST_balance(BST bst);

#endif /* BST_h */
