#include <stdio.h>
#include <stdlib.h>

void sort( int list[], int n );
void customQSortRec( int arr[], int beg, int end );
void customQSortPar( int * arr, int beg, int end );
int findLargest( int * array, int n );
void radixSort( int * array, int n );
void recQSort( int *array, int nitems );
void swap( int *x, int *y );
void printArray( int * array, int n, char * comment );
int * randGenerator( int n );
