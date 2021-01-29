#include <stdio.h>
#include <stdlib.h>

/*
	PROBLEMA: si vogliono tutti gli anagrammi della parola ORO

	Si rende necessaria una l'introduzione di un array di valori distinti, ossia
	val[n] diventa dist_val[n_dist]: in questo modo le due 'O' della parola 'ORO'
	vengono considerati come una scleta sola, anche se viene mantenuto il valore di
	n per generare comunque soluzioni della stessa dimensione dell'input

	Vengono introdotti

	n = 3 -> dimensione spazio input = dimensione spazio output
	n_dist = 2 -> numero di elementi distinti
	dist_val[n_dist] -> array con gli elementi di input non ripetuti
	mark[n_dist] -> nuemro di ripetizioni consentite per ogni elemento (in questo caso 1)
	sol[n] -> array su cui verrà salvata la soluzione

	
*/



void permutazioni_con_ripetizione(int pos, int n, int n_dist, char* sol, char* dist_val, int* mark);

int main(int argc, char const *argv[]){
	
	int n = 3; // = k
	int pos = 0;
	int n_dist = 2;
	char sol[3];
	char dist_val[2] = {'o', 'r'};
	int mark[2] = {2, 1};

	permutazioni_con_ripetizione(pos, n, n_dist, sol, dist_val, mark);

	return 0;
}


void permutazioni_con_ripetizione(int pos, int n, int n_dist, char* sol, char* dist_val, int* mark){

	if (pos >= n){
		for (int i = 0; i < n; i++)
			printf("%c ", sol[i]);
		printf("\n");

		return;
	}


	for (int i = 0; i < n_dist; i++){
		if (mark[i] > 0){
			mark[i] --;
			sol[pos] = dist_val[i];
			permutazioni_con_ripetizione(pos + 1, n, n_dist, sol, dist_val, mark);
			mark[i] ++;
		}
	}

}


