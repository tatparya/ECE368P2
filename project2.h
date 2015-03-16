#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void sort( int list[], int n );
void customQSortRec( int * arr, int beg, int end );
void swap( int *x, int *y );
void printArray( int * array, int n, char * comment );
