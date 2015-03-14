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

//  Swap funciton to swap two numbers
void swap( int *x, int *y )
{
    int t = *x;
    *x = *y;
    *y = t;
}

//  Main Sort Function
void sort( int list[], int n )
{
    //  Call to C-library qsort
    //qsort(list, n, sizeof(int), cmpfunc);

    //  Call to recQSort
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
    }

    //  Return list
    return list;
}
