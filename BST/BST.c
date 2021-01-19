#include "BST.h"

typedef struct _bst_node* link;

/* CORE della logica bst, ogni nodo ha il proprio 'item', nonchè il puntatore ai figli sinistro e destro */
struct _bst_node {
	int item;
	link parent; // puntatore al padre
	link left; // puntatore a figlio sinistro
	link right; // puntatore a figlio destro
	int N; // dimensione sottoalbero
};

/* La struttura propria del bst contiene solo il puntatore alla testa, e il valore del nodo sentinella */
struct _bst {
	link root;
	link z;
};

/* Alloca un nuovo nodo, inizializzandolo con i parametri forniti */
static link new_node(int item, link parent, link left, link right, int N){
	
	link node = (link) malloc(sizeof(link));
	node->item = item;
	node->parent = parent;
	node->left = left;
	node->right = right;
	
	node->N = N;
	
	return node;
	
}

/* Dealloca ricorsivamente il BST */
static void tree_free(link head, link z){
	
	if (head == z)
		return;
	
	/* Ricorro fino alla fine dell'albero, dealloco il nodo (non avrò figli destri) e risalgo */
	
	tree_free(head->left, z);
	tree_free(head->right, z);
	
	free(head);
	
}

/* Funzione ricorsiva di conteggio elementi BST */
static int count(link head, link z){
	
	if (head == z)
		return 0;
	
	return count(head->left, z) + count(head->right, z) + 1;
	
}

/* Funzione di ricerca ricorsiva */
static int search(link h, int key, link z){
	
	/* Caso in cui abbiamo trovato l'item corrispondente alla chiave cercata */
	if (h->item == key)
		return h->item;
	
	/* Caso in cui si sia arricati alla fine dell'albero e la chiave non sia stata trovata */
	if (h == z)
		return -1;
	
	/* Se la chiave è minore del nodo corrente ricorro sul ramo di sinistra */
	if (h->item > key)
		return search(h->left, key, z);
	/* In caso contrario ricorro sul ramo di destra */
	return search(h->right, key, z);
	
}

/* Ricorre sui figli "sinistri" finche trova il minimo di un BST */
static int get_min(link h, link z){
	
	/* Caso albero vuoto */
	if (h == z)
		return -1;
	
	/* Se sono sull'ultima foglia sinistra (elemento più piccolo del BST) */
	if (h->left == z)
		return h->item;
	
	/* Ricorro sempre sul ramo sinistro */
	return get_min(h->left, z);
}

/* Ricorre sui figli "destri" finche trova il massimo di un BST */
static int get_max(link h, link z){
	
	/* Caso albero vuoto */
	if (h == z)
		return -1;
	
	/* Se sono sull'ultima foglia destra (elemento più grande del BST) */
	if (h->right == z)
		return h->item;
	
	/* Ricorro sempre sul ramo destro */
	return get_max(h->right, z);
}

/* Funzione ricorsiva per inserimento IN FOGLIA */
static link insert_leaf(link h, int item, link z){
	
	/* Nel caso il BST sia vuoto o fossimo arrivati alla fine */
	if (h == z)
		return new_node(item, z, z, z, 1);
	
	/* se la foglia da inserire è minore del nodo attuale ricorriamo a sinistra, altrimenti a destra */
	if (h->item > item){
		h->left = insert_leaf(h->left, item, z);
		h->left->parent = h;
	} else {
		h->right = insert_leaf(h->right, item, z);
		h->right->parent = h;
	}
	
	h->N = h->N + 1;
	
	/* Ritorniamo h (puntatore a foglia) */
	return h;
	
}

/* Funzione ricorsiva per la stampa di un BST secondo strategie diverse */
static void tree_print(link h, link z, Strategy strategy){
	
	if (h == z)
		return;
	
	if (strategy == PREORDER)
		printf("%d ", h->item);
	
	tree_print(h->left, z, strategy);
	
	if (strategy == INORDER)
		printf("%d ", h->item);
	
	tree_print(h->right, z, strategy);
	
	if (strategy == POSTORDER)
		printf("%d ", h->item);
	
}

