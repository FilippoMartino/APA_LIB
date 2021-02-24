#include "PQ.h"

struct pqueue {
	int* A; // coda a priorità vera e prorpia
	int* qp; // vettore che tiene conto degli indici a cui sono memorizzati i dati nella coda
	int heapsize; // numero di elementi presenti in coda
};

/* Funzioni di servizio */

static void Swap(PQ pq, int n1, int n2){
	
	int temp = pq->A[n1];
	pq->A[n1] = pq->A[n2];
	pq->A[n2] = temp;
	
	n1 = pq->A[n1];
	n2 = pq->A[n2];
	temp = pq->qp[n1];
	pq->qp[n1] = pq->qp[n2];
	pq->qp[n2] = temp;
	
}
static int LEFT(int i){
	return 2 * i + 1;
}
static int RIGHT(int i){
	return 2 * i + 2;
}
static int PARENT(int i){
	return (i - 1) / 2;
}
static void Heapify(PQ pq, int *mindist, int i){
	
	int l = LEFT(i);
	int r = RIGHT(i);
	
	int smallest;
	
	if (l < pq->heapsize && (mindist[pq->A[l]] < mindist[pq->A[i]]))
		smallest = l;
	else
		smallest = i;
	
	if (r < pq->heapsize && (mindist[pq->A[r]] < mindist[pq->A[smallest]]))
		smallest = r;
	
	if (smallest != i){
		Swap(pq, i, smallest);
		Heapify(pq, mindist, smallest);
	}
	
	return;
	
}

/* Funzioni di libreria */

PQ PQinit(int maxN){
	
	/* Inizializzazioni */
	PQ pq = (PQ) malloc(sizeof(PQ));
	pq->A = (int*) malloc(sizeof(int) * maxN);
	pq->qp = (int*) malloc(sizeof(int) * maxN);
	for (int i = 0; i < maxN; i++)
	pq->qp[i] = -1;
	
	pq->heapsize = 0;
	
	return pq;
}

void PQfree(PQ pq){
	free(pq->A);
	free(pq->qp);
	free(pq);
}

int PQempty(PQ pq){
	return pq->heapsize == 0;
}

void PQinsert (PQ pq, int *mindist, int node){
	int i;
	i = pq->heapsize++;
	pq->qp[node] = i;
	while (i>=1 && (mindist[pq->A[PARENT(i)]] > mindist[node])) {
		pq->A[i] = pq->A[PARENT(i)];
		pq->qp[pq->A[i]] = i;
		i = (i-1)/2;
	}
	pq->A[i] = node;
	pq->qp[node] = i;
	return;
}

int PQextractMin(PQ pq, int *mindist) {
	
	int k;
	Swap (pq, 0, pq->heapsize-1);
	k = pq->A[pq->heapsize-1];
	pq->heapsize--;
	Heapify(pq, mindist, 0);
	return k;
}

void PQchange (PQ pq, int *mindist, int k) {
	
	int pos = pq->qp[k];
	int temp = pq->A[pos];
	
	while (pos>=1 && (mindist[pq->A[PARENT(pos)]] > mindist[pq->A[pos]])) {
		pq->A[pos] = pq->A[PARENT(pos)];
		pq->qp[pq->A[pos]] = pos;
		pos = (pos-1)/2;
	}
	pq->A[pos] = temp;
	pq->qp[temp] = pos;
	
	Heapify(pq, mindist, pos);
	return;
}


