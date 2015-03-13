#include <stdio.h>
#include <stdlib.h>

void sort( int list[], int n );
void customQSortRec( int arr[], int beg, int end );
void customQSortItr( int list[], int n );
void recQSort( int *array, int nitems );
void swap( int *x, int *y );
void printArray( int * array, int n, char * comment );
int * randGenerator( int n );
