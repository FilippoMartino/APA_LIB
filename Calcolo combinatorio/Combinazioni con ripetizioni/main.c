#include <stdio.h>
#include <stdlib.h>

/*
	Vale lo stesso esempio fatto per le combinazioni semplici, con la differenza che nelle combianzioni
	ripetute possono essere, appunto, ripetuti più volte elementi nella soluzione via via generata

	L'UNICA VARIANTE e che si mette l'incremento di start dopo la chiamata ricorsiva

	Cambiamo solo i dati dell'esempio: 
	"Lanciando due dadi, quali sono tutte le possibili combinazioni che possono presentare le facce?"

	Si rende quindi necessaria la ripetizione dei numeri, ad esempio (1, 1), ma la differenza che discrimina
	la scelta delle disposizioni con ripetizioni e che la coppia (4, 5) è uguale a (5, 4), che le combinaioni con
	ripetizioni scarta  
*/

void combinazioni_semplici(int pos, int n, int k, int start, int* sol, int* val);

int main(int argc, char const *argv[]){
	
	/* Per i dati mi baso sull'esempio introdotto nella descrizione */

	int n = 6;
	int k = 2;
	int start = 0;
	int pos = 0;
	int val[6] = {1, 2, 3, 4, 5, 6};
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
		combinazioni_semplici(pos + 1, n, k , start, sol, val);
		start ++;
	}

}








