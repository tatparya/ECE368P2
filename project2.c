/* ****************************
**
**  ECE 368 Project 2
**
**  Title: Sorting Competetion
**
**  Student 1: Tatparya Shankar
**  username: tshankar
**
***************************** */

#include "project2.h"

//  Main Sort Function
void sort( int list[], int n )
{
    //  Call custom qsort
    customQSortRec( list, 0, n );
}

void insertionSort( int * arr, int num   )
{
    int i;
    int j;
    int temp;

    for (i = 1; i < num; i++) {
        temp = arr[i];
        j = i - 1;
        while ((temp < arr[j]) && (j >= 0)) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
}

void customQSortRec( int * arr, int beg, int end )
{
    if (end > beg + 1)
    {
        int piv = arr[beg];
        int l = beg + 1;
        int r = end;
        //printf( "Pivot = %d\n", piv );
        while (l < r)
        {
            if (arr[l] <= piv)
            {
                l++;
            }
            else
            {
                swap(&arr[l], &arr[--r]);
            }
        }

        //printArray( arr, (end - beg),"Array being sorted: " );

        swap(&arr[--l], &arr[beg]);
        if( l - beg < 10 )
        {
            //  Insertion sort
            insertionSort( &arr[beg], l - beg );
        }
        else
        {
            customQSortRec(arr, beg, l);
        }
        if( l - beg < 10 )
        {
            //  Insertion sort
            insertionSort( &arr[r], end - r );
        }
        else
        {
            customQSortRec(arr, r, end);
        }

    }
}

//  Swap funciton to swap two numbers
void swap( int *x, int *y )
{
    int t = *x;
    *x = *y;
    *y = t;
}


//  To print an array of length n
void printArray( int * array, int n, char * comment )
{
    int i = 0;
    printf("%s\n", comment );
    for( i = 0; i < n; i++ )
    {
        printf( "%d : %d\n", i + 1, array[i] );
    }
    printf( "\n" );
}
