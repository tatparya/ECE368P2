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

#include "testCode.h"

//  Find largest number in array
int findLargest( int * array, int n )
{
    int i = 0;
    int max = 0;

    for( i = 0; i < n; i++ )
    {
        //  Check if negative
        if( array[i] > 0 )
        {
            if( array[i] > max )
            {
                max = array[i] * -1;
            }
        }
        //  Positive
        else
        {
            if( array[i] > max )
            {
                max = array[i];
            }
        }

    }

    return max;
}


//  Regular radix sort
//
void radixSort( int * array, int n )
{
    //  Find largest element
    int i = 0;
    int max = 0;
    int sigDig = 1;
    const int base = 10;
    int * b = (int *) malloc( n * sizeof( int ) );

    //  Find the lasrgest number in the list
    max = findLargest( array, n );

    //  Sort by each radix
    while( max / sigDig != 0 )
    {
        //  Initiallize bucket to 0
        int bucket[10] = { 0 };

        //  Count num keys for each bucket
        for( i = 0; i < n; i ++ )
        {
            bucket[ ( array[i] / sigDig ) % base ]++;
        }

        //printArray( bucket, 10, "Bucket" );

        //  Add the count of the previous buckets
        //  to aquire the indices after the end of
        //  each bucket location in the array
        for( i = 1; i < 10; i++ )
        {
            bucket[i] += bucket[i - 1];
        }

        //printArray( bucket, 10, "Bucket after summing" );

        //  Starting at the end of the list,
        //  get index correspoinding to a[i]'s key
        //  Decremend it, and use it to place a[i]
        //  into the array
        for( i = n - 1; i >= 0; i -- )
        {

            b[--bucket[(array[i] / sigDig) % base]] = array[i];
        }

        //printArray( bucket, 10, "Bucket" );

        //  Copy array b to a
        for( i = 0; i < n; i++ )
        {
            array[i] = b[i];
        }

        //printArray( array, n, "Main array after pass" );

        //  Incremend significant digit
        sigDig *= base;
    }

    //  Free allocated memory
    free( b );
}

//  Custom qsort function ** Recursive **
//  1. array
//  2. beginning index
//  3. last index
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
                l++;
            else
                swap(&arr[l], &arr[--r]);
        }

        //printArray( arr, (end - beg),"Array being sorted: " );

        swap(&arr[--l], &arr[beg]);
        customQSortRec(arr, beg, l-1);
        customQSortRec(arr, r, end);
    }
}

//  Call to rec qsort
//  1. array
//  2. number of elements
void recQSort( int *array, int nitems )
{
    printf( "Going into qsort\n" );
    customQSortRec(array, 0, nitems );
}


//  Thread data struct declaration
//  1. beggining index
//  2. end index
//  3. array to sort
typedef struct ThreadData
{
    int beg;
    int end;
    int * array;
}   data;

//  Create Thread function
void createThreadDataStruct( struct ThreadData * threadStructPtr, int beg, int end, int * array )
{
    threadStructPtr -> beg = beg;
    threadStructPtr -> end = end;
    threadStructPtr -> array = array;
}

//  Custom qsort function ** Iterative **
void customQSortPar( int * arr, int beg, int end )
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
        customQSortRec(arr, beg, l-1);
        customQSortRec(arr, r, end);
    }
}

//  Main Sort Function
void sort( int list[], int n )
{
    //  Call to C-library qsort
    //qsort(list, n, sizeof(int), cmpfunc);

    //  Call to recQSort
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

//  Function to generate a list of random numbers of n elements
int * randGenerator( int n )
{
    //  Randomize
    time_t t;
    srand( ( unsigned ) time( &t ) );
    int * list;

    //  Mallo list memory
    list = malloc( n * sizeof( int ) );
    int i = 0;
    int num;

    //  Generate random integers and put into list
    for( i = 0; i < n; i ++ )
    {
        num = rand() % 1000 + 1;
        list[i] = num;
        //printf( "%d : %d\n", i + 1, list[i] );
    }

    //  Return list
    return list;
}
