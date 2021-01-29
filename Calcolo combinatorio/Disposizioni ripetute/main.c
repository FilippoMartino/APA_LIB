#include <stdio.h>
#include <stdlib.h>

/*
	PROBLEMA:

	Elencare tutti i numeri binari di 4 cifre realizzabili con 1 e 0

	n (dimensioni input) -> 2
	k (dimensione output) -> 4
	insieme input -> int val[n] = {1, 0}
	insieme output -> int sol[k] 

	La dimensione della soluzione è ESCLUSIVAMENTE DATA dal valore di k

*/

void disposizioni_con_ripetizioni(int pos, int n, int k, int* val, int* sol);

int main(int argc, char const *argv[]){

	/* dichiarazione ed inizializzazione variabili */
	int n = 2;
	int k = 3;
	int pos = 0;
	int sol[k];
	int val[2] = {1, 0};

	disposizioni_con_ripetizioni(pos, n, k, val, sol);

	return 0;
}

void disposizioni_con_ripetizioni(int pos, int n, int k, int* val, int* sol){

	/* condizione di terminazione (se ho raggiunto la dimensione della soluzione desiderata) */
	if (pos >= k){
		for (int i = 0; i < k; i++)
			printf("%d ", sol[i]);
		printf("\n");

		return;
	}

	/* Dispongo gli elementi dall'insieme di input sulla soluzione */
	for (int i = 0; i < n; i++){
		sol[pos] = val[i];
		disposizioni_con_ripetizioni(pos + 1, n, k, val, sol);
	}

}

