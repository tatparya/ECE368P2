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



//  Main function

int main (int argc, char ** argv)
{
    int n;
    int num = atoi( argv[1] );
    int values[] = { 88, 56, 100, 2, 25 };

    printArray( values, 5, "Before Sorting:" );

    qsort(values, 5, sizeof(int), cmpfunc);

    printArray( values, 5, "After Sorting:" );

    //  Testing time with inc number of itr
    int i = 0;
    int a = 1;

    for( i = 0; i < num; i ++ )
    {
        for( a = 0; a < num; a ++ )
        {

        }
    }

    printf( "Num = %d\n", num );
    return(0);
}

//  Custom qsort function ** Recursive **
//  1. array
//  2. size of array
//  3. size of an element
//  4. beginning index
//  5. last index
void customQSortRec(int *array, int size, int (*cmp)(void*,void*), int begin, int end)
{
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
        sort(array, size, cmp, begin, l);
        sort(array, size, cmp, r, end);
    }
}

//  Call to rec qsort
//  1. array
//  2. number of elements
//  3. size of an element
//  4. compare function
void recQSort(void *array, int nitems, int size, int (*cmp)(void*,void*)) {
    sort(array, size, cmp, 0, nitems*size);
}

//  Custom qsort function ** Iterative **
void customQSortItr( int list[], int n )
{

}

//  Compares two values
int cmpfunc (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

//  Swap funciton to swap two numbers
void swap(void *x, void *y, int l)
{
    int *a = x, *b = y, c;
    while(l--)
    {
        c = *a;
        *a++ = *b;
        *b++ = c;
    }
}

//  Main Sort Function
void sort( int list[], int n )
{

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

//  Print array of numbers
void * printArray( int list[], int n )
{
    int i = 0;
    printf( "Array :\n" );
    for( i = 0; i < n; i++ )
    {
        printf( "%d", list[i] );
    }
    printf( "\n" );
}

//  Function to generate a list of random numbers of n elements
int * randGenerator( int n )
{
    time_t t;
    srand( ( unsigned ) tiem( &t ) );
    int * list;
    list = malloc( n * sizeof( int ) )
    int i = 0;
    int num;
    for( i = 0; i < n; i ++ )
    {
        num = rand() % 10 + 1;
        list[i] = num;
    }
}
