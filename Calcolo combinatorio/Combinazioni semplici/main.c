#include <stdio.h>
#include <stdlib.h>

/*
	Rispetto alle disposizioni semplici, qui si va a forzare uno dei possibili ordinamenti.

	Un esempio viene fornito dal seguente problema:
	Dato un insieme di n interi, generare tutte le combinazioni SEMPLICI di k di questi valori:
	per semplici si intende combinare i numeri nell'insieme in modo che non vengano ripetuti, a livello
	di valore, le stesse disposizioni, ergo

	insieme {7, 2, 0, 4 , 1}, voglio combinarli in insiemi da 3 elementi in maniera semplice

	Accettabili: {7, 2, 0, 4}, ..., {7, 2, 0, 1} Dopo aver generato queste soluzioni, non è necessario avere:
	Non accettabili: {2, 7, 0, 4}, {0, 1, 2, 7}

	Naturalmente non sono nemmeno accettabili ripetizioni all'interno dell'insieme generato, es {2, 2, 2, 7}
	Per queste vi sono le combinazioni con ripetizioni.

	Elementi necessari per l'algoritmo:
	- tutti gli elementi necessari nelle disposizioni con ripetizione, TRANNE il vettore mark
	- un indice start che determina a partire da quale valore di val si inizia a riempire sol

*/


void combinazioni_semplici(int pos, int n, int k, int start, int* sol, int* val);

int main(int argc, char const *argv[]){
	
	/* Per i dati mi baso sull'esempio introdotto nella descrizione */

	int n = 5;
	int k = 4;
	int start = 0;
	int pos = 0;
	int val[5] = {7, 2, 0, 4, 1};
	int sol[k];

	combinazioni_semplici(pos, n, k, start, sol, val);


	return 0;
}


void combinazioni_semplici(int pos, int n, int k, int start, int* sol, int* val){

	/* Condizione di terminazione identica a disposizioni semplici */
	if (pos >= k){
		for (int i = 0; i < k; i++)
			printf("%d ", sol[i]);
		printf("\n");

		return;
	}

	/* Costruzione della soluzione a partire da indice start (dipende quindi a che profondità ci troviamo) */
	for (int i = start; i < n; i++){
		sol[pos] = val[i];
		combinazioni_semplici(pos + 1, n, k , i + 1, sol, val);
	}

}