/* Rotazione a destra */
static link rot_right(link h){
	
	link x = h->left;
	h->left = x->right;
	x->right->parent = h;
	x->right = h;
	x->parent = h->parent;
	h->parent = x;
	x->N = h->N;
	h->N = 1;
	h->N += (h->left) ? h->left->N : 0;
	h->N += (h->right) ? h->right->N : 0;
	
	return x;
}

/* Rotazione a sinistra */
static link rot_left(link h){
	
	link x = h->right;
	h->right = x->left;
	x->left->parent = h;
	x->left = h;
	x->parent = h->parent;
	h->parent = x;
	x->N = h->N;
	h->N = 1;
	h->N += (h->left) ? h->left->N : 0;
	h->N += (h->right) ? h->right->N : 0;
	
	return x;
	
}

/* Inserimento di un elemento in radice */
static link insert_root(link h, int item, link z){
	
	if (h == z)
		return new_node(item, z, z, z, 1);
	
	if (h->item < item){
		h->left = insert_root(h->left, item, z);
		h = rot_right(h);
		h->N ++;
	} else {
		h->right = insert_root(h->right, item, z);
		h = rot_left(h);
		h->N ++;
	}
		
	return h;
	
}

/* Restituisce (se presente) il nodo successore a quello specificato dalla chiave */
static int search_succ(link h, int key, link z){
	
	link p;
	
	/* Gestisco caso BST vuoto */
	if (h == z)
		return -1;
	
	/* Individuo la chiave dalla quale partire per la ricerca del successore */
	if (h->item == key) {
		
		/* Se non sono in una fogli */
		if (h->right != z) {
			/* Uso la funzione per trovare il minimo */
			return get_min(h->right, z);
			/* Altrimenti devo fare un paio di swap */
		} else {
			p = h->parent;
			
			for (; p != z && h == p->right;){
				h = p;
				p = p->parent;
			}
			return p->item;
		}
	}
	
	/* "indirizzamento" ricorsione */
	if (key < h->item)
		return search_succ(h->left, key, z);
	else
		return search_succ(h->right, key, z);
	
	return 0;
}

/* Restituisce (se presente) il nodo predecessore a quello specificato dalla chiave */
static int search_pred(link h, int key, link z){
	
	link p;
	
	/* Gestisco caso BST vuoto */
	if (h == z)
		return -1;
	
	/* Individuo la chiave dalla quale partire per la ricerca del successore */
	if (h->item == key) {
		
		/* Se non sono in una foglia */
		if (h->left != z) {
			/* Uso la funzione per trovare il minimo */
			return get_max(h->left, z);
			/* Altrimenti devo fare un paio di swap */
		} else {
			p = h->parent;
			
			for (; p != z && h == p->left;){
				h = p;
				p = p->parent;
			}
			return p->item;
		}
	}
	
	/* "indirizzamento" ricorsione */
	if (key < h->item)
		return search_pred(h->left, key, z);
	else
		return search_pred(h->right, key, z);
	
	return 0;
}

/* Selezione R-esimo elemento minore */
static int select(link h, int r, link z){
	
	int t;
	
	if (h == z)
		return -1;
	
	t = h->left->N;
	
	if (t > r)
		return select(h->left, r, z);
	else
		return select(h->right, r - t - 1, z);
	
	return h->item;
	
}

/* Funzione di partizionamento: riorganizza il BST avendo l'item con la k-esima chiave più piccola in radice */
static link partition(link h, int r){
	
	int t = h->left->N;
	
	if (t > r){
		h->left = partition(h->left, r);
		h = rot_right(h);
	}
	
	if (t < r){
		h->right = partition(h->right, r - t - 1);
		h = rot_left(h);
	}
	
	return h;
	
}

/* Unisce due nodi */
static link join(link a, link b, link z){
	
	/* controllo se si vogliono unire due puntatori non validi */
	if (b == z)
		return a;
	
	b = partition(b, 0);
	b->left = a;
	a->parent = b;
	b->N = a->N + b->right->N + 1;
	
	return b;
	
	
}

