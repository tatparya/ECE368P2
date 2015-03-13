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
//  2. size of array
//  3. size of an element
//  4. beginning index
//  5. last index
void customQSortRec(int *array, int size, int (*cmp)(void*,void*), int begin, int end)
{
    printf( "Size = %d", size );
    printArray( array, ( begin - end ), "\nMid sort:" );
    if (end > begin)
    {
        void *pivot = array + begin;
        int l = begin + size;
        int r = end;
        while(l < r)
        {
            if (cmp(array+l,pivot) <= 0)
            {
                l += size;
            } else if ( cmp(array+r, pivot) > 0 )  {
                r -= size;
            } else if ( l < r )
            {
                swap(array+l, array+r, size);
            }
        }
        l -= size;

        swap(array+begin, array+l, size);
        printArray( array, size, "\nAfter swap:\n" );
        customQSortRec(array, size, cmp, begin, l);
        customQSortRec(array, size, cmp, r, end);
    }
}

//  Call to rec qsort
//  1. array
//  2. number of elements
//  3. size of an element
//  4. compare function
void recQSort(void *array, int nitems, int size, int (*cmp)(void*,void*)) {
    printf( "Going into qsort\n" );
    printf( "Size = %d\nn items = %d\n", size, nitems );
    customQSortRec(array, size, cmp, 0, nitems*size);
}

//  Custom qsort function ** Iterative **
void customQSortItr( int list[], int n )
{

}



//  Swap funciton to swap two numbers
void swap(void *x, void *y, int l)
{
    int *a = x, *b = y, c;
    printf( "Before \na = %d, b =  %d\n", *a,*b );
    while(l--)
    {
        c = *a;
        *a++ = *b;
        *b++ = c;
    }
}

//  Compares two values
int cmpfunc ( void * a,  void * b )
{
    return ( *(int*)a - *(int*)b );
}

//  Main Sort Function
void sort( int list[], int n )
{
    //  Call to C-library qsort
    //qsort(list, n, sizeof(int), cmpfunc);

    //  Call to recQSort
    recQSort( list, n, sizeof( int ), cmpfunc );
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
        num = rand() % 10 + 1;
        list[i] = num;
    }

    //  Return list
    return list;
}
