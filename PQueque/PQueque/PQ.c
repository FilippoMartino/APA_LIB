#include "PQ.h"

/* Definizione struttura coda ADT I livello */
struct pqueque {
	int* heap;
	int heap_size;
};

/* Funzioni di "serivzio" */
static void swap(int* array, int i, int j);

/* Inizializzazione */
PQ PQ_init(int heap_size){

	PQ pq = (PQ) malloc(sizeof(PQ));
	
	if (pq == NULL) {
		printf("Errore allocazione memoria [PQ.c]\n");
		return NULL;
	}
	
	pq->heap = (int*) malloc(sizeof(int) * heap_size);
	
	if (pq->heap == NULL) {
		printf("Errore allocazione memoria [PQ.c]\n");
		return NULL;
	}
	
	pq->heap_size = 0;
	
	return pq;

}

/* Free */
void PQ_free(PQ pq){

	free(pq->heap);
	free(pq);

}

/* Informazione sullo stato della dimensione */
int PQ_empty(PQ pq){
	return pq->heap_size == 0;
}

/* Inserimento di un elemento in coda, con evenutale ordinamento */
void PQ_insert(PQ pq, int item){

	/* partiamo come rifermento dall'ultimo elemento disponibile */
	int i = pq->heap_size ++;
	
	/* Ciclo finchè arriviamo in radice oppure troviamo un padre a priorità maggiore */
	for (; i >= 1 && pq->heap[PARENT(i)] < item;){
		/*
		 Se ci troviamo qui è perchè il padre del nodo nel quale ci troviamo è
		 a priorità minore: facciamo quindi scendere il nodo padre nel nodo
		 figlio in cui ci troviamo limitandoci a copiarlo, ripetiamo questa operazione
		 sul prossimo nodo padre
		 */
		pq->heap[i] = pq->heap[PARENT(i)];
		i = PARENT(i);
	}

	/*
	 Una volta usciti dal ciclo abbiamo fatto scendere (copiandoli) tutti gli
	 elementi minori nei nodi sottostanti al posto che deve occopare il nodo da inserire
	 non ci resta quindi che sovrascrivere il valore del nodo indicato dal contatore
	 */
	pq->heap[i] = item;
	return;

}

/* Estra la radice con la stessa logica degli heap */
int PQ_exctract_max(PQ pq){
	
	int max;
	
	/* Swap dell'elemento da estrarre con l'ultimo */
	swap(pq->heap, 0, pq->heap_size - 1);
	/* Acquisizione elemento */
	max = pq->heap[pq->heap_size - 1];
	/* Diminuzione dimensione heap */
	pq->heap_size --;
	
	/* Riordina la coda con la heapify */
	heapify(pq->heap, 0, pq->heap_size);

	return max;

}

/* Si limita a restituire la radice senza rimuoverla */
int PQ_show_max(PQ pq){
	return pq->heap[0];
}

/* Stampa la coda */
void PQ_display(PQ pq){
	
	for (int i = 0; i < pq->heap_size; i++)
		printf("%d ", pq->heap[i]);
	
	printf("\n");
	
}

/* Restituisce la dimensione della coda */
int PQ_size(PQ pq){
	return pq->heap_size;
}

/* Cambia la proprità di un elemento e riordina di conseguenza la coda */
void PQ_change(PQ pq, int pos, int item){

	/* Cicla funchè non arriviamo in radice o il padre ha priorità maggiore */
	for(;pos >= 1 && pq->heap[PARENT(pos)] < item;){
		/* Setessa logica di far discendere i nodi a valore minore copiando i padri nei figli*/
		pq->heap[pos] = pq->heap[PARENT(pos)];
		pos = PARENT(pos);
	}
	
	/* Sostituzione valore nel nodo all'indice corretto */
	pq->heap[pos] = item;
	/* Riordino della coda dopo un possibile "sconvolgimento" delle priorità */
	heapify(pq->heap, pos, pq->heap_size);

	return;

}

/* Semplice funzione di swap dati gli indici degli elementi da scambiare in un vettore */
static void swap(int* array, int i, int j){
	
	int temp = array[i];
	array[i] = array[j];
	array[j] = temp;
	
	
}