/* Bilancia un BST */
static link balance(link h, link z){
	
	/* Se BST vuoto */
	if (h == z)
		return z;
	
	/* Ricavo valore di r con la formula presente sui lucidi */
	int r = (h->N + 1) / 2 - 1;
	/* Partiziono h secondo r */
	h = partition(h, r);
	/* Bilancio i due sottoalberi */
	h->left = balance(h->left, z);
	h->right = balance(h->right, z);
	
	return h;
}

/* Cancella, se presente, il nodo corrispondente alla key */
link delete(link h, int key, link z){
	
	/* Necessari quando andrò a fare la free del nodo da eliminare */
	link y;
	link p;
	
	/* Se bst vuoto */
	if (h == z)
		return z;
	
	/* Scendo fino al nodo da eliminare (ricorsivamente) */
	if (h->item > key)
		h->left = delete(h->left, key, z);
	if (h->item < key)
		h->right = delete(h->right, key, z);
	
	/* Arrivato sul nodo decremento al dimensione del bst */
	h->N = h->N - 1;
	
	if (h->item == key){
		/* Salvo le inforazioni nell var temporanee*/
		y = h;
		p = h->parent;
		/* Salvo in ha l'unione dei suoi due sottoalberi */
		h = join(h->left, h->right, z);
		/* Salvo nuovamente il padre */
		h->parent = p;
		/* Libero il "vecchio nodo */
		free(y);
	}
	
	return h;
	
}

/* Alloca e restituisce un nuovo BST */
BST BST_init(void){
	
	/* Allocazione dinamica */
	BST bst = (BST) malloc(sizeof(BST));
	
	/* Inizializzazione nodo sentinella, questo non verrà più cambiato */
	bst->z = new_node(-1, NULL, NULL, NULL, 0);
	/* Inizialmente a root viene assegnato il valore del nodo sentinella*/
	bst->root = bst->z;
	
	return bst;
}

/* Wrapper, utilizza tree_free */
void BST_free(BST bst){
	
	if (bst == NULL)
		return;
	
	/* Deallochiamo tutto l'albero */
	tree_free(bst->root, bst->z);
	
	free(bst->z);
	
}

/* Wrapper conteggio elementi BST */
int BST_count(BST bst){
	return count(bst->root, bst->z);
}

/* Controllo BST vuoto */
int BST_empty(BST bst){
	
	if (!BST_count(bst))
		return 1;
	else
		return 0;
	
}

/* Wrapper, sfrutta la funzione di ricerca ricorsiva search */
int BST_search(BST bst, int key){
	return search(bst->root, key, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva get_min() */
int BST_min(BST bst){
	return get_min(bst->root, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva get_max() */
int BST_max(BST bst){
	return get_max(bst->root, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva insert_leaf() */
void BST_insert_leaf(BST bst, int item){
	bst->root = insert_leaf(bst->root, item, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva insert_root() */
void BST_insert_root(BST bst, int item){
	bst->root = insert_root(bst->root, item, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva tree_print() */
void BST_visit(BST bst, Strategy strategy){
	
	if (BST_empty(bst)) {
		printf("BST vuoto\n");
		return;
	}
	
	tree_print(bst->root, bst->z, strategy);
	printf("\n");
	
}

/* Wrapper, sfrutta funzione ricorsiva search_succ() */
int BST_succ(BST bst, int key){
	return search_succ(bst->root, key, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva search_pred() */
int BST_pred(BST bst, int key){
	return search_pred(bst->root, key, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva select() */
int BST_select(BST bst, int r){
	return select(bst->root, r, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva delete() */
void BST_delete(BST bst, int key){
	bst->root = delete(bst->root, key, bst->z);
}

/* Wrapper, sfrutta funzione ricorsiva balance() */
void BST_balance(BST bst){
	bst->root = balance(bst->root, bst->z);
}
