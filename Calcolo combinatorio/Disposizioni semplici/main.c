#include <stdio.h>
#include <stdlib.h>

/*
	PROBLEMA:
	Quali sono i numeri di 2 cifre distinte realizzabili utilizzando
	i numeri (4, 9, 1, 0)?

	Individuazione di n (dimensione input) -> 4
	Individuazione di k (dimensione output) -> 2
	
	Ripetizione SI/NO -> NO, ci vengono chieste le cifre distinte

	Seguono:
	val -> vettore con gli n elementi di input
	sol -> vettore vuoto di n elementi in cui la funzione va a realizzare la soluzione
	mark -> vettore di n elementi con il numero massimo di ripetizioni (1)

*/



void disposizioni_semplici(int pos, int* val, int* sol, int* mark, int n, int k);


int main(int argc, char const *argv[]) {
	
	int n = 4;
	int k = 2;

	/* Vettore per evitare ripetizioni */
	int mark[4] = {0, 0, 0, 0};

	/* Spazio allocato per la soluzione */
	int* sol = (int*) malloc(sizeof(int) * n);

	int val[4] = {4, 9, 1, 0};
	int pos = 0;
	
	disposizioni_semplici(pos, val, sol, mark, n, k);


	

	return 0;
}

void disposizioni_semplici(int pos, int* val, int* sol, int* mark, int n, int k){

	/* Condizione di terminazione */
	if (pos >= k){
		for (int i = 0; i < k; i++)
			printf("%d ", sol[i]);
		printf("\n");
		return;
	}

	/* Costruzione della soluzione*/
	for (int i = 0; i < n; i++){
		if (mark[i] == 0){
			/* Viene markato l'elemento che non deve ripetersi */
			mark[i] = 1;
			/* Verranno via via aggiunti nuovi elementi dall'insieme di input a quello di output, tenendo appunto conto di mark */
			sol[pos] = val[i];
			/* Ricorsione con incremento della posizione */
			disposizioni_semplici(pos + 1, val, sol, mark, n, k);
			/* Smarcamento: quando si arriva qui si sono già costruite tutte le soluzioni con 'i' fisso */
			mark[i] = 0;
		}
	}
}