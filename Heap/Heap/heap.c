#include "heap.h"


/* Semplice funzione di swap di due elementi in un vettore */
static void swap(int* a, int i, int j);

/**
	Ritorna l'indice dell'elemento padre relativo all'indice passato
*/
int PARENT(int i){ return (i - 1) / 2; }

/**
	Ritorna l'indice dell'elemento figlio sinistro relativo all'indice passato
*/
int LEFT(int i){ return (i * 2) + 1; }

/**
	Ritorna l'indice dell'elemento figlio destro relativo all'indice passato
*/
int RIGHT(int i){ return (i * 2) + 2; }

/**
	Dato un vettore in cui sia memorizzato un albero binario, questa funzione
	sfrutta la heapify a partire dalle foglie (cui siamo sicuri essere heap) in
	maniera ricorsiva all'indietro fino alla radice
*/
void build_heap(int* a, int heap_size){

	for (int i = (heap_size / 2 - 1); i >= 0; i--)
		heapify(a, i, heap_size);

	return;

}

/**
  Questa funzione si occupa, partendo dalla terna (PARENT, LEFT, RIGHT)
  Di rendere rispettate le condizioni strutturali e funzionale di uno heap
*/
void heapify(int* a, int i, int heap_size){
	
	/* Acquisisco l'indice dei figli */
	int l = LEFT(i);
	int r = RIGHT(i);
	int largest = 0;

	/* Determino il più grande tra i tre nodi (padre e figli) */
	if (l < heap_size && a[l] > a[i])
		largest = l;
	else
		largest = i;

	if (r < heap_size && a[r] > a[largest])
		largest = r;

	/* Procedo solo se il padre è minore di uno dei due figli */
	if (i != largest){
		/* Scambio nell'array il padre attuale con il valore maggiore */
		swap(a, i, largest);
		/* Ricorro sul figlio che adesso contiene il valore che una volta apparteneva al padre */
		heapify(a, largest, heap_size);
	}

}

void swap(int* a, int i, int j){

	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;

}

/**
	Sfrutta le caratteristiche dello heap per ordinare un vettore:
	ricevuto un array binario, lo converte in uno heap, avremo
	quindi l'elemento a valore maggiore nella radice; ricorsivamente:
	- si estre la radice, scambiandola con l'ultima foglia, che nella rappresentazione
	  con vettore corrisponde proprio all'ultimo elemento (elementi maggiori in fondo al vettore)
	- si va a decrementare la grandezza dello heap, in modo che l'algoritmo operi solo sulla parte
	  ancora da ordinare
	- essendo, tolta la radice, i due figli a loro volta sicuramente degli heap, procediamo ad applicare
	  la heapify che porterà il prossimo elemento massimo in radice
	- si procede in questo modo finchè non terminiamo l'heap (la dimesione decrementata si esaurisce)

*/
void heap_sort(int* a, int heap_size){

	/* Iniziamo, naturalmente, convertendo l'array binario in uno heap */
	build_heap(a, heap_size);

	/* Ora l'elemento con valore maggiore si troverà alla radice, lo estraiamo */
	for (int i = heap_size - 1; i > 0; i--){
		/* Scambio la radice con l'ultimo elemento */
		swap(a, 0, i);
		/* Decremento le dimensioni dello heap */
		heap_size --;
		/* Porto in radice il prossimo elemento maggiore con la heapify */
		heapify(a, 0, heap_size);
	}

	return;

}

/**
 Semplice funzione di stampa
 */
void print_heap(int* heap, int heap_size){
	
	int level = 0;

	for (int i = 0; i < heap_size; i++){

		if (!level){
			printf("%d\n", heap[i]);
			level = 2;
		} else {
			for (int j = 0; j  < level && i < heap_size; j ++, i++)
				printf("%d ", heap[i]);

			printf("\n");
			level *= 2;
		}


	}
}

