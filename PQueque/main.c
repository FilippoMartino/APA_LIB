#include "PQ.h"

int main(int argc, const char * argv[]) {
	
	// Usare questo main come test della libreria se necessario
	
	PQ pq = PQ_init(10);
	PQ_insert(pq, 15);
	PQ_insert(pq, 17);
	PQ_insert(pq, 30);
	PQ_insert(pq, 31);
	PQ_insert(pq, 123);
	PQ_insert(pq, 73);
	
	PQ_display(pq);
	
	int max = PQ_exctract_max(pq);
	printf("max: %d\n\n", max);
	PQ_display(pq);
	
	max = PQ_exctract_max(pq);
	printf("max: %d\n\n", max);
	PQ_display(pq);
	
	max = PQ_exctract_max(pq);
	printf("max: %d\n\n", max);
	PQ_display(pq);
	
	return 0;
}
