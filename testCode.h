#include <stdio.h>
#include <stdlib.h>

void sort( int list[], int n );
void customQSortRec( int arr[], int beg, int end );
void customQSortItr( int list[], int n );
void swap( int *x, int *y );
int cmpfunc ( int * a,  int * b );
void printArray( int * array, int n, char * comment );
int * randGenerator( int n );
