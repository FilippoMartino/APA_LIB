#include "ST.h"

struct symboltable {
	char* table;
	int N;
	int M;
};

ST STinit(int maxN){
	
	ST st = (ST) malloc(sizeof(ST));
	
	st->table = malloc(sizeof(int) * maxN);
	
	for (int i = 0; i < maxN; i++)
		st->table[i] = '0';
	
	st->M = maxN;
	st->N = 0;
	
	return st;
	
}

void STfree(ST st){
	free(st->table);
	free(st);
}

int STcount(ST st){
	return st->N;
}

void STinsert(ST st, char key){
	st->table[st->N] = key;
	st->N ++;
}

int STserach(ST st, char key){
	
	for (int i = 0; i < st->N; i++)
		if (st->table[i] == key)
			return i;
	
	return -1;
	
}

char STserachByIndex(ST st, int index){
	
	if (index > st->M || index < 0)
		return '0';
	
	return st->table[index];
	
}

void STdelete(ST st, char key){
	
	for (int i = 0; i < st->N; i++) {
		if (st->table[i] == key){
			st->table[i] = '0';
			st->N --;
			return;
		}
	}
	
}

void STdisplay(ST st){
	
	printf("Tabella di simboli:\n");
	for (int i = 0; i < st->N; i++)
		printf("%d. %c\n", i, st->table[i]);
	
}

