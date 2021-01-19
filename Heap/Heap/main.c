#include "heap.h"


/* Main.c inutile, sfruttato solo per eventuali controlli */


int main(int argc, const char * argv[]) {
	
	int array[11] = {3, 5, 7, 9, 1, 2, 0, 8, 6, 4, 10};
	int heap_size = 11;
	
	build_heap(array, heap_size);
	
	print_heap(array, heap_size);
	
	
	
	
	return 0;
}
