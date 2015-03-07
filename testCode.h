#include <stdio.h>
#include <stdlib.h>

void sort( int list[], int n );
void customQSortRec(char *array, size_t size, int (*cmp)(void*,void*), int begin, int end) ;
void customQSortItr( int list[], int n );
void swap(void *x, void *y, size_t l);
int cmpfunc (const void * a, const void * b);
void printArray( int * array, int n, char * comment );
