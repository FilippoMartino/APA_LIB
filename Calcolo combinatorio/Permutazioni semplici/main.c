#include <stdio.h>
#include <stdlib.h>

void permutazioni_semplici(int pos, int n, char* sol, char* val, int* mark);

/*
	PROBLEMA:

	Generare tutti gli anagrammi della parola ora

	Gli anagrammi, per loro natura, hanno lo stasso numero di caratteri della parola di partenza:
	notiamo appunto che n = k, il che introduce il modello delle permutazioni

	Non vogliamo però il ripetersi dei caratteri più volte, a meno che non sia specificatamente richiesto.

	Il codice si compone esattamente come nel caso delle disposizioni semplici, con anche l'introduzione del 
	vettore "mark" per la limitazione delle ripetizioni.
	L'unica differenza propria sta nel fatto che nelle permutazioni, in generale, la dimensione dell'output
	è uguale a quella dell'input

	n (dimensioni input) -> 3
	k (dimensione output) -> 3
	insieme input -> int val[n] = {o, r, a}
	insieme output -> int sol[k]  

	

*/

int main(int argc, char const *argv[]){
	

	int n = 3; // = k
	int pos = 0;
	char* sol = (char*) malloc(sizeof(char) * n);
	char val[4] = {'o', 'r', 'a'};


	int mark[3] = {0, 0, 0};

	permutazioni_semplici(pos, n, sol, val, mark);

	return 0;
}

void permutazioni_semplici(int pos, int n, char* sol, char* val, int* mark){

	/* Stessa gestione della condizione di terminazione rispetto alle disposizioni ripetute */

	/* Si noti come unica differenza l'aver utilizzato n al posto di k, perchè uguali */
	
	if (pos >= n){

		for (int i = 0; i < n; i++)
			printf("%c ", sol[i]);
		printf("\n");

		return;
		
	}

	/* Costruzione della soluzione via via con marcamento e smarcamento */
	for (int i = 0; i < n; i++){

		if (!mark[i]){
			mark[i] = 1;
			sol[pos] = val[i];
			permutazioni_semplici(pos + 1, n, sol, val, mark);
			mark[i] = 0;
		}

	}

}


