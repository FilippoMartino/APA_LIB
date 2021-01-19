#include "BST.h"

int main(int argc, const char * argv[]) {
	
	
	BST bst = BST_init();
	
	BST_insert_leaf(bst, 11);
	BST_insert_leaf(bst, 4);
	BST_insert_leaf(bst, 17);
	BST_insert_leaf(bst, 2);
	BST_insert_leaf(bst, 7);
	BST_insert_leaf(bst, 13);
	BST_insert_leaf(bst, 23);
	BST_insert_leaf(bst, 6);
	BST_insert_leaf(bst, 8);
	BST_insert_leaf(bst, 12);
	BST_insert_leaf(bst, 15);
	
	if (!BST_empty(bst))
		printf("Albero non vuoto\n");
	else
		printf("Albero vuoto\n");
	
	BST_visit(bst, INORDER);
	printf("\n");
	
	printf("Valore massimo: %d\n", BST_max(bst));
	printf("Valore minimo: %d\n", BST_min(bst));
	printf("In questo bst ci sono %d elementi\n", BST_count(bst));
	printf("\n");
	
	printf("Cerco elemento 8 -> %d\n", BST_search(bst, 8));
	printf("\n");
	
	printf("Succssore 11: %d\n", BST_succ(bst, 11));
	printf("Predecessore 11: %d\n", BST_pred(bst, 11));
	printf("\n");
	
	printf("Cancellazione elemento con chiave 6\n");
	BST_delete(bst, 6);
	
	BST_visit(bst, INORDER);
	
	printf("\n");
	
	printf("Cancellazione elemento con chiave 7\n");
	BST_delete(bst, 7);
	
	BST_visit(bst, INORDER);
	
	printf("\n");
	
	BST_free(bst);
	
	return 0;
}
