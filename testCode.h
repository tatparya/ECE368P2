#include <stdio.h>
#include <stdlib.h>

void sort( int list[], int n );
void customQSortRec(int *array, int size, int (*cmp)(void*,void*), int begin, int end);
void customQSortItr( int list[], int n );
void swap(void *x, void *y, int l);
int cmpfunc (const void * a, const void * b);
void printArray( int * array, int n, char * comment );
int * randGenerator( int n );
