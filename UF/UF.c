#include "UF.h"

static int* id;
static int* sz;

void UFinit(int N){
	
	id = (int*) malloc(sizeof(int) * N);
	sz = (int*) malloc(sizeof(int) * N);
	
	for (int i = 0; i < N; i++) {
		id[i] = i;
		sz[i] = 1;
	}
}

static int find(int x){
	
	int i = x;
	
	/* Si sposta usando le referenze finchè non arriva alla prima cella che abbia valore uguale all'indice */
	for (;i != id[i];)
		i = id[i];
	
	return i;
}

int UFfind(int p, int q){
	return (find(p) == find(q));
}

void UFunoin(int p, int q){
	int i = find(p);
	int j = find(q);
	
	/* Se i risultati sono uguali esiste già una relazione, non dibbiamo unire nulla */
	if (i == j)
		return;
	
	
	if (sz[i] < sz[j]){
		id[i] = j;
		sz[j] += sz[i];
	} else {
		id[j] = i;
		sz[i] += sz[j];
	}
	
}

