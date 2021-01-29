#include <stdio.h>
#include <stdlib.h>

/*
	Il powerset consente di dividere l'insieme di input in tutti i suoi sottoinsiemi
	compreso quello vuoto e se stesso

	Si realizza con un utlizzo di mark diverso, non per gestire le ripetizioni ma per indicare alla 
	condizione di terminazione quali elementi dell'insieme di input prendere e "mettere" nell'insieme di output

	Non vi è k, essendo il risultato una divisione in sottoinsiemi di un insieme di n elementi
	
	Nell'implementazione sviluppata di seguito non ho compreso "sol", perchè voglio solo stampare gli elementi
	del powerset senza manipolarli; per situazioni più complesse si va a costruire il sottoinsieme in sol (o lo si
	passa sovradimensionato o lo si costruisce direttamente nella condizione di terminazione) e si va via via ad operare

*/


void powerset(int pos, int n, int* val, int* mark);


int main(int argc, char const *argv[]){
	

	int n = 4;
	int pos = 0;
	int mark[n];

	for (int i = 0; i < n; i++)
		mark[i] = 0;

	int val[4] = {1, 2, 3, 4};

	powerset(pos, n, val, mark);

	return 0;
}

void powerset(int pos, int n, int* val, int* mark){

	if (pos >= n){
		
		printf("{ ");

		for (int i = 0; i < n; i++)
			if (mark[i])
				printf("%d ", val[i]);

		printf("}\n");

		return;			

	}

	mark[pos] = 0;
	powerset(pos + 1, n, val, mark);
	mark[pos] = 1;
	powerset(pos + 1, n, val, mark);


}







