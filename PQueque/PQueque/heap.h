#ifndef heap_h
#define heap_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 Funzioni per l'acquisizione dell'indice di padre, figlio destro o sinistro dato l'indice del nodo corrente
 */
int PARENT(int i);
int LEFT(int i);
int RIGHT(int i);

/**
 Funzione per la costruzione dell'heap
 @param a array binario da convertire in heap
 @param heap_size numero di elementi che andranno a costituire l'heap
 */
void build_heap(int* a, int heap_size);

/**
 Funzione per "l'adattamento" alle consizioni strutturali e funzionali dello heap
 @param a array da adattare alla proprietà funzionale
 @param left indice figlio sinistro (DEVE essere un heap)
 @param right indice figlio destro (DEVE essere un heap)
 */
void heapify(int* a, int left, int right);

/**
 Funzione di ordinamento che sfrutta le proprietà dello heap
 @param a array binario da ordinare
 @param heap_size numero elementi da ordinare
 */
void heap_sort(int* a, int heap_size);

/**
 Funzione stampa di uno heap
 @param heap da stampare
 @param heap_size numero di elementi da stampare (stampa in ordine)
 */
void print_heap(int* heap, int heap_size);

#endif /* heap_h */
